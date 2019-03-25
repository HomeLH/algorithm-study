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
// no more space
template<typename T>
void _shiftDown(T arr[], int n, int k){
    // left child is valid
    // arr[0,n)
    while(2*k + 1 < n){
        // left child max
        int  j = 2*k + 1;
        // right child is valid && max
        if (2*k + 2 < n && arr[j] < arr[j+1]){
            j = 2*k + 2;
        }
        // child is more less than parent
        if(arr[j] < arr[k]){
            break;
            // do nothing, it is actually heap
        }
        swap(arr[j], arr[k]);
        // update k
        k = j;
    }
}
template<typename T>
void _heapify(T arr[], int n){
    // i==0 root
    for(int i = (n-1)/2; i >= 0; i--){
        //[0,n)
        _shiftDown(arr, n, i);
    }
}
template<typename T>
void heapsort(T arr[], int n){
    // left 2i -> 2i + 1
    // right 2i+1 -> 2i+2
    // parent i/2 ->(i-1)/2
    // non-leaf
    // (count-1)/2
    _heapify(arr, n);
    // last one element in array; no operator
    for(int i = n-1; i > 0; i--){
        swap(arr[i], arr[0]);
        _shiftDown(arr, i, 0);
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
