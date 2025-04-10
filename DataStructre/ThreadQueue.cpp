#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 10

typedef int Elemtype;
typedef struct LinkNode
{                          // 链式队列结点
    Elemtype data;         // 数据域
    struct LinkNode *next; // 指针域
} LinkNode;

typedef struct
{                           // 链式队列
    LinkNode *front, *rear; // 队列的队头和队尾指针
} LinkQueue;

// 初始化一个空队列(带头结点)
void InitQueue1(LinkQueue &Q)
{
    // 初始化时front和rear都指向头结点
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

// 判断队列是否为空(带头结点)
bool QueueEmpty1(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

// 初始化一个空队列(不带头结点)
void InitQueue2(LinkQueue &Q)
{
    // 初始时front和rear都指向NULL
    Q.front = Q.rear = NULL;
}

// 判断队列是否为空(不带头结点)
bool QueueEmpty2(LinkQueue Q)
{
    if (Q.front == NULL)
        return true;
    else
        return false;
}

// 入队(带头结点)
void EnQueue1(LinkQueue &Q, Elemtype x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode)); // 分配一个新结点s
    s->data = x;                                        // 将x赋值给新结点的数据域
    s->next = NULL;                                     // 将新结点的指针域置为NULL
    Q.rear->next = s;                                   // 将新结点s赋值给原队尾结点的后继
    Q.rear = s;                                         // 修改队尾指针
}

// 入队(不带头结点)
void EnQueue2(LinkQueue &Q, Elemtype x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode)); // 分配一个新结点s
    s->data = x;                                        // 将x赋值给新结点的数据域
    s->next = NULL;                                     // 将新结点的指针域置为NULL
    if (Q.front == NULL)
    {                // 在入队前，队列是空队列
        Q.front = s; // 修改队头指针
        Q.rear = s;  // 修改队尾指针
    }
    else
    {
        Q.rear->next = s; // 将新结点s赋值给原队尾结点的后继
        Q.rear = s;       // 修改队尾指针
    }
}

// 出队(带头结点)
bool DeQueue1(LinkQueue &Q, Elemtype &x)
{
    if (Q.front == Q.rear)
        return false;            // 队列空，不能出队
    LinkNode *p = Q.front->next; // p指向队头结点
    x = p->data;                 // 用变量x返回队头元素
    Q.front->next = p->next;     // 修改头结点的指针域，将其指向下一个结点
    if (Q.rear == p)             // 此次是最后一个结点出队
        Q.rear = Q.front;        // 修改队尾指针
    free(p);                     // 释放结点空间
    return true;
}

// 出队(不带头结点)
bool DeQueue2(LinkQueue &Q, Elemtype &x){
    if(Q.front == NULL)
        return false;
    LinkNode *p = Q.front;//p指向队头结点
    x = p->data;//用变量x返回队头元素
    Q.front = p->next;//修改头结点的指针域，将其指向下一个结点
    if(Q.rear == p)//此次是最后一个结点出队
        Q.front = Q.rear = NULL;//此次是最后一个结点出队
    free(p);//释放结点空间
    return true;
}

int main()
{
    LinkQueue Q;
    InitQueue1(Q);
    EnQueue1(Q, 1);
    EnQueue1(Q, 2);
    return 0;
}