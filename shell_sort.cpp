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

using namespace std;

void InsertionSort(vector<int> &vec, int increment)
{
    for (int i = increment; i < vec.size(); i++)
    {
        int gap = i;
        int temp = vec[i];
        while (gap >= increment && vec[gap - increment] > temp)
        {
            vec[gap] = vec[gap - increment];
            gap -= increment;
        }
        vec[gap] = temp;
    }
}

void ShellSort(vector<int> &vec)
{
    //用增量控制
    for (int increment = vec.size() >> 1; increment > 0; increment >>= 1)
    {
        InsertionSort(vec, increment);
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
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> vec2 = vec;
    sort(vec2.begin(), vec2.end());
    cout << "Use generic function: ";
    for_each(vec2.begin(), vec2.end(), [](int i)
    {
        cout << i << " ";
    });
    cout << endl;

    ShellSort(vec);

    cout << "Use hand-by function: ";
    for_each(vec.begin(), vec.end(), [](int i)
    {
        cout << i << " ";
    });

    cout << endl;

    return 0;
}
