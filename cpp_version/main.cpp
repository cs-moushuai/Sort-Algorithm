#include <iostream>
#include <vector>
#include <algorithm>

#include "header.h"

using namespace std;


void print(vector<int> &vec)
{
    for_each(vec.begin(), vec.end(), [](int i)
    {
        cout << i << " ";
    });
    cout << endl;
}

void Init()
{
    srand((unsigned)time(NULL));
    for (int count = 0; count < 5; ++count)
    {
        vector<int> vec;
        for (int i = 0; i < 120; ++i)
        {
            vec.push_back(static_cast<int>(rand() % (34 - 2 + 1) + 2));

        }

        //1).quick sort
        cout << "Before sort:              ";
        print(vec);

        Count record;
        vector<int> vec1(vec);
        cout << "1).After QuickSort:       ";
        record = QuickSort(vec1);
        print(vec1);
        cout << "the counts of comparison and movtion are " << record.compare << ", " << record.move << endl;



        vector<int> vec2(vec);
        cout << "2).After MergeSort:       ";
        record = MergeSort(vec2);
        print(vec2);
        cout << "the counts of comparison and movtion are " << record.compare << ", " << record.move << endl;

        vector<int> vec3(vec);
        cout << "3).After BubbleSort:      ";
        record = BubbleSort(vec3);
        print(vec3);
        cout << "the counts of comparison and movtion are " << record.compare << ", " << record.move << endl;


        vector<int> vec4(vec);
        cout << "4).After CountSort:       ";
        record = CountSort(vec4);
        print(vec4);
        cout << "the counts of comparison and movtion are " << record.compare << ", " << record.move << endl;


        vector<int> vec5(vec);
        cout << "5).After HeapSort:        ";
        record = HeapSort(vec5);
        print(vec5);
        cout << "the counts of comparison and movtion are " << record.compare << ", " << record.move << endl;


        vector<int> vec6(vec);
        cout << "6).After InsertionSort:   ";
        record = InsertionSort(vec6);
        print(vec6);
        cout << "the counts of comparison and movtion are " << record.compare << ", " << record.move << endl;


        vector<int> vec7(vec);
        cout << "7).After RadixSort:       ";
        record = RadixSort(vec7);
        print(vec7);
        cout << "the counts of comparison and movtion are " << record.compare << ", " << record.move << endl;


        vector<int> vec8(vec);
        cout << "8).After SelectionSort:   ";
        record = SelectionSort(vec8);
        print(vec8);
        cout << "the counts of comparison and movtion are " << record.compare << ", " << record.move << endl;


        vector<int> vec9(vec);
        cout << "9).After ShellSort:       ";
        record = ShellSort(vec9);
        print(vec9);
        cout << "the counts of comparison and movtion are " << record.compare << ", " << record.move << endl;


        cout << endl;
        cout << endl;


    }

}


int main(void)
{
    Init();

    return 0;
}
