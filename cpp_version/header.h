#pragma once

#include <vector>

struct Count
{
    int compare;
    int move;
    Count(int _compare = 0, int _move = 0): compare(_compare), move(_move) {}
};

Count MergeSort(std::vector<int> &);
Count QuickSort(std::vector<int> &);
Count CountSort(std::vector<int> &);
Count HeapSort(std::vector<int> &);
Count RadixSort(std::vector<int> &);
Count SelectionSort(std::vector<int> &);
Count BubbleSort(std::vector<int> &);
Count ShellSort(std::vector<int> &);
Count InsertionSort(std::vector<int> &);
