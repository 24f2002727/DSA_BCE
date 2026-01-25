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
    int arr[5]={1,8,0,4,9};  //here 0 is converted to 1 and order is descending
    int n=5;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }    
    
    display(arr,5);
    return 0;
}