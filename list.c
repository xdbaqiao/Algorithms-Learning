//单个数组链表实现, 有空间分配和释放
#include <stdio.h>

int a1[15]= {3,0,0,6,0,0,9,0,0,12,0,0,0,0,0};
int idx;
int head;
int free1;

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
        idx = free1;
        free1 = a[idx];
        a[idx] = key; //关键字
        a[idx+1] = -1;  //prev
        a[idx+2] = -1;   //next
    }
    else
    {
        if(free1!=0)
        {
            idx = free1;
            free1 = a[free1];
        }
        a[idx] = key;
        a[head+1] = idx;
        a[idx+1] = -1;
        a[idx+2] = head; 
        head = idx;
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
    a[idx2] = free1;
    a[idx2+1] = a[idx2+2] = 0;
    if(free1==0)
        a[idx2] = -3;
    free1 = idx2;
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
    free1 = 0;
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
    ListDelect(a1, 3);
    printf("Delete index %d:\n", 3);
    Print();
    ListDelect(a1, 6);
    printf("Delete index %d:\n", 6);
    Print();
    ListDelect(a1, 9);
    printf("Delete index %d:\n", 9);
    Print();
    printf("freenum is %d\n", free1);
    ListInsert(a1, 111);
    Print();

    return 0;
}

/*
 * 链表的结构是 a[j], a[j+1], a[j+2] 
 *              key， prev，  next
 *****result****
 *
 * 10 -1 -1 6 0 0 9 0 0 12 0 0 0 0 0 
 * 10 3 -1 30 -1 0 9 0 0 12 0 0 0 0 0 
 * 10 3 -1 30 6 0 50 -1 3 12 0 0 0 0 0 
 * 10 3 -1 30 6 0 50 9 3 19 -1 6 0 0 0 
 * 10 3 -1 30 6 0 50 9 3 19 12 6 25 -1 9 
 * Search index is 12.
 * Delect index 3:
 * 10 6 -1 -3 0 0 50 9 0 19 12 6 25 -1 9 
 * Delect index 6:
 * 10 9 -1 -3 0 0 3 0 0 19 12 0 25 -1 9 
 * Delect index 9:
 * 10 12 -1 -3 0 0 3 0 0 6 0 0 25 -1 0 
 * freenum is 9
 * 10 12 -1 -3 0 0 3 0 0 111 -1 12 25 9 0
 *
 *****************/
