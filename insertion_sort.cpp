/*
------------------------------------------------------------
    Insertion Sort in C++
    Author: Mohammed Sofiyan Pasha
    Description:
        This program implements the Insertion Sort algorithm.
        - Takes user input for array size and elements.
        - Sorts the array in ascending order.
        - Does not use any library swap function.
        - Prints the sorted array.

    Insertion Sort:
        - Builds the sorted array one item at a time by
          inserting each new element into its proper place.
        - Time Complexity:
            Best Case   : O(n)   (when already sorted)
            Worst Case  : O(n^2)
        - Space Complexity: O(1) (in-place sorting)
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];  // Current element
        int j = i - 1;

        // Move elements greater than key one position ahead
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);

    cout << "\nSorted array (Insertion Sort): ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
Example Run:
Enter number of elements: 5
Enter 5 elements:
10 3 7 5 2

Sorted array (Insertion Sort): 2 3 5 7 10
*/
