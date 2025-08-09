/*
------------------------------------------------------------
    Shell Sort in C++
    Author: Mohammed Sofiyan Pasha
    Description:
        This program implements the Shell Sort algorithm.
        - Takes user input for array size and elements.
        - Uses gap method to sort.
        - Prints the sorted array.

    Shell Sort:
        - Generalization of Insertion Sort using gap sequences.
        - Time Complexity: O(n^2) worst case, better in practice.
        - Space Complexity: O(1)
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {
    for(int gap = n / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
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

    shellSort(arr, n);

    cout << "\nSorted array (Shell Sort): ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
Example Run:
Enter number of elements: 5
Enter 5 elements:
5 2 9 1 6

Sorted array (Shell Sort): 1 2 5 6 9
*/
