#pragma once
/*
顺序串的实现
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
	char date[MaxSize];//存储字符串
	unsigned int len;//当前长度
}SqString;
//
SqString StrAssign(SqString *s, char *cstr);
//将字符串s复制给t
void StrCopy(SqString *s, SqString *t);
//判断字符串是否相等
int StrEqual(SqString *s, SqString *t);
//求串长
int StrLength(SqString *s);
//返回两个串连接起来的新串
SqString *Concat(SqString *s, SqString *t);
//返回从第i个字符连续的J个字符组成的子串
SqString *SubStr(SqString *s, int i, int j);
//将串2插入到串1的第i号字符前,返回产生的新串
SqString *InsStr(SqString *s, SqString *t);
//删除从第i个字符连续的J个字符组成的子串,返回新串
SqString *DelStr(SqString *s, int i, int j);
//从第i号元素连续的j个元素的子串用t代替
SqString *RepStr(SqString *s, int i, int j, SqString *t);
//输出全部元素
void DispString(SqString *s);