#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long n_bomb;    /* Number of bombs */
    long is_bomb;   /* 1 if is a bomb, 0 if is not  */
}TPos;

/* Print the vector of TPos    */
void print_vector(TPos **v, long m, long n) {
    long i,j;
    printf("\n");
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (v[i][j].is_bomb == 1) 
                printf("%c", '*');
            else
                printf("%ld", v[i][j].n_bomb);
        }
    printf("\n");
    }
}

/* Transform the input format into a vector of TPos */
void gera_vetor(char input[150][150], TPos **v, long m, long n) {
    long i,j;
        
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            v[i][j].n_bomb = 0;
            if (input[i-1][j-1] == '.') 
                v[i][j].is_bomb = 0;
            if (input[i-1][j-1] == '*')
                v[i][j].is_bomb = 1;
        }
    }
}

/* Generate the solution, increment each bomb neighbor */
void solution(TPos **v, long m, long n) {
    long i,j,k;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) 
            if (v[i][j].is_bomb == 1) {
                for (k=0;k<3;k++) {
                    v[i+1][j-1+k].n_bomb++;
                    v[i-1][j-1+k].n_bomb++;
                }
                v[i][j-1].n_bomb++;
                v[i][j+1].n_bomb++;
            }
    }
}
long main() {
    char aux[150][150], input[150];
    long i,m,n,
        field=1;
    TPos **vetor;
    while(1) {
        fgets(input, 150, stdin);
        sscanf(input, "%ld %ld", &m, &n);
        if (m==0 && n==0) return 0;  /* If 0 0, exit */
        else if (field != 1) printf("\n"); /*Else, print a break of line */

        vetor = malloc((m+2)*sizeof(TPos));
        for (i=0; i< m+2; i++)
            vetor[i] = malloc((n+2) * sizeof(TPos));
        for (i = 0; i < m; i++)   
            fgets(aux[i], 150, stdin);
        gera_vetor(aux,vetor,m,n);
        solution(vetor,m,n);
        printf("Field #%ld:", field++);
        print_vector(vetor,m,n);
        free(vetor); 
        }
    return 0;
}

