/*
Question 2: Merge Sort

Description:
Implement merge sort to sort an integer array in ascending order.

Merge sort is a divide-and-conquer algorithm:
1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the two sorted halves into one sorted array.

You should implement:

    void mergeSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void mergeSortHelper(int arr[], int left, int right);
    void merge(int arr[], int left, int mid, int right);

Example:
Input:  [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]

Notes:
- If the array is empty or has only one element, do nothing.
- You may use temporary arrays inside your merge function.
*/

#include <stdlib.h>

static void merge(int arr[], int left, int mid, int right) {
    int ln = mid - left + 1, rn = right - mid;
    int* L = malloc(ln * sizeof(int));
    int* R = malloc(rn * sizeof(int));
    for (int i = 0; i < ln; i++) L[i] = arr[left + i];
    for (int i = 0; i < rn; i++) R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < ln && j < rn)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < ln) arr[k++] = L[i++];
    while (j < rn) arr[k++] = R[j++];
    free(L); free(R);
}

static void mergeSortHelper(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(int arr[], int size) {
    if (size <= 1) return;
    mergeSortHelper(arr, 0, size - 1);
}

