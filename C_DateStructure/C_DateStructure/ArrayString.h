#pragma once
/*
˳�򴮵�ʵ��
*/
#define ERROR 0
#define OK 1
#define init_size 100
#define add_size 10
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MaxSize 100
typedef struct
{
	char date[MaxSize];//�洢�ַ���
	unsigned int len;//��ǰ����
}SqString;
//
SqString StrAssign(SqString *s, char *cstr);
//���ַ���s���Ƹ�t
void StrCopy(SqString *s, SqString *t);
//�ж��ַ����Ƿ����
int StrEqual(SqString *s, SqString *t);
//�󴮳�
int StrLength(SqString *s);
//���������������������´�
SqString *Concat(SqString *s, SqString *t);
//���شӵ�i���ַ�������J���ַ���ɵ��Ӵ�
SqString *SubStr(SqString *s, int i, int j);
//����2���뵽��1�ĵ�i���ַ�ǰ,���ز������´�
SqString *InsStr(SqString *s, SqString *t);
//ɾ���ӵ�i���ַ�������J���ַ���ɵ��Ӵ�,�����´�
SqString *DelStr(SqString *s, int i, int j);
//�ӵ�i��Ԫ��������j��Ԫ�ص��Ӵ���t����
SqString *RepStr(SqString *s, int i, int j, SqString *t);
//���ȫ��Ԫ��
void DispString(SqString *s);