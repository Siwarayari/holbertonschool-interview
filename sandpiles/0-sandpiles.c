#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i = 0;
    int j = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }
}
