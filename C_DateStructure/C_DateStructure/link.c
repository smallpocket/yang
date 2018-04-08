#include"link.h"
//���һ���ڵ��ֵ
void visit(Lnode *e)
{
	printf("%d", e->data);
}
//Ϊp������ռ䣬����ֵΪe
Lnode * MakeNode(int e)
{
	Lnode *p;
	if (p = (Lnode *)malloc(sizeof(Lnode)))
	{
		p->data = e;
		p->next = NULL;
		return p;
	}
	else NodeAllocFailure();
}
//�ͷţ�ɾ����p��ָ������
Lnode * FreeNode(Lnode *p)
{
	Lnode *q = p->next;
	free(p);
	return q;//���ر�ɾ���ĺ��
}
//����һ����ͷ���Ŀ�����L
LinkList * InitList_L(LinkList *L)
{
	if ((L = (LinkList *)malloc(sizeof(LinkList))) && (L->head = (Lnode *)malloc(sizeof(Lnode))))
	{
		//������ͷ����ͷ�����ɹ�����ռ�ʱ
		L->head->next = NULL; //��ʼ��ͷ���
		L->tail = NULL; //��ʼ��βָ��
		L->len = 0; //��ʼ����
		return L;
	}
	else
		NodeAllocFailure();
}
//����һ����ͷ��������L
LinkList * DestroyList_L(LinkList *L)
{
	while (L->head)
		L->head = FreeNode(L->head);
	free(L);
	return NULL;
}
//���һ����ͷ��������L
void ClearList_L(LinkList *L)
{
	while (L->head->next)
		L->head->next = FreeNode(L->head->next);
	L->tail = NULL;
	L->len = 0;
}
//��s��ָ�����Ϊ�׽����뵽��ͷ��������L��
void InsFirst(LinkList *L, Lnode *s)
{
	s->next = L->head->next; //��ԭ�׽��ҽ����½�����
	L->head->next = s; //ͷָ��ָ���½��
	if (!L->len) L->tail = s; //���½��ǡΪΨһ��㣬���ʼ��βָ��
	L->len++;          //�ҽӳɹ�������������	
}
//ɾ��һ����ͷ��������L���׽��
int DelFirst(LinkList *L)
{
	Lnode *p;
	if (!L->len)
	{
		printf("�ձ�ɾ��ʧ�ܣ�\n");
		system("pause");
		return ERROR;
	}
	if (!(L->head->next = FreeNode(L->head->next)))
		L->tail = NULL; //���׽�㱻ɾ֮����˿ձ���β���ָ�븴λ
	L->len--;
	return OK;
}
//��s��ָ��㸽����һ����ͷ��������L��ĩβ
void Append(LinkList *L, Lnode *s)
{
	if (L->tail)
		//�����β�ڵ���ָ���������һ��Ԫ�صĽڵ�,��ͷ��㲻ͬ����ͷ���һ��Ϊ��,��β�ڵ㲻Ϊ��
		L->tail->next = s;//�ǿձ�����β������
	else
		L->head->next = s;//�ձ�����Ϊ�׽��
	L->tail = s;
	L->len++;
}
//ɾ��һ����ͷ��������L��β���
int Remove(LinkList *L)
{
	Lnode *p;
	//����Ϊ0��Ϊ�ձ�
	if (!L->len)
	{
		printf("�ձ�ɾ��ʧ�ܣ�\n");
		system("pause");
		return ERROR;
	}
	p = L->head->next;//pָ���׽��
	if (L->len == 1) L->head->next = L->tail = NULL; //����һ�������ɾ�ɿձ�
	else
	{
		while (p->next != L->tail) p = p->next; //����pָ�룬ֱ��pָ��β���ǰ��
		p->next = FreeNode(p->next); //ɾ��β���
		L->tail = p; //����βָ��
	}
	L->len--;
	return OK;
}
//��һ����ͷ��������L�н�s��ָ��������p��ָ���н��ǰ
void InsBefore(LinkList *L, Lnode *p, Lnode *s)
{
	//ͷ���Ϊ��,head->nextΪ�׽ڵ�
	Lnode *q = L->head->next; //��qָ���׽��
	if (q == p)
		InsFirst(L, s); //��pǡΪ�׽�㣬���Ϊǰ��
	else
	{
		while (q->next != p)
			q = q->next; //����qָ�룬ֱ��qָ��pǰ��
		s->next = p;
		q->next = s;
		L->len++;
	}
}
//��һ����ͷ��������L�н�s��ָ��������p��ָ���н���
void InsAfter(LinkList *L, Lnode *p, Lnode *s)
{
	if (p == L->tail)
		Append(L, s); //��pǡΪβ��㣬���Ϊ׷��
	else
	{
		s->next = p->next;
		p->next = s;
		L->len++;
	}
}
//��p��ָ�����ֵ����Ϊe
void SetCurElem(Lnode *p, int e)
{
	p->data = e;
}
//ȡ��������p��ָ����ֵ
int GetCurElem_L(Lnode *p)
{
	return p->data;
}
//�ж������Ƿ�Ϊ��
int ListEmpty_L(LinkList *L)
{
	if (L->len) return ERROR;
	else return OK;
}
//���ͷ��������L��p��ָ����ֱ��ǰ��
Lnode * PriorPos(LinkList *L, Lnode *p)
{
	Lnode *q = L->head; //��qָ��ͷ���
	while (q->next != p)
		q = q->next; //��q��ֱ�Ӻ�̲���p����qָ�����
					 //��Ŀ,��q==L->headΪ����NULL,����q
	return q == L->head ? NULL : q; //��pǡΪ�׽�㣬�򷵻ؿ�
}
//���ͷ��������L�е�i������λ��
Lnode * LocatePos(LinkList *L, int i)
{
	Lnode *p = L->head; //��pָ��ͷ��㣨�൱��0��λ�ã�
	if (i <= 0 || i > L->len)
		return NULL; //iֵ�Ƿ����򷵻ؿ�
	else if (i == L->len)
		return L->tail;  //ǡΪβ��㣬��ֱ�ӷ���
	while (i--)
		p = p->next; //Ѱ�Ҹý��
	return p;
}

void ListTraverse_L(LinkList *L)
{
	//������ͷ��������L
	Lnode *p = L->head; //��pָ��ͷ���
	while (p = p->next)
		visit(p->data);
}

//�ռ����ʧ��
int NodeAllocFailure()
{
	printf("���ռ����ʧ�ܣ�");
	system("pause");
	exit(ERROR);
}