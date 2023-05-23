#include <stdio.h>
#include "sort.h"


//���Ժ���
void BubbleSortTest(void)
{
	int i = 0;
	int arr[10] = { 5,6,8,7,3,1,2,4,9,0 };

	size_t size = sizeof(arr) / sizeof(arr[0]);

	BubbleSort(arr, size);

	for (i = 0; i < size; i++)
		printf("%d\t", arr[i]);
	printf("\r\n");
}

//���Ժ���
void QuickSortTest(void)
{
	int i = 0;
	int arr[10] = { 20,12,6,17,8,4,4,32,13,48};

	int size = sizeof(arr) / sizeof(arr[0]);

	QuickSort(arr, 0, size-1);

	for (i = 0; i < size; i++)
		printf("%d\t", arr[i]);
	printf("\r\n");
}

//���Ժ���
void SelectSortTest(void)
{
	int i = 0;
	int arr[10] = { 20,12,6,17,8,4,4,32,13,48 };

	int size = sizeof(arr) / sizeof(arr[0]);

	SelectSort(arr, size);

	for (i = 0; i < size; i++)
		printf("%d\t", arr[i]);
	printf("\r\n");
}

//ֱ�Ӳ�������
void InsertSortTest(void)
{
	int i = 0;
	int arr[10] = { 20,12,6,17,8,4,4,32,13,48 };

	int size = sizeof(arr) / sizeof(arr[0]);

	InsertSort(arr, size);

	for (i = 0; i < size; i++)
		printf("%d\t", arr[i]);
	printf("\r\n");
}

//ϣ������
void HillSortTest(void)
{
	int i = 0;
	int arr[] = { 20,12,6,17,8,4,4,32,13,48,4,32,13,48,20,12,6,17,8};

	int size = sizeof(arr) / sizeof(arr[0]);

	HillSort(arr, size);

	for (i = 0; i < size; i++)
		printf("%d\t", arr[i]);
	printf("\r\n");
}

//������
int main(void)
{
	//BubbleSortTest();
	//QuickSortTest();
	//SelectSortTest();
	//InsertSortTest();
	
	HillSortTest();

	return 0;
}