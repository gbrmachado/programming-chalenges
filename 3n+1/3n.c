#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/***************************************
 * The count is called by reference.
 * Calculate the length of the cycle
 **************************************/
long cycle_length(long n, long *count) {
    if (n==1) {
        return 1;
    }
    if ( n%2 == 1 ) {
        (*count)++;
        cycle_length(3*n+1,count);
    }
    else {
        (*count)++;
        cycle_length( n/2, count);
    }
}
/********************************************
 * Max Cycle calculate the max length cycle
 * between two numbers                   
 *******************************************/
long max_cycle_length(long a, long b) {
    long count, i, max_cycle;
    max_cycle = -1;
    if (a < b) 
        for (i = a; i <= b; i++) {
            count = 1;
            cycle_length(i, &count);
            if (count > max_cycle)
                max_cycle = count;
        }
    else
        for (i = b; i <= a; i++) {
            count = 1;
            cycle_length(i, &count);
            if (count > max_cycle)
                max_cycle = count;
        }
    return max_cycle;
}
int main(void) {
    long a,b;
    while (scanf("%ld %ld", &a, &b) != EOF) { 
        printf("%ld %ld %ld\n", a,b,max_cycle_length(a,b));
    }
    return 0;
}

