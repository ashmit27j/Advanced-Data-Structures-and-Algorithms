#include <iostream>
using namespace std;
bool BinarySearch(int arr[], int low, int high, int key)
{
    if(low<=high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
        {
            return true;
        }
        else if(arr[mid] > key)
        {
            return BinarySearch(arr, low, mid-1, key);
        }
        else
        {
            return BinarySearch(arr, mid+1, high, key);
        }
    }
    return false;
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the element to be searched: ";
    cin >> key;
    int low = 0, high = n-1;
    if ( BinarySearch(arr, low, high, key) == true )
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}