#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int kCutOff = 4;

void print(vector<int> &vec)
{
    for_each(vec.begin(), vec.end(), [](int i)
    {
        cout << i << " ";
    });
    cout << endl;
}

int Medium(vector<int> &vec, int left, int right)
{
    int center = (left + right) / 2;
    // care for the sequence of comparision
    if(vec[left] > vec[center])
    {
        swap(vec[left], vec[center]);
    }
    if(vec[left] > vec[right])
    {
        swap(vec[left], vec[right]);
    }
    if(vec[center] > vec[right])
    {
        swap(vec[center], vec[right]);
    }
    swap(vec[center], vec[right - 1]);
    return right - 1;
}

int Partition(vector<int> &vec, int left, int right)
{
    int pivot = Medium(vec, left, right);
    right = pivot;

    while(1)
    {
        while(left < right && vec[++left] < vec[pivot])
        {
            ;
        }
        while(left < right && vec[--right] > vec[pivot])
        {
            ;
        }
        if (left < right)
        {
            swap(vec[left], vec[right]);
        }
        else
        {
            swap(vec[left], vec[pivot]);
            return left;
        }
    }
}

void InsertionSort(vector<int> &vec, int left, int right)
{
    for (int i = left + 1; i < right + 1; i++)
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

void QuickSortImplement(vector<int> &vec, int left, int right)
{
    if(left < right)
    {
        if ( left + kCutOff < right )
        {
            int pivot = Partition(vec, left, right);

            QuickSortImplement(vec, left, pivot - 1);
            QuickSortImplement(vec, pivot + 1, right);
        }
        else
        {
            InsertionSort(vec, left, right);
        }
    }

}

void QuickSort(vector<int> &vec)
{
    QuickSortImplement(vec, 0, vec.size() - 1);
}

int QuickSelectImplement(vector<int> &vec, int kth_lowest_value, int left, int right)
{
    int pivot = Partition(vec, left, right);

    if(kth_lowest_value < pivot)
        return QuickSelectImplement(vec, kth_lowest_value, left, pivot - 1);
    else if (kth_lowest_value > pivot)
        return QuickSelectImplement(vec, kth_lowest_value, pivot + 1, right);
    else
        return vec[kth_lowest_value];
}

int QuickSelect(vector<int> &vec, int kth_lowest_value)
{
    int len = vec.size();
    if (kth_lowest_value < 1 || kth_lowest_value > len)
    {
        throw std::out_of_range(string("The kth_lowest_value is invalid!   (1~") + to_string(vec.size()) + string(") \nyour input is ") + to_string(kth_lowest_value));
    }
    if (len == 1)
    {
        return vec[0];
    }

    vector<int> temp = vec;
    return QuickSelectImplement(temp, kth_lowest_value - 1, 0, len - 1);
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

    QuickSort(vec);

    cout << "Use hand-by function: ";
    print(vec);
    int i = 4;
    try
    {
        int val = QuickSelect(vec, i);
        cout << "the " << i << "th lowest value: " << val << endl;
    }
    catch(exception &ex)
    {
        cerr << ex.what() << endl;
    }

    return 0;
}
