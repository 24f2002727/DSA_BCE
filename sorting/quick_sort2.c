#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int left,int right)
{
    pivot=arr[left];
    int position=-1;
    for(int j=left,j<right,j++)
    {
        if(arr[j]<pivot)
        {
            position++;
            swap(&arr[j],&arr[position]);
        }
        swap(&arr[j+1],&arr[position]);
        return i+1;

    }
}


void quickSort(int arr[],left,right)
{
    if(left<right)
    {
        
    }
}

int main()
{
    
    return 0;
}