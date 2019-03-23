
#include <iostream>
#include "mysort.h"
#include "SortTestHelper.h"
#include "Student.h"
int main()
{
    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, 100);
//    int *arr = SortTestHelper::generateNearlyOrderedArrary(n, 100);
    //SortTestHelper::testSort("Selection sort", selectionSort, arr, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    int *arr3 = SortTestHelper::copyIntArray(arr, n);
//    SortTestHelper::testSort("InsertSort", insertSort, arr, n);
//    SortTestHelper::testSort("Selection sort", selectionSort, cpy_arr, n);
    //SortTestHelper::testSort("Bubble sort", bubbleSort, cpy_arr, n);
//    SortTestHelper::testSort("Merge Sort", mergeSort, cpy_arr, n);
//    SortTestHelper::testSort("MergeSortBU", mergeSortBU, arr, n);
    // 快排时间长于优化过归并排序，随机化的快排优于非随机化的快排  2019年3月22日16:49:57有点不理解
    // debug 版本与 release版本存在差异
    SortTestHelper::testSort("Quick Sort", quickSort, arr, n);
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n);
    SortTestHelper::testSort("Quick Sort3", quickSort3, arr3, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    cout << "Hello";
}
