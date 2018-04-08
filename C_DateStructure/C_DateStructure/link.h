#pragma once
#include "PublicBase.h"
/*
链表
*/
//链表节点定义
typedef struct link
{
	int data;//数据域
	struct link *next;//next
}Lnode;
//链表定义
typedef struct linklist
{
	Lnode *head, *tail;  //头指针和尾指针
	int len;            //表长
}LinkList;  //TODO:如果说我的LinkList写作了linklist会不会有问题

//故障函数
//内存空间分配失败时调用
int NodeAllocFailure();
//为p分配结点空间，并赋值为e
Lnode * MakeNode(int e);
//输出一个节点的值
void visit(Lnode *e);
//释放（删除）p所指链表结点
Lnode * FreeNode(Lnode *p);
//构造一个带头结点的空链表L
LinkList * InitList_L(LinkList *L);
//销毁一个带头结点的链表L
LinkList * DestroyList_L(LinkList *L);
//清空一个带头结点的链表L
void ClearList_L(LinkList *L);
//将s所指结点作为首结点插入到带头结点的链表L中
void InsFirst(LinkList *L, Lnode *s);
//删除一个带头结点的链表L的首结点
int DelFirst(LinkList *L);
//将s所指结点附加在一个带头结点的链表L的末尾
void Append(LinkList *L, Lnode *s);
//删除一个带头结点的链表L的尾结点
int Remove(LinkList *L);
//在一个带头结点的链表L中将s所指结点插入在p所指表中结点前
void InsBefore(LinkList *L, Lnode *p, Lnode *s);
//在一个带头结点的链表L中将s所指结点插入在p所指表中结点后
void InsAfter(LinkList *L, Lnode *p, Lnode *s);
//将p所指表结点的值更新为e
void SetCurElem(Lnode *p, int e);
//取出链表中p所指结点的值
int GetCurElem_L(Lnode *p);
//判断链表是否为空
int ListEmpty_L(LinkList *L);
//求带头结点的链表L中p所指结点的直接前驱
Lnode * PriorPos(LinkList *L, Lnode *p);
//求带头结点的链表L中第i个结点的位置
Lnode * LocatePos(LinkList *L, int i);
//遍历带头结点的链表
void ListTraverse_L(LinkList *L);