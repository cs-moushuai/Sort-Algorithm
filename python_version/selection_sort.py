#!/usr/bin/env python3

def SelectionSort(arr):
    size = len(arr)
    for i in range(size - 1):
        min = i
        for j in range(i+1, size):
            if arr[j] < arr[min]:
                min = j
        if min != i:
            arr[i], arr[min] = arr[min], arr[i]
