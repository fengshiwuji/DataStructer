#include "signlist.h"

/*********************************************************
�������ܣ���������һ���ڵ�
����������x������
����ֵ���´����ڵ�ĵ�ַ.
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
�������ܣ��������ӡ
����������plistָ������ͷ���
����ֵ��None.
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
�������ܣ�������β��
����������plistָ������ͷ���
		  x:����
����ֵ��None.
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
�������ܣ�������βɾ
����������plistָ������ͷ���
		  x:����
����ֵ��None.
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
�������ܣ�������ͷ��
����������plistָ������ͷ���
		  x:����
����ֵ��None.
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
�������ܣ�������ͷɾ
����������plistָ������ͷ���
		  x:����
����ֵ��None.
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
�������ܣ����������
����������plistָ������ͷ���
		  x:���ҵ�����
����ֵ��None.
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
�������ܣ����������
����������plistָ������ͷ���
	      pos:�����λ��
		  x:���ҵ�����
����ֵ��None.
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
�������ܣ��������м�ɾ��
����������plistָ������ͷ���
		  pos:Ҫɾ���Ľڵ��ַ
����ֵ��None.
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
�������ܣ�����������
����������pplistָ������ͷ����ָ��ĵ�ַ
����ֵ��None.
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
	printf("�������ٳɹ���\r\n");
}