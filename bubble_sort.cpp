/*
------------------------------------------------------------
    Bubble Sort in C++
    Author: Mohammed Sofiyan Pasha
    Description:
        This program implements the Bubble Sort algorithm.
        - Takes user input for array size and elements.
        - Sorts the array in ascending order.
        - Does not use any library swap function (manual swapping).
        - Prints the sorted array.

    Bubble Sort:
        - Repeatedly compares adjacent elements and swaps them
          if they are in the wrong order.
        - Largest element "bubbles" to the end in each pass.
        - Time Complexity:
            Best Case   : O(n)   (when already sorted)
            Worst Case  : O(n^2) (when sorted in reverse)
        - Space Complexity: O(1) (in-place sorting)
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        // Last i elements are already in place after i-th pass
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Manual swap without using swap()
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    bubbleSort(arr, n);

    // Output: sorted array
    cout << "\nSorted array (Bubble Sort): ";
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
5 2 9 1 6

Sorted array (Bubble Sort): 1 2 5 6 9
-------------------------
*/
