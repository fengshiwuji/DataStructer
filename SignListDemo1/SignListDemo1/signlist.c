#include "signlist.h"

/*********************************************************
函数功能：单链表创建一个节点
函数参数：x：数据
返回值：新创建节点的地址.
**********************************************************/
SListNode* CreatSListNode(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListDataType));
	if (newNode != NULL)
	{
		newNode->data = x;
		newNode->next = NULL;
		return newNode;
	}
	return NULL;
}


/*********************************************************
函数功能：单链表打印
函数参数：plist指向单链表头结点
返回值：None.
**********************************************************/
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

/*********************************************************
函数功能：单链表尾插
函数参数：plist指向单链表头结点
		  x:数据
返回值：None.
**********************************************************/
void SListPushBack(SListNode** pplist,SListDataType x)
{
	SListNode* NewNode = CreatSListNode(x);
	if (NewNode)
	{
		if (*pplist == NULL)
		{
			*pplist = NewNode;
		}
		else
		{
			SListNode* tail = *pplist;
			while (tail->next!=NULL)
			{
				tail = tail->next;
			}
			tail->next = NewNode;
		}
	}
}

/*********************************************************
函数功能：单链表尾删
函数参数：plist指向单链表头结点
		  x:数据
返回值：None.
**********************************************************/
void SListPopBack(SListNode** pplist)
{
	if (*pplist)
	{
		if ((* pplist)->next==NULL)
		{
			free(*pplist);
			*pplist = NULL;
		}
		else
		{
			SListNode* prev = *pplist;
			SListNode* tail = *pplist;
			while (tail->next)
			{
				prev = tail;
				tail = tail->next;
			}
			free(tail);
			prev->next = NULL;
		}
	}
}

/*********************************************************
函数功能：单链表头插
函数参数：plist指向单链表头结点
		  x:数据
返回值：None.
**********************************************************/
void SListPushFront(SListNode** pplist, SListDataType x)
{
	SListNode* NewNode = CreatSListNode(x);
	if (*pplist==NULL)
	{
		*pplist = NewNode;
	}
	else
	{
		NewNode->next = *pplist;
		*pplist = NewNode;
	}
}

/*********************************************************
函数功能：单链表头删
函数参数：plist指向单链表头结点
		  x:数据
返回值：None.
**********************************************************/
void SListPopFront(SListNode** pplist)
{
	SListNode* dhead = NULL;
	if (*pplist)
	{
		dhead = *pplist;
		*pplist = dhead->next;
		free(dhead);
	}
}

/*********************************************************
函数功能：单链表查找
函数参数：plist指向单链表头结点
		  x:查找的数据
返回值：None.
**********************************************************/
SListNode* SListFind(SListNode* plist,SListDataType x)
{
	while (plist)
	{
		if (plist->data == x)
			return plist;
		plist = plist->next;
	}
	return NULL;
}


/*********************************************************
函数功能：单链表查找
函数参数：plist指向单链表头结点
	      pos:插入的位置
		  x:查找的数据
返回值：None.
**********************************************************/
void SListInsert(SListNode** pplist, SListNode* pos, SListDataType x)
{
	SListNode* NewNode = CreatSListNode(x);
	if (*pplist == pos)
	{
		NewNode->next = *pplist;
		*pplist = NewNode;
	}
	else
	{
		SListNode* prevPos = *pplist;
		while (prevPos->next != pos)
		{
			prevPos = prevPos->next;
		}
		NewNode->next = pos;
		prevPos->next = NewNode;
	}
}

/*********************************************************
函数功能：单链表中间删除
函数参数：plist指向单链表头结点
		  pos:要删除的节点地址
返回值：None.
**********************************************************/
void SListErase(SListNode** pplist, SListNode* pos)
{
	if (*pplist == pos)
	{
		*pplist = pos->next;
		free(pos);
	}
	else
	{
		SListNode* prevPos = *pplist;
		while (prevPos->next != pos)
		{
			prevPos = prevPos->next;
		}
		prevPos->next = pos->next;
		free(pos);
	}
}

/*********************************************************
函数功能：单链表销毁
函数参数：pplist指向单链表头结点的指针的地址
返回值：None.
**********************************************************/
void SListDestory(SListNode** pplist)
{
	SListNode* del = *pplist;
	SListNode* cur = *pplist;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		free(del);
	}
	printf("链表销毁成功！\r\n");
}