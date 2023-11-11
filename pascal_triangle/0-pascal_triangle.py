#!/usr/bin/python3
"""function def pascal_triangle(n): that returns
a list of lists of integers representing
the Pascal’s triangle of n"""


def pascal_triangle(n):
    """function def pascal_triangle(n): that returns
a list of lists of integers representing
the Pascal’s triangle of n"""
    if n <= 0:
        return []
    result = []
    for line in range(n):
        row = []
        x = 1
        for i in range(line + 1):
            row.append(x)
            b = (i + 1)
            x = x * (line - i) // b
        result.append(row)
    return result
