#include<iostream>
using namespace std;
int partition(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);
int main()
{
    int arr[]={1,5,3,4,2};
    quick_sort(arr,0,5-1);
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int partition(int arr[], int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low; j<high; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
        
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}
void quick_sort(int arr[], int low, int high){
    if(low<high)
    {
        int pivot_index=partition(arr, low, high);
        quick_sort(arr, low, pivot_index-1);
        quick_sort(arr, pivot_index+1, high);
    }
    else
    return;
}