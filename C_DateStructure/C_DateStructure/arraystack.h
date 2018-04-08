#include "PublicBase.h"
/*
˳��ջ
*/
typedef struct stack
{
	int *top;//ջ��
	int *date;//������--˳��ջ��������
	int length;//ջ����
}ArrayStack;
//�ռ����ʧ��
int NodeAllocFailure()
{
	printf("���ռ����ʧ�ܣ�");
	system("pause");
	exit(ERROR);
}
//��ʼ��һ��ջ
int InitStruck(ArrayStack * s);
//����ջ
int DestroyStack(ArrayStack *);
//�ж��Ƿ�Ϊ��ջ
int StackEmpty(ArrayStack *);
//���ջ
int ClearStack(ArrayStack *);
//����ջ��Ԫ��
int GetTop(ArrayStack S, int);
//������Ԫ��
int Push(ArrayStack *, int);
//ɾ��ջ��Ԫ��
int Pop(ArrayStack *);
//��ջ�׵�ջ���Դ˶�ջ��Ԫ�ص���visit
int StackTraverse(ArrayStack *);
//����һ���µ����鳤��
int DilatationList(ArrayStack *);

#pragma once
