//Worst Case Complexity in time: O(n^2)
//Average Case Complexity in time: O(n)
//Best Case Complexity in time: O(n+k)
//Space Complexity: O(n)
//Bucket Sort Applications
//Bucket sort is used when:
//input is uniformly distributed over a range.
//there are floating point values
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<double> &vec)
{
    for_each(vec.begin(), vec.end(), [](double i)
    {
        cout << i << " ";
    });
    cout << endl;
}

void BucketSort(vector<double> &vec)
{
    int len = vec.size();
    vector<double> buckets[len];

    //分进相应的桶里
    for (int i = 0; i < len; i++)
    {
        int index = 10 * vec[i];
        buckets[index].push_back(vec[i]);
    }

    int k = 0;
    //排序每个桶并把在前面的桶依次放进原来数组里
    for (int i = 0; i < len; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());

        int temp_size = buckets[i].size();
        for (int j = 0; j < temp_size;)
        {
            vec[k++] = buckets[i][j++];
        }
    }

}

int main(void)
{
    srand((unsigned)time(NULL));
    vector<double> vec;
    for (int i = 0; i < 15; ++i)
    {
        vec.push_back(static_cast<double>( 0 + 1.0 * rand() / RAND_MAX * (1 - 0)));

    }

    cout << "Before sort:          ";
    print(vec);

    vector<double> vec2 = vec;
    sort(vec2.begin(), vec2.end());
    cout << "Use generic function: ";
    print(vec2);

    BucketSort(vec);

    cout << "Use hand-by function: ";
    print(vec);

    return 0;
}
