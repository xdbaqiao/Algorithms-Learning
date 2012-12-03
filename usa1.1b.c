/*
ID: xinjing2
LANG: C
PROG: ride
*/
#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fin = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");
    char a[10],b[10];
    int tempa, tempb;
    int i;
    tempa = tempb = 1;
    fscanf(fin,"%s%s",a,b);
    for(i =0;i<strlen(a);i++)
        tempa *= ((int)(a[i])-64);
    for(i =0;i<strlen(b);i++)
        tempb *= (int)(b[i])-64;
    if((tempa%47)==(tempb%47))
        fprintf(fout, "GO\n");
    else
        fprintf(fout, "STAY\n");
    return 0;
}
