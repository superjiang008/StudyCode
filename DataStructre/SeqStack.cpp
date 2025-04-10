// 顺序栈
#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 100   // 定义顺序栈的最大长度
typedef int Elemtype; // 定义元素类型为整型

typedef struct
{
    Elemtype data[MAXSIZE]; // 静态数组存放栈中元素
    int top;                // 栈顶指针
} SqStack;                  // 顺序栈类型定义

typedef struct
{
    Elemtype *data; // 动态数组存放栈中元素
    int top0;       // 0号栈顶指针
    int top1;       // 1号栈顶指针
} ShStack;          // 共享栈定义

// 初始化一个顺序栈
/*  S:传入的顺序栈  */
void InitStack(SqStack &S)
{
    S.top = -1; // 初始化栈顶指针
}

// 初始化一个共享栈
/*  S:传入的共享栈  */
void InitShareStack(ShStack &S)
{
    S.top0 = -1;      // 0号栈顶指针
    S.top1 = MAXSIZE; // 1号栈顶指针
}
// 判断顺序栈是否为空
/*  S:传入的顺序栈  */
bool StackEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 判断共享栈是否为空
/*  S:传入的共享栈  */
bool ShareStackEmpty(ShStack S)
{
    if (S.top0 == -1 && S.top1 == MAXSIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 入栈操作
/*  S:传入的顺序栈  x:传入的入栈元素    */
bool Push(SqStack &S, Elemtype x)
{
    if (S.top == MAXSIZE - 1)
    { // 栈满，报错
        return false;
    }
    S.data[++S.top] = x; // 先将栈顶指针加1，再将元素x赋值给栈顶元素
    return true;
}

// 共享栈入栈操作
/*  S:传入的共享栈  x:传入的入栈元素    stackNum:栈号*/
bool ShareStackPush(ShStack &S, Elemtype x, int stackNum)
{
    if (S.top0 + 1 == S.top1)
    { // 栈满，报错
        return false;
    }
    if (stackNum == 0)
    {                         // 0号栈入栈
        S.data[++S.top0] = x; // 先将0号栈顶指针加1，再将元素x赋值给0号栈顶元素
    }
    else if (stackNum == 1)
    {                         // 1号栈入栈
        S.data[--S.top1] = x; // 先将1号栈顶指针减1，再将元素x赋值给1号栈顶元素
    }
    return true;
}

// 出栈操作
/*  S:传入的顺序栈  x:传出的出栈元素    */
bool Pop(SqStack &S, Elemtype &x)
{
    if (S.top == -1)
    { // 栈空，报错
        return false;
    }
    x = S.data[S.top--]; // 先将栈顶元素赋值给x，再将栈顶指针减1
    return true;
}

// 共享栈出栈操作
/*  S:传入的共享栈  x:传出的出栈元素    stackNum:栈号*/
bool ShareStackPop(ShStack &S, Elemtype &x, int stackNum)
{
    if (stackNum == 0)
    { // 0号栈出栈
        if (S.top0 == -1)
        { // 0号栈空，报错
            return false;
        }
        x = S.data[S.top0--]; // 先将0号栈顶元素赋值给x，再将0号栈顶指针减1
    }
    else if (stackNum == 1)
    { // 1号栈出栈
        if (S.top1 == MAXSIZE)
        { // 1号栈空，报错
            return false;
        }
        x = S.data[S.top1++]; // 先将1号栈顶元素赋值给x，再将1号栈顶指针加1
    }
    return true;
}

// 读栈顶元素
/*  S:传入的顺序栈  x:栈顶元素*/
bool GetTop(SqStack S, Elemtype &x)
{
    if (S.top == -1)
    { // 栈空，报错
        return false;
    }
    x = S.data[S.top]; // 将栈顶元素赋值给x
    return true;
}

// 读共享栈顶元素
/*  S:传入的共享栈  x:栈顶元素    stackNum:栈号*/
bool ShareStackGetTop(ShStack S, Elemtype &x, int stackNum)
{
    if (stackNum == 0)
    { // 0号栈读栈顶元素
        if (S.top0 == -1)
        { // 0号栈空，报错
            return false;
        }
        x = S.data[S.top0]; // 将0号栈顶元素赋值给x
    }
    else if (stackNum == 1)
    { // 1号栈读栈顶元素
        if (S.top1 == MAXSIZE)
        { // 1号栈空，报错
            return false;
        }
        x = S.data[S.top1]; // 将1号栈顶元素赋值给x
    }
    return true;
}

// 销毁一个顺序栈
/*  S:传入的顺序栈  */
void DestroyStack(SqStack &S)
{
    free(S.data); // 释放内存空间
}

// 栈的应用：括号匹配
/* str[]: 要检查的字符串   length: 字符串长度 */
bool bracketCheck(char str[], int length)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Push(S, str[i]); // 扫描到左括号，入栈
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (StackEmpty(S))
            {
                return false; // 扫描到右括号，但栈空，匹配失败
            }
            Elemtype topElem;
            Pop(S, topElem);
            if (str[i] == ')' && topElem != '(')
            {
                return false;
            }
            if (str[i] == ']' && topElem != '[')
            {
                return false;
            }
            if (str[i] == '}' && topElem != '{')
            {
                return false;
            }
        }
        // 其他字符直接忽略
    }
    return StackEmpty(S); // 最后检查栈是否为空
}

// 不使用栈的括号匹配
/* str[]: 要检查的字符串   length: 字符串长度 */
bool bracketCheckNoStack(char str[], int length)
{
    int count1 = 0; // 小括号 () 计数
    int count2 = 0; // 中括号 [] 计数
    int count3 = 0; // 大括号 {} 计数

    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(')
            count1++;
        else if (str[i] == '[')
            count2++;
        else if (str[i] == '{')
            count3++;
        else if (str[i] == ')')
        {
            count1--;
            if (count1 < 0)
                return false; // 右括号多于左括号
        }
        else if (str[i] == ']')
        {
            count2--;
            if (count2 < 0)
                return false; // 右括号多于左括号
        }
        else if (str[i] == '}')
        {
            count3--;
            if (count3 < 0)
                return false; // 右括号多于左括号
        }
        // 其他字符直接忽略
    }

    // 检查所有括号是否都配对完成
    return (count1 == 0 && count2 == 0 && count3 == 0);
}

// 数组模拟一个栈
bool bracketCheckArr(char str[], int length)
{
    char Data[MAXSIZE]; // 静态数组存放栈中元素
    int top = -1;       // 栈顶指针
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Data[++top] = str[i];
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (top == -1)
            {
                return false;
            }
            if (str[i] == ')' && Data[top] != '(')
            {
                return false;
            }
            if (str[i] == ']' && Data[top] != '[')
            {
                return false;
            }
            if (str[i] == '}' && Data[top] != '{')
            {
                return false;
            }
            top--;
        }
    }
    return top == -1;
}

// 栈的应用：中缀表达式转后缀表达式
/* str[]: 中缀表达式   length: 字符串长度   backer[]: 存放后缀表达式 */
bool infixToPostfix(char str[], int length, char backer[])
{
    SqStack S;
    InitStack(S); // 初始化栈
    int j = 0;    // 后缀表达式下标

    for (int i = 0; i < length; i++)
    {
        // 如果是数字，直接添加到后缀表达式
        if (str[i] >= '0' && str[i] <= '9')
        {
            backer[j++] = str[i];
        }
        // 如果是左括号，直接入栈
        else if (str[i] == '(')
        {
            Push(S, str[i]);
        }
        // 如果是右括号，弹出栈中元素直到遇到左括号
        else if (str[i] == ')')
        {
            Elemtype topElem;
            while (!StackEmpty(S))
            {
                Pop(S, topElem);
                if (topElem == '(')
                    break;
                backer[j++] = topElem;
            }
        }
        // 如果是运算符
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            // 当前运算符优先级较低，需要先弹出栈中高优先级运算符
            while (!StackEmpty(S))
            {
                Elemtype topElem;
                GetTop(S, topElem);
                if (topElem == '(' ||
                    ((str[i] == '*' || str[i] == '/') && (topElem == '+' || topElem == '-')))
                {
                    break; // 栈顶是左括号或当前运算符优先级更高，停止弹出
                }
                Pop(S, topElem);
                backer[j++] = topElem;
            }
            // 当前运算符入栈
            Push(S, str[i]);
        }
    }
    // 处理栈中剩余的运算符
    while (!StackEmpty(S))
    {
        Elemtype topElem;
        Pop(S, topElem);
        if (topElem != '(') // 忽略左括号
            backer[j++] = topElem;
    }
    backer[j] = '\0'; // 添加字符串结束符
    return true;
}

// 栈的应用：后缀表达式求值
/* str[]: 后缀表达式   length: 字符串长度 */
int evaluatePostfix(char str[], int length)
{
    SqStack S;
    InitStack(S); // 初始化栈
    for (int i = 0; i < length; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            Push(S, str[i] - '0'); // 将数字字符转换为整数并入栈
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            int operand2, operand1;
            Pop(S, operand2); // 弹出第二个操作数
            Pop(S, operand1); // 弹出第一个操作数
            // 根据运算符进行运算
            switch (str[i])
            {
            case '+':
                Push(S, operand1 + operand2);
                break;
            case '-':
                Push(S, operand1 - operand2);
                break;
            case '*':
                Push(S, operand1 * operand2);
                break;
            case '/':
                Push(S, operand1 / operand2);
                break;
            }
        }
    }
    int result;
    Pop(S, result); // 弹出最终结果
    return result;
}

// 栈的应用：中缀表达式求值
/* str[]: 中缀表达式   length: 字符串长度 */
int evaluateInfix(char str[], int length)
{
    SqStack S1;
    InitStack(S1); // 初始化栈，用于存放操作数
    SqStack S2;
    InitStack(S2); // 初始化栈，用于存放运算符
    for (int i = 0; i < length; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            Push(S1, str[i] - '0'); // 将数字字符转换为整数压入操作数栈
        }
        else if (str[i] == '(')
        {
            Push(S2, str[i]); // 左括号直接压入运算符栈
        }
        else if (str[i] == ')')
        {
            while (!StackEmpty(S2))
            {
                Elemtype topElem;    // 用于存放运算符栈顶元素
                GetTop(S2, topElem); // 获取运算符栈顶元素
                if (topElem == '(')
                {
                    Pop(S2, topElem); // 弹出左括号
                    break;
                }

                // 执行括号内的运算
                Pop(S2, topElem); // 弹出运算符
                int operand2, operand1;
                Pop(S1, operand2); // 弹出第二个操作数
                Pop(S1, operand1); // 弹出第一个操作数

                // 根据运算符进行运算
                switch (topElem)
                {
                case '+':
                    Push(S1, operand1 + operand2);
                    break;
                case '-':
                    Push(S1, operand1 - operand2);
                    break;
                case '*':
                    Push(S1, operand1 * operand2);
                    break;
                case '/':
                    Push(S1, operand1 / operand2);
                    break;
                }
            }
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            while (!StackEmpty(S2))
            {
                Elemtype topElem;    // 用于存放运算符栈顶元素
                GetTop(S2, topElem); // 获取运算符栈顶元素
                if (topElem == '(' || ((str[i] == '*' || str[i] == '/') && (topElem == '+' || topElem == '-')))
                {
                    break; // 栈顶是左括号或当前运算符优先级更高，停止弹出
                }

                Pop(S2, topElem); // 弹出运算符
                int operand2, operand1;
                Pop(S1, operand2); // 弹出第二个操作数
                Pop(S1, operand1); // 弹出第一个操作数

                // 根据运算符进行运算
                switch (topElem)
                {
                case '+':
                    Push(S1, operand1 + operand2);
                    break;
                case '-':
                    Push(S1, operand1 - operand2);
                    break;
                case '*':
                    Push(S1, operand1 * operand2);
                    break;
                case '/':
                    Push(S1, operand1 / operand2);
                    break;
                }
            }

            // 当前运算符入栈
            Push(S2, str[i]);
        }
    }

    // 处理栈中剩余的运算符
    while (!StackEmpty(S2))
    {
        Elemtype topElem;
        Pop(S2, topElem); // 弹出运算符

        if (topElem == '(')
            continue; // 忽略剩余的左括号

        int operand2, operand1;
        Pop(S1, operand2); // 弹出第二个操作数
        Pop(S1, operand1); // 弹出第一个操作数

        // 根据运算符进行运算
        switch (topElem)
        {
        case '+':
            Push(S1, operand1 + operand2);
            break;
        case '-':
            Push(S1, operand1 - operand2);
            break;
        case '*':
            Push(S1, operand1 * operand2);
            break;
        case '/':
            Push(S1, operand1 / operand2);
            break;
        }
    }

    int result;
    Pop(S1, result); // 弹出最终结果
    return result;
}

int main()
{
    SqStack S;                                                // 声明一个顺序栈
    InitStack(S);                                             // 初始化一个顺序栈
    char bracketstr[] = "([)]";                               // 要检查的字符串
    int lengthB = sizeof(bracketstr) / sizeof(bracketstr[0]); // 字符串长度
    bool result = bracketCheck(bracketstr, lengthB);          // 括号匹配
    printf("%d\n", result);                                   // 输出结果

    char fixstr[] = "3+2*(1+2)";                      // 要运算的表达式
    char backer[MAXSIZE];                             // 用于存放后缀表达式的数组
    int lengthF = sizeof(fixstr) / sizeof(fixstr[0]); // 表达式长度
    infixToPostfix(fixstr, lengthF, backer);          // 中缀表达式转后缀表达式
    printf("%s\n", backer);                           // 打印后缀表达式
    int resultF = evaluatePostfix(backer, lengthF);   // 后缀表达式求值
    printf("%d\n", resultF);                          // 打印结果

    int resultI = evaluateInfix(fixstr, lengthF); // 中缀表达式求值
    printf("%d\n", resultI);                      // 打印结果
    return 0;
}