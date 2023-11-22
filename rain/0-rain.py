#!/usr/bin/python3
"""Assume that the ends of the list
(before index 0 and afterindex walls[-1]) are not
walls, meaning they will not retain water"""


def rain(walls):
    rain = 0
    length = len(walls)
    for i in range(1, length - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for k in range(i + 1, length):
            right = max(right, walls[k])
        rain = rain + (min(left, right) - walls[i])

    return rain
