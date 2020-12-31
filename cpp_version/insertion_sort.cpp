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

using namespace std;

void print(vector<int> &vec)
{
    for_each(vec.begin(), vec.end(), [](int i)
    {
        cout << i << " ";
    });
    cout << endl;
}

void InsertionSort(vector<int> &vec)
{
    int len = vec.size();
    for (int i = 1; i < len; i++)
    {
        //空位下标为i, 空位值为temp
        int gap = i;
        int temp = vec[i];
        while (gap >= 1 && vec[gap - 1] > temp)
        {
            //赋值给右边
            vec[gap] = vec[gap - 1];
            --gap;
        }
        vec[gap] = temp;
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

    InsertionSort(vec);

    cout << "Use hand-by function: ";
    print(vec);

    return 0;
}
