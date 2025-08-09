/*
------------------------------------------------------------
    Merge Sort in C++
    Author: Mohammed Sofiyan Pasha
    Description:
        This program implements the Merge Sort algorithm.
        - Takes user input for array size and elements.
        - Uses divide and conquer to sort.
        - Prints the sorted array.

    Merge Sort:
        - Recursively divides array into halves, sorts, and merges.
        - Time Complexity: O(n log n) for all cases.
        - Space Complexity: O(n) (needs temporary arrays)
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array (Merge Sort): ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
Example Run:
Enter number of elements: 5
Enter 5 elements:
5 1 4 2 8

Sorted array (Merge Sort): 1 2 4 5 8
*/
