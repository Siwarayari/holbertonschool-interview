#!/usr/bin/python3
"""queens puzzle is the challenge of placing N
non-attacking queens on an N×N chessboard. Write
a program that solves the N queens problem"""


import sys


def nqueens(n: int):
    """queens puzzle is the challenge of placing N
non-attacking queens on an N×N chessboard. Write
a program that solves the N queens problem"""
    columns = [0] * n

    def valid(row, col):
        """chack if the position is valid to place a nqueens"""
        for i in range(row):
            if columns[i] == col:
                return False
            if columns[i] - i == col - row:
                return False
            if columns[i] + i == col + row:
                return False
        return True

    result = []

    def backtrack(row):
        """function to place nqueens"""
        if row != n:
            for col in range(n):
                if valid(row, col):
                    columns[row] = col
                    backtrack(row + 1)
        else:
            result.append([[i, columns[i]] for i in range(n)])

    backtrack(0)
    for board in result:
        print(board)


if __name__ == "__main__":
    """Usage: nqueens N
    where N must be an integer greater or equal to 4
    The program should print every possible solution
    to the problem"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    if not sys.argv[1].isdigit():
        print("N must be a number")
        exit(1)
    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        exit(1)
    nqueens(int(sys.argv[1]))
