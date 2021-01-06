
#include "struct_my.h"
//Worst Case Complexity in time: O(n*log n)
//Average Case Complexity in time: O(n*log n)
//Best Case Complexity in time: O(n*log n)
//Space Complexity: O(1)
//Heap Sort Applications
//Systems concerned with security and embedded systems such as Linux Kernel use Heap Sort because of the O(n log n) upper bound on Heapsort's running time and constant O(1) upper bound on its auxiliary storage.
//Although Heap Sort has O(n log n) time complexity even for the worst case, it doesn't have more applications ( compared to other sorting algorithms like Quick Sort, Merge Sort ). However, its underlying data structure, heap, can be efficiently used if we want to extract the smallest (or largest) from the list of items without the overhead of keeping the remaining items in the sorted order. For e.g Priority Queues.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static Count res;

static void Heapif(vector<int> &vec, int len, int root)
{
    int largest = root;
    //左节点
    int left = 2 * root + 1;
    //右节点
    int right = 2 * root + 2;

    if (left < len && vec[left] > vec[largest])
    {
        largest = left;
    }
    if (right < len && vec[right] > vec[largest])
    {
        largest = right;
    }
    res.compare += 2;

    //使最大值在跟上
    if (largest != root)
    {
        swap(vec[largest], vec[root]);
        res.move += 3;
        //使叶子节点也满足大顶堆
        Heapif(vec, len, largest);
    }
}

Count HeapSort(vector<int> &vec)
{
    int len = vec.size();
    //最后一个有分支节点(非叶子)
    //构造大顶堆
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        Heapif(vec, len, i);
    }

    //交换大顶堆和最后一个元素,使最后一个元素最大,重新heapify(但大小要减少)
    for (int i = len - 1; i > 0; i--)
    {
        res.move += 3;
        swap(vec[0], vec[i]);
        Heapif(vec, i, 0);
    }

    return res;
}
