#include <iostream>
#include <cassert>
#include "SortTestHelper.h"
#include "heap.h"
using namespace std;

template<typename T>
void heapSort1(T arr[], int n){
    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for(int i = 0; i < n; i++){
        maxheap.insert(arr[i]);
    }
    for(int i = n-1; i >=0; i--){
        arr[i] = maxheap.pop();
    }
}
template<typename T>
void heapsort2(T arr[], int n){
    MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
    for(int i = n-1; i >= 0; i--){
        arr[i] = maxheap.pop();
    }
}
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
    int n = 1000000;
    int * arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("heapsort1", heapSort1, arr, n);
    int * arr2 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("heapsort2", heapsort2, arr, n);
    delete[] arr;
    delete[] arr2;
    return 0;
}
