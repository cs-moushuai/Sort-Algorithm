//Worst Case Complexity in time: O(n^2)
//Average Case Complexity in time: O(n*log n)
//Best Case Complexity in time: O(n*log n)
//Space Complexity: O(n*log n)
//Quicksort Applications:
//the programming language is good for recursion
//time complexity matters
//space complexity matters
#include <iostream>
#include <vector>
#include <algorithm>

#include "header.h"

using namespace std;

static Count res;

static void Merge(vector<int> &vec, int left, int middle, int right)
{
    //left~middle, middle+1~right合并
    vector<int> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    vector<int> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);
    int left_len = middle - left + 1;
    int right_len = right - middle;
    res.move += right - left + 1;

    int i = 0, j = 0;
    int k = left;

    //优先把两个数组里小的拷贝进来
    while (i < left_len && j < right_len)
    {
        if (left_vec[i] < right_vec[j])
        {
            vec[k++] = left_vec[i++];
        }
        else
        {
            vec[k++] = right_vec[j++];
        }
        res.compare++;
        res.move++;
    }

    //剩余项拷贝进来
    while (i < left_len)
    {
        vec[k++] = left_vec[i++];
        res.move++;
    }
    while (j < right_len)
    {
        vec[k++] = right_vec[j++];
        res.move++;
    }
}

static void MergeSortImplement(vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;
        //left~middle的分割
        MergeSortImplement(vec, left, middle);
        //middle+1~right的分割
        MergeSortImplement(vec, middle + 1, right);
        //合并left~middle,middle+1~right到left~right
        Merge(vec, left, middle, right);
    }


}

Count MergeSort(vector<int> &vec)
{
    MergeSortImplement(vec, 0, vec.size() - 1);
    return res;
}

