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
