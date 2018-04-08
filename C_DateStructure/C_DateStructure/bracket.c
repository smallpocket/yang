//0302020��c����ƥ��ļ���
#include<stdio.h>
#include<stdlib.h>
#define StackInitSize 100//�洢�ռ��ʼ������
#define Stacklncrement 10//�洢�ռ��������
#define Overflow -1
#define Underflow -2
typedef struct stack
{
	char*bottom;//����ָʾջ��ռ�
	char*top;	//ջ��ָ��
	int stacksize;//��ǰջ�ռ��С����Ԫ��Ϊ��λ
}SqStack;
SqStack ST;//��ջ��Ϊȫ�ֱ���

voidInitStack(SqStack *s)//����Ԫ��eΪ�µ�ջ��Ԫ
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
		s->bottom = (char *)realloc(s->bottom,//ջ��������
			(s->stacksize + Stacklncrement) * sizeof(char));
		if (!s->bottom)exit(Overflow);//����ʧ��
		s->top = s->bottom + s->stacksize;
		s->stacksize += Stacklncrement;;
	}
	*(s->top++) = e;//��ջ
}

charPop(SqStack *s)
{
	if (s->top == s->bottom)
		exit(Underflow);
	return *(--s->top);
}
void DetectExp(void)//������ʽ����ƥ��
{
	char *exp = (char *)calloc(StackInitSize, sizeof(char));
	char *p = exp, t;
	InitStack(&ST);
	printf("������һ������Բ/�����ŵı��ʽ��\n");
	scanf_s("%s", exp, StackInitSize);
	while (*p)
	{
		if (*p == '(' || *p == '[')Push(&ST, *p++);
		else if (*p == ')'&&Pop(&ST) == '(' ||
			*p == ']'&&Pop(&ST) == '[' ||
			*p == '��'&&*p != ']')
			p++;
		else {
			puts("���ʽ���Ų�ƥ�䣡\n");
			free(exp);
			return;
		}
	}

	if (ST.bottom == ST.top)puts("���ʽ����ƥ�䣡\n");
	else puts("���ʽ���Ų�ƥ�䣡\n");
	printf("\n");
	free(exp);
}
//k+c,k+u
//void main()
//{
//	DetectExp();
//	system("pause");
//}
