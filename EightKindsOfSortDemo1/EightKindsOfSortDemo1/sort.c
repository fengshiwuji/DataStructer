#include "sort.h"


/*************************************************
�������ܣ������������ͱ�����ֵ
����������arr:������ͱ���������Ԫ���׵�ַ
		  size:������Ԫ�صĸ���
����ֵ��None.
**************************************************/
void swap(int* pnum1, int* pnum2)
{
    int temp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = temp;
}

/*************************************************
�������ܣ�ʵ�ֶ����������ð������
����������arr:������ͱ���������Ԫ���׵�ַ
		  size:������Ԫ�صĸ���
����ֵ��None.
**************************************************/
void BubbleSort(int* arr, size_t size)
{
	int i = 0; 
	int j = 0;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

/*************************************************
�������ܣ���������(hoare�汾)
����������arr:������ͱ���������Ԫ���׵�ַ
		  left:��������±�
		  right����������±�
����ֵ�������±��������ʱ������λ��.
**************************************************/
int PartSort1(int* arr, int left, int right)
{
	int base = left;

	while (left < right)
	{
		while (left < right && (arr[right] >= arr[base]))
			right--;
		while (left < right && (arr[left] <= arr[base]))
			left++;
		if (left < right)
			swap(&arr[left], &arr[right]);
	}
	swap(&arr[base], &arr[left]);
	return left;
}
/*************************************************
�������ܣ���������(�ڿӷ�)
����������arr:������ͱ���������Ԫ���׵�ַ
		  left:��������±�
		  right����������±�
����ֵ�������±��������ʱ������λ��.
**************************************************/
int PartSort2(int* arr, int left, int right)
{
	int base = arr[left];

	while (left < right)
	{
		while (left < right && (arr[right] >= base))
			right--;
		arr[left] = arr[right];

		while (left < right && (arr[left] <= base))
			left++;
		arr[right] = arr[left];
	}
	arr[left] = base;
	return left;
}

/*************************************************
�������ܣ�ʵ�ֶ���������Ŀ�������
����������arr:������ͱ���������Ԫ���׵�ַ
		  size:������Ԫ�صĸ���
����ֵ��None.
**************************************************/
void QuickSort(int* arr, int left,int right)
{
	if (left >= right)
		return;

	int met = 0;

	met = PartSort2(arr, left, right);

	QuickSort(arr, left, met - 1);
	QuickSort(arr, met+1, right);
}


/*************************************************
�������ܣ�ʵ�ֶ����������ֱ��ѡ������
����������arr:������ͱ���������Ԫ���׵�ַ
		  size:������Ԫ�صĸ���
����ֵ��None.
**************************************************/
void SelectSort(int* arr, size_t size)
{
	size_t cur = 0;
	size_t  i = 0;
	size_t min = 0;

	while (cur < size)
	{
		for (i = cur; i < size; i++)
		{
			if (arr[i] < arr[min])
				min = i;
		}
		swap(&arr[cur],&arr[min]);
		cur++;
		min = cur;
	}
}

/*************************************************
�������ܣ�ʵ�ֶ����������ֱ�Ӳ�������
����������arr:������ͱ���������Ԫ���׵�ַ
		  size:������Ԫ�صĸ���
����ֵ��None.
**************************************************/
void InsertSort(int* arr, int size)
{
	int i = 0;
	int cur = 0;
	int temp = 0;
	for (i = 0; i < size-1; i++)
	{
		cur = i;
		temp = arr[cur+1];
		while (cur >= 0)
		{
			if (temp < arr[cur])
			{
				arr[cur + 1] = arr[cur];
				cur--;
			}
			else
				break;
		}
		arr[cur + 1] = temp;
	}
}


/*************************************************
�������ܣ�ʵ�ֶ����������ϣ������
����������arr:������ͱ���������Ԫ���׵�ַ
		  size:������Ԫ�صĸ���
����ֵ��None.
**************************************************/
void HillSort(int* arr, int size)
{
	int i = 0;
	int cur = 0;
	int temp = 0;
	int gap = size / 2;
	while (gap)
	{
		for (i = 0; i < size - gap; i++)
		{
			cur = i;
			temp = arr[cur + gap];
			while (cur >= 0)
			{
				if (temp < arr[cur])
				{
					arr[cur + gap] = arr[cur];
					cur-=gap;
				}
				else
					break;
			}
			arr[cur + gap] = temp;
		}
		gap /= 2;
	}
}
