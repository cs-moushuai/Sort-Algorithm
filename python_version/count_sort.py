#!/usr/bin/env python3

import copy

def CountSort(arr):
    max_val = max(arr)
    count_arr = list(0 for i in range(max_val + 1))
    for i in arr:
        count_arr[i] += 1
    for i in range(1, max_val + 1):
        count_arr[i] += count_arr[i-1]
    size = len(arr)
    output = list(0 for i in range(size))
    for i in reversed(arr):
        output[count_arr[i] - 1] = i
        count_arr[i] -= 1
    # arr = copy.deepcopy(output)
    for i in range(size):
        arr[i] = output[i]
