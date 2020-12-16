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

    for (int i = 0; i < vec.size(); i++)
    {
        int index = len * vec[i];
        buckets[index].push_back(vec[i]);
    }

    int k = 0;
    for (int i = 0; i < len; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());

        for (int j = 0; j < buckets[i].size();)
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
