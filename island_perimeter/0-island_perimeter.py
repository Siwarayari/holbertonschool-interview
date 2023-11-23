#!/usr/bin/python3
"""
function that returns the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """function that returns the perimeter of the island described in grid"""
    row = len(grid)
    col = len(grid[0])
    count = 0

    for i in range(row):
        for j in range(col):
            if grid[i][j] == 1:
                count += 4
                if i > 0 and grid[i - 1][j] == 1:
                    count -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    count -= 2
    return count
  
