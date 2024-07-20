#include<iostream>
using namespace std;
int main(){
    int n, i, ele;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n+1];
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter the element to be inserted: ";
    cin >> ele;
    for(i = n; i >= 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = ele;
    cout << "Array after insertion: ";
    for(i = 0; i <= n; i++){
        cout << arr[i] << " ";
    }
}