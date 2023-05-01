#include "seqlist.h"


/**************************************************************
  * @brief �ڴ濽������
  * @param dest:Ŀ�ĵ�ַ
  * @param src:Դ��ַ
  * @param count:�����ֽ���
  * @return Ŀ�ĵ�ַ.
  *************************************************************/
void* my_memmove(void* dest, const void* src, size_t count)
{
	void* temp = dest;
	/*��Ŀ�ĵ�ַ��Դ��ַС���ǰ���󿽱�������֮*/
	if (dest < src)
	{
		while (count--)
		{
			*((char*)dest) = *((char*)src);
			++(char*)dest;
			++(char*)src;
		}
	}
	else
	{
		dest = (char*)dest + count - 1;
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dest = *(char*)src;
			--(char*)dest;
			--(char*)src;
		}
	}
	return temp;
}

/*******************************************
�������ܣ���ʼ��˳���
����������psl��˳���ṹ������ĵ�ַ
********************************************/
void SeqListInit(SeqList* psl)
{
	psl->Data = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

/*******************************************
�������ܣ�˳����ӡ
����������psl��˳���ṹ������ĵ�ַ
********************************************/
void SeqListPrint(SeqList* psl)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
		printf("%d\t",psl->Data[i]);
	printf("\r\n");
}

/*******************************************
�������ܣ�˳������
����������psl��˳���ṹ������ĵ�ַ
********************************************/
static void SeqListCheckCapacity(SeqList* psl)
{
	if (psl->size == psl->capacity)
	{
		size_t NewCapacity = (psl->capacity == 0) ? 4 : psl->capacity * 2;
		SLDataType* temp = (SLDataType*)realloc(psl->Data, NewCapacity*sizeof(SLDataType));
		if (temp != NULL)
		{
			psl->Data = temp;
			psl->capacity = NewCapacity;
		}
	}
}

/*******************************************
�������ܣ�˳���β��
����������psl��˳���ṹ������ĵ�ַ
		  x: ����
********************************************/
void SeqListPushBack(SeqList* psl,SLDataType x)
{
	SeqListCheckCapacity(psl);
	psl->Data[psl->size] = x;
	psl->size++;
}

/*******************************************
�������ܣ�˳���βɾ
����������psl��˳���ṹ������ĵ�ַ
********************************************/
void SeqListPopBack(SeqList* psl)
{
	if (psl->size)
		psl->size--;
}

/*******************************************
�������ܣ�˳���ͷ��
����������psl��˳���ṹ������ĵ�ַ
		  x: ����
********************************************/
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	SeqListCheckCapacity(psl);
	my_memmove(psl->Data + 1, psl->Data, psl->size * sizeof(SLDataType));
	psl->Data[0] = x;
	psl->size++;
}

/*******************************************
�������ܣ�˳���ͷɾ
����������psl��˳���ṹ������ĵ�ַ
********************************************/
void SeqListPopFront(SeqList* psl)
{
	if (psl->size)
	{
		my_memmove(psl->Data, psl->Data+1, (psl->size-1) * sizeof(SLDataType));
		psl->size--;
	}	
}

/*******************************************
�������ܣ�˳����м����
����������psl��˳���ṹ������ĵ�ַ
          pos:Ҫ�����λ��
		  x: ����
********************************************/
void SeqListInsert(SeqList* psl, size_t pos,SLDataType x)
{
	SeqListCheckCapacity(psl);
	my_memmove(psl->Data + pos+1, psl->Data+pos, (psl->size-pos) * sizeof(SLDataType));
	psl->Data[pos] = x;
	psl->size++;
}

/*******************************************
�������ܣ�˳����м�ɾ��
����������psl��˳���ṹ������ĵ�ַ
          pos:Ҫɾ����λ��
********************************************/
void SeqListErase(SeqList* psl,size_t pos)
{
	my_memmove(psl->Data + pos, psl->Data + pos+1, (psl->size - pos-1) * sizeof(SLDataType));
	psl->size--;
}

/*******************************************
�������ܣ�˳�������
����������psl��˳���ṹ������ĵ�ַ
********************************************/
void SeqListDestory(SeqList* psl)
{
	free(psl->Data);
	psl->Data = NULL;
	psl->size = psl->capacity = NULL;
}

