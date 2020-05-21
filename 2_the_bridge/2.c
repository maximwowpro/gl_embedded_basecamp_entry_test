#include <stdio.h>
#include <stdlib.h>


/*
 * Function:  count_cable_len
 * --------------------
 * Computes a total length of cable using function of sum of
 * members of an arithmetic progression:
 * summ = (2*d + (n-1)*d)*n / 2
 * Dividing and multiplication by 2 implemented as a 
 * shift to right/left by 1 byte to increase performance.
 *
 *  n: total number of spans of the bridge;
 *  d: the distance between the spans.
 *
 *  returns: the total length of cable.
 */
static int count_cable_len(int n, int d);

int main(int argc, char *argv[])
{
        if (3 != argc) {
                printf("Usage: %s <number of spans != 0> <the distance != 0>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
        
        int n = 0;
        int d = 0;
        int total_len = 0;
        n = atoi(argv[1]);
        d = atoi(argv[2]);
        if (n < 0) {
                printf("ERROR: number of spans should be positive integer, you entered: %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }
        if (d < 1) {
                printf("ERROR: the distance should be positive integer, you entered: %s\n", argv[2]);
                exit(EXIT_FAILURE);
        }
        
        total_len = count_cable_len(n, d);
        printf("%i\n", total_len);       
        
        return EXIT_SUCCESS;
}

static int count_cable_len(int n, int d)
{
        return (((d << 1) + ((n - 1) * d)) * n) >> 1;
}
