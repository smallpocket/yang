#pragma once
//����ͷ�ļ��Ķ���
#include "PublicBase.h"
/**
*˳���
*��һ������������˳����ʱ��ʹ����date[100]��������ʽ��ʵ����Ӧ��ʹ��һ��ָ��
*���ʹ�������ͷ����һ��malloc����������������޸ĵ���ֵ����
*/
typedef struct arraylist
{
	int *date;//����ָ��
	int nowlength;//��ǰ��˳�����
	int maxlength;//����˳�����
}ArrayList;
//����һ���µ����鳤��
int DilatationList(ArrayList *list);
//����յ�˳���
int InitLinkList(ArrayList *);
/*�������������һ���յ����Ա�*/

int DestroyList(ArrayList *);
/*��ʼ���������Ա�L�Ѵ���*/
/*����������������Ա�L*/

int ClearList(ArrayList *);
/*��ʼ���������Ա�L�Ѵ���*/
/*�����������L����Ϊ�ձ�*/

int ListEmpty(ArrayList *);
/*��ʼ���������Ա�L�Ѵ���*/
/*�����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE*/

int ListLength(ArrayList *);
/*��ʼ���������Ա�L�Ѵ���*/
/*�������������L������Ԫ�ظ���*/

int GetElem(ArrayList *, int);
/*��ʼ���������Ա�L�Ѵ���,1��i��maxlength*/
/*�������������L�е�i������Ԫ�ص�ֵ*/

int LocatElem(ArrayList *, int);
/*��ʼ���������Ա�L�Ѵ���*/
/*�������������L�е�1����e��ȵ�����Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�-1*/

int PriorElem(ArrayList *, int);
/*��ʼ���������Ա�L�Ѵ���*/
/*���������ȡ��˳���L�е�i��Ԫ�ص�ǰ�����������ʧ��*/

int NextElem(ArrayList *, int);
/*��ʼ���������Ա�L�Ѵ���*/
/*���������ȡ��˳���L�е�i��Ԫ�صĺ�̣��������ʧ��*/

int ListInsert(ArrayList *, int, int);
/*��ʼ���������Ա�L�Ѵ���*/
/*�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1*/

int ListDelete(ArrayList *, int, int);
/*��ʼ���������Ա�L�Ѵ���*/
/*���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1*/