#include <stdio.h>
#include "seqlist.h"

//顺序表的测试
void SeqListTest1(void)
{
	SeqList sl;
	
	SeqListInit(&sl);
	SeqListPushBack(&sl, 8);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);
	
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

//顺序表的测试
void SeqListTest2(void)
{
	SeqList sl;

	SeqListInit(&sl);
	SeqListPushFront(&sl, 8);
	SeqListPushFront(&sl, 7);
	SeqListPushFront(&sl, 6);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

//顺序表的测试
void SeqListTest3(void)
{
	SeqList sl;

	SeqListInit(&sl);
	SeqListInsert(&sl,0,8);
	SeqListInsert(&sl,0,7);
	SeqListInsert(&sl,1,6);
	SeqListInsert(&sl,2,5);
	SeqListPrint(&sl);

	SeqListErase(&sl,0);
	SeqListErase(&sl,0);
	SeqListErase(&sl,1);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

//主函数
int main(void)
{
	//SeqListTest1();
	//SeqListTest2();
	SeqListTest3();

	return 0;
}
