/*************************************************************************
* File Name: whole.c
* Author: yexinjing
* Mail: yexj061761@gmail.com
* Created Time: 2013年09月08日 星期日 14时47分41秒
*************************************************************************/
#include <stdio.h>
#include <string.h>

int swap(char *m, char *n)
{
    char tmp;
    tmp = *m;
    *m = *n;
    *n = tmp;
    return 0;
}

int sort(char *str, int m, int n)
{
    if(m==n)
    {
        static int num=0;
        num += 1;
        printf("the %d is %s\n", num, str);
    }
    else
    {
        int i=m;
        for(i;i<=n;i++)
        {
            swap(str+m, str+i);
            sort(str, m+1, n);
            swap(str+m, str+i);
        }
    }
    return 0;
}

int qsort(char *str, int n)
{
    int tmp = 1<<n;
    int i, j;
    for(i=1;i<=tmp;i++)
    {
        for(j=0;j<n;j++)
            if(i>>j&1)
                printf("%c " , str[j]);
        printf("\n");
    }
    return 0; 
}

int main(int argc, char *argv[])
{
    char str[] = "1234";
    //sort(str, 0, strlen(str)-1);
    qsort(str, strlen(str));
    return 0;
}
