//顺序表
#include "stdio.h"
#include "stdlib.h"
#define InitSize 10   // 初始化的默认大小
typedef int Elemtype; // 定义顺序表中元素的类型
typedef struct
{
    Elemtype *data; // 指示动态分配数组的指针
    int MaxSize;    // 顺序表最大容量
    int length;     // 顺序表当前长度
} SqList;           // 顺序表的类型定义

// 静态分配初始化顺序表，分配内存空间
/*  L:传入的顺序表  */
void InitListstastic(SqList &L)
{
    for (int i = 0; i < InitSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}

// 动态分配初始化顺序表，分配内存空间
/*  L:传入的顺序表  */
void InitListmdynamic(SqList &L)
{
    L.data = (Elemtype *)malloc(sizeof(Elemtype) * InitSize); // 开辟内存空间，并将首地址赋给data
    L.length = 0;                                             // 当前长度为0
    L.MaxSize = InitSize;                                     // 最大容量为InitSize
}
// 增加动态数组的长度
/*  len:需要拓展的长度  L:传入的顺序表  */
void IncreaseSize(SqList &L, int len)
{
    Elemtype *p = L.data;                                              // 定义一个指针指向顺序表的首地址
    L.data = (Elemtype *)malloc(sizeof(Elemtype) * (L.MaxSize + len)); // 分配内存空间
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i]; // 将原来的元素复制到新的内存空间
    }
    L.MaxSize = L.MaxSize + len; // 最大容量增加len
    free(p);                     // 释放原来的内存空间
}
// 销毁顺序表，释放内存空间
/*  L:传入的顺序表  */
void DestroyList(SqList &L)
{
    free(L.data); // 释放内存空间
}
// 插入操作，在第i个位置插入元素e
/*  L:传入的顺序表  i:顺序表第i个位置   e:插入的元素e  */
bool ListInsert(SqList &L, int i, Elemtype e)
{
    if (i < 1 || i > L.length + 1)
        return false; // 检查i的范围是否合法
    if (L.length >= L.MaxSize)
    {
        return false; // 检查顺序表是否已满
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1]; // 将第i个位置及之后的元素后移
    }
    L.data[i - 1] = e; // 将元素e插入第i个位置
    L.length++;        // 顺序表长度加1
    return true;
}
// 删除操作，删除第i个位置的元素
/*  L:传入的顺序表  i:顺序表第i个位置   e:返回删除的元素e  */
bool ListDelete(SqList &L, int i, Elemtype &e)
{
    if (i < 1 || i > L.length)
        return false;  // 检查i的范围是否合法
    e = L.data[i - 1]; // 保存被删除的元素
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j]; // 将第i个位置及之后的元素前移
    }
    L.length--; // 顺序表长度减1
    return true;
}
// 按值查找操作，查找元素e
/*  L:传入的顺序表   e:返回删除的元素e  */
void LocateElem(SqList L, Elemtype e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            printf("元素%d的位序是%d\n", e, i + 1);
            break;
        } // 找到元素，输出位序
        else
        {
            printf("元素%d不在表中\n", e);
            break;
        } // 找不到元素，输出提示
    }
}
// 按位查找操作，查找第i个位置的元素
/*  L:传入的顺序表  i:顺序表第i个位置  */
Elemtype GetElem(SqList L, int i)
{
    return L.data[i - 1]; // 按位返回第i个位置的元素
}
// 求表长，返回表中元素的个数
int Length(SqList L)
{
    return L.length; // 返回表中元素的个数
}
// 输出操作，按前后顺序输出顺序表的所有元素值
void PrintList(SqList L)
{
    for (int j = 0; j < L.length; j++)
    {
        printf("第%d个值:%d ", j+1, L.data[j]);
        printf("\n");
    }
}
// 判空操作，判断顺序表是否为空
bool Empty(SqList L)
{
    if (L.length == 0)
        return true; // 顺序表为空
}
int main()
{
    SqList L; // 声明一个顺序表
    // InitListstastic(L);//静态分配初始化顺序表
    InitListmdynamic(L);  // 动态分配初始化顺序表
    ListInsert(L, 1, 20); // 在第1个位置插入元素20
    ListInsert(L, 2, 30); // 在第2个位置插入元素30
    ListInsert(L, 3, 40); // 在第3个位置插入元素40
    PrintList(L);         // 输出顺序表的所有元素值
    int e = -1;           // 定义一个变量e，用于存储被删除的元素
    if (ListDelete(L, 2, e))
    {                                 // 删除第2个位置的元素
        printf("被删除的值:%d\n", e); // 输出被删除的元素
    }
    else
    {
        printf("位序i不合法,删除失败\n");
    }
    return 0;
}