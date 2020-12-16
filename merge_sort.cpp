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

void Merge(vector<int> &vec, int left, int middle, int right)
{
    vector<int> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    vector<int> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);
    int left_len = middle - left + 1;
    int right_len = right - middle;

    int i = 0, j = 0;
    int k = left;

    while (i < left_len && j < right_len)
    {
        if (left_vec[i] < right_vec[j])
        {
            vec[k++] = left_vec[i++];
        }
        else
        {
            vec[k++] = right_vec[j++];
        }
    }

    while (i < left_len)
    {
        vec[k++] = left_vec[i++];
    }
    while (j < right_len)
    {
        vec[k++] = right_vec[j++];
    }
}

void MergeSortImplement(vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;
        MergeSortImplement(vec, left, middle);
        MergeSortImplement(vec, middle + 1, right);
        Merge(vec, left, middle, right);
    }


}

void MergeSort(vector<int> &vec)
{
    MergeSortImplement(vec, 0, vec.size() - 1);
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

    MergeSort(vec);

    cout << "Use hand-by function: ";
    print(vec);

    return 0;
}
