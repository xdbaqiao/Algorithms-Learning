//红黑树, 二叉树改写而来
/***************************result************************
 *
 * 中序遍历红黑树：
 * value=3  color=RED   parent=7  
 * value=7  color=BLACK parent=10 left=3  
 * value=10 color=RED   parent=14 left=7  right=12 
 * value=12 color=BLACK parent=10 
 * value=14 color=BLACK parent=17 left=10 right=16 
 * value=15 color=RED   parent=16 
 * value=16 color=BLACK parent=14 left=15 
 * value=17 color=RED   parent=26 left=14 right=21 
 * value=19 color=BLACK parent=21 right=20 
 * value=20 color=RED   parent=19 
 * value=21 color=BLACK parent=17 left=19 right=23 
 * value=23 color=BLACK parent=21 
 * value=26 color=BLACK parent=0  left=17 right=41 
 * value=28 color=BLACK parent=30 
 * value=30 color=RED   parent=41 left=28 right=38 
 * value=35 color=RED   parent=38 
 * value=38 color=BLACK parent=30 left=35 right=39 
 * value=39 color=RED   parent=38 
 * value=41 color=BLACK parent=26 left=30 right=47 
 * value=47 color=BLACK parent=41 
 * 搜索到值：16
 * 删除16后，中序遍历红黑树：
 * value=3  color=RED   parent=7  
 * value=7  color=BLACK parent=10 left=3  
 * value=10 color=RED   parent=14 left=7  right=12 
 * value=12 color=BLACK parent=10 
 * value=14 color=BLACK parent=17 left=10 right=15 
 * value=15 color=BLACK parent=14 
 * value=17 color=RED   parent=26 left=14 right=21 
 * value=19 color=BLACK parent=21 right=20 
 * value=20 color=RED   parent=19 
 * value=21 color=BLACK parent=17 left=19 right=23 
 * value=23 color=BLACK parent=21 
 * value=26 color=BLACK parent=0  left=17 right=41 
 * value=28 color=BLACK parent=30 
 * value=30 color=RED   parent=41 left=28 right=38 
 * value=35 color=RED   parent=38 
 * value=38 color=BLACK parent=30 left=35 right=39 
 * value=39 color=RED   parent=38 
 * value=41 color=BLACK parent=26 left=30 right=47 
 * value=47 color=BLACK parent=41 
 *
 * *********************************************************************/


#include <stdio.h>
#include <malloc.h>
#define RED 0
#define BLACK 1

struct RBtree
{
    int key;
    int color;
    struct RBtree *parent, *left, *right;
};

static struct RBtree sb = {0, BLACK, NULL, NULL, NULL};                                  //哨兵
#define NIL &sb

void LeftRotate(struct RBtree **T, struct RBtree **z)
{
    struct RBtree *tmp;
    tmp = (*z)->right;
    (*z)->right = tmp->left;
    if(tmp->left != NIL)
        tmp->left->parent = (*z);
    tmp->parent = (*z)->parent;
    if((*z)->parent == NIL)
        *T = tmp;
    else
    {
        if((*z) == (*z)->parent->left)
            (*z)->parent->left = tmp;
        else
            (*z)->parent->right = tmp;
    }
    tmp->left = (*z);
    (*z)->parent = tmp;
}

void RightRotate(struct RBtree **T, struct RBtree **z)
{
    struct RBtree *tmp;
    tmp = (*z)->left;
    (*z)->left = tmp->right;
    if(tmp->right != NIL)
        tmp->right->parent = (*z);
    tmp->parent = (*z)->parent;
    if((*z)->parent == NIL)
        *T = tmp;
    else
    {
        if((*z) == (*z)->parent->left)
            (*z)->parent->left = tmp;
        else
            (*z)->parent->right = tmp;
    }
    tmp->right = (*z);
    (*z)->parent = tmp;
}

void RBInsertFixup(struct RBtree **T, struct RBtree **z)
{
    struct RBtree *uncle;
    while((*z)->parent->color==RED)
    {
        if((*z)->parent->parent->left == (*z)->parent)
        {
            uncle = (*z)->parent->parent->right;
            if(uncle->color == RED)
            {
                uncle->color = BLACK;
                uncle->parent->color = RED;
                (*z)->parent->color = BLACK;
                (*z) = (*z)->parent->parent;
            }
            else
            {
                if((*z)->parent->right = *z)
                {
                    (*z) = (*z)->parent;
                    LeftRotate(T, z);
                }
                (*z)->parent->color = BLACK;
                (*z)->parent->parent->color = RED;
                RightRotate(T, &((*z)->parent->parent));
            }
        }
        else if((*z)->parent->parent->right == (*z)->parent)
        {
            uncle = (*z)->parent->parent->left;
            if(uncle->color == RED)
            {
                uncle->color = BLACK;
                uncle->parent->color = RED;
                (*z)->parent->color = BLACK;
                (*z) = (*z)->parent->parent;
            }
            else
            {
                if((*z)->parent->left = *z)
                {
                    (*z) = (*z)->parent;
                    RightRotate(T, z);
                }
                (*z)->parent->color = BLACK;
                (*z)->parent->parent->color = RED;
                LeftRotate(T, &((*z)->parent->parent));
            }
        }
    }
    (*T)->color = BLACK;
}

void RBTreeInsert(struct RBtree **T, int a)                   
{
    struct RBtree *x, *y;
    struct RBtree *z = (struct RBtree *)malloc(sizeof(struct RBtree));
    y = NIL;
    x = *T;
    z->parent=z->left=z->right=NIL;
    while(x!=NIL)
    {
        y = x;
        if(a < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->key = a;
    z->parent = y;
    if(y==NIL)
        *T = z;                                         //这样才能改写T的地址值
    else 
    {
        if(a < y->key)
            y->left = z;
        else
            y->right = z;
    }
    z->left=z->right=NIL;
    z->color = RED;
    RBInsertFixup(T, &z);
}

void RBTreeWalk(struct RBtree *T)
{
    if(T!=NIL)
    {
        RBTreeWalk(T->left);
        printf("value=%-2d color=%-5s parent=%-2d ", T->key, T->color?"BLACK":"RED", T->parent->key);
        if(T->left != NIL)
            printf("left=%-2d ", T->left->key);
        if(T->right != NIL)
            printf("right=%-2d ", T->right->key);
        printf("\n");
        RBTreeWalk(T->right);
    }
}

struct RBtree *RBTreeSearch(struct RBtree *T, int a)
{
    while(T!=NIL && T->key != a)
    {
        if(T->key < a)
            T = T-> right;
        else
            T = T-> left;
    }
    return T;
}

void RBDelectFixup(struct RBtree **T, struct RBtree **z)
{
    struct RBtree *bother;
    while((*z) != *T && (*z)->color == BLACK)
    {
        if((*z)->parent->left == (*z))
        {
            bother = (*z)->parent->right;
            if(bother->color == RED)
            {
                bother->color = BLACK;
                (*z)->parent->color = RED;
                LeftRotate(T, &((*z)->parent));
                bother = (*z)->parent->right;
            }
            if(bother->left->color == BLACK && bother->right->color == BLACK)
            {
                bother->left->color = RED;
                (*z) = (*z)->parent;
            }
            else 
            {
                if(bother->right->color == BLACK)
                {
                    bother->color = RED;
                    bother->left->color = BLACK;
                    RightRotate(T, &(bother));
                    bother = (*z)->parent->right;
                }
                bother->color = bother->parent->color;
                bother->parent->color = BLACK;
                bother->right->color = BLACK;
                LeftRotate(T, &((*z)->parent));
                (*z) = (*T);
            }
        }
        else if((*z)->parent->right == (*z))
        {
            bother = (*z)->parent->left;
            if(bother->color == RED)
            {
                bother->color = BLACK;
                (*z)->parent->color = RED;
                RightRotate(T, &((*z)->parent));
                bother = (*z)->parent->left;
            }
            if(bother->left->color == BLACK && bother->right->color == BLACK)
            {
                bother->right->color = RED;
                (*z) = (*z)->parent;
            }
            else 
            {
                if(bother->left->color == BLACK)
                {
                    bother->color = RED;
                    bother->right->color = BLACK;
                    LeftRotate(T, &(bother));
                    bother = (*z)->parent->left;
                }
                bother->color = bother->parent->color;
                bother->parent->color = BLACK;
                bother->left->color = BLACK;
                RightRotate(T, &((*z)->parent));
                (*z) = (*T);
            }
        }
    }
    (*z)->color = BLACK;
}

struct RBtree *RBTreeMinimum(struct RBtree *T)
{
    if(T->left != NIL)
        T = T->left;
    else
        return T;
}

struct RBtree *RBTreeSuccessor(struct RBtree *T)
{
    struct RBtree *tmp;
    if(T->right != NIL)
        return RBTreeMinimum(T->right);
    else
    {
        tmp = T->parent;
        while(tmp!= NIL && tmp->right == T)
        {
            T = tmp;
            tmp = tmp->parent;
        }
        return tmp;
    }
}

struct RBtree *RBTreeDelect(struct RBtree **T, struct RBtree **z)
{
    struct RBtree *del, *con;
    if((*z)->left ==NIL || (*z)->right==NIL)                              //首先确定需要删除的是什么
        del = *z;
    else
        del = RBTreeSuccessor(*z);
    if(del->left != NIL)                                                  //然后确定需要连接的是什么
        con = del->left;
    else
        con = del->right;
    con->parent = del->parent;
    if(del->parent == NIL)
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
    if((*z)->color == BLACK)
        RBDelectFixup(T, &con);
    return del;
}

int main()
{
    struct RBtree *T, *tmp;
    T = NIL;
    RBTreeInsert(&T, 26), RBTreeInsert(&T, 17);
    RBTreeInsert(&T, 41), RBTreeInsert(&T, 14);
    RBTreeInsert(&T, 21), RBTreeInsert(&T, 30);
    RBTreeInsert(&T, 47), RBTreeInsert(&T, 10);
    RBTreeInsert(&T, 16), RBTreeInsert(&T, 19);
    RBTreeInsert(&T, 23), RBTreeInsert(&T, 28);
    RBTreeInsert(&T, 38), RBTreeInsert(&T, 7);
    RBTreeInsert(&T, 12), RBTreeInsert(&T, 15);
    RBTreeInsert(&T, 20), RBTreeInsert(&T, 35);
    RBTreeInsert(&T, 39), RBTreeInsert(&T, 3);
    printf("中序遍历红黑树：\n");
    RBTreeWalk(T);
    tmp = RBTreeSearch(T, 16);
    if(tmp->key == 16)
        printf("搜索到值：16\n");
    RBTreeDelect(&T, &tmp);
    printf("删除16后，中序遍历红黑树：\n");
    RBTreeWalk(T);
    return 0;
}
