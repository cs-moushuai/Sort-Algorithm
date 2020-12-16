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

void Heapif(vector<int> &vec, int len, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < len && vec[left] > vec[largest])
    {
        largest = left;
    }
    if (right < len && vec[right] > vec[largest])
    {
        largest = right;
    }

    if (largest != root)
    {
        swap(vec[largest], vec[root]);
        Heapif(vec, len, largest);
    }
}

void HeapSort(vector<int> &vec)
{
    int len = vec.size();
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        Heapif(vec, len, i);
    }

    for (int i = len - 1; i > 0; i--)
    {
        swap(vec[0], vec[i]);
        Heapif(vec, i, 0);
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

    HeapSort(vec);

    cout << "Use hand-by function: ";
    print(vec);

    return 0;
}
