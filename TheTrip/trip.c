/* PC/UVa IDs: 110103/10137, Popularity: B, Success rate: average Level: 1
 * Resolved by: GOMA
 * 2013-12-26
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* It Contains the information about each strip */
typedef struct _trip {
    double *v,           /* Vector with the money spent by each person */
           total,        /* Total spent by all persons */
           mean;         /* The Mean of all students costs */
    long n_students;
} T_Trip;

int main(int argc, const char *argv[])
{
    T_Trip trip;
    long i,n;
    double differ,      /* Difference between each spent and the mean */
           exchange;
    while ( scanf("%ld", &trip.n_students) && trip.n_students != 0 ) {
        trip.v = malloc(trip.n_students * sizeof(double));
        trip.total = 0;      
        double uppersum, lowersum;
        uppersum = lowersum = 0;
        for (i = 0; i < trip.n_students; i++) {
            scanf("%lf", &trip.v[i]);     
            trip.total += trip.v[i];
        }
        trip.mean = trip.total / trip.n_students ;
        for (i = 0; i < trip.n_students; i++) {
            differ = (double) (long) ((trip.v[i] - trip.mean) * 100.0) / 100.0;
            if (differ < 0) lowersum += differ;
            else uppersum += differ;
        }
        exchange = ( -lowersum > uppersum ) ? -lowersum : uppersum;
        printf("$%.2lf\n", exchange);

        free(trip.v);
    }
    return 0;

}
