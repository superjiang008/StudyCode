//递归算法
#include "stdio.h"
#include "stdlib.h"

//递归实现阶乘
int factorial(int n){
    if(n==1)
        return 1;
    else
        return n*factorial(n-1);
}

//递归实现斐波那契数列
int fibonacci(int n){
    if(n==1||n==2)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",factorial(n));
    printf("%d\n",fibonacci(n));
    return 0;
}