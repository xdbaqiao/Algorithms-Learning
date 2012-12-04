//栈
#include <stdio.h>
#include <string.h>

int S[10];
int P;

void PUSH(int *a, int b)
{
    if(P<9)
    {
        P++;
        a[P] = b;
    }
    else
        printf("Push Error!\n");
}

int POP(int *a)
{
    if(P)
    {
        P--;
        return a[P+1];
    }
    else
    {
        printf("Pop Error!\n");
        return 0;
    }
}

void Print()
{
    int i;
    for(i=0;i<P+1;i++)
        printf("%d ",S[i]);
    printf("\n");
}



int main()
{
    P = -1;
    PUSH(S, 4);
    Print();
    PUSH(S, 1);
    Print();
    PUSH(S, 3);
    Print();
    POP(S);
    Print();
    PUSH(S, 8);
    Print();
    POP(S);
    Print();
    return 0;
}
