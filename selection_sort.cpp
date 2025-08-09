/*
------------------------------------------------------------
    Selection Sort in C++
    Author: Mohammed Sofiyan Pasha
    Description:
        This program implements the Selection Sort algorithm.
        - Takes user input for array size and elements.
        - Sorts the array in ascending order.
        - Does not use any library swap function (manual swapping).
        - Prints the sorted array.

    Selection Sort:
        - Repeatedly finds the minimum element from the unsorted
          portion and places it at the beginning.
        - Time Complexity:
            Best Case   : O(n^2)
            Worst Case  : O(n^2)
        - Space Complexity: O(1) (in-place sorting)
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume first unsorted element is the smallest
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j; // Update minimum index
            }
        }
        // Manual swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int n;

    // Input: size of array
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];

    // Input: array elements
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call sorting function
    selectionSort(arr, n);

    // Output: sorted array
    cout << "\nSorted array (Selection Sort): ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
-------------------------
Example Run:
-------------------------
Enter number of elements: 5
Enter 5 elements:
8 4 2 9 1

Sorted array (Selection Sort): 1 2 4 8 9
-------------------------
*/
