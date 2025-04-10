#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 10

typedef int Elemtype;
typedef struct {
    Elemtype data[MAXSIZE];//静态数组存放队列元素
    int front,rear;//队头指针和队尾指针
    //int size;//可以避免牺牲一个存储单元。第一种方式：记录队列当前长度
    //int tag = 0;//第二种方式：标志位，默认为0，队列为空，1为非空
}SqQueue;

//初始化一个空队列
/*  Q:传入的顺序队列  */
void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;//初始时front和rear值为0，队列为空
    //第一种方式：记录队列当前长度
    //Q.size = 0;
    //第二种方式：标志位
    //Q.tag = 0;
}

//判断队列是否为空
/*  Q:传入的顺序队列  */
bool QueueEmpty(SqQueue Q){
    if(Q.front == Q.rear)
        return true;
    else
        return false;
    //第一种方式：记录队列当前长度
    //if (Q.size == 0); 
    //  return true;
    //第二种方式：标志位
    //if(Q.front == Q.rear && Q.tag == 0)
    //  return true;
}

//入队
/*  Q:传入的顺序队列  x:传入的元素  */
bool EnQueue(SqQueue &Q,Elemtype x){
    if((Q.rear + 1) % MAXSIZE == Q.front)//队满
        return false; 
    //第一种方式：记录队列当前长度
    //if(Q.size == MAXSIZE)  
    //  return false;  
    //第二种方式：标志位
    //if(Q.front == Q.rear && Q.tag == 1)
    //  return false;    
    Q.data[Q.rear] = x;//新元素插入队尾
    Q.rear = (Q.rear + 1) % MAXSIZE;//更新队尾指针，加1取模
    //第一种方式：记录队列当前长度
    //Q.size++;
    //第二种方式：标志位
    //Q.tag = 1;
    return true;
}

//出队
/*  Q:传入的顺序队列  x:传出的元素  */
bool DeQueue(SqQueue &Q,Elemtype &x){
    if(QueueEmpty(Q))//队空
        return false;
    x = Q.data[Q.front];//保存队头元素
    Q.front = (Q.front + 1) % MAXSIZE;//更新队头指针，加1取模
    //第一种方式：记录队列当前长度
    //Q.size--;
    //第二种方式：标志位
    //Q.tag = 0;
    return true;
}

//获取队头元素
/*  Q:传入的顺序队列  x:传出的元素  */
bool GetHead(SqQueue Q,Elemtype &x){
    if(Q.front == Q.rear)//队空
        return false;
    x = Q.data[Q.front];//保存队头元素
    return true;
}

int main(){
    SqQueue Q;
    InitQueue(Q);
    return 0;
}