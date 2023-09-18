#include <iostream>
using namespace std;
void insertionSort(int array[], int length_of_array)
{
    for(int i=1; i<length_of_array; i++)
    {
        int temp=array[i];
        int j;
        for(j=i-1; j>=0; j--)
        {
            if(array[j]>temp)
            {
                array[j+1]=array[j];
            }
            else
            {
                break;
            }
        }
        array[j+1]=temp;
    }
}
int main()
{
    int a[]={1, 55, 11, 0, 69};
    insertionSort(a,5);
    cout<<"Array after sorting : ";
    for(int i=0; i<5; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}