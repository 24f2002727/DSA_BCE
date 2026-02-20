#include<stdio.h>
#include<stdlib.h>

void tower(int,char[],char[],char[]);

void main()
{
    int n;
    printf("Enter the no of disks to be transfered:\t");
    scanf("%d",&n);
    if(n<1)
    {
        printf("\nIncorrect value");
        exit(0);
    }
    else
    {
        printf("\nThe follefting moves are required for N=%d\n",n);
        tower(n,"beg","aux","end");
    }
    return;
}

void tower(int num,char A[5],char B[5],char C[5])
{
    if(num==1)
    {
        printf("%s -> %s\t",A,C);
        return;
    }
    tower(num-1,A,C,B);
    printf("%s -> %s\t",A,C);
    tower(num-1,B,A,C);
    return;
}