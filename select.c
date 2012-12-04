//中位数和顺序统计学
#include <stdio.h>

int Partition(int *a, int b, int c)
{
    int i,j, key, tmp;
    key = a[c];
    i = b-1;
    for(j=b;j<c;j++)
    {
        if(a[j]<=a[c])
        {
            i++;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    a[c] = a[i+1];
    a[i+1] = key;
    return i+1;
}

int Select(int *a, int b, int c, int pos)
{
    int q;
    q = Partition(a, b, c);
    if((q+1)==pos)
        return a[q];
    else if((q+1)>pos)
        return Select(a, 0, q-1, pos);
    else if((q+1)<pos)
        return Select(a, q+1, 8, pos);
}

int main()
{
    int a[] = {9,6,5,7,1,8,3,2,4,6};
    int pos, res;
    scanf("%d", &pos);
    res = Select(a, 0, 8, pos);
    printf("%d\n", res);
    return 0;
}
