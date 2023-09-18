#include<iostream>
using namespace std;
void selectionSort(int array[], int size)
{
    for(int i=0; i<size-1; i++)
    {
        int selected=i;
        for(int j=i+1; j<size; j++)
        {
            if(array[j]<array[selected])
            {
                selected=j;
            }
            swap(array[i],array[selected]);
        }
    }
    return;
}
int main()
{
    int a[]={10, 0, 11, 0};
    selectionSort(a,4);
    for(int i=0; i<4; i++)
    {
        cout<<a[i]<<" ";
    }
}