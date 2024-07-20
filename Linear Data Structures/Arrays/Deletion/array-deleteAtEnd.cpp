#include<iostream>
using namespace std;
int main(){
    int n, i, ele;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    //input array from the user
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }

    //assign last element as 0 becaue we are deleting the last element
    arr[n-1] = 0;

    //printing the array after deletion
    cout << "Array after deletion: ";
    for(i = 0; i < n-1; i++){
        cout << arr[i] << " ";
    }
}