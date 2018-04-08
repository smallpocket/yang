#pragma once
//包含头文件的定义
#include "PublicBase.h"
/**
*顺序表
*第一个错误：在声明顺序表的时候，使用了date[100]的数组形式，实际上应该使用一个指针
*如果使用数组的头进行一个malloc操作，会产生不可修改的左值错误
*/
typedef struct arraylist
{
	int *date;//数据指针
	int nowlength;//当前的顺序表长度
	int maxlength;//最大的顺序表长度
}ArrayList;
//增加一个新的数组长度
int DilatationList(ArrayList *list);
//构造空的顺序表
int InitLinkList(ArrayList *);
/*操作结果：构造一个空的线性表*/

int DestroyList(ArrayList *);
/*初始条件：线性表L已存在*/
/*操作结果：销毁线性表L*/

int ClearList(ArrayList *);
/*初始条件：线性表L已存在*/
/*操作结果：将L重置为空表*/

int ListEmpty(ArrayList *);
/*初始条件：线性表L已存在*/
/*操作结果：若L为空表，则返回TRUE，否则返回FALSE*/

int ListLength(ArrayList *);
/*初始条件：线性表L已存在*/
/*操作结果：返回L中数据元素个数*/

int GetElem(ArrayList *, int);
/*初始条件：线性表L已存在,1≤i≤maxlength*/
/*操作结果：返回L中第i个数据元素的值*/

int LocatElem(ArrayList *, int);
/*初始条件：线性表L已存在*/
/*操作结果：返回L中第1个与e相等的数据元素的位序。若这样的数据元素不存在，则返回-1*/

int PriorElem(ArrayList *, int);
/*初始条件：线性表L已存在*/
/*操作结果：取出顺序表L中第i号元素的前驱，否则操作失败*/

int NextElem(ArrayList *, int);
/*初始条件：线性表L已存在*/
/*操作结果：取出顺序表L中第i号元素的后继，否则操作失败*/

int ListInsert(ArrayList *, int, int);
/*初始条件：线性表L已存在*/
/*操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/

int ListDelete(ArrayList *, int, int);
/*初始条件：线性表L已存在*/
/*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/