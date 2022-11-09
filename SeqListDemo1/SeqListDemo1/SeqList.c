#include "SeqList.h"


/**
  * @brief ��ʼ��˳���
  * @param ps:˳���
  * @return None.
  */
void SeqListInit(SL* ps)
{
	ps->data = NULL;
	ps->size = ps->capacity = 0;
}

/**
  * @brief ˳����ӡ���
  * @param ps:˳���
  * @return None.
  */
void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d\t", ps->data[i]);
	}
	printf("\n");
}

/**
  * @brief ˳���Ĳ���
  * @param ps:˳���
  * @return None.
  */
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newCapacity = (ps->capacity == 0) ? 4 : ps->capacity * 2;
		SLDataType* temp = (SLDataType*)realloc(ps->data, newCapacity * sizeof(SLDataType));
		if (temp != NULL)
		{
			ps->data = temp;
			ps->capacity = newCapacity;
			printf("�ռ俪�ٳɹ���newCapacity:%d\n", newCapacity);
		}
	}
}

/**
  * @brief ˳����β��
  * @param ps:˳���
  * @param data:Ҫ���������
  * @return None.
  */
void SeqListPushBack(SL* ps, SLDataType data)
{
	SeqListCheckCapacity(ps);
	ps->data[ps->size] = data;
	ps->size++;
}

/**
  * @brief ˳����βɾ
  * @param ps:˳���
  * @return None.
  */
void SeqListPopBack(SL* ps)
{
	ps->size--;
}


/**
  * @brief ˳����ͷ��
  * @param ps:˳���
  * @param data:Ҫ���������
  * @return None.
  */
void SeqListPushFront(SL* ps, SLDataType data)
{
	SeqListCheckCapacity(ps);
	my_memmove(ps->data + 1, ps->data, ps->size*sizeof(SLDataType));
	ps->data[0] = data;
	ps->size++;
}

/**
  * @brief ˳����ͷɾ
  * @param ps:˳���
  * @return None.
  */
void SeqListPopFront(SL* ps)
{
	my_memmove(ps->data,ps->data +1, ps->size*sizeof(SLDataType));
	ps->size--;
}

/**
  * @brief ˳�������λ�ò���
  * @param ps:˳���
  * @param data:���������
  * @return None.
  */
void SeqListPushInsert(SL* ps, int pos, SLDataType data)
{
	assert(pos>=0);
	SeqListCheckCapacity(ps);
	my_memmove(ps->data + 1+pos, ps->data+pos , (ps->size-pos) * sizeof(SLDataType));
	ps->data[pos] = data;
	ps->size++;
}

/**
  * @brief ɾ������λ�õ�Ԫ��
  * @param ps:˳���
  * @return None.
  */
void SeqListErase(SL* ps, int pos)
{
	assert(ps->data && pos >= 0); 
	my_memmove(ps->data + pos, ps->data + pos + 1, (ps->size - pos - 1) * sizeof(SLDataType));
	ps->size--;
}

/**
  * @brief	��˳����������
  * @param ps:˳���
  * @param data:Ҫ���ҵ�����
  * @return �ҵ��˷���������˳�����±꣬�Ҳ�������-1.
  */
int SeqListFind(SL* ps, SLDataType data)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == data)
			return i;
	}
	return -1;
}

/**
  * @brief ���ٶ�̬����Ŀռ�
  * @param ps:˳���
  * @return None.
  */
void SeqListDestory(SL* ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->size = ps->capacity = 0;
}
