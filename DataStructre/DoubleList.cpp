//双链表
#include "stdio.h"
#include "stdlib.h"

typedef int Elemtype; // 定义顺序表中元素的类型
// Dnode为结点，DLinkList为双链表
typedef struct DNode
{
    Elemtype data;              // 数据域
    struct DNode *prior, *next; // 前驱和后继指针
} DNode, *DLinkList;

// 初始化双链表
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode)); // 分配一个头结点
    if (L == NULL)
    { // 内存不足，分配失败
        return false;
    }
    L->prior = NULL; // 头结点的prior永远指向NULL
    L->next = NULL;  // 头结点之后暂时还没有结点
    return true;
}

// 判断双链表是否为空
bool Empty(DLinkList L)
{
    if (L->next == NULL) // 空表
        return true;
    else
        return false;
}

// 后插操作，在p结点之后插入s结点
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL) // 非法参数
        return false;
    s->next = p->next;   // 将结点s插入到结点p之后
    if (p->next != NULL) // 如果p结点有后继结点
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

// 前插操作，在p结点之前插入s结点
bool InsertPriorDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL) // 非法参数
        return false;
    if (p->prior == NULL) // p结点没有前驱
        return false;
    s->prior = p->prior; // 将结点s插入到结点p之前
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return true;
}

// 删除p结点的后继结点q
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL) // 非法参数
        return false;
    DNode *q = p->next; // 令q指向被删除结点
    if (q == NULL)      // p结点没有后继
        return false;
    p->next = q->next;   // 将q结点从链中断开
    if (q->next != NULL) // q结点不是最后一个结点
        q->next->prior = p;
    free(q); // 释放结点空间
    return true;
}

// 删除p结点的前驱结点q
bool DeletePriorDNode(DNode *p)
{
    if (p == NULL) // 非法参数
        return false;
    DNode *q = p->prior; // 令q指向被删除结点
    if(q == NULL) // p结点没有前驱
        return false;
    p->prior =q->prior; // 将q结点从链中断开
    if(q->prior != NULL) // q结点不是第一个结点
        q->prior->next = p;
    free(q); // 释放结点空间
    return true;
}

// 销毁双链表
void DestroyList(DLinkList &L){
    // 循环释放各个数据结点
    while(L->next!= NULL)
        DeleteNextDNode(L);
    free(L); // 释放头结点
    L = NULL; // 头指针指向NULL
}


int main()
{
    return 0;
}