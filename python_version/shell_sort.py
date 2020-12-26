#!/usr/bin/env python3

def InsertionSort(arr, increment):
    size = len(arr)
    for i in range(1, size):
        gap = i
        temp = arr[i]
        while gap >= increment and arr[gap-increment] > temp:
            arr[gap] = arr[gap-increment]
            gap -= increment
        arr[gap] = temp


def ShellSort(arr):
    size = len(arr)
    i = size//2
    while i > 0:
        InsertionSort(arr, i)
        i //= 2
