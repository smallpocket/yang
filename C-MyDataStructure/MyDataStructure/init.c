#include "linkList.h"
#include "public.h"
//构造空的顺序表
int InitLinkList(LinkList *);
/*操作结果：构造一个空的线性表*/

int DestroyList(LinkList *);
/*初始条件：线性表L已存在*/
/*操作结果：销毁线性表L*/

int ClearList(LinkList *);
/*初始条件：线性表L已存在*/
/*操作结果：将L重置为空表*/

int ListEmpty(LinkList *);
/*初始条件：线性表L已存在*/
/*操作结果：若L为空表，则返回TRUE，否则返回FALSE*/

int ListLength(LinkList *);
/*初始条件：线性表L已存在*/
/*操作结果：返回L中数据元素个数*/

int GetElem(LinkList *, int);
/*初始条件：线性表L已存在,1≤i≤maxlength*/
/*操作结果：返回L中第i个数据元素的值*/

int LocatElem(LinkList *, int);
/*初始条件：线性表L已存在*/
/*操作结果：返回L中第1个与e相等的数据元素的位序。若这样的数据元素不存在，则返回-1*/

int PriorElem(LinkList *, int);
/*初始条件：线性表L已存在*/
/*操作结果：取出顺序表L中第i号元素的前驱，否则操作失败*/

int NextElem(LinkList *, int);
/*初始条件：线性表L已存在*/
/*操作结果：取出顺序表L中第i号元素的后继，否则操作失败*/

int ListInsert(LinkList *, int, int);
/*初始条件：线性表L已存在*/
/*操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/

int ListDelete(LinkList *, int, int);
/*初始条件：线性表L已存在*/
/*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/

int InitLinkList(LinkList *list)
{
	list->date = (int *)malloc(ListInitSize * sizeof(int));
	if (!list->date) DestributeFailure();
	list->nowlength = 0;
	list->maxlength = ListInitSize;
	return 0;
}

//Destroy可以传入一个指针的地址
//注意销毁的是list->date,不是list
//不能仅仅销毁掉list->date就结束了，因为list是一个结构体，而不仅仅是有一个date
int DestroyList(LinkList *list)
{
	free(list->date);
	list->date = NULL;
	list->nowlength = 0;
	return 0;
}
//what happened，这这么狂暴的吗？，不过如果说严格的按照结构体的话，如果一个顺序表get它的当前长度为0的话
//那么可以去认为它的数据都是一些无用数据，66666
int ClearList(LinkList *list)
{
	list->nowlength = 0;
}
//没什么难度
int ListEmpty(LinkList *list)
{
	if (list->nowlength == 0)
		return 0;
	else
		return 1;
}
//没什么难度
int ListLength(LinkList *list)
{
	return list->nowlength;
}
int GetElem(LinkList *list, int i)
{
	return list->date[i];
}
int LocatElem(LinkList *list, int e)
{
	for (int i = 0; i < list->nowlength; i++)
		if (e == list->date[i])
			return i;
	return -1;
}
int PriorElem(LinkList *list, int i)
{
	if (i<0 || i>list->nowlength)
		FetchFailture();
	else return list->date[i - 1];
}
int NextElem(LinkList *list, int i)
{
	if (i<0 || i>list->nowlength-1)
		FetchFailture();
	else return list->date[i + 1];
}
//
int DilatationList(LinkList *list)
{
	//增加一个新的数组长度
	int *newlist = (int *)relloc(list->date, (ListAddSize + list->maxlength) * sizeof(int));
	if (!newlist) DestributeFailure();
	list->date = newlist;
	list->maxlength += ListAddSize;
	return 0;
}
int ListInsert(LinkList * list, int i, int e)
{
	if (i > list->nowlength || i < 0)
		InsertFailture();
	if (list->nowlength == list->maxlength);
		DilatationList(list);
	//自己又犯了一个错误，没有能够加&，导致指针赋值有问题，
	int *temp=list->date[list->nowlength-1];
	for (int p = list->nowlength; p >= i; p--)
	{
		list->date[p + 1] = list->date[p];
	}
	//指针确认，p指向最后一个元素，p>=q：p的地址在q的后面，，--p每次向前移动一个int的量
	//for ( p = &(L->elem[L->length - 1]); p >= q; --p) *(p + 1) = *p;
	list->date[i] = e;
	//顺序表伸长，长度增加
	++list->nowlength;
	return 0;
}
int ListDelete(LinkList * list, int i, int e)
{
	if(i<0||i>list->nowlength)
		DeleteFailture();
	for (int *p = &list->date[i]; p < &list->date[list->nowlength]; p++)
		*p = *(p + 1);
	--list->nowlength;
	return 0;
}
//测试函数
//Ctrl+k,Ctrl+c
//Ctrl+c,Ctrl+u
int main()
{
	LinkList Sqlist;
	LinkList *alist=&Sqlist;
	InitLinkList(alist);
	printf("哈哈哈");
	printf("%d",alist->maxlength);
	Sqlist.date[0] = 1;
	Sqlist.nowlength = 1;
	DestroyList(alist);
	printf("%d",Sqlist.nowlength);
	system("pause");
	return 0;
}