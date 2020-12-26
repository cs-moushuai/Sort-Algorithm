#!/usr/bin/env python3

import copy


def CountSort(arr, place):
    count_arr = list(0 for i in range(10))
    for i in arr:
        count_arr[(i//place) % 10] += 1
    for i in range(1, 10):
        count_arr[i] += count_arr[i-1]
    size = len(arr)
    output = list(0 for i in range(size))
    for i in reversed(arr):
        output[count_arr[(i//place) % 10] - 1] = i
        count_arr[(i//place) % 10] -= 1
    # arr = copy.deepcopy(output)
    for i in range(size):
        arr[i] = output[i]


def RadixSort(arr):
    max_val = max(arr)
    place = 1
    while max_val // place > 0:
        CountSort(arr, place)
        place *= 10
