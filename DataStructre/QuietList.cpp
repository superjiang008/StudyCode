// 静态链表
#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 10    // 定义静态链表的最大长度
typedef int Elemtype; // 定义顺序表中元素的类型

// 静态链表的结点类型
typedef struct Node
{
    Elemtype data;    // 数据域
    int next;         // 游标，为0时表示无指向
} SLinkList[MAXSIZE]; // 静态链表类型

// 初始化静态链表
bool InitList(SLinkList &L)
{
    L[0].next = -1; // 第一个结点的next指向-1,表示链表为空
    for (int i = 2; i < MAXSIZE; i++)
    {
        L[i].next = -2; // 除第一个外，其余结点的next指向-2,表示节点空闲
    }
    return true;
}

// 查找操作
int LocateElem(SLinkList L, Elemtype e)
{
    int i = L[0].next; // i指向第一个结点
    while (i != -1 && L[i].data != e)
    {
        i = L[i].next; // 继续查找下一个结点
    }
    return i; // 返回结点的下标
}

// 插入操作
bool ListInsert(SLinkList &L, int i, Elemtype e)
{
    // 判断i的合法性
    if (i < 1 || i > MAXSIZE - 1)
    {
        return false; // i值不合法
    }
    // 寻找空闲结点
    int j = 1;
    while (j < MAXSIZE && L[j].next != -2)
    {
        j++; // 找到空闲结点
    }
    if (j == MAXSIZE)
    {
        return false; // 没有空闲结点
    }
    // 找到第i-1个结点的位置
    int p = 0; // 头结点的位置
    int count = 0;
    while (p != -1 && count < i - 1)
    {
        p = L[p].next; // 移动到下一个结点
        count++;
    }
    if (p == -1)
    {
        return false; // 找不到第i-1个结点
    }
    // 插入操作
    L[j].data = e;         // 在空闲结点中存入数据e
    L[j].next = L[p].next; // 新结点的next指向原来第i个结点
    L[p].next = j;         // 第i-1个结点的next指向新结点
    return true;
}
// 删除操作
bool ListDelete(SLinkList &L, int i)
{
    if (i < 1)
    {
        return false; // i值不合法
    }

    // 找到第i-1个结点的位置
    int p = 0; // 头结点的位置
    int count = 0;
    while (p != -1 && count < i - 1)
    {
        p = L[p].next; // 移动到下一个结点
        count++;
    }
    if (p == -1)
    {
        return false; // 找不到第i-1个结点
    }

    // 获取第i个结点的位置
    int q = L[p].next;
    if (q == -1)
    {
        return false; // 第i个结点不存在
    }

    // 删除操作
    L[p].next = L[q].next; // 第i-1个结点的next指向第i个结点的next
    L[q].next = -2;        // 标记为空闲结点

    return true;
}
int main()
{
    return 0;
}