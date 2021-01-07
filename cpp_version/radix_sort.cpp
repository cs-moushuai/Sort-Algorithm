//Worst Case Complexity in time: O(d(n+k))
//Average Case Complexity in time: O((n+k))
//Best Case Complexity in time: O(d(n+k))
//Space Complexity: O(10*d)
//Radix sort is implemented in
//DC3 algorithm (Kärkkäinen-Sanders-Burkhardt) while making a suffix array.
//places where there are numbers in large ranges.
#include <iostream>
#include <vector>
#include <algorithm>

#include "header.h"

using namespace std;

static Count res;

static void CountSort(vector<int> &vec, int place)
{
    int len = vec.size();
    //和计数排序区别在于一个大小是max+1,一个是10
    vector<int> count_arr(10, 0);
    for (int i = 0; i < len; i++)
    {
        count_arr[(vec[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count_arr[i] += count_arr[i - 1];
    }

    vector<int> output(len);
    //注意这边必须要是从后向前,才能保证顺序
//|| Before sort:          33 12 12 3 6 25 8 11 9 19 7 32 15 25 20
//|| Use generic function: 3 6 7 8 9 11 12 12 15 19 20 25 25 32 33
//---------->>>>>>>>>>>>>>>从左开始
//|| 20 11 32 12 12 3 33 25 15 25 6 7 8 19 9
//|| 9 8 7 6 3 19 15 12 12 11 25 25 20 33 32
//---------->>>>>>>>>>>>>>>从右开始
//|| 20 11 32 12 12 3 33 25 15 25 6 7 8 19 9
//|| 3 6 7 8 9 11 12 12 15 19 20 25 25 32 33
    for (int i = len - 1; i >= 0; i--)
    {
        output[count_arr[(vec[i] / place) % 10] - 1] = vec[i];
        res.move++;
        count_arr[(vec[i] / place) % 10]--;
    }

    vec = output;
    res.move += len;
}

Count RadixSort(vector<int> &vec)
{
    auto max_iter = max_element(vec.begin(), vec.end());
    res.compare += vec.size() - 1;
    int max_val = *max_iter;

    //根据基数来排序
    for (int place = 1; max_val / place > 0; place *= 10)
    {
        CountSort(vec, place);
    }
    return res;
}

