#pragma once
#define ListInitSize 100
#define ListAddSize 10
	/**
	*第一个错误：在声明顺序表的时候，使用了date[100]的数组形式，实际上应该使用一个指针
	*如果使用数组的头进行一个malloc操作，会产生不可修改的左值错误
	*
	*/
typedef struct linklist
{
	int *date;//数据指针
	int nowlength;//当前的顺序表长度
	int maxlength;//最大的顺序表长度
}LinkList;
