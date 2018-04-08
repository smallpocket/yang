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

//Destroy���Դ���һ��ָ��ĵ�ַ
//ע�����ٵ���list->date,����list
//���ܽ������ٵ�list->date�ͽ����ˣ���Ϊlist��һ���ṹ�壬������������һ��date
int DestroyList(ArrayList *list)
{
	free(list->date);
	list->date = NULL;
	list->nowlength = 0;
	return OK;
}
//what happened������ô�񱩵��𣿣��������˵�ϸ�İ��սṹ��Ļ������һ��˳���get���ĵ�ǰ����Ϊ0�Ļ�
//��ô����ȥ��Ϊ�������ݶ���һЩ�������ݣ�66666
int ClearList(ArrayList *list)
{
	list->nowlength = 0;
}
//ûʲô�Ѷ�
int ListEmpty(ArrayList *list)
{
	if (list->nowlength == 0)
		return ERROR;
	else
		return OK;
}
//ûʲô�Ѷ�
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
//����һ���µ����鳤��
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
	//�Լ��ַ���һ������û���ܹ���&������ָ�븳ֵ�����⣬
	int *temp = &list->date[list->nowlength - 1];
	for (int p = list->nowlength; p >= i; p--)
	{
		list->date[p + 1] = list->date[p];
	}
	//ָ��ȷ�ϣ�pָ�����һ��Ԫ�أ�p>=q��p�ĵ�ַ��q�ĺ��棬��--pÿ����ǰ�ƶ�һ��int����
	//for ( p = &(L->elem[L->length - 1]); p >= q; --p) *(p + 1) = *p;
	list->date[i] = e;
	//˳����쳤����������
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