/*
    CH-231-A
    hw7
    Redon Jashari
    RJASHARI@constructor.university
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

//Lomuto partition
int lomutoPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksortLomuto(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = lomutoPartition(arr, low, high);
        quicksortLomuto(arr, low, pivotIndex - 1);
        quicksortLomuto(arr, pivotIndex + 1, high);
    }
}

//Hoare partition
int hoarePartition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    while (true) {
        do { j--; } while (arr[j] > pivot);
        do { i++; } while (arr[i] < pivot);
        if (i < j) swap(arr[i], arr[j]);
        else return j;
    }
}

void quicksortHoare(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = hoarePartition(arr, low, high);
        quicksortHoare(arr, low, pivotIndex);
        quicksortHoare(arr, pivotIndex + 1, high);
    }
}

//Median of three partition
int medianOfThreePartition(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low]) swap(arr[mid], arr[low]);
    if (arr[high] < arr[low]) swap(arr[high], arr[low]);
    if (arr[mid] < arr[high]) swap(arr[mid], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksortMedianOfThree(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = medianOfThreePartition(arr, low, high);
        quicksortMedianOfThree(arr, low, pivotIndex - 1);
        quicksortMedianOfThree(arr, pivotIndex + 1, high);
    }
}

void measurePerformance() {
    const int numTests = 100000;
    const int arrSize = 1000;
    vector<int> sample(arrSize);
    vector<int> arr;

    srand(time(0));

    auto measureTime = [&](auto sortFunction) {
        auto start = high_resolution_clock::now();
        for (int i = 0; i < numTests; i++) {
            generate(sample.begin(), sample.end(), rand);
            arr = sample;
            sortFunction(arr, 0, arrSize - 1);
        }
        auto end = high_resolution_clock::now();
        return duration<double>(end - start).count() / numTests;
    };

    double timeLomuto = measureTime(quicksortLomuto);
    double timeHoare = measureTime(quicksortHoare);
    double timeMedian = measureTime(quicksortMedianOfThree);

    cout << "Average time (Lomuto): " << timeLomuto << " seconds\n";
    cout << "Average time (Hoare): " << timeHoare << " seconds\n";
    cout << "Average time (Median-of-three): " << timeMedian << " seconds\n";
}

int main() {
    measurePerformance();
    return 0;
}
