//二叉查找树
/***********result****************
 *
 * 中序遍历:3 5 6 7 10 12 13 15 16 18 20 23 
 * 最小值：3
 * 最大值：23
 * 搜索到值：12
 * 值12的中序遍历后继是：13
 * 删除6后中序遍历:3 5 7 10 12 13 15 16 18 20 23
 *
 ****************************************/

#include <stdio.h>
#include <malloc.h>

struct tree
{
    int key;
    struct tree *parent, *left, *right;
};

void TreeInsert(struct tree **T, int a)                   //注意是指针的指针，这样才能改写T的地址值,不然没有return，T是无法更改的
{
    struct tree *x, *y;
    struct tree *z = (struct tree *)malloc(sizeof(struct tree));
    y = NULL;
    x = *T;
    z->parent=z->left=z->right=NULL;
    while(x!=NULL)
    {
        y = x;
        if(a < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->key = a;
    z->parent = y;
    if(y==NULL)
        *T = z;                                         //这样才能改写T的地址值
    else 
    {
        if(a < y->key)
            y->left = z;
        else
            y->right = z;
    }
}

void TreeWalk(struct tree *T)
{
    if(T!=NULL)
    {
        TreeWalk(T->left);
        printf("%d ", T->key);
        TreeWalk(T->right);
    }
}

struct tree *TreeSearch(struct tree *T, int a)              //搜索，有return，所以可以保存T更改后的值
{
    while(T!=NULL && T->key !=a)
    {
        if(a<T->key)
            T = T->left;
        else
            T = T->right;
    }
    return T;
}

struct tree *TreeMinimum(struct tree *T)
{
    while(T->left != NULL)
        T = T->left;
    return T;
}

struct tree *TreeMaximum(struct tree *T)
{
    while(T->right != NULL)
        T = T->right;
    return T;
}

struct tree *TreeSuccessor(struct tree *T)
{
    struct tree *tmp;
    if(T->right != NULL)
        return TreeMinimum(T->right);
    else
    {
        tmp = T->parent;
        while(tmp != NULL && tmp->right == T)
        {
            T = tmp;
            tmp = tmp->parent;
        }
        return tmp;
    }
}
struct tree *TreeDelect(struct tree **T, struct tree **z)
{
    struct tree *del, *con;
    if((*z)->left ==NULL || (*z)->right==NULL)                              //首先确定需要删除的是什么
        del = *z;
    else
        del = TreeSuccessor(*z);
    if(del->left != NULL)                                                  //然后确定需要连接的是什么
        con = del->left;
    else
        con = del->right;
    if(con != NULL)                                                         //连接
        con->parent = del->parent;
    if(del->parent == NULL)
        *T = con;
    else
    {
        if(del == del->parent->right)
            del->parent->right = con;
        else
            del->parent->left = con;
        if(del != *z)                                                       //区分删除的是否是后继，是后继就替代
            (*z)->key = del->key;
    }
    return del;
}

int main()
{
    struct tree *T;
    T = NULL;
    TreeInsert(&T, 3);
    TreeInsert(&T, 5);
    TreeInsert(&T, 12);
    TreeInsert(&T, 10);
    TreeInsert(&T, 13);
    TreeInsert(&T, 7);
    TreeInsert(&T, 6);
    TreeInsert(&T, 16);
    TreeInsert(&T, 15);
    TreeInsert(&T, 18);
    TreeInsert(&T, 23);
    TreeInsert(&T, 20);
    printf("中序遍历:");
    TreeWalk(T);
    printf("\n");
    struct tree *tmp;
    tmp = TreeMinimum(T);
    printf("最小值：%d\n", tmp->key);
    tmp = TreeMaximum(T);
    printf("最大值：%d\n", tmp->key);

    //试图找出12的后继
    tmp = TreeSearch(T, 12);
    printf("搜索到值：%d\n", tmp->key);
    struct tree *tmp2;
    tmp2 = TreeSuccessor(tmp);
    printf("值12的中序遍历后继是：%d\n", tmp2->key);

    //删除
    tmp = TreeSearch(T, 6);
    struct tree *tmp3;
    tmp3 = TreeDelect(&T, &tmp);
    printf("删除6后中序遍历:");
    TreeWalk(T);
    printf("\n");


    return 0;
}

/*******************把错误代码也贴出来,分析一下******************************************************
#include <stdio.h>
#include <malloc.h>

struct tree
{
    int key;
    struct tree *parent, *left, *right;
};

void TreeInsert(struct tree *T, int a)
{
    struct tree *x, *y;
    struct tree *z = (struct tree *)malloc(sizeof(struct tree));
    y = NULL;
    x = T;
    z->parent=z->left=z->right=NULL;
    while(x!=NULL)
    {
        y = x;
        if(a < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->key = a;
    z->parent = y;
    if(y==NULL)
        T = z;                     //地址是形参，不会改变!!
    else 
    {
        printf("%d ", y->key);
        if(a < y->key)
            y->left = z;
        else
            y->right = z;
    }
}

void TreeWalk(struct tree *T)
{
    if(T!=NULL)
    {
        TreeWalk(T->left);
        printf("%d ", T->key);
        TreeWalk(T->right);
    }
}

int main()
{
    struct tree *T;         
    T = NULL;
    TreeInsert(T, 3);
    TreeInsert(T, 5);
    TreeInsert(T, 12);
    TreeInsert(T, 10);
    TreeInsert(T, 13);
    TreeInsert(T, 7);
    TreeInsert(T, 6);
    TreeInsert(T, 16);
    TreeInsert(T, 15);
    TreeInsert(T, 18);
    TreeInsert(T, 23);
    TreeInsert(T, 20);
    TreeWalk(T);
    return 0;
}
***********************************************************************************************/
