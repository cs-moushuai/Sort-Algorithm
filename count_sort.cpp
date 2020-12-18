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

using namespace std;

void print(vector<int> &vec)
{
    for_each(vec.begin(), vec.end(), [](int i)
    {
        cout << i << " ";
    });
    cout << endl;
}

void CountSort(vector<int> &vec)
{
    int len = vec.size();
    int max = vec[0];
    for (int i = 1; i < len; i++)
    {
        if (vec[i] > max)
        {
            max = vec[i];
        }
    }

    //创建一个max+1(包括0下标)的数组存储vec里元素出现的个数
    vector<int> count_arr(max + 1, 0);
    for (int i = 0; i < len; i++)
    {
        count_arr[vec[i]]++;
    }

    //对count数组安排元素结束下标为count[i]-1
    for (int i = 1; i <= max; i++)
    {
        count_arr[i] += count_arr[i - 1];
    }

    //根据原数组找到count里对应的数并-1得到结束下标,并将里面的数减一
    vector<int> output(len);
    for (int i = len - 1; i >= 0; i--)
    {
        output[count_arr[vec[i]] - 1] = vec[i];
        count_arr[vec[i]]--;
    }
    //重赋值
    vec = output;

}

int main(void)
{
    srand((unsigned)time(NULL));
    vector<int> vec;
    for (int i = 0; i < 15; ++i)
    {
        vec.push_back(static_cast<int>(rand() % (34 - 2 + 1) + 2));

    }

    cout << "Before sort:          ";
    print(vec);

    vector<int> vec2 = vec;
    sort(vec2.begin(), vec2.end());
    cout << "Use generic function: ";
    print(vec2);

    CountSort(vec);

    cout << "Use hand-by function: ";
    print(vec);

    return 0;
}
