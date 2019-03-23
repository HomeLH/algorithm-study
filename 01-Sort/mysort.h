#pragma once
#include <iostream>
#include <algorithm>
#include <ctime>

const int Quick_Len = 0;
using namespace std;
template<typename T>
void selectionSort(T arr[], int  n) {
	for (int i = 0; i < n; i++) {
		int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		swap(arr[i], arr[min_idx]);
	}
}

// insertion sort
// note: difference between swap and assignment operation
// stable; only swap adjacent element
// [0,n-1]
template<typename T>
void insertSort(T arr[], int n) {
	for (int i = 1; i < n; i++) {
		T aux = arr[i];
		for (int j = i; j > 0; j--) {
			// version 1 : too much swap
// 			if (arr[j] < arr[j - 1]) {
// 				swap(arr[j], arr[j - 1]);
// 			}
// 			else {
// 				break;
// 			}
			// version 2 : aux variable
			// 
			if (aux < arr[j-1]) {
				arr[j] = arr[j - 1];
			}
			else {
				arr[j] = aux;
				break;
			}
		}

	}
}
template<typename T>
void insertSort(T arr[], int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		T e = arr[i];
		int j;
		for (j = i; j > left && e < arr[j - 1]; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
	return;
}

// bubble sort
// stable sort; swap only adjacent element
template<typename T>
void bubbleSort(T arr[], int n) {
	// optimiztion : Swap flag can teminate sort progress in advance;
	for (int i = 0; i < n; i++) {
		//bool swapped{ false };
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				//swapped = true;
			}
		}
// 		if (!swapped) {
// 			break;
// 		}
	}
}

// merge sort
// definition
// arr[l...mid] arr[mid+1...r]
// left lowwer l; not number 1
template<typename T>
void _merge(T arr[], int left, int r, int mid) {
//	static const int arr_size = r - left + 1;
    // vs compiler has some problem, but it can work well with gcc.
    T aux[r - left + 1];
	for (int i = left; i <= r; i++) {
		aux[i - left] = arr[i];
	}
	int i = left, j = mid + 1;
	for (int k = left; k <= r; k++) {
		if (i > mid) {
			arr[k] = aux[j - left];
			j++;
		}else if (j > r) {
			arr[k] = aux[i - left];
			i++;
		}else if (aux[i - left] < aux[j - left]) {
			arr[k] = aux[i - left];
			i++;
		}
		else {
			arr[k] = aux[j - left];
			j++;
		}
	}
}
//arr[l...r]
template<typename T>
void _mergeSort(T arr[], int l, int r) {
	// only one element
	// 递归到底的情况下，可以利用插入排序进行优化
// 	if (l >= r)
// 	{
// 		return;
// 	}
	if (r - l <= 15) {
		insertSort(arr, l, r);
		return;
	}
	int mid = l + (r - l) / 2;
	_mergeSort(arr, l, mid);
	_mergeSort(arr, mid + 1, r);
	// 对于近乎有序的数组进行优化
	if(arr[mid] >= arr[mid+1])
		_merge(arr, l, r, mid);
}
template<typename T>
void mergeSort(T arr[], int n) {
	_mergeSort(arr, 0, n - 1);
}

// mergesort bu
// 不使用索引获取元素；
// 可以实现nlogn的复杂度对链表进行排序
// 归并排序不随机选取数据所以是稳定排序
template<typename T>
void mergeSortBU(T arr[], int n) {
	// size
	for (int sz = 1; sz <= n; sz += sz) {
		for (int i = 0; i + sz < n; i += sz +sz)
		{
			// 保证两部分不越界
			// 第二部分可能不足size大小
			_merge(arr, i,  min(i + sz + sz - 1, n-1), i + sz - 1);
		}

	}
}
// quick sort
template<typename T>
int partition(T arr[], int left, int right) {
	// ****************** // 随机pivot

	int pos = rand() % (right - left + 1) + left;
	swap(arr[left], arr[pos]);
// ************************// 
	T e = arr[left];
	// <e :[left+1,j] 
	// >e : [j+1,i)

	int i = left + 1, j = left;
	for (; i <= right; i++) {
		if (arr[i] < e)
		{
			swap(arr[i], arr[j + 1]);
			j++;
		}
	}
	swap(arr[j], arr[left]);
	return j;

}

template<typename T>
void _quickSort(T arr[], int left, int right) {
// 	if (left >= right) {
// 		return;
// 	}
    if (right - left <= Quick_Len) {
		insertSort(arr, left, right);
		return;
	}
	int p = partition(arr, left, right);
	_quickSort(arr, left, p - 1);
	_quickSort(arr, p + 1, right);
}
// 近乎有序的排序时，固定标定元素会是的递归成熟大于logn，最差可以退化为O(n*n)
// 大量重复元素会导致递归划分不平衡
template<typename T>
void quickSort(T arr[], int n) {
	srand(time(nullptr));
	_quickSort(arr, 0, n - 1);
}

// partition 2
template<typename T>
int _partition2(T arr[], int left, int right){
    swap(arr[left], arr[rand()%(right - left + 1) + left]);
    T e = arr[left];
    // <= e : [left+1, i)
    // >= e : (j, r]
    // left <=e[left+1, i) (j, r]>=e
    int i = left + 1, j = right;
    while(true){
        while(arr[i] < e && i <= right) i++;
        while(arr[j] > e && j >= left + 1) j--;
        if( i > j) break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    // j [<=e] last one
    // i [>=e] first one
    // arr[left] [<=e] so => swap(arr[left], j)
    swap(arr[left], arr[j]);
    return j;
}
template<typename T>
void _quickSort2(T arr[], int left, int right){
    if(right - left <= Quick_Len){
        insertSort(arr, left, right);
        return;
    }
    int p = _partition2(arr, left, right);
    _quickSort2(arr, left, p-1);
    _quickSort2(arr, p+1, right);
}
template<typename T>
void quickSort2(T arr[], int n){
    srand(time(nullptr));
    _quickSort2(arr, 0, n-1);
}

// quick sort3
template<typename T>
void _quickSort3(T arr[], int left, int right){
    if(right - left <= Quick_Len){
        insertSort(arr, left, right);
        return;
    }
    swap(arr[left], arr[rand()%(right - left + 1) + left]);
    T v = arr[left];
    // left [left+1, lt]<e [lt+1, i) =e [gt,r]>e
    int lt = left, gt = right+1, i = left + 1;
//    while(true){
//        while(arr[i] > v && i <= right) {
//            i++;
//            gt--;
//        }
//        while(arr[i] == v && i <= right){
//            i++;
//        }
//        while(arr[i] < v && i <= right){
//            swap(arr[i], arr[lt+1]);
//            lt++;
//        }
//        if (lt > gt) break;
//    }
    while(i < gt){
        if(arr[i] < v){
            swap(arr[i], arr[lt+1]);
            lt++;
            i++;
        } else if(arr[i] > v){
            swap(arr[i], arr[gt-1]);
            gt--;
        } else { // v == arr[i]
            i++;
        }
    }
    swap(arr[left], arr[lt]);
    _quickSort3(arr, left, lt-1);
    _quickSort3(arr, gt, right);
}
template<typename T>
void quickSort3(T arr[], int n){
    srand(time(nullptr));
    _quickSort3(arr, 0, n-1);
}

