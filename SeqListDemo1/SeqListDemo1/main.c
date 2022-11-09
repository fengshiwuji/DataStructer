/******************************************************************************
  *  Instruction: ��ϰ��̬˳���
  *  Time : 2022-11-10
  *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include "SeqList.h"

#pragma warning(disable:4996)
#pragma warning(disable:6031)

/*��β�塢βɾ�Ĳ���*/
void SeqListTest1(void)
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);
	printf("����ɹ�\n");
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
	printf("βɾ�ɹ�\n");
	SeqListDestory(&sl);	/*���ٿռ�*/
}

/*��ͷ�塢ͷɾ�Ĳ���*/
void SeqListTest2(void)
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPrint(&sl);
	printf("����ɹ�\n");
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);
	printf("βɾ�ɹ�\n");
	SeqListDestory(&sl);	/*���ٿռ�*/
}

/*������λ�ò��롢ɾ���Ĳ���*/
void SeqListTest3(void)
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushInsert(&sl,0,1);
	SeqListPushInsert(&sl,0,2);
	SeqListPushInsert(&sl, 0, 3);
	SeqListPrint(&sl);
	printf("����ɹ�\n");
	SeqListErase(&sl,0);
	SeqListPrint(&sl);
	printf("ɾ���ɹ�\n");
}

/*��SeqListFind�����Ĳ���*/
void SeqListTest4(void)
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushInsert(&sl, 0, 1);
	SeqListPushInsert(&sl, 0, 2);
	SeqListPushInsert(&sl, 0, 3);
	SeqListPrint(&sl);
	printf("����ɹ�\n");

	int pos = SeqListFind(&sl,5);
	if (pos != -1)
	{
		printf("�ҵ��ˣ��±�Ϊ%d\n",pos);
	}
	else
	{
		printf("δ�ҵ�������!\n");
	}

}

/**
  * @brief main����
  * @param None.
  * @return None.
  */
int main(void)
{
	//SeqListTest1();

	//SeqListTest2();

	//SeqListTest3();

	SeqListTest4();

	return 0;
}