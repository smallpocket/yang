//0302020．c括号匹配的检验
#include<stdio.h>
#include<stdlib.h>
#define StackInitSize 100//存储空间初始分配量
#define Stacklncrement 10//存储空间分配增量
#define Overflow -1
#define Underflow -2
typedef struct stack
{
	char*bottom;//用于指示栈体空间
	char*top;	//栈顶指针
	int stacksize;//当前栈空间大小，以元素为单位
}SqStack;
SqStack ST;//将栈设为全局变量

voidInitStack(SqStack *s)//插入元素e为新的栈顶元
{
	s->bottom = (char*)malloc(StackInitSize * sizeof(char));
	if (!s->bottom)
		exit(Overflow);
	s->top = s->bottom;
	s->stacksize = StackInitSize;
}
void Push(SqStack*s, char e)
{
	if (s->top - s->bottom >= s->stacksize)
	{
		s->bottom = (char *)realloc(s->bottom,//栈满，扩容
			(s->stacksize + Stacklncrement) * sizeof(char));
		if (!s->bottom)exit(Overflow);//分配失败
		s->top = s->bottom + s->stacksize;
		s->stacksize += Stacklncrement;;
	}
	*(s->top++) = e;//进栈
}

charPop(SqStack *s)
{
	if (s->top == s->bottom)
		exit(Underflow);
	return *(--s->top);
}
void DetectExp(void)//检验表达式括号匹配
{
	char *exp = (char *)calloc(StackInitSize, sizeof(char));
	char *p = exp, t;
	InitStack(&ST);
	printf("请输入一个包含圆/方括号的表达式：\n");
	scanf_s("%s", exp, StackInitSize);
	while (*p)
	{
		if (*p == '(' || *p == '[')Push(&ST, *p++);
		else if (*p == ')'&&Pop(&ST) == '(' ||
			*p == ']'&&Pop(&ST) == '[' ||
			*p == '）'&&*p != ']')
			p++;
		else {
			puts("表达式括号不匹配！\n");
			free(exp);
			return;
		}
	}

	if (ST.bottom == ST.top)puts("表达式括号匹配！\n");
	else puts("表达式括号不匹配！\n");
	printf("\n");
	free(exp);
}
//k+c,k+u
//void main()
//{
//	DetectExp();
//	system("pause");
//}
