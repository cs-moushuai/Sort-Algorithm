#include <iostream>
#include <vector>
#include <algorithm>

#include "header.h"

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
        res.move += 3;
    }
    res.compare++;
    if(vec[left] > vec[right])
    {
        swap(vec[left], vec[right]);
        res.move += 3;
    }
    res.compare++;
    if(vec[center] > vec[right])
    {
        swap(vec[center], vec[right]);
        res.move += 3;
    }
    res.compare++;
    //将pivot设置到后面
    swap(vec[center], vec[right - 1]);
    res.move += 3;
    return right - 1;
}

static int Partition(vector<int> &vec, int left, int right)
{
    //取中间点为pivot, 避免最坏情况弱化为冒泡排序
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
    //见插入排序部分解释(在其他文件)
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
            //分区,pivot为得到的枢点
            int pivot = Partition(vec, left, right);

            QuickSortImplement(vec, left, pivot - 1);
            QuickSortImplement(vec, pivot + 1, right);
        }
        else
        {
            //长度较小的可以用insertion sort来优化
            InsertionSort(vec, left, right);
        }
    }

}

Count QuickSort(vector<int> &vec)
{
    QuickSortImplement(vec, 0, vec.size() - 1);
    return res;
}
