#pragma once
#include "arraylist.h"
int InitArrayList(ArrayList *list)
{
	list->date = (int *)malloc(init_size * sizeof(int));
	if (!list->date) DestributeFailure();
	list->nowlength = 0;
	list->maxlength = init_size;
	return OK;
}

//Destroy可以传入一个指针的地址
//注意销毁的是list->date,不是list
//不能仅仅销毁掉list->date就结束了，因为list是一个结构体，而不仅仅是有一个date
int DestroyList(ArrayList *list)
{
	free(list->date);
	list->date = NULL;
	list->nowlength = 0;
	return OK;
}
//what happened，这这么狂暴的吗？，不过如果说严格的按照结构体的话，如果一个顺序表get它的当前长度为0的话
//那么可以去认为它的数据都是一些无用数据，66666
int ClearList(ArrayList *list)
{
	list->nowlength = 0;
}
//没什么难度
int ListEmpty(ArrayList *list)
{
	if (list->nowlength == 0)
		return ERROR;
	else
		return OK;
}
//没什么难度
int ListLength(ArrayList *list)
{
	return list->nowlength;
}
int GetElem(ArrayList *list, int i)
{
	return list->date[i];
}
int LocatElem(ArrayList *list, int e)
{
	for (int i = 0; i < list->nowlength; i++)
		if (e == list->date[i])
			return i;
	return -1;
}
int PriorElem(ArrayList *list, int i)
{
	if (i<0 || i>list->nowlength)
		FetchFailture();
	else return list->date[i - 1];
}
int NextElem(ArrayList *list, int i)
{
	if (i<0 || i>list->nowlength - 1)
		FetchFailture();
	else return list->date[i + 1];
}
//增加一个新的数组长度
int DilatationList(ArrayList *list)
{
	int *newlist = (int *)realloc(list->date, (add_size + list->maxlength) * sizeof(int));
	if (!newlist) DestributeFailure();
	list->date = newlist;
	list->maxlength += add_size;
	return 0;
}
int ListInsert(ArrayList * list, int i, int e)
{
	if (i > list->nowlength || i < 0)
		InsertFailture();
	if (list->nowlength == list->maxlength);
	DilatationList(list);
	//自己又犯了一个错误，没有能够加&，导致指针赋值有问题，
	int *temp = &list->date[list->nowlength - 1];
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
int ListDelete(ArrayList * list, int i, int e)
{
	if (i<0 || i>list->nowlength)
		DeleteFailture();
	for (int *p = &list->date[i]; p < &list->date[list->nowlength]; p++)
		*p = *(p + 1);
	--list->nowlength;
	return 0;
}