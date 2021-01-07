//Worst Case Complexity in time: O(n^2)
//Average Case Complexity in time: O(n^2)
//Best Case Complexity in time: O(n)
//Space Complexity: O(1)
//The insertion sort is used when:
//the array is has a small number of elements
//there are only a few elements left to be sorted
#include <iostream>
#include <vector>
#include <algorithm>

#include "header.h"

using namespace std;

static Count res;

Count InsertionSort(vector<int> &vec)
{
    int len = vec.size();
    for (int i = 1; i < len; i++)
    {
        //空位下标为i, 空位值为temp
        int gap = i;
        int temp = vec[i];
        while (gap >= 1 && vec[gap - 1] > temp)
        {
            res.compare++;
            //赋值给右边
            vec[gap] = vec[gap - 1];
            --gap;
            res.move++;
        }
        vec[gap] = temp;
        res.move++;
    }
    return res;
}
