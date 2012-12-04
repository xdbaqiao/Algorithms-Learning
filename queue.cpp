//队列
#include <iostream>
#include <stdio.h>

using namespace std;

int Q[6];
int tail, head;

void Enqueue(int *a, int b)
{
    if((tail+1)==head)
        cout<<"Enqueue Error!"<<endl;
    else
    {
        if(tail==5)
            tail = 0;
        else
            tail++;
        a[tail] = b;
    }
}

int Dequeue(int *a)
{
    if(tail==head)
    {
        cout<<"Dequeue Error!"<<endl;
        return 0;
    }
    else
    {
        if(head==5)
            head = 0;
        else
            head++;
        return a[head];
    }
}

void Print()
{
    int i;
    for(i=0;i<6;i++)
        cout<<Q[i]<<" ";
    cout<<endl;
}

int main()
{
    int tmp;
    tail = head = -1;
    Enqueue(Q, 4);
    Print();
    Enqueue(Q, 1);
    Print();
    Enqueue(Q, 3);
    Print();
    tmp = Dequeue(Q);
    cout<<"POP "<<tmp<<endl;
    Print();
    Enqueue(Q, 8);
    Print();
    tmp = Dequeue(Q);
    cout<<"POP "<<tmp<<endl;
    Print();
    return 0;
}


/****result*****
 4 0 0 0 0 0 
 4 1 0 0 0 0 
 4 1 3 0 0 0 
 POP 4
 4 1 3 0 0 0 
 4 1 3 8 0 0 
 POP 1
 4 1 3 8 0 0
 ***************/
