/*************************************************************************
* File Name: insertSort.c
* Author: yexinjing
* Mail: yexj061761@gmail.com
* Created Time: 2013年07月01日 星期一 19时55分45秒
*************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[10] = {10,9,8,7,6,5,4,3,2,12};
    int i, tmp, b;
    for(i=0;i<10;i++)
    {
        tmp = i;
        while(i>0 && a[i-1]>a[i])
        {
            b = a[i-1];
            a[i-1] = a[i];
            a[i] = b;
            i--;
        }
        i = tmp;
    }
    for(i=0;i<10;i++)
        printf("%d ", a[i]);
    return 0;
}

