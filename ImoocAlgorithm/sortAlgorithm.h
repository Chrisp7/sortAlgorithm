//
// Created by chrisp on 07/09/2018.
//

#ifndef IMOOCALGORITHM_SORTALGORITM_H
#define IMOOCALGORITHM_SORTALGORITM_H

#include <iostream>

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[minIndex] > arr[j])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

template<typename T>
void insertSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
            else
                break;
        }
    }
}

template<typename T>
void __merge(T arr[], int l, int mid, int r) {
    T aux[r - l + 1];
    for (int i = l; i <= r; ++i)
        aux[i - l] = arr[i];

    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (i > mid) {
            arr[k] = aux[j - l];
            j++;

        } else if (j > r) {
            arr[k] = aux[i - l];
            i++;
        } else if (aux[i - l] < aux[j - l]) {
            arr[k] = aux[i - l];
            i++;
        } else {
            arr[k] = aux[j - l];
            j++;
        }
    }

}

template<typename T>
void __mergeSort(T arr[], int l, int r) {
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n - 1);
}

template<typename T>
void mergeSortBU(T arr[], int n) {
    for (int size = 1; size <= n; size += size) {
        for (int i = 0; i < n - size; i += size + size) {
            __merge(arr, i, i + size - 1, min(i + size + size - 1, n - 1));
        }
    }
}

template<typename T>
int __partition(T arr[], int l, int r) {
    int randIndex = rand() % (r - l + 1) + l;
    swap(arr[l], arr[randIndex]);
    T v = arr[l];
    int j = l;
    for (int i = l + 1; i <= r; ++i) {
        if (arr[i] < v) {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[l]);
    return j;

}

template<typename T>
int __partitionSolveEuqal(T arr[], int l, int r) {
    int randIndex = rand() % (r - l + 1) + l;
    swap(arr[l], arr[randIndex]);
    T v = arr[l];

    int i = l + 1, j = r;
    while (true) {
        while (arr[i] < v && i <= r) i++;
        while (arr[j] > v && j >= l + 1) j--;
        if (i > j)
            break;
        swap(arr[i], arr[j]);
        i++;
        j--;

    }
    //cause the left part store the value smaller than arr[l]
    //if you swap arr[l] with arr[i], the arr[i] may greater than arr[l]
    swap(arr[l], arr[j]);
    return j;

}

template<typename T>
void __quickSort(T arr[], int l, int r) {
    if (l >= r)
        return;
    int q = __partitionSolveEuqal(arr, l, r);
    __quickSort(arr, l, q);
    __quickSort(arr, q + 1, r);
}

template<typename T>
void quickSort(T arr[], int n) {
    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
}

#endif //IMOOCALGORITHM_SORTALGORITM_H
