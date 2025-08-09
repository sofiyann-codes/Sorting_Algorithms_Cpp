/*
------------------------------------------------------------
    Quick Sort in C++
    Author: Mohammed Sofiyan Pasha
    Description:
        This program implements the Quick Sort algorithm.
        - Takes user input for array size and elements.
        - Uses partition method to sort.
        - Does not use any library swap function.

    Quick Sort:
        - Picks a pivot and partitions the array.
        - Recursively sorts left and right partitions.
        - Time Complexity:
            Best/Average Case: O(n log n)
            Worst Case: O(n^2) (when pivot is worst choice)
        - Space Complexity: O(log n) (recursive stack)
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array (Quick Sort): ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
Example Run:
Enter number of elements: 5
Enter 5 elements:
8 4 2 9 1

Sorted array (Quick Sort): 1 2 4 8 9
*/
