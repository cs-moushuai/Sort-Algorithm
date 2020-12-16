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
    for (int i = 0; i < vec.size() - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[min] > vec[j])
            {
                min = j;
            }
        }
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
