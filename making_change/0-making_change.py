#!/usr/bin/python3
"""
Given a pile of coins of different values,
determine the fewest number of coins needed
to meet a given amount total
"""
import sys


def makeChange(coins, total):
    if total <= 0:
        return 0

    table = [0 for i in range(total + 1)]

    m = len(coins)

    for i in range(1, total + 1):
        table[i] = sys.maxsize

    for i in range(1, total + 1):

        for j in range(m):
            if (coins[j] <= i):
                sub_result = table[i - coins[j]]
                if (sub_result != sys.maxsize and sub_result + 1 < table[i]):
                    table[i] = sub_result + 1

    if table[total] == sys.maxsize:
        return -1

    return table[total]
