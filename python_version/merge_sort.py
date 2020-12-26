#!/usr/bin/env python3

def Merge(arr, left, middle, right):
    left_arr = arr[left: middle + 1] 
    right_arr = arr[middle + 1: right + 1]
    # print("left_arr: ", left_arr)
    # print("right_arr: ", right_arr)
    # print("arr: ", arr[left:right+1])
    left_size = middle - left + 1
    right_size = right - middle
    i, j = 0, 0
    k = left
    while i < left_size and j < right_size:
        if left_arr[i] < right_arr[j]:
            arr[k] = left_arr[i]
            i += 1
            k += 1
        else:
            arr[k] = right_arr[j]
            j += 1
            k += 1

    while i < left_size:
        arr[k] = left_arr[i]
        i += 1
        k += 1
    while j < right_size:
        arr[k] = right_arr[j]
        j += 1
        k += 1
    # print("after sort arr: ", arr[left:right+1])


def MergeSortImplement(arr, left, right):
    if left < right:
        middle = (left + right) // 2
        MergeSortImplement(arr, left, middle)
        MergeSortImplement(arr, middle + 1, right)
        Merge(arr, left, middle, right)


def MergeSort(arr):
    MergeSortImplement(arr, 0, len(arr) - 1)


arr = [2, 4, 1, 5, 12, 0, 23]
print(arr)
MergeSort(arr)
print(arr)
