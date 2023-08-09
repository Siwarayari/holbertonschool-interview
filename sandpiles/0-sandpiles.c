#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
static void print_grid_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid1[i][j]);
        }

        printf(" %c ", (i == 1 ? '+' : ' '));

        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid2[i][j]);
        }
        printf("\n");
    }
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int stable = 0;
    int tmp_grid[3][3];

    // Add grids element-wise
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];

            // Check if the sum is unstable
            if (grid1[i][j] > 3)
                stable = 1;
        }
    }

    // Perform toppling until the grid is stable
    while (stable)
    {
        printf("=\n");
        print_grid(grid1);
        stable = 0;

        // Copy grid1 to tmp_grid
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                tmp_grid[i][j] = grid1[i][j];
            }
        }

        // Topple the sandpiles
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                // Check if the current cell has more than 3 grains
                if (tmp_grid[i][j] > 3)
                {
                    grid1[i][j] -= 4; // Reduce the grains by 4

                    // Distribute the grains to neighboring cells
                    if (i - 1 >= 0)
                        grid1[i - 1][j] += 1; // Top neighbor
                    if (i + 1 < 3)
                        grid1[i + 1][j] += 1; // Bottom neighbor
                    if (j - 1 >= 0)
                        grid1[i][j - 1] += 1; // Left neighbor
                    if (j + 1 < 3)
                        grid1[i][j + 1] += 1; // Right neighbor
                }
            }
        }

        // Check if the resulting grid is stable
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                // Check if any cell has more than 3 grains
                if (grid1[i][j] > 3)
                    stable = 1;
            }
        }
    }
}
