//建堆，堆排序
#include <iostream>
#include <stdio.h>
#define Left(i) 2*i+1
#define Right(i) 2*i+2
using namespace std;

int a[]={4,1,3,2,16,9,10,14,8,7};
int la = sizeof(a)/sizeof(a[0]);
void MaxHeapfiy(int *a,int i)
{
    int l = Left(i);
    int r = Right(i);
    int largest;
    if(l<la && a[l]>a[i])
        largest = l;
    else
        largest = i;
    if(r<la && a[r]>a[largest])
        largest = r;
    if(largest != i)
    {
        int temp;
        temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        MaxHeapfiy(a, largest);
    }
}

void BuildMaxHeap(int *a)
{
    int c = la/2;
    for(int i=c-1;i>=0;i--)
        MaxHeapfiy(a,i);
}

void SortHeap(int *a)
{
    int temp;
    while(la-1)
    {
        temp =  a[la-1];
        a[la -1] = a[0];
        a[0] = temp;
        la--;
        MaxHeapfiy(a,0);
    }
}

int main(int argc, char * argv[])
{
    BuildMaxHeap(a);
    SortHeap(a);
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
        cout<<a[i]<<endl;
    return 0;
}
