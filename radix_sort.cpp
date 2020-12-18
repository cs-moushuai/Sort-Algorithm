//Worst Case Complexity in time: O(d(n+k))
//Average Case Complexity in time: O((n+k))
//Best Case Complexity in time: O(d(n+k))
//Space Complexity: O(1)
//Radix sort is implemented in
//DC3 algorithm (Kärkkäinen-Sanders-Burkhardt) while making a suffix array.
//places where there are numbers in large ranges.
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

void CountSort(vector<int> &vec, int place)
{
    int len = vec.size();
    //和计数排序区别在于一个大小是max+1,一个是10
    vector<int> count_arr(10, 0);
    for (int i = 0; i < len; i++)
    {
        count_arr[(vec[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count_arr[i] += count_arr[i - 1];
    }

    vector<int> output(len);
    for (int i = len - 1; i >= 0; i--)
    {
        output[count_arr[(vec[i] / place) % 10] - 1] = vec[i];
        count_arr[(vec[i] / place) % 10]--;
    }

    vec = output;
}

void RadixSort(vector<int> &vec)
{
    auto max = max_element(vec.begin(), vec.end());
    int max_val = *max;

    //根据基数来排序
    for (int place = 1; max_val / place > 0; place *= 10)
    {
        CountSort(vec, place);
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

    RadixSort(vec);

    cout << "Use hand-by function: ";
    print(vec);

    return 0;
}
