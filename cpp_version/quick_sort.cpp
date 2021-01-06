#include "struct_my.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static constexpr int kCutOff = 4;

static Count res;

static int Medium(vector<int> &vec, int left, int right)
{
    int center = (left + right) / 2;
    // care for the sequence of comparision
    if(vec[left] > vec[center])
    {
        swap(vec[left], vec[center]);
    }
    if(vec[left] > vec[right])
    {
        swap(vec[left], vec[right]);
    }
    if(vec[center] > vec[right])
    {
        swap(vec[center], vec[right]);
    }
    swap(vec[center], vec[right - 1]);
    return right - 1;
}

static int Partition(vector<int> &vec, int left, int right)
{
    int pivot = Medium(vec, left, right);
    right = pivot;

    while(1)
    {
        while(left < right && vec[++left] < vec[pivot])
        {
            res.compare++;
            ;
        }
        res.compare++;
        while(left < right && vec[--right] > vec[pivot])
        {
            res.compare++;
            ;
        }
        res.compare++;
        if (left < right)
        {
            res.move += 3;
            swap(vec[left], vec[right]);
        }
        else
        {
            res.move += 3;
            swap(vec[left], vec[pivot]);
            return left;
        }
    }
}

static void InsertionSort(vector<int> &vec, int left, int right)
{
    for (int i = left + 1; i < right + 1; i++)
    {
        int gap = i;
        int temp = vec[i];
        while (gap >= 1 && vec[gap - 1] > temp)
        {
            res.compare++;
            vec[gap] = vec[gap - 1];
            --gap;
            res.move++;
        }
        vec[gap] = temp;
        res.move++;
    }

}

static void QuickSortImplement(vector<int> &vec, int left, int right)
{
    if(left < right)
    {
        if ( left + kCutOff < right )
        {
            int pivot = Partition(vec, left, right);

            QuickSortImplement(vec, left, pivot - 1);
            QuickSortImplement(vec, pivot + 1, right);
        }
        else
        {
            InsertionSort(vec, left, right);
        }
    }

}

Count QuickSort(vector<int> &vec)
{
    QuickSortImplement(vec, 0, vec.size() - 1);
    return res;
}
