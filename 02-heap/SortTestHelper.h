#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
using namespace std;

namespace SortTestHelper {
	//[rangeL, rangeR]
	int * generateRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeL < rangeR);
		int *arr = new int[n];
		// 设置随机种子为当前时间
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}
	template<typename T>
	void  printArray(T arr[], int n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	template<typename T>
	bool isSorted(T arr[], int n) {
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				return false;
			}
		}
		return true;
	}
	template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
//        printArray(arr, n);
		assert(isSorted(arr, n));
		cout << sortName << ":"<< double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

	}
    // 深拷贝， 浅拷贝
	int * copyIntArray(int a[], int n) {
		int *arr = new int[n];
//		copy(a, a + n, arr);
        for(int i = 0; i < n; i++){
            arr[i] = a[i];
        }
		return arr;
	}
	int *generateNearlyOrderedArrary(int n, int swapTimes) {
		int *arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = i;
		}
		srand(time(NULL));
		for (int i = 0; i < swapTimes; i++) {
			// posx, posy in [0,n)
			int posx = rand() % n;
			int posy = rand() % n;
			swap(arr[posx], arr[posy]);
		}
		return arr;
	}

}
