//链栈
#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;//定义栈元素类型
typedef struct StackNode{
    ElemType data;//数据域
    struct StackNode *next;//指针域
}*LinkStack;//链栈类型

//初始化链栈
/*  S:栈顶指针    */
bool Initstack(LinkStack &S){
    S = NULL;
    return true;
}

//判断链栈是否为空
/*  S:栈顶指针    */
bool StackEmpty(LinkStack S){
    if(S == NULL){
        return true; 
    }
    else{
        return false;
    }
}

//入栈
/*  S:栈顶指针    e:传入的元素    */
bool Push(LinkStack &S,ElemType e){
    LinkStack p = (LinkStack)malloc(sizeof(StackNode));//分配内存
    if(p == NULL){
        return false;//内存分配失败
    }
    p->data = e;//存入新元素
    p->next = S->next;// 新节点指向原栈顶
    S = p; //栈顶指针指向新结点 
    return true;
}

//出栈
/*  S:栈顶指针    e:传出的元素    */
bool Pop(LinkStack &S,ElemType &e){
    if(S == NULL){
        return false;//栈空，无法出栈
    }
    LinkStack p = S;//p指向栈顶结点
    e = p->data;//取出栈顶元素
    S = p->next;//栈顶指针指向下一个结点
    free(p);//释放原栈顶结点的内存
    return true;
}

//取栈顶元素
/*  S:栈顶指针    e:传出的元素    */
bool GetTop(LinkStack S,ElemType &e){
    if(S == NULL){
        return false;//栈空，无法取栈顶元素
    } 
    e = S->data;//取出栈顶元素
    return true;
}

int main(){
    LinkStack S; //定义链栈指针并初始化
    Initstack(S); //初始化链栈  
    return 0;
}