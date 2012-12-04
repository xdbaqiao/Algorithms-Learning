//计数排序
#include <stdio.h>

int main()
{
    int a[] = {2,5,3,0,2,3,0,3};
    int b[9], c[6], i;
    for(i=0;i<6;i++)
        c[i]=0;
    for(i=0;i<8;i++)
        c[a[i]]++;
    for(i=1;i<6;i++)
        c[i] += c[i-1];
    for(i=7;i>=0;i--)
    {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
    for(i=1;i<=8;i++)
        printf("%d\n", b[i]);

    return 0;
}
