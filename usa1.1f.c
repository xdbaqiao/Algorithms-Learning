/*
ID: xinjing2
LANG: C
PROG: friday
*/
#include <stdio.h>

int LeapYear(int y)
{
    if(y%4==0)
    {
        if(y%100==0&&y%400!=0)
            return 0;
        else
            return 1;
    }
    else
        return 0;
}
int main()
{
    FILE *fin = fopen("friday.in", "r");
    FILE *fout = fopen("friday.out", "w");
    int N, sig, year, i, j;
    int a[7];
    for(i=0;i<7;i++)
        a[i]=0;
    fscanf(fin, "%d", &N);
    int week, daynum , week13;
    week =1;
    for(i=0;i<N;i++)
    {
        year = 1900 + i;
        sig = LeapYear(year);
        for(j=1;j<=12;j++)
        {
            if(j==1||j==3||j==5||j==7||j==8||j==12||j==10)
            {
                week13 = (week+5)%7;
                a[week13] += 1;
                week = (week+3)%7;
            }
            else if(j==2)
            {
                week13 = (week+5)%7;
                a[week13] += 1;
                if(sig==1)week = (week+1)%7;
            }
            else
            {
                week13 = (week+5)%7;
                a[week13] += 1;
                week = (week+2)%7;
            }
        }
    }
    fprintf(fout,"%d %d ",a[6], a[0]);
    for(i=1;i<5;i++)
        fprintf(fout,"%d ",a[i]);
    fprintf(fout,"%d\n",a[5]);
    return 0;
}
