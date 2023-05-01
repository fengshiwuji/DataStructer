/***********************************************************************
ʹ�ö�������ʵ��˳���

���ڣ�2023-05-01
************************************************************************/

#include <stdio.h>
#include "seqlist.h"

//˳�����Ժ���
void SeqListTest1(void)
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 8);
	SeqListPrint(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
}

//˳�����Ժ���
void SeqListTest2(void)
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 8);
	SeqListPopFront(&sl);
	SeqListPushFront(&sl, 8);
	SeqListPrint(&sl);
	int pos = SeqListFind(&sl, 8);

	if (pos != -1)
		printf("�ҵ��ˣ��±�: %d\r\n", pos);
	else
		printf("��˳�����δ�ҵ� %d \r\n",8);
}

//˳�����Ժ���
void SeqListTest3(void)
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 8);
	SeqListPopFront(&sl);
	SeqListPushFront(&sl, 8);
	SeqListPrint(&sl);
	int pos = SeqListFind(&sl, 8);

	if (pos != -1)
		printf("�ҵ��ˣ��±�: %d\r\n", pos);
	else
		printf("��˳�����δ�ҵ� %d \r\n", 8);

	SeqListInsert(&sl,pos,100);
	SeqListInsert(&sl, pos, 200);
	SeqListInsert(&sl, pos, 300);
	SeqListInsert(&sl, pos, 400);
	SeqListInsert(&sl, pos, 500);
	SeqListPrint(&sl);
	SeqListErase(&sl, pos);
	SeqListErase(&sl, pos);
	SeqListPrint(&sl);
}

//������
int main(void)
{
	//SeqListTest1();
	//SeqListTest2();
	SeqListTest3();

	return 0;
}
