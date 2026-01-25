#include<stdio.h>
#include<stdlib.h>

void display(int arr[],int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[5]={1,8,6,4,9};
    int n=5;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]<arr[j+1])
            {
                arr[j]=arr[j]+arr[j+1];
                arr[j+1]=arr[j]-arr[j+1];
                arr[j]-=arr[j+1];
                // printf("%d ",arr[j]);
                // printf("%d ",arr[j+1]);
                // int temp=arr[j];
                // arr[j]=arr[j+1];
                // arr[j+1]=temp;
            }
        }
    }    
    // for(int i=0;i<n;i++){
    //     printf("%d ",arr[i]);
    // }

    display(arr,5);
    return 0;
}