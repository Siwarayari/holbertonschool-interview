#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    printf("=\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j != 0)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First sandpile grid
 * @grid2: Second sandpile grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j, unstable;
    int grid3[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    do {
        unstable = 0;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (grid1[i][j] > 3)
                {
                    unstable = 1;
                    grid1[i][j] -= 4;

                    if (i - 1 >= 0)
                        grid3[i - 1][j] += 1;
                    if (i + 1 < 3)
                        grid3[i + 1][j] += 1;
                    if (j - 1 >= 0)
                        grid3[i][j - 1] += 1;
                    if (j + 1 < 3)
                        grid3[i][j + 1] += 1;
                }
            }
        }

        if (unstable)
        {
            printf("=\n");
            print_grid(grid1);

            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    grid1[i][j] += grid3[i][j];
                    grid3[i][j] = 0;
                }
            }
        }
    } while (unstable);
}
