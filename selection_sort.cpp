//Worst Case Complexity in time: O(n^2)
//Average Case Complexity in time: O(n^2)
//Best Case Complexity in time: O(n^2)
//Space Complexity: O(1)
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

void SelectionSort(vector<int> &vec)
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
        }
        //交换最小元素到数组头
        if (min != i)
        {
            swap(vec[min], vec[i]);
        }
    }
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

    SelectionSort(vec);

    cout << "Use hand-by function: ";
    print(vec);

    return 0;
}
