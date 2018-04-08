#pragma once
#define ERROR 0
#define OK 1
#define init_size 100
#define add_size 10
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
//对分配空间失败的说明
int DestributeFailure()
{
	printf("向量空间分配失败！\n");
	system("pause");
	exit(1);
}
//非法获取
int FetchFailture()
{
	printf("非法获取！\n");
	system("pause");
	exit(1);
}
//非法插入
int InsertFailture()
{
	printf("非法插入！\n");
	system("pause");
	exit(1);
}
//非法删除
int DeleteFailture()
{
	printf("非法删除！\n");
	system("pause");
	exit(1);
}