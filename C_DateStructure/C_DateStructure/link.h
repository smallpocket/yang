#pragma once
#include "PublicBase.h"
/*
����
*/
//����ڵ㶨��
typedef struct link
{
	int data;//������
	struct link *next;//next
}Lnode;
//������
typedef struct linklist
{
	Lnode *head, *tail;  //ͷָ���βָ��
	int len;            //��
}LinkList;  //TODO:���˵�ҵ�LinkListд����linklist�᲻��������

//���Ϻ���
//�ڴ�ռ����ʧ��ʱ����
int NodeAllocFailure();
//Ϊp������ռ䣬����ֵΪe
Lnode * MakeNode(int e);
//���һ���ڵ��ֵ
void visit(Lnode *e);
//�ͷţ�ɾ����p��ָ������
Lnode * FreeNode(Lnode *p);
//����һ����ͷ���Ŀ�����L
LinkList * InitList_L(LinkList *L);
//����һ����ͷ��������L
LinkList * DestroyList_L(LinkList *L);
//���һ����ͷ��������L
void ClearList_L(LinkList *L);
//��s��ָ�����Ϊ�׽����뵽��ͷ��������L��
void InsFirst(LinkList *L, Lnode *s);
//ɾ��һ����ͷ��������L���׽��
int DelFirst(LinkList *L);
//��s��ָ��㸽����һ����ͷ��������L��ĩβ
void Append(LinkList *L, Lnode *s);
//ɾ��һ����ͷ��������L��β���
int Remove(LinkList *L);
//��һ����ͷ��������L�н�s��ָ��������p��ָ���н��ǰ
void InsBefore(LinkList *L, Lnode *p, Lnode *s);
//��һ����ͷ��������L�н�s��ָ��������p��ָ���н���
void InsAfter(LinkList *L, Lnode *p, Lnode *s);
//��p��ָ�����ֵ����Ϊe
void SetCurElem(Lnode *p, int e);
//ȡ��������p��ָ����ֵ
int GetCurElem_L(Lnode *p);
//�ж������Ƿ�Ϊ��
int ListEmpty_L(LinkList *L);
//���ͷ��������L��p��ָ����ֱ��ǰ��
Lnode * PriorPos(LinkList *L, Lnode *p);
//���ͷ��������L�е�i������λ��
Lnode * LocatePos(LinkList *L, int i);
//������ͷ��������
void ListTraverse_L(LinkList *L);