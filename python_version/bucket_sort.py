#!/usr/bin/env python3



def bucket_sort(arr):
    """sort a array"""
    buckets = []
    for i in range(len(arr)):
        buckets.append([])
    for i in arr:
        index = int(i * 10)
        arr[index].append(i)

    for i in buckets:
        i.sort()

    k = 0
    for i in buckets:
        for j in i:
            arr[k] = j
            k += 1

arr = [0.2, 0.12, 0.7, 0.5, 0.4]
bucket_sort(arr)
print(arr)
