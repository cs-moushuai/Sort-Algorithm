//Worst Case Complexity in time: O(n^2)
//Average Case Complexity in time: O(n^2)
//Best Case Complexity in time: O(n^2)
//Space Complexity: O(1)
#include <iostream>
#include <vector>
#include <algorithm>

#include "header.h"

using namespace std;

static Count res;

Count SelectionSort(vector<int> &vec)
{
    int len = vec.size();
    for (int i = 0; i < len - 1; i++)
    {
        //设最小值为i,将index(i+1~len-1)的数和它对比找出最小值的下标
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (vec[min] > vec[j])
            {
                min = j;
            }
            res.compare++;
        }
        //交换最小元素到数组头
        if (min != i)
        {
            res.move += 3;
            swap(vec[min], vec[i]);
        }
    }
    return res;
}
