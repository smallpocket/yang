#pragma once
/*
�Ѵ���ʵ��
��˳�򴮵�����Ϊ�Ѵ�Ϊ��̬����
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
	char *ch;//�洢�ַ���
	unsigned int len;//��ǰ����
}HSring;
//
HSring StrAssign(char *cstr);
//���ַ���s���Ƹ�t
void StrCopy(HSring *s, HSring *t);
//�ж��ַ����Ƿ����
int StrEqual(HSring *s, HSring *t);
//�󴮳�
int StrLength(HSring *s);
//���������������������´�
HSring *Concat(HSring *s, HSring *t);
//���شӵ�i���ַ�������J���ַ���ɵ��Ӵ�
HSring *SubStr(HSring *s, int i, int j);
//����2���뵽��1�ĵ�i���ַ�ǰ,���ز������´�
HSring *InsStr(HSring *s, HSring *t);
//ɾ���ӵ�i���ַ�������J���ַ���ɵ��Ӵ�,�����´�
HSring *DelStr(HSring *s, int i, int j);
//�ӵ�i��Ԫ��������j��Ԫ�ص��Ӵ���t����
HSring *RepStr(HSring *s, int i, int j, HSring *t);
//���ȫ��Ԫ��
void DispString(HSring *s);