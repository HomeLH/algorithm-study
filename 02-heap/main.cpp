#include <iostream>
#include <cassert>
#include "SortTestHelper.h"
#include "heap.h"
using namespace std;


   
int main()
{
    MaxHeap<int> maxheap = MaxHeap<int>(100);
    srand(time(nullptr));
    for(int i = 0; i < 10; i++){
        maxheap.insert(rand()%100);
    }
    for(int i = 0; i < 10; i++){
        cout << maxheap.pop() << " ";
    }
    cout << endl;
    int n = 10000000;
    int * arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("heapsort1", heapSort1, arr, n);
    int * arr2 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("heapsort2", heapsort2, arr, n);
    int * arr3 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("heapsort", heapsort, arr, n);
    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    return 0;
}
