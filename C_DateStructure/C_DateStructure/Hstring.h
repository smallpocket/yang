#pragma once
/*
堆串的实现
与顺序串的区别为堆串为动态分配
*/
#define ERROR 0
#define OK 1
#define init_size 100
#define add_size 10
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MaxSize 100
typedef struct
{
	char *ch;//存储字符串
	unsigned int len;//当前长度
}HSring;
//
HSring StrAssign(char *cstr);
//将字符串s复制给t
void StrCopy(HSring *s, HSring *t);
//判断字符串是否相等
int StrEqual(HSring *s, HSring *t);
//求串长
int StrLength(HSring *s);
//返回两个串连接起来的新串
HSring *Concat(HSring *s, HSring *t);
//返回从第i个字符连续的J个字符组成的子串
HSring *SubStr(HSring *s, int i, int j);
//将串2插入到串1的第i号字符前,返回产生的新串
HSring *InsStr(HSring *s, HSring *t);
//删除从第i个字符连续的J个字符组成的子串,返回新串
HSring *DelStr(HSring *s, int i, int j);
//从第i号元素连续的j个元素的子串用t代替
HSring *RepStr(HSring *s, int i, int j, HSring *t);
//输出全部元素
void DispString(HSring *s);