//Worst Case Complexity in time: O(n^2)
//Average Case Complexity in time: O(n*log n)
//Best Case Complexity in time: O(n*log n)
//Space Complexity: O(1)
//Shell sort is used when:

//calling a stack is overhead. uClibc library uses this sort.
//recursion exceeds a limit. bzip2 compressor uses it.
//Insertion sort does not perform well when the close elements are far apart. Shell sort helps in reducing the distance between the close elements. Thus, there will be less number of swappings to be performed.
#include <iostream>
#include <vector>
#include <algorithm>

#include "struct_my.h"

using namespace std;


static Count res;

static void InsertionSort(vector<int> &vec, int increment)
{
    int len = vec.size();
    for (int i = increment; i < len; i++)
    {
        int gap = i;
        int temp = vec[i];
        while (gap >= increment && vec[gap - increment] > temp)
        {
            res.compare++;
            vec[gap] = vec[gap - increment];
            gap -= increment;
            res.move++;
        }
        vec[gap] = temp;
        res.move++;
    }
}

Count ShellSort(vector<int> &vec)
{
    //用增量控制
    for (int increment = vec.size() >> 1; increment > 0; increment >>= 1)
    {
        InsertionSort(vec, increment);
    }
    return res;
}
