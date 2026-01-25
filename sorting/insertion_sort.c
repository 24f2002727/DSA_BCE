#include<stdio.h>

void display(int arr[],int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[5]={1,8,0,4,9};  
    int n=5;

    for(int i=0;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }


    display(arr,5);
    return 0;
}