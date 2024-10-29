#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0...i-1] that are greater than key
        // one position ahead to make space for the key
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() 
{
    int arr[] = {5, 4, 3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    // Print the sorted array directly in main
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
