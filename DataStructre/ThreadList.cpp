//链表
#include <stdlib.h>
#include <stdio.h>

typedef int Elemtype; // 定义顺序表中元素的类型
typedef struct LNode  // Lnode为结点，LinkList为单链表
{
    Elemtype data;      // 数据域，存放数据
    struct LNode *next; // 指针域，存放后继结点的地址
} LNode, *LinkList;

/*  创建不带头结点的单链表  */
/*  L:传入的单链表  */
bool InitList(LinkList &L)
{
    L = NULL; // 创建空表，暂时没有任何结点
    return true;
}

/*  判断单链表是否为空  */
/*  L:传入的单链表  */
bool empty(LinkList L)
{
    return (L == NULL);
}

// 创建带头结点的单链表
/*  L:传入的单链表  */
bool InitListNode(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); // 分配一个头结点
    if (L == NULL)
    { // 内存不足，分配失败
        return false;
    }
    L->next = NULL; // 头结点之后暂时还没有结点
    return true;
}

// 按位查找操作，带头结点的单链表
/*  L:传入的单链表  i:查找的位置  */
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    int j = 0; // 当前p指向的位置
    LNode *p;  // p指向当前扫描到的结点
    p = L;     // p指向头结点
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p; // 找到后返回该结点指针，否则返回NULL
}

// 按值查找操作，带头结点的单链表
/*  L:传入的单链表  e:查找的元素  */
LNode *LocateElem(LinkList L, Elemtype e)
{
    LNode *p = L->next; // p指向第一个结点
    while (p != NULL && p->data != e)
    {
        p = p->next; // 循环找到e相等的结点
    }
    return p; // 找到后返回该结点指针，否则返回NULL
}
// 后插操作，在p结点之后插入元素e
/*  p:传入的结点  e:插入的元素  */
bool InsertNextNode(LNode *p, Elemtype e)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *newNode = (LNode *)malloc(sizeof(Elemtype)); // 生成新结点
    if (newNode == NULL)
    { // 内存不足，分配失败
        return false;
    }
    newNode->data = e;       // 新结点的数据域为e
    newNode->next = p->next; // 新结点的指针域指向p的后继结点
    p->next = newNode;       // p的指针域指向新结点
    return true;
}

// 前插操作，在p结点之前插入元素e
/*  p:传入的结点  e:插入的元素  */
bool InsertPriorNode(LNode *p, Elemtype e)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *newNode = (LNode *)malloc(sizeof(LNode)); // 生成新结点
    if (newNode == NULL)
    { // 内存不足，分配失败
        return false;
    }
    newNode->next = p->next; // 新结点的指针域指向p的后继结点
    p->next = newNode;       // p的指针域指向新结点
    newNode->data = p->data; // 新结点的数据域为p的数据域
    p->data = e;             // p的数据域为e
    return true;
}

// 插入操作，不带头结点的单链表
/*  L:传入的单链表  i:插入的位置  e:插入的元素  */
bool ListInsert(LinkList &L, int i, Elemtype e)
{
    if (i < 1)
    {
        return false;
    }
    if (i == 1)
    { // 插入到表头
        LNode *newNode = (LNode *)malloc(sizeof(LNode));
        newNode->data = e;
        newNode->next = L;
        L = newNode;
        return true;
    }
    LNode *p;  // p指向当前扫描到的结点
    int j = 1; // 当前p指向的位置
    p = L;     // p指向头结点
    while (p != NULL && j < i - 1)
    { // 循环找到第i-1个结点
        p = p->next;
        j++;
    }
    return InsertNextNode(p, e); // 采用后插操作插入结点
}

// 插入操作，带头结点的单链表
/*  L:传入的单链表  i:插入的位置  e:插入的元素  */
bool ListInsertNode(LinkList &L, int i, Elemtype e)
{
    LNode *p = GetElem(L, i - 1); // 调用查找函数，找到第i-1个结点
    return InsertNextNode(p, e);  // 采用后插操作插入结点
}

// 删除操作，带头结点的单链表
/*  L:传入的单链表  i:删除的位置  e:删除的元素  */
bool ListDelete(LinkList &L, int i, Elemtype &e)
{
    LNode *p = GetElem(L, i - 1); // 调用查找函数，找到第i-1个结点
    if (p->next == NULL)
    {
        return false;
    }
    LNode *newNode = p->next; // newNode指向要删除的结点
    e = newNode->data;        // 用e返回元素的值
    p->next = newNode->next;  // 将newNode的后继赋值给p的后继
    free(newNode);            // 释放结点空间
    return true;
}

// 头插法建立单链表
/*  L:传入的单链表  */
LinkList CreateListHead(LinkList &L)
{
    Elemtype x;                          // 存放输入的数据域
    L = (LinkList)malloc(sizeof(LNode)); // 建立头结点
    L->next = NULL;                      // 将头结点的指针域置为NULL
    scanf("%d", &x);                     // 输入要存放的数据
    while (x != 9999)
    {                                              // 当输入9999时结束输入
        LNode *s = (LNode *)malloc(sizeof(LNode)); // 建立新结点
        s->data = x;                               // 将输入的数据赋值给s的数据域
        s->next = L->next;                         // 将s的后继指向头结点的后继结点
        L->next = s;                               // 将头结点的后继指向s
        scanf("%d", &x);                           // 输入下一个数据
    }
    return L; // 返回头结点
}
// 尾插法建立单链表
/*  L:传入的单链表  */
LinkList CreateListTail(LinkList &L)
{
    Elemtype x;                          // 存放输入的数据域
    L = (LinkList)malloc(sizeof(LNode)); // 建立头结点
    LNode *s, *r = L;                    // r为表尾指针
    scanf("%d", &x);                     // 输入要存放的数据
    while (x != 9999)
    { // 当输入9999时结束输入
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;     // 将输入的数据赋值给s的数据域
        r = L->next;     // 将r指向头结点的后继结点
        r = s;           // r指向新的表尾结点
        scanf("%d", &x); // 输入下一个数据
    }
    r->next = NULL; // 将尾结点的指针域置为NULL
    return L;
}

// 删除指定结点
/*  p:传入的结点  */
bool DeleteNode(LNode *p)
{
    if (p == NULL || p->next == NULL)
    { // 不能删除最后一个节点
        return false;
    }
    LNode *newNode = p->next; // newNode指向p的后继结点
    p->data = newNode->data;  // p的数据域为newNode的数据域
    p->next = newNode->next;  // p的指针域指向newNode的后继结点
    free(newNode);
    return true;
}

// 求表长
/*  L:传入的单链表  */
int Length(LinkList L)
{
    int len = 0;  // 统计表长
    LNode *p = L; // p指向当前扫描到的结点
    while (p->next != NULL)
    { // 循环直到p指向最后一个结点
        p = p->next;
        len++;
    }
    return len;
}

int main()
{
    LinkList L;
    return 0;
}