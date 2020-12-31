#!/usr/bin/env python3

from selection_sort import *
from count_sort import *
from bubble_sort import *
# from radix_sort import *
from shell_sort import *
from quick_sort import *

from random import randint

arr = [randint(2, 40) for i in range(20)]
# for i in range(20):
    # arr.append(randint(2, 40))

print(arr)
print(sorted(arr))
# SelectionSort(arr)
# BubbleSort(arr)
# ShellSort(arr)
# CountSort(arr)
quicksort(arr)
print(arr)
