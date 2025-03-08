/*
    CH-231-A
    hw4
    Redon Jashari
    RJASHARI@constructor.university
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = rightArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void customMergeSort(vector<int> &arr, int left, int right, int k) {
    if (right - left + 1 <= k) {
        insertionSort(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    customMergeSort(arr, left, mid, k);
    customMergeSort(arr, mid + 1, right, k);
    merge(arr, left, mid, right);
}

vector<int> bestCase(int size) {
    vector<int> vec;
    int elem = rand() % 50;
    vec.push_back(elem);

    for (int i = 1; i < size; i++) {
        int inc = 1 + rand() % 10;
        elem += inc;
        vec.push_back(elem);
    }

    return vec;
}

vector<int> worstCase(int size) {
    vector<int> vec = bestCase(size);
    reverse(vec.begin(), vec.end());
    return vec;
}

vector<int> averageCase(int size) {
    vector<int> vec(size);
    for (int i = 0; i < size; i++) vec[i] = rand() % 1000;
    return vec;
}

int main() {
    vector<int> bestCaseTimes;
    vector<int> worstCaseTimes;
    vector<int> averageCaseTimes;

    int kValue = 50;
    int n = 1000;

    for (int i = 2; i < kValue; i++) {
        vector<int> vec = bestCase(n);
        auto start = high_resolution_clock::now();
        customMergeSort(vec, 0, vec.size() - 1, i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        bestCaseTimes.push_back(duration.count());
    }

    for (int i = 2; i < kValue; i++) {
        vector<int> vec = worstCase(n);
        auto start = high_resolution_clock::now();
        customMergeSort(vec, 0, vec.size() - 1, i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        worstCaseTimes.push_back(duration.count());
    }

    for (int i = 2; i < kValue; i++) {
        vector<int> vec = averageCase(n);
        auto start = high_resolution_clock::now();
        customMergeSort(vec, 0, vec.size() - 1, i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        averageCaseTimes.push_back(duration.count());
    }

    cout << "Times for Best Case: ";
    for (auto elem : bestCaseTimes) cout << elem << ", ";
    cout << endl << endl;

    cout << "Times for Worst Case: ";
    for (auto elem : worstCaseTimes) cout << elem << ", ";
    cout << endl << endl;

    cout << "Times for Average Case: ";
    for (auto elem : averageCaseTimes) cout << elem << ", ";
    cout << endl << endl;

    return 0;
}
