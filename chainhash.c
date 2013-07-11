//链接法解决Hash冲撞
#include <stdio.h>
#include <malloc.h>

struct Nodelist
{
    int  key;
    struct Nodelist *next;
};

struct Hashlist
{
    int tablesize;
    struct Nodelist **nd;  //指针的指针
};

int Hash(int a, int tablesize)
{
    return a%tablesize; //除法散列
}
struct Nodelist * Find(struct Hashlist *H, int a)
{
    struct Nodelist *pos;
    pos = H->nd[Hash(a, H->tablesize)]->next;
    while(pos !=NULL && pos->key != a)
        pos = pos->next;
    if(pos==NULL)
        return H->nd[Hash(a, H->tablesize)];
    else return pos;
}

void Insert(struct Hashlist *H, int a)
{
    struct Nodelist *insertpos;
    insertpos = Find(H, a);
    if(insertpos->key == a)
        printf("无需插入，存在%d.\n", a);
    else
    {
        struct Nodelist *tmp = (struct Nodelist *)malloc(sizeof(struct Nodelist*));
        tmp->key = a;
        tmp->next = H->nd[Hash(a, H->tablesize)]->next;
        //H->nd[Hash(a, H->tablesize)] = tmp; //这是错误的
        insertpos->next = tmp;
        printf("已插入%d.\n", a);
    }
}

void Delect(struct Hashlist *H, int a)
{
    struct Nodelist *delpos;
    struct Nodelist *prevpos;
    prevpos = H->nd[Hash(a, H->tablesize)];
    delpos = H->nd[Hash(a, H->tablesize)]->next;
    while(delpos != NULL && delpos->key != a)
    {
        prevpos = delpos;
        delpos = delpos->next;
    }
    if(delpos != NULL &&delpos->key==a)
    {
        free(delpos);
        prevpos->next = delpos->next;
        printf("已删除%d.\n", a);
    }
    else
        printf("不存在，无法删除%d.\n", a);
}


int main()
{
    struct Hashlist *H;
    H = (struct Hashlist *)malloc(sizeof(struct Hashlist));
    int ts, i;
    
    printf("输入HASH表的槽大小：");
    scanf("%d", &H->tablesize);
    ts = H->tablesize;
    H->nd = (struct Nodelist **)malloc(ts*sizeof(struct Nodelist *));
    if(H->nd==NULL)
        printf("Malloc Error.\n");
    H->nd[0] = (struct Nodelist *)malloc(ts*sizeof(struct Nodelist));
    if(H->nd==NULL)
        printf("Malloc Error.\n");
    for(i=0;i<ts;i++)
    {
        H->nd[i] = (struct Nodelist *)malloc(ts*sizeof(struct Nodelist));
        //H->nd[i] = H->nd[0] + i;
        H->nd[i]->next = NULL;
    }
    Insert(H, 19);
    Insert(H, 20);
    Insert(H, 19);
    struct Nodelist *tmp;
    tmp = Find(H, 21);
    if(tmp->key == 21)
        printf("找到21.\n");
    else
        printf("未找到21.\n");
    Delect(H, 19);
    Delect(H, 21);
    Insert(H, 19);
    return 0;
}


/*****result*******
 *
 * 输入HASH表的槽大小：12
 * 已插入19.
 * 已插入20.
 * 无需插入，存在19.
 * 未找到21.
 * 已删除19.
 * 不存在，无法删除21.
 * 已插入19.
 *
 *********************/
