//Worst Case Complexity in time: O(n^2)
//Average Case Complexity in time: O(n^2)
//Best Case Complexity in time: O(n) 因为这是优化后的bubble sort
//Space Complexity: O(1)
#include <iostream>
#include <vector>
#include <algorithm>

#include "header.h"

using namespace std;

static Count res;

Count BubbleSort(vector<int> &vec)
{
    int len = vec.size();
    //控制第二个循环的长度
    for (int i = 0; i < len - 1; i++)
    {
        int flag = false;
        //j=0,j+1=1;j=1,j+1=2;j=len-2,j+1=len-1;
        //j=0,j+1=1;i=len-2
        //一直交换将最大项移动到尾
        for (int j = 0; j < len - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
                flag = true;
                res.compare++;
                res.move += 3;
            }
        }
        //如果是没有交换过一次的,就是已排序的就直接退出
        if (!flag)
        {
            break;
        }
    }
    return res;
}
