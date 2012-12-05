//单个数组链表实现
#include <stdio.h>

int a1[15];
int idx;
int head;

int ListSearch(int *a ,int key)
{
    int i;
    while(a[i] != key && a[i+1] != -1)
    {
        i = a[i+1];
    }
    return i;
}

void ListInsert(int *a, int key)
{
    if(head==-1)
    {
        head = 0;
        a[idx] = key; //关键字
        a[++idx] = -1;  //prev
        a[++idx] = -1;   //next
    }
    else
    {
        head = idx++;
        a[idx] = key;
        a[idx-2] = idx;
        a[++idx] = -1;
        a[++idx] = idx-5; 
    }
}

void ListDelect(int *a, int idx2)
{
    if(a[idx2+1] != -1)
        a[a[idx2+1]+2] = a[idx2+2];
    else
        a[a[idx2+2]+1] = -1;
    if(a[idx2+2] != -1)
        a[a[idx2+2]+1] = a[idx2+1];
}

void Print()
{
    int i;
    for (i=0;i<15;i++)
        printf("%d ", a1[i]);
    printf("\n");
}

int main()
{
    int tmp;
    head = -1;
    idx = 0;
    ListInsert(a1, 10);
    Print();
    ListInsert(a1, 30);
    Print();
    ListInsert(a1, 50);
    Print();
    ListInsert(a1, 19);
    Print();
    ListInsert(a1, 25);
    Print();
    tmp = ListSearch(a1, 19);
    printf("Search index is %d.\n", tmp);
    ListDelect(a1, 12);
    printf("Delect index %d:\n", 12);
    Print();

    return 0;
}

/*
 * 链表的结构是 a[j], a[j+1], a[j+2] 
 *              key， prev，  next
 *****result****
 *
 *10 -1 -1 0 0 0 0 0 0 0 0 0 0 0 0 
 *10 3 -1 30 -1 0 0 0 0 0 0 0 0 0 0 
 *10 3 -1 30 6 0 50 -1 3 0 0 0 0 0 0 
 *10 3 -1 30 6 0 50 9 3 19 -1 6 0 0 0 
 *10 3 -1 30 6 0 50 9 3 19 12 6 25 -1 9 
 *Search index is 9.
 *Delect index 12:
 *10 3 -1 30 6 0 50 9 3 19 -1 6 25 -1 9
 *
 *****************/
