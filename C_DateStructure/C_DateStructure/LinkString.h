#pragma once
#include "PublicBase.h"
/*
链串,对于链串,一个节点可以存放不止一个值,可以有效节约空间,(一个char一个长度,一个指针都4个长度)
即块链
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