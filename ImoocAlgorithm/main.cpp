#include <iostream>
#include "sortAlgorithm.h"
#include <string>
#include "SortTestHelper.h"

using namespace std;

int main() {

    int n = 10000;
    int swapNum = 10;
    int *arr_template = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr_near_orderd = SortTestHelper::generateNearlyOrderedArray(n, swapNum);
    int *arr_selection = SortTestHelper::copyArr(arr_near_orderd, n);
    int *arr_insert = SortTestHelper::copyArr(arr_near_orderd, n);
    int *arr_merge = SortTestHelper::copyArr(arr_near_orderd, n);
    int *arr_quick = SortTestHelper::copyArr(arr_near_orderd, n);

//    selection_sort(arr, n);
//    SortTestHelper::printArray(arr, n);
//    SortTestHelper::testSort("Selection sort", selectionSort, arr_selection, n);
    SortTestHelper::testSort("Insert sort", insertSort, arr_insert, n);
    SortTestHelper::testSort("Merge sort", mergeSort, arr_merge, n);
    SortTestHelper::testSort("Quick sort", quickSort, arr_quick, n);

    delete[] arr_template;
    delete[] arr_near_orderd;
    delete[] arr_selection;
    delete[] arr_insert;
    delete[] arr_merge;
    delete[] arr_quick;

    return 0;

}