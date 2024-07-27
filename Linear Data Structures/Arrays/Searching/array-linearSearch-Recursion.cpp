#include<iostream>
using namespace std;
bool linearSearch(int n, int ele, int arr[], int low, int high){
    int mid = arr[( low + high ) / 2];
    if (mid == ele){
        return true;
    }   
    else if (mid < ele){
        linearSearch(n,ele,arr,mid+1,high);
    }
    else{
        linearSearch(n,ele,arr,low,mid-1);
    }
    return false;
}
int main(){
    int n,ele;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter element to search: ";
    cin>>ele;
    if(linearSearch(n,ele,arr,0,n-1)){
        cout<<"Element found";
    }
    else{
        cout<<"Element not found";
    }
}