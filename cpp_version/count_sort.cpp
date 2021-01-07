//Worst Case Complexity in time: O(n+k) max+size
//Average Case Complexity in time: O(n+k)
//Best Case Complexity in time: O(n+k)
//Space Complexity: O(max)
//Counting sort is used when:
//there are smaller integers with multiple counts.
//linear complexity is the need.
#include <iostream>
#include <vector>
#include <algorithm>

#include "header.h"

using namespace std;

static Count res;

Count CountSort(vector<int> &arr)
{
    auto max_iter = max_element(arr.begin(), arr.end());
    res.compare += arr.size() - 1;
    int len = *max_iter + 1;

    //创建一个max+1(包括0下标)的数组存储vec里元素出现的个数
    vector<int> counts(len, 0);
    for (auto i : arr)
    {
        counts[i]++;
    }

    //对count数组安排元素结束下标为count[i]-1
    for (int i = 1; i < len; i++)
    {
        counts[i] += counts[i - 1];
    }

    //根据原数组找到count里对应的数并-1得到结束下标,并将里面的数减一
    //len-1~0,0~len-1两种遍历都行
    //但由于基于count sort的radix sort需要len-1~0则一般用这种方式
    int len_arr = arr.size();
    vector<int> output(len_arr);
    for (int i = len_arr - 1; i >= 0; i--)
    {
        output[counts[arr[i]] - 1] = arr[i];
        counts[arr[i]]--;
        res.move++;
    }
    //重赋值
    arr = output;
    res.move += len_arr;

    return res;
}
