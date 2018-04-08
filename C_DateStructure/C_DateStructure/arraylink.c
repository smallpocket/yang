#include "arraylink.h"
#include "arraylinkcode.h"

//²âÊÔº¯Êý
//Ctrl+k,Ctrl+c
//Ctrl+k,Ctrl+u
int main()
{
	LinkList sqlist;
	LinkList *alist = &sqlist;
	InitLinkList(alist);
	printf("¹þ¹þ¹þ");
	printf("%d", alist->maxlength);
	sqlist.date[0] = 1;
	sqlist.nowlength = 1;
	DestroyList(alist);
	printf("%d", sqlist.nowlength);
	system("pause");
	return 0;
}