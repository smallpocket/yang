#pragma once
#include "PublicBase.h"
/*
����,��������,һ���ڵ���Դ�Ų�ֹһ��ֵ,������Ч��Լ�ռ�,(һ��charһ������,һ��ָ�붼4������)
������
*/
#define ChunkSize 80
typedef struct chunk
{
	char ch[ChunkSize];
	struct chunk *next;
}Chunk;
typedef struct chunkchain
{
	Chunk *head, *tail;
	int curlen;
}Lstring;