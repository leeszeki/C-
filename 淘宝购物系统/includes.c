#define _CRT_SECURE_NO_WARNINGS
#include "includes.h"

//#define FOOD 15
//#define CLOTH 40
//#define SHOSE 70

//��ʼ����
void menu()
{
	printf("/*********************************************************/\n");
	printf("\t\t��ӭ�����ϵͳ������Ʒѡ��\t\t\n");
	printf("1����ѡ�����µ���Ʒ�����Լ�����ѡ����Ʒ�����������˳��������˳���\n");
	printf("\t�·�\t\n");
	printf("\t���\t\n");
	printf("\tЬ��\t\n");
	printf("\tˮ��\t\n");
	printf("\t�߲�\t\n");
	printf("\t�鼮\t\n");
	printf("\t����\t\n");
	printf("\t��������\t\n");
	printf("2��ɾ����Ʒ\n");
	printf("3������Ʒ������������\n");
	printf("4��������Ʒ(β�巨)\n");
	printf("5��������Ʒ(ָ��λ��)\n");
	printf("6����ӡ��Ϣ\n");
	printf("7������\n");
	printf("0�˳�\n");
	printf("/*********************************************************/\n");
}

//ѡ������
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
		printf("�����룺\n");
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
			printf("��������Ҫɾ������Ʒ��");
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
			printf("��������Ҫ�������Ʒ��");
			scanf("%s", val1);
			printf("��������Ʒ������:");
			scanf("%d", &num);
			InsertList(head,val1,num);
			system("cls");
			system("pause");
			break;
		case 5:
			printf("��������Ҫ�������Ʒ���ĸ���Ʒ���棺");
			scanf("%s", val2);
			printf("��������Ҫ�������Ʒ��");
			scanf("%s", val1);
			printf("��������Ʒ������:");
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
			printf("����ɹ�!");
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
����ͷ���
�����ͷ����ַ�ɺ���ֵ����
*/
CommodityInfo *CreateList()
{
	char ExitTmp[] = "�˳�";
	CommodityInfo *head = NULL;

	//ͷ�����Ϊ��־�����洢��Ч����
	head = (CommodityInfo *)malloc(sizeof(CommodityInfo));
	if (head == NULL)
	{
		return NULL;
	}

	//��head�ĳ�Ա������ֵ
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

		printf("��������ѡ�����Ʒ���֣�");
		scanf("%s", goods);

		if (0 == (strcmp(goods, ExitTmp)))	//���롰�˳����������˳�
		{
			break;
		}

		printf("��������ѡ����Ʒ�ĸ�����");
		scanf("%d", &number);
		if (0 == number)
		{
			printf("�����������������룺");
			scanf("%d", &number);
		}


		//�½�㶯̬����ռ�
		pNew = (CommodityInfo *)malloc(sizeof(CommodityInfo));
		if (pNew == NULL)
		{
			break;
		}

		//��pNew��Ա������ֵ
		strcpy(pNew->m_Goods, goods);
		pNew->m_Number = number;
		pNew->m_next = NULL;

		//��������ϵ

		//��ǰ����nextָ��pNew
		pCur->m_next = pNew;

		//pNew����һ�����ָ��NULL
		pNew->m_next = NULL;

		//��pCur�ƶ���pNew,pCurָ��pNew
		pCur = pNew;
	}

	return head;
}


//����ı���
int PrintList(CommodityInfo *head)
{
	if (head == NULL)
	{
		return -1;
	}

	//ȡ����һ����Ч���(ͷ����next)
	CommodityInfo *pCur = head->m_next;


	while (pCur != NULL)
	{
		printf("��Ʒ��");
		printf("%s\t", pCur->m_Goods);
		printf("������");
		printf("%d\n", pCur->m_Number);

		//��ǰ��������ƶ�һλ��pCurָ����һ��
		pCur = pCur->m_next;
	}
	printf("\n");

	return 0;
}

//����β��ķ����������ڲ���Ԫ��
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
		
		pPre = pCur;//pPreָ��PCur��λ��
		pCur = pCur->m_next;//pCurָ����һ�����
	}

	CommodityInfo *pNew = (CommodityInfo*)malloc(sizeof(CommodityInfo));
	if (pNew == NULL)
	{
		return -2;
	}
	strcpy(pNew->m_Goods, val);
	pNew->m_Number = val_number;
	pNew->m_next = NULL;

	pPre->m_next = pNew; //pPre��һ��ָ��pNew
	pNew->m_next = pCur; //pNew��һ��ָ��pCur
	
	return 0;

}

//ָ������ķ����������ڲ���Ԫ��
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
	
	//����ָ��λ��
	pPre->m_next = pNew; //pPre��һ��ָ��pNew
	pNew->m_next = pCur; //pNew��һ��ָ��pCur

	return 0;
}


//������Ʒ�ĸ�����������
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


//ɾ����Ʒ
int DeleteList(CommodityInfo *head, char *val)
{
	if (head == NULL)
	{
		return -1;
	}

	int flag = 0;//0Ϊ�ҵ���1Ϊ�ҵ�
	CommodityInfo *pPre = head;
	CommodityInfo *pCur = head->m_next;
	
	while (pCur != NULL)
	{
		if (!(strcmp(pCur->m_Goods, val)))//�ҵ�ƥ��Ľ��
		{
			//pPre����һ�����ָ��PCur����һ��
			pPre->m_next = pCur->m_next;
			free(pCur);
			pCur = NULL;

			flag = 1;
			break;
		}

		pPre = pCur;//pPreָ��pCurλ��
		pCur = pCur->m_next;//pCurָ����һ�����
	}

	if (0 == flag)
	{
		printf("û���ҵ�%s��Ʒ\n", val);
		return -2;
	}

	return 0;
}

//��������������뵽�ļ��б�������
int ConserveList(CommodityInfo *head)
{
	FILE *fp;
	CommodityInfo *pCur = head->m_next;

	if ((fp = fopen("CommodityInformation.txt", "w")) == NULL)
	{
		printf("�ļ��޷��򿪣�\n");
		exit(1);
	}

	if (head == NULL)
	{
		return -1;
	}

	while (pCur != NULL)
	{
		fprintf(fp,"��Ʒ��%s\t", pCur->m_Goods);
		fprintf(fp, "������%d\n", pCur->m_Number);
		pCur = pCur->m_next;

	}

	fclose(fp);
	return 0;
}

//��������ͷ����еĽ��
int DestroyList(CommodityInfo *head)
{
	if (head == NULL)
	{
		return -1;
	}

	//���ڴ�ŵ�ַ�ı���
	CommodityInfo *tmp = NULL;

	while (head == NULL)
	{
		//����head����һ�����
		tmp = head->m_next;
		free(head);
		head = NULL;

		head = tmp;
	}

	return 0;
}