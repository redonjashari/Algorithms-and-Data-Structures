/*
    CH-231-A
    hw6
    Redon Jashari
    RJASHARI@constructor.university
*/

#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

void heapify(vector<int>& arr, int n, int i){
    int largest = i;

    int l = 2 * i + 1;

    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr){
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void bottomDown(vector<int>& arr, int n, int i) {
    int parent = i;

    while (true) {
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;

        if (left >= n) break;

        int child = left;
        if (right < n && arr[right] > arr[left]) {
            child = right;
        }

        swap(arr[parent], arr[child]);
        parent = child;
    }

    while (parent > 0) {
        int parentIndex = (parent - 1) / 2;
        if (arr[parentIndex] < arr[parent]) {
            swap(arr[parentIndex], arr[parent]);
            parent = parentIndex;
        } else {
            break;
        }
    }
}

void bottomUpHeapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        bottomDown(arr, i, 0);
    }
}

void testSortingAlgorithms() {
    vector<int> sizes = {10, 100, 1000, 5000, 10000};

    for (int n : sizes) {
        vector<int> arr1(n), arr2(n);
        srand(time(0));

        for (int i = 0; i < n; i++) {
            int num = rand() % 10000;
            arr1[i] = arr2[i] = num;
        }

        auto start = chrono::high_resolution_clock::now();
        heapSort(arr1);
        auto end = chrono::high_resolution_clock::now();
        double heapSortTime = chrono::duration<double>(end - start).count();

        start = chrono::high_resolution_clock::now();
        bottomUpHeapSort(arr2);
        end = chrono::high_resolution_clock::now();
        double bottomUpHeapSortTime = chrono::duration<double>(end - start).count();

        cout << "Input size: " << n << endl;
        cout << "  Heap Sort time: " << heapSortTime << " sec" << endl;
        cout << "  Bottom-up Heap Sort time: " << bottomUpHeapSortTime << " sec" << endl;
        cout << "----------------------------------" << endl;
    }
}

int main() {
    testSortingAlgorithms();
    return 0;
}
