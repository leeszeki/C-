#pragma once

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 
#include <string.h>

//#define FOOD 15
//#define CLOTH 40
//#define SHOSE 70

typedef struct CommodityInfo
{
	char m_Goods[10];
	int m_Number;
	//int m_UnitPrice;
	struct CommodityInfo *m_next;
}CommodityInfo;


void view();

//�˵�����
void menu();

//����Ľ����Լ���ʼ��
CommodityInfo *CreateList();

//����ı�����ӡ
int PrintList(CommodityInfo *head);

//ɾ����Ʒ
int DeleteList(CommodityInfo *head, char *val);

//��β��������Ʒ
int InsertList(CommodityInfo *head, const char *val, int val_number);

//ָ������ķ����������ڲ���Ԫ��
//int AppointInsertList(CommodityInfo *head, const char *val, int val_number);
int AppointInsertList(CommodityInfo *head, const char *locate, const char *val, int val_number);

//������Ʒ�ĸ�����������
int SortList(CommodityInfo *head);

//����Ϣ������ļ�
int ConserveList(CommodityInfo *head);

//��������ͷ����еĽ��
int DestroyList(CommodityInfo *head);
