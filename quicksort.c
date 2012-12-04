//快速排序
#include <stdio.h>

int Partition(int *b, int d, int c)
{
    int i,j,tmp;
    int key;
    key = b[c];
    i = d-1;
    for(j=d;j<c;j++)
    {
        if(b[j]<=key)
        {
            i++;
            tmp = b[j];
            b[j] = b[i];
            b[i] = tmp;
        }
        //int f;
        //for(f=0;f<8;f++)
        //    printf("%d ", b[f]);
        //printf("\n");
    }
    b[c] = b[i+1];
    b[i+1] = key;

    return i+1;
}

void QuickSort(int *b, int d, int c)
{
    int q;
    if(d<c)
    {
        q = Partition(b, d, c);
        QuickSort(b, d, q-1);
        QuickSort(b, q+1, c);
    }
}

int main()
{
    int A[] = {2, 8, 7, 1, 3, 5, 6, 4};
    QuickSort(A, 0, 7);
    int i;
    for(i=0;i<8;i++)
        printf("%d ", A[i]);
}
