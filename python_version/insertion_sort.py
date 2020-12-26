#!/usr/bin/env python3


def insertion_sort(arr):
    '''sort the arr by insertion sort'''
    for i in range(1, len(arr)):
        gap = i
        temp = arr[i]
        while gap >= 1 and arr[gap - 1] > temp:
            arr[gap] = arr[gap - 1]
            gap -= 1
        arr[gap] = temp


arr = [2, 4, 1, 5, 12, 0, 23]
print(arr)
insertion_sort(arr)
print(arr)
