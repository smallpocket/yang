//�����ļ���"",
#include"ArrayStack.h"
/*
����������,����ʹ��&Astruct,,Ӧ����Astruct *;
˳��ջ��ʵ��
*/
//��Ϊ������һ��ָ��,���Բ��÷���
int InitStruck(Astruct * s)
{
	s->base = (Astruct *)malloc(init_size * sizeof(Astruct));
	if (!s->base)//s->base��Ϊ��,��˵���޿ռ�,��һ��mallocʧ��
		NodeAllocFailure();//��������ռ�ʧ��,���˳�
	s->top = s->base;//��ʼ��ջ,��ǰ��ջ����ջ���غ�,��Ϊû��Ԫ��
	s->length = 0;
	return OK;
}
//TODO:realloc�����,��Ҫ���¿�һ��CPP
int DilatationList(Astruct *s)
{
	int *news;
	news = (int *)realloc(s->date,(s->length + add_size) * sizeof(int));
	if (!news) NodeAllocFailure();
	s->date = news;
	return OK;
}
/*
����Ӧ��ʹs->baseΪnull,����Ϊ0
*/
int DestroyStack(Astruct * s)
{
	//s->base�������ڴ�ռ�,����free�伴������
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
	if (s->top - s->base == s->length)//ջ��-ջ�׵Ĳ�ֵΪԪ�ظ���,������ڳ���,����Ҫ����
		DilatationList(s);
	else
	{
		s->top = e;
		s->length++;
	}
	return OK;
}
//clear��ô����,ɾ��Ҳ�Ͳ����,top�ƿ�,���ȼ�һ��OK
int Pop(Astruct * s)
{
	s->top--;
	s->length--;
}
int StackTraverse(Astruct *s)
{
	int *min = s->base;
	int *max = s->top;//ָ���ʶջ�׺�ջ��
	for (; min < max; min++)
	{
		printf("%d\n", *min);//���
	}
	return OK;
}
