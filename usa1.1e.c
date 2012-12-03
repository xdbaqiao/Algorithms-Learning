/*
ID: xinjing2
LANG: C
PROG: gift1
*/
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fin = fopen("gift1.in", "r");
    FILE *fout = fopen("gift1.out", "w");
    int num, i, j, k;
    char name[12][15], names[15], names2[15];
    int res[12];
    fscanf(fin, "%d", &num);
    for(i=0;i<num;i++)res[i]=0;
    for(i=0;i<num;i++)
        fscanf(fin, "%s", name[i]);
    int val, pernum, temp;
    for(i=0;i<num;i++)
    {
        fscanf(fin, "%s", names2);
        fscanf(fin, "%d %d", &val, &pernum);
        if(pernum)
            temp = val/pernum;
        else
            continue;
        for(k=0;k<num;k++)
        {
            if(!strcmp(names2, name[k]))
            {res[k] -= temp*pernum;break;}
        }
        for(j=0; j<pernum; j++)
        {
            fscanf(fin, "%s", names);
            for(k=0;k<num;k++)
                if(!strcmp(names, name[k]))
                {res[k] += temp;break;}
        }
    }
    for(i=0;i<num;i++)
        fprintf(fout, "%s %d\n", name[i], res[i]);
    return 0;
}   
