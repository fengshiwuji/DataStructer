#pragma once

#include <stdio.h> 
#include <stdlib.h> 
#include "memory.h"

typedef int SLDataType;	

typedef struct SeqList
{
	SLDataType* data;
	int size;		//��¼�洢�˶��ٸ�Ԫ��
	int capacity;
}SL;

/*-------------------------------˳����ýӿ�����-------------------------------*/

void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListPushBack(SL* ps, SLDataType data);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType data);
void SeqListPopFront(SL* ps);
void SeqListPushInsert(SL* ps, int pos, SLDataType data);
void SeqListErase(SL* ps, int pos);
int SeqListFind(SL* ps, SLDataType data);
void SeqListDestory(SL* ps);

/*--------------------------------------end--------------------------------------*/
