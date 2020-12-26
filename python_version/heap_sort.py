#!/usr/bin/env python3

def Heapify(arr, size, root):
    largest = root
    left = root * 2 + 1
    right = root * 2 + 2

    if left < size and arr[left] > arr[largest]:
        largest = left
    if right < size and arr[right] > arr[largest]:
        largest = right
    if largest != root:
        arr[root], arr[largest] = arr[largest], arr[root]
        Heapify(arr, size, largest)


def heap_sort(arr):
    '''sort a array'''
    size = len(arr)
    for i in range(size//2 - 1, -1, -1):
        Heapify(arr, size, i)

    for i in range(size - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        Heapify(arr, i, 0)


arr = [2, 4, 1, 5, 12, 0, 23]
print(arr)
heap_sort(arr)
print(arr)
