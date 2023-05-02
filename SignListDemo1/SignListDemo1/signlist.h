#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

void SListPrint(SListNode* plist);
SListNode* CreatSListNode(SListDataType x);
void SListPushBack(SListNode** pplist, SListDataType x);
void SListPopBack(SListNode** pplist);
void SListPushFront(SListNode** pplist, SListDataType x);
void SListPopFront(SListNode** pplist);
SListNode* SListFind(SListNode* plist, SListDataType x);
void SListInsert(SListNode** pplist, SListNode* pos, SListDataType x);
void SListErase(SListNode** pplist, SListNode* pos);
void SListDestory(SListNode** pplist);