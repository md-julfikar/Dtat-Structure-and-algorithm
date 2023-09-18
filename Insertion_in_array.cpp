#include<bits/stdc++.h>
using namespace std;
const int capacity=15;
void insert_at_mid(int arr[],int &size , int zero_based_index, int element)
{
    if(size==capacity)
    {
        cout<<"Array is full, can't insert element"<<endl;
        return;
    }
    if(size==0)
    {
        arr[0]=element;
        size++;
        return;
    }
    if(zero_based_index>=size)
    {
        cout<<"Out of Range"<<endl;
        return;
    }
    for(int i=size; i>zero_based_index; i--)
    {
       arr[i]=arr[i-1];
    }
    arr[zero_based_index]=element;
    size++;
    return;
}
void insert_at_begin(int array[],int &size, int element)
{
    if(size==0)
    {
        array[0]=element;
        size++;
        return;
    }
    for(int i=size; i>0; i--)
    {
        array[i]=array[i-1];
    }
    array[0]=element;
    size++;
}
void display(int array[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
void insert_at_end(int array[],int &size, int element)
{
    if(size==0)
    {
        array[0]=element;
        return;
    }
    array[size]=element;
    size++;
    return;
}
int main()
{
   int a[capacity];
   int size=0;
   insert_at_begin(a, size,10);
   insert_at_mid(a,size,1,5);
   insert_at_begin(a,size,2);
   insert_at_end(a,size,99);
   insert_at_end(a,size,100);
   insert_at_begin(a,size,1);
    insert_at_mid(a,size,0,69);
   display(a,size);
}