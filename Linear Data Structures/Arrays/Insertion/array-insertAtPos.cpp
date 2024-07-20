#include<iostream>
using namespace std;
int main(){
    int n, i, ele, pos;
    cout << "Enter the size of the array: ";
    cin >> n;

    //increment size by 1
    int arr[n+1]; 
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }

    //input element and position
    cout << "Enter the element to be inserted: ";
    cin >> ele;
    cout << "Enter the position it has to be inserted at: ";
    cin >> pos;

    //shift elements to the right
    for(i = n; i > pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = ele;
    cout << "Array after insertion: ";
    for(i = 0; i <= n; i++){
        cout << arr[i] << " ";
    }
}