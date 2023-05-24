#include<iostream>
using namespace std;

void selectionSort(int n,int arr[])
{
    int smallest,temp;
    for(int i=0;i<n-1;i++)
    {
        smallest=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[smallest])
            {
                smallest=j;
            }
        
        }
        temp=arr[smallest];
        arr[smallest]=arr[i];
        arr[i]=temp;
        
    }
}
void printArray(int n,int arr[])
{
    cout<<"Sorted array is:\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    
    int n;
    cout<<"Enter the number of element:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    selectionSort(n,arr);
    printArray(n,arr);
    return 0;
}
