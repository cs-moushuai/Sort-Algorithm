#!/usr/bin/env python3

def BubbleSort(arr):
    size = len(arr)
    for i in range(size - 1):
        flag = False
        for j in range(size - i - 1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                flag = True
        if not flag:
            return
