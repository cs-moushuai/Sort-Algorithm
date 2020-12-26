#!/usr/bin/env python3


def partition(arr, left, right):
    pivot = right
    right -= 1

    while True:
        while left < right and arr[left] < arr[pivot]:
            left += 1
        while left < right and arr[right] > arr[pivot]:
            right -= 1

        if left >= right:
            arr[left], arr[pivot] = arr[pivot], arr[left]
            return left
        else:
            arr[left], arr[right] = arr[right], arr[left]



def quicksortimplement(arr, left, right):
    if left < right:
        pivot = partition(arr, left, right)

        quicksortimplement(arr, left, pivot - 1)
        quicksortimplement(arr, pivot + 1, right)

def quicksort(arr):
    quicksortimplement(arr, 0, len(arr) - 1)
