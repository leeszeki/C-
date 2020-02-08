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

//菜单界面
void menu();

//链表的建立以及初始化
CommodityInfo *CreateList();

//链表的遍历打印
int PrintList(CommodityInfo *head);

//删除商品
int DeleteList(CommodityInfo *head, char *val);

//用尾插增加商品
int InsertList(CommodityInfo *head, const char *val, int val_number);

//指定插入的方法往链表内插入元素
//int AppointInsertList(CommodityInfo *head, const char *val, int val_number);
int AppointInsertList(CommodityInfo *head, const char *locate, const char *val, int val_number);

//根据商品的个数进行排序
int SortList(CommodityInfo *head);

//将信息保存进文件
int ConserveList(CommodityInfo *head);

//清空链表，释放所有的结点
int DestroyList(CommodityInfo *head);
