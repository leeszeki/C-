#define _CRT_SECURE_NO_WARNINGS
#include "includes.h"

//#define FOOD 15
//#define CLOTH 40
//#define SHOSE 70

//初始界面
void menu()
{
	printf("/*********************************************************/\n");
	printf("\t\t欢迎进入此系统进行商品选购\t\t\n");
	printf("1、请选择以下的商品类型以及输入选择商品个数（输入退出即立刻退出）\n");
	printf("\t衣服\t\n");
	printf("\t面包\t\n");
	printf("\t鞋子\t\n");
	printf("\t水果\t\n");
	printf("\t蔬菜\t\n");
	printf("\t书籍\t\n");
	printf("\t肉类\t\n");
	printf("\t电子器件\t\n");
	printf("2、删除商品\n");
	printf("3、对商品数量进行排序\n");
	printf("4、插入商品(尾插法)\n");
	printf("5、插入商品(指定位置)\n");
	printf("6、打印信息\n");
	printf("7、保存\n");
	printf("0退出\n");
	printf("/*********************************************************/\n");
}

//选项设置
void view()
{
	CommodityInfo *head = NULL;
	char val[10] = { 0 };
	char val1[10] = { 0 };
	char val2[10] = { 0 };
	int num = 0;
	int num1 = 0;

	int input;
	while (1)
	{
		
		menu();
		printf("请输入：\n");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			head = CreateList();
			PrintList(head);
			system("cls");
			break;
		case 2:
			system("cls");
			printf("请输入你要删除的商品：");
			scanf("%s", val);
			DeleteList(head, val);

			system("pause");
			break;
		case 3:
			SortList(head);
			PrintList(head);
			system("cls");
			system("pause");
			break;
		case 4:
			printf("请输入你要插入的商品：");
			scanf("%s", val1);
			printf("请输入商品的数量:");
			scanf("%d", &num);
			InsertList(head,val1,num);
			system("cls");
			system("pause");
			break;
		case 5:
			printf("请输入你要插入的商品在哪个商品后面：");
			scanf("%s", val2);
			printf("请输入你要插入的商品：");
			scanf("%s", val1);
			printf("请输入商品的数量:");
			scanf("%d", &num1);
			AppointInsertList(head, val2, val1, num1);
			system("cls");
			system("pause");
			break;
		case 6:
			system("cls");
			PrintList(head);
			break;
		case 7:
			system("cls");
			ConserveList(head);
			printf("保存成功!");
			break;
		default:
			system("cls");
			DestroyList(head);
			head = NULL;
			exit(0);
			break;
		}
	}
}


/*
创建头结点
链表的头结点地址由函数值返回
*/
CommodityInfo *CreateList()
{
	char ExitTmp[] = "退出";
	CommodityInfo *head = NULL;

	//头结点作为标志，不存储有效数据
	head = (CommodityInfo *)malloc(sizeof(CommodityInfo));
	if (head == NULL)
	{
		return NULL;
	}

	//给head的成员变量赋值
	head->m_Goods[10] = 0;
	head->m_Number = 0;
	//head->m_UnitPrice = 0;
	head->m_next = NULL;

	CommodityInfo *pCur = head;
	CommodityInfo *pNew = NULL;

	char goods[10];
	int number;
	//int unitprice;


	while (1)
	{

		printf("请输入你选择的商品名字：");
		scanf("%s", goods);

		if (0 == (strcmp(goods, ExitTmp)))	//输入“退出”即立刻退出
		{
			break;
		}

		printf("请输入你选择商品的个数：");
		scanf("%d", &number);
		if (0 == number)
		{
			printf("个数有误请重新输入：");
			scanf("%d", &number);
		}


		//新结点动态分配空间
		pNew = (CommodityInfo *)malloc(sizeof(CommodityInfo));
		if (pNew == NULL)
		{
			break;
		}

		//给pNew成员变量赋值
		strcpy(pNew->m_Goods, goods);
		pNew->m_Number = number;
		pNew->m_next = NULL;

		//链表建立关系

		//当前结点的next指向pNew
		pCur->m_next = pNew;

		//pNew的下一个结点指向NULL
		pNew->m_next = NULL;

		//把pCur移动到pNew,pCur指向pNew
		pCur = pNew;
	}

	return head;
}


//链表的遍历
int PrintList(CommodityInfo *head)
{
	if (head == NULL)
	{
		return -1;
	}

	//取出第一个有效结点(头结点的next)
	CommodityInfo *pCur = head->m_next;


	while (pCur != NULL)
	{
		printf("商品：");
		printf("%s\t", pCur->m_Goods);
		printf("个数：");
		printf("%d\n", pCur->m_Number);

		//当前结点往下移动一位，pCur指向下一个
		pCur = pCur->m_next;
	}
	printf("\n");

	return 0;
}

//利用尾插的方法往链表内插入元素
int InsertList(CommodityInfo *head, const char *val, int val_number)
{
	if (head == NULL)
	{
		return -1;
	}

	CommodityInfo *pPre = head;
	CommodityInfo *pCur = head->m_next;

	while (pCur != NULL)
	{
		
		pPre = pCur;//pPre指向PCur的位置
		pCur = pCur->m_next;//pCur指向下一个结点
	}

	CommodityInfo *pNew = (CommodityInfo*)malloc(sizeof(CommodityInfo));
	if (pNew == NULL)
	{
		return -2;
	}
	strcpy(pNew->m_Goods, val);
	pNew->m_Number = val_number;
	pNew->m_next = NULL;

	pPre->m_next = pNew; //pPre下一个指向pNew
	pNew->m_next = pCur; //pNew下一个指向pCur
	
	return 0;

}

//指定插入的方法往链表内插入元素
int AppointInsertList(CommodityInfo *head, const char *locate, const char *val, int val_number)
{
	if (head == NULL)
	{
		return -1;
	}

	CommodityInfo *pPre = head;
	CommodityInfo *pCur = head->m_next;

	while (strcmp(locate, pCur->m_Goods) == 0)
	{
		pPre = pCur;
		pCur = pCur->m_next;
	}

	CommodityInfo *pNew = (CommodityInfo*)malloc(sizeof(CommodityInfo));
	if (pNew == NULL)
	{
		return -2;
	}
	strcpy(pNew->m_Goods, val);
	pNew->m_Number = val_number;
	
	//插入指定位置
	pPre->m_next = pNew; //pPre下一个指向pNew
	pNew->m_next = pCur; //pNew下一个指向pCur

	return 0;
}


//根据商品的个数进行排序
int SortList(CommodityInfo *head)
{
	if (head == NULL)
	{
		return -1;
	}

	CommodityInfo *pPre;
	CommodityInfo *pCur;
	int tmp;

	for (pCur = head->m_next; pCur != NULL; pCur = pCur->m_next)
	{
		for (pPre = pCur->m_next; pPre != NULL; pPre = pPre->m_next)
		{
			if (pCur->m_Number > pPre->m_Number)
			{
				tmp = pCur->m_Number;
				pCur->m_Number = pPre->m_Number;
				pPre->m_Number = tmp;
			}
		}
	}

	return 0;
}


//删除商品
int DeleteList(CommodityInfo *head, char *val)
{
	if (head == NULL)
	{
		return -1;
	}

	int flag = 0;//0为找到，1为找到
	CommodityInfo *pPre = head;
	CommodityInfo *pCur = head->m_next;
	
	while (pCur != NULL)
	{
		if (!(strcmp(pCur->m_Goods, val)))//找到匹配的结点
		{
			//pPre的下一个结点指向PCur的下一个
			pPre->m_next = pCur->m_next;
			free(pCur);
			pCur = NULL;

			flag = 1;
			break;
		}

		pPre = pCur;//pPre指向pCur位置
		pCur = pCur->m_next;//pCur指向下一个结点
	}

	if (0 == flag)
	{
		printf("没有找到%s商品\n", val);
		return -2;
	}

	return 0;
}

//将链表的内容输入到文件中保存起来
int ConserveList(CommodityInfo *head)
{
	FILE *fp;
	CommodityInfo *pCur = head->m_next;

	if ((fp = fopen("CommodityInformation.txt", "w")) == NULL)
	{
		printf("文件无法打开！\n");
		exit(1);
	}

	if (head == NULL)
	{
		return -1;
	}

	while (pCur != NULL)
	{
		fprintf(fp,"商品：%s\t", pCur->m_Goods);
		fprintf(fp, "个数：%d\n", pCur->m_Number);
		pCur = pCur->m_next;

	}

	fclose(fp);
	return 0;
}

//清空链表，释放所有的结点
int DestroyList(CommodityInfo *head)
{
	if (head == NULL)
	{
		return -1;
	}

	//用于存放地址的变量
	CommodityInfo *tmp = NULL;

	while (head == NULL)
	{
		//保存head的下一个结点
		tmp = head->m_next;
		free(head);
		head = NULL;

		head = tmp;
	}

	return 0;
}