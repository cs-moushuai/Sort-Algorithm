#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void InsertionSort(vector<int> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        int gap = i;
        int temp = vec[i];
        while (gap >= 1 && vec[gap - 1] > temp)
        {
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

    InsertionSort(vec);

    cout << "Use hand-by function: ";
    for_each(vec.begin(), vec.end(), [](int i)
    {
        cout << i << " ";
    });

    cout << endl;

    return 0;
}
