#pragma once
#define ERROR 0
#define OK 1
#define init_size 100
#define add_size 10
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
//�Է���ռ�ʧ�ܵ�˵��
int DestributeFailure()
{
	printf("�����ռ����ʧ�ܣ�\n");
	system("pause");
	exit(1);
}
//�Ƿ���ȡ
int FetchFailture()
{
	printf("�Ƿ���ȡ��\n");
	system("pause");
	exit(1);
}
//�Ƿ�����
int InsertFailture()
{
	printf("�Ƿ����룡\n");
	system("pause");
	exit(1);
}
//�Ƿ�ɾ��
int DeleteFailture()
{
	printf("�Ƿ�ɾ����\n");
	system("pause");
	exit(1);
}