//
// Created by chrisp on 07/09/2018.
//

#ifndef IMOOCALGORITHM_SORTTESTHELPER_H
#define IMOOCALGORITHM_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {
    // genereate a random array, in which the elements have the range from [rangeL,rangeR]
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            // rand() % (rangeR - rangeL + 1) will give us an array that range from 0 to rangeR-rangeL+1
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        double consumingTime = double(endTime - startTime) / CLOCKS_PER_SEC;
        cout << sortName << " consumes " << consumingTime << " s" << endl;
    }


    int *copyArr(int arr[], int n) {
        int *arr2 = new int[n];
        for (int i = 0; i < n; ++i) {
            arr2[i] = arr[i];
        }
        return arr2;
    }

    int *generateNearlyOrderedArray(int n, int swapNum) {
        int *arr = new int[n];;
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
        int randomSwap[swapNum];
        srand(time(NULL));
        for (int j = 0; j < swapNum; ++j) {
            randomSwap[j] = rand() % n;
        }
        for (int k = 0; k < swapNum; ++k) {
            swap(arr[randomSwap[k]], arr[randomSwap[k] + 1]);
        }
        return arr;
    }

}
#endif //IMOOCALGORITHM_SORTTESTHELPER_H
