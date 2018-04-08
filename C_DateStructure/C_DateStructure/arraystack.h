#include "PublicBase.h"
/*
顺序栈
*/
typedef struct stack
{
	int *top;//栈顶
	int *date;//数据域--顺序栈基于数组
	int length;//栈长度
}ArrayStack;
//空间分配失败
int NodeAllocFailure()
{
	printf("结点空间分配失败！");
	system("pause");
	exit(ERROR);
}
//初始化一个栈
int InitStruck(ArrayStack * s);
//销毁栈
int DestroyStack(ArrayStack *);
//判断是否为空栈
int StackEmpty(ArrayStack *);
//清空栈
int ClearStack(ArrayStack *);
//返回栈顶元素
int GetTop(ArrayStack S, int);
//插入新元素
int Push(ArrayStack *, int);
//删除栈顶元素
int Pop(ArrayStack *);
//从栈底到栈顶以此对栈的元素调用visit
int StackTraverse(ArrayStack *);
//增加一个新的数组长度
int DilatationList(ArrayStack *);

#pragma once
