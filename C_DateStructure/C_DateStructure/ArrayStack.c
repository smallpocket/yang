//导入文件用"",
#include"ArrayStack.h"
/*
方法定义中,不能使用&Astruct,,应该是Astruct *;
顺序栈的实现
*/
//因为传入了一个指针,所以不用返回
int InitStruck(Astruct * s)
{
	s->base = (Astruct *)malloc(init_size * sizeof(Astruct));
	if (!s->base)//s->base若为空,则说明无空间,上一步malloc失败
		NodeAllocFailure();//倘若分配空间失败,则退出
	s->top = s->base;//初始化栈,当前的栈顶与栈底重合,因为没有元素
	s->length = 0;
	return OK;
}
//TODO:realloc的详解,需要重新看一下CPP
int DilatationList(Astruct *s)
{
	int *news;
	news = (int *)realloc(s->date,(s->length + add_size) * sizeof(int));
	if (!news) NodeAllocFailure();
	s->date = news;
	return OK;
}
/*
销毁应该使s->base为null,长度为0
*/
int DestroyStack(Astruct * s)
{
	//s->base请求了内存空间,所以free其即可销毁
	free(s->base);
	s->base = NULL;
	s->length = 0;
	return OK;
}
int StackEmpty(Astruct * s)
{
	if (s->length)
		return OK;
	else
		return ERROR;
}
int ClearStack(Astruct * s)
{
	s->length = 0;
}
int GetTop(Astruct *s, int *e)
{
	e = &(*(s->top-1));
	return OK;
}
int Push(Astruct *s, int e)
{
	if (s->top - s->base == s->length)//栈顶-栈底的差值为元素个数,如果等于长度,则需要扩容
		DilatationList(s);
	else
	{
		s->top = e;
		s->length++;
	}
	return OK;
}
//clear那么暴力,删除也就差不多了,top移开,长度减一就OK
int Pop(Astruct * s)
{
	s->top--;
	s->length--;
}
int StackTraverse(Astruct *s)
{
	int *min = s->base;
	int *max = s->top;//指针标识栈底和栈顶
	for (; min < max; min++)
	{
		printf("%d\n", *min);//输出
	}
	return OK;
}
