#!/usr/bin/python3
"""Rotate 2D Matrix"""


def rotate_2d_matrix(matrix):
    length = len(matrix)
    matrix.reverse()
    for i in range(0, length - 1):
        for j in range(i + 1, length):
            temp = matrix[i][j]
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = temp
