/* PC/UVa IDs: 110103/10137, Popularity: B, Success rate: average Level: 1
 * Resolved by: GOMA
 * 2013-12-26
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* It Contains the information about each strip */
typedef struct {
    long   n,    /* number of students of each strip */
           *v,   /* vector with money spent by each student, in cents */
           mean, /* The Mean of the money spent by students */
           exc;  /* Money exchanged by the students */
} T_Trip;

void T_Trip_mean (T_Trip *trip) {
    long sum = 0,
        i;
    double mean_aux;  /* Mean in floating */
    for (i = 0; i < trip->n; i++) 
        sum += trip->v[i];
    
    mean_aux = ((double) sum / trip->n ) ;
    trip->mean =  (int) (mean_aux+0.5);
}

/* Calculate the money exchanged. All the operations are made with money in cents */
void T_Trip_exc (T_Trip *trip) {
    long i;
    trip->exc = 0;
    for (i = 0; i < trip->n ; i++) 
        if (trip->v[i] > trip->mean) 
            trip->exc += (trip->v[i] - trip->mean);

}

int main(int argc, const char *argv[])
{
    T_Trip trip;
    long i;
    while ( scanf("%d", &trip.n) && trip.n != 0 ) {
        double aux;
        trip.v = malloc( trip.n * sizeof(int) ); 
        for (i = 0; i < trip.n; i++) {
            scanf("%lf", &aux);
            trip.v[i] = aux * 100 ;        /* converting to cents */
        }
        T_Trip_mean(&trip);
        T_Trip_exc(&trip);
        printf("$%.2lf\n", (double) trip.exc/100);
        free(trip.v);
    }
    return 0;
}
