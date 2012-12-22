//动态规划之矩阵乘法
/**************result***********
 *最小的乘法次数是 15125
 *((A1(A2A3))((A4A5)A6))
 *
 ********************************/

#include <stdio.h>
#define N 7 

int s[N][N], m[N][N];

void Matrix_chain_order(int *p)
{
    int i, l, j, k, tmp;
    for(i=1;i<=N-1;i++)m[i][i] = 0;
    for(l=2;l<=N-1;l++)                     //l为矩阵链长度
    {
        for(i=1;i<=N-l;i++)
        {
            j = i+l-1;
            m[i][j] = 2000000000;
            for(k=i;k<j;k++)
            {
                tmp = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(tmp< m[i][j])
                {
                    m[i][j] = tmp;
                    s[i][j] = k;
                }
            }
        }
    }
}

void Print_optinal_parens(int i, int j)
{
    if(i==j)
        printf("A%d",i);
    else
    {
        printf("(");
        Print_optinal_parens(i, s[i][j]);
        Print_optinal_parens(s[i][j]+1, j);
        printf(")");
    }
}

int main()
{
    int p[] = {30,35,15,5,10,20,25};
    int num;
    Matrix_chain_order(p);
    printf("最小的乘法次数是 %d\n", m[1][6]);
    Print_optinal_parens(1, 6);
    printf("\n");
    return 0;
}
