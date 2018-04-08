#include"link.h"
//输出一个节点的值
void visit(Lnode *e)
{
	printf("%d", e->data);
}
//为p分配结点空间，并赋值为e
Lnode * MakeNode(int e)
{
	Lnode *p;
	if (p = (Lnode *)malloc(sizeof(Lnode)))
	{
		p->data = e;
		p->next = NULL;
		return p;
	}
	else NodeAllocFailure();
}
//释放（删除）p所指链表结点
Lnode * FreeNode(Lnode *p)
{
	Lnode *q = p->next;
	free(p);
	return q;//返回被删结点的后继
}
//构造一个带头结点的空链表L
LinkList * InitList_L(LinkList *L)
{
	if ((L = (LinkList *)malloc(sizeof(LinkList))) && (L->head = (Lnode *)malloc(sizeof(Lnode))))
	{
		//仅当表头结点和头结点均成功分配空间时
		L->head->next = NULL; //初始化头结点
		L->tail = NULL; //初始化尾指针
		L->len = 0; //初始化表长
		return L;
	}
	else
		NodeAllocFailure();
}
//销毁一个带头结点的链表L
LinkList * DestroyList_L(LinkList *L)
{
	while (L->head)
		L->head = FreeNode(L->head);
	free(L);
	return NULL;
}
//清空一个带头结点的链表L
void ClearList_L(LinkList *L)
{
	while (L->head->next)
		L->head->next = FreeNode(L->head->next);
	L->tail = NULL;
	L->len = 0;
}
//将s所指结点作为首结点插入到带头结点的链表L中
void InsFirst(LinkList *L, Lnode *s)
{
	s->next = L->head->next; //将原首结点挂接在新结点后面
	L->head->next = s; //头指针指向新结点
	if (!L->len) L->tail = s; //若新结点恰为唯一结点，则初始化尾指针
	L->len++;          //挂接成功，更新链表长度	
}
//删除一个带头结点的链表L的首结点
int DelFirst(LinkList *L)
{
	Lnode *p;
	if (!L->len)
	{
		printf("空表，删除失败！\n");
		system("pause");
		return ERROR;
	}
	if (!(L->head->next = FreeNode(L->head->next)))
		L->tail = NULL; //若首结点被删之后成了空表，则尾结点指针复位
	L->len--;
	return OK;
}
//将s所指结点附加在一个带头结点的链表L的末尾
void Append(LinkList *L, Lnode *s)
{
	if (L->tail)
		//链表的尾节点是指向链表最后一个元素的节点,与头结点不同的是头结点一般为空,而尾节点不为空
		L->tail->next = s;//非空表则在尾部附加
	else
		L->head->next = s;//空表则作为首结点
	L->tail = s;
	L->len++;
}
//删除一个带头结点的链表L的尾结点
int Remove(LinkList *L)
{
	Lnode *p;
	//长度为0则为空表
	if (!L->len)
	{
		printf("空表，删除失败！\n");
		system("pause");
		return ERROR;
	}
	p = L->head->next;//p指向首结点
	if (L->len == 1) L->head->next = L->tail = NULL; //仅有一个结点则删成空表
	else
	{
		while (p->next != L->tail) p = p->next; //后移p指针，直到p指向尾结点前驱
		p->next = FreeNode(p->next); //删除尾结点
		L->tail = p; //更新尾指针
	}
	L->len--;
	return OK;
}
//在一个带头结点的链表L中将s所指结点插入在p所指表中结点前
void InsBefore(LinkList *L, Lnode *p, Lnode *s)
{
	//头结点为空,head->next为首节点
	Lnode *q = L->head->next; //令q指向首结点
	if (q == p)
		InsFirst(L, s); //若p恰为首结点，则改为前插
	else
	{
		while (q->next != p)
			q = q->next; //后移q指针，直到q指向p前驱
		s->next = p;
		q->next = s;
		L->len++;
	}
}
//在一个带头结点的链表L中将s所指结点插入在p所指表中结点后
void InsAfter(LinkList *L, Lnode *p, Lnode *s)
{
	if (p == L->tail)
		Append(L, s); //若p恰为尾结点，则改为追加
	else
	{
		s->next = p->next;
		p->next = s;
		L->len++;
	}
}
//将p所指表结点的值更新为e
void SetCurElem(Lnode *p, int e)
{
	p->data = e;
}
//取出链表中p所指结点的值
int GetCurElem_L(Lnode *p)
{
	return p->data;
}
//判断链表是否为空
int ListEmpty_L(LinkList *L)
{
	if (L->len) return ERROR;
	else return OK;
}
//求带头结点的链表L中p所指结点的直接前驱
Lnode * PriorPos(LinkList *L, Lnode *p)
{
	Lnode *q = L->head; //令q指向头结点
	while (q->next != p)
		q = q->next; //若q的直接后继不是p，则q指针后移
					 //三目,若q==L->head为真则NULL,否则q
	return q == L->head ? NULL : q; //若p恰为首结点，则返回空
}
//求带头结点的链表L中第i个结点的位置
Lnode * LocatePos(LinkList *L, int i)
{
	Lnode *p = L->head; //令p指向头结点（相当于0号位置）
	if (i <= 0 || i > L->len)
		return NULL; //i值非法，则返回空
	else if (i == L->len)
		return L->tail;  //恰为尾结点，则直接返回
	while (i--)
		p = p->next; //寻找该结点
	return p;
}

void ListTraverse_L(LinkList *L)
{
	//遍历带头结点的链表L
	Lnode *p = L->head; //令p指向头结点
	while (p = p->next)
		visit(p->data);
}

//空间分配失败
int NodeAllocFailure()
{
	printf("结点空间分配失败！");
	system("pause");
	exit(ERROR);
}