/*
    CH-231-A
    hw7
    Redon Jashari
    RJASHARI@constructor.university
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int,int> dualPivotPartition(vector<int>& arr, int low, int high) {
    if (arr[low] > arr[low+1])
        swap(arr[low], arr[low+1]);
    swap(arr[low+1], arr[high]);
    
    int pivot1 = arr[low];
    int pivot2 = arr[high];
    
    int less = low + 1;
    int great = high - 1;
    int j = low + 1;
    
    while (j <= great) {
        if (arr[j] < pivot1) {
            swap(arr[j], arr[less]);
            less++;
            j++;
        } else if (arr[j] > pivot2) {
            swap(arr[j], arr[great]);
            great--;
        } else {
            j++;
        }
    }
    swap(arr[low], arr[less - 1]);
    swap(arr[high], arr[great + 1]);
    
    return {less - 1, great + 1};
}

void dualPivotQuicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        auto pivots = dualPivotPartition(arr, low, high);
        int p1 = pivots.first;
        int p2 = pivots.second;

        dualPivotQuicksort(arr, low, p1 - 1);
        dualPivotQuicksort(arr, p1 + 1, p2 - 1);
        dualPivotQuicksort(arr, p2 + 1, high);
    }
}

void runTests() {
    vector<vector<int>> testCases = {
        {45, 7, 5, 2, 8, 34, 23, 32, 32, 62},
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000},
        {50, 20, 60, 10, 90, 30, 80, 40, 70, 100},
        {5, 1, 3, 7, 9, 2, 8, 6, 4, 10}
    };
    
    for (auto test : testCases) {
        vector<int> arr = test;
        dualPivotQuicksort(arr, 0, arr.size() - 1);
        cout << "Sorted (Deterministic): ";
        for (int num : arr)
            cout << num << " ";
        cout << "\n";
    }
}

int main() {
    runTests();
    return 0;
}
