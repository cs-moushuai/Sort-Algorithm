#!/usr/bin/env python3

def medium(arr, left, right):
    middle = (left + right) // 2
    if arr[left] > arr[middle]:
        arr[left], arr[middle] = arr[middle], arr[left]
    if arr[left] > arr[right]:
        arr[left], arr[right] = arr[right], arr[left]
    if arr[left] > arr[right]:
        arr[left], arr[right] = arr[right], arr[left]
    arr[right-1], arr[middle] = arr[middle], arr[right-1]
    return right-1


def partition(arr, left, right):
    pivot = right
    right -= 1

    for left in range(left, right):
        if arr[left] <= arr[pivot]:
            left += 1
            (arr[left], arr[right]) = (arr[right], arr[left])
    (arr[pivot], arr[right]) = (arr[right], arr[pivot])
    return left + 1



def quicksortimplement(arr, left, right):
    if left < right:
        pivot = partition(arr, left, right)

        quicksortimplement(arr, left, pivot - 1)
        quicksortimplement(arr, pivot + 1, right)

def quicksort(arr):
    quicksortimplement(arr, 0, len(arr) - 1)
