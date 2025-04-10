// 循环链表
#include "stdio.h"
#include "stdlib.h"

typedef int Elemtype; // 定义顺序表中元素的类型
// Dnode为结点，DLinkList为双链表
typedef struct DNodeOne
{                       // 循环单链表
    Elemtype data;      // 数据域
    struct DNode *next; // 前驱和后继指针
} LNode, *LinkList;

typedef struct DNodeTwo
{                        // 循环双链表
    Elemtype data;       // 数据域
    struct DNode *prior; // 前驱和后继指针
    struct DNode *next;
} DNode, *DLinkList;

// 初始化循环单链表
bool InitListOne(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); // 分配一个头结点
    if (L == NULL)
    { // 内存不足，分配失败
        return false;
    }
    L->next = L; // 头结点的next指向头结点
    return true;
}

// 初始化循环双链表
bool InitListTwo(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode)); // 分配一个头结点
    if (L == NULL)
    { // 内存不足，分配失败
        return false;
    }
    L->prior = L; // 头结点的prior指向头结点
    L->next = L;  // 头结点的next指向头结点
    return true;
}

// 判断循环双链表是否为空
bool Empty(DLinkList L)
{
    if (L->next == L)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 判断结点p是否为表尾结点
bool isTailTwo(DLinkList L, DNode *p)
{
    if (p->next == L)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 判断结点p是否为表尾结点
bool isTailOne(LinkList L, LNode *p)
{
    if (p->next == L)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 循环双链表的插入
bool InsertNextDNode(DNode *p, DNode *s)
{
    s->next = p->next;  // 将结点*s插入到结点*p之后
    p->next->prior = s; // 将结点*p的后继结点的前驱指向结点*s
    s->prior = p;       // 将结点*s的前驱指向结点*p
    p->next = s;        // 将结点*p的后继指向结点*s
    return true;
}

// 循环双链表的删除
bool DeleteNextDNode(DNode *p){
    if(p->next==p){
        return false;
    }
    DNode *q=p->next; // q指向要删除的结点
    p->next=q->next; // 将结点*p的后继指向结点*q的后继
    q->next->prior=p; // 将结点*q的后继结点的前驱指向结点*p
    free(q); // 释放结点*q的空间
    return true;
}

int main()
{
    return 0;
}