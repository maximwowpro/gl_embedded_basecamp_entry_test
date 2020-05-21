#include <stdio.h>
#include <stdlib.h>


/*
 * Function:  count_stairs
 * --------------------
 * Computes a total number of the Giant's steps using this formula:
 * 
 * Dividing and multiplication by 2 implemented as a 
 * shift to right/left by 1 byte to increase performance.
 *
 *  n: total number of stairs;
 *  k: the Giant could step over each K-th stair.
 *
 *  returns: the total number of stairs the Giant steps.
 */
static int count_stairs(int n, int k);

int main(int argc, char *argv[])
{
        if (3 != argc) {
                printf("Usage: %s <number of stairs >= 0> <the number of steps Giant could step over >= 0>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
        
        int n = 0;
        int k = 0;
        int stairs_total = 0;
        n = atoi(argv[1]);
        k = atoi(argv[2]);
        if (n < 0) {
                printf("ERROR: number of stairs should be non-negative integer, you entered: %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }
        if (k < 0) {
                printf("ERROR: number of steps should be non-negative integer, you entered: %s\n", argv[2]);
                exit(EXIT_FAILURE);
        }
        
        stairs_total = count_stairs(n, k);
        printf("%i\n", stairs_total);       
        
        return EXIT_SUCCESS;
}

static int count_stairs(int n, int k)
{
        return ((n % (k+1)) == 0) ? (n / (k+1)) : ((n / (k+1)) + 1);
}
