#include<iostream>
using namespace std;
int main()
{
    int n,s,high,low,mid;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter element to search: ";
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==s)
        {
            cout<<"Element found at index "<<i;
            return 0;
        }
    }
}