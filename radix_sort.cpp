/*
------------------------------------------------------------
    Radix Sort in C++
    Author: Mohammed Sofiyan Pasha
    Description:
        This program implements the Radix Sort algorithm.
        - Takes user input for array size and elements.
        - Sorts integers by processing digits from least to most significant.
        - Uses Counting Sort as a subroutine.

    Radix Sort:
        - Time Complexity: O(nk) where k is number of digits.
        - Space Complexity: O(n + k)
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for(int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for(int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr, n);

    cout << "\nSorted array (Radix Sort): ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
Example Run:
Enter number of elements: 6
Enter 6 elements:
170 45 75 90 802 24

Sorted array (Radix Sort): 24 45 75 90 170 802
*/
