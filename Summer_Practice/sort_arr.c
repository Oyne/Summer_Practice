/**
* @file sort_arr.c
* @author �i��i��� �.�, ��. 515-�
* @date 7 �����	 2022
* @brief ��������� ��������.
*
* 22 ���i��� - ��������� ���������� �����i�
*/

#include "sort_arr.h"

PUBLIC void person_input(int arr[])
{
		for (int i = 0; i < size; i++)
		{
			printf("����i�� arr[%d] = ", i);
			scanf_s("%d", &arr[i]);
		}
		return;
} 

PUBLIC void random_input(int arr[])
{
		srand(time(NULL));
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 201 - 100;
		}
		return;
}

PUBLIC void arr_print(int arr[])
{
	for (int i = 0; i < size; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	return;
}

PUBLIC void arr_copy(int arr[], int copy[])
{
	for (int i = 0; i < size; i++)
	{
		copy[i] = arr[i];
	}
}

//������� ��� ��'������� ������ ��� ���������� �������
PRIVATE void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	//��������� �������� ������
	int *L = malloc(n1), *R = malloc(n2);

	//������� �������� �� ���
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	//��'������ �������� ������
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	//������� �������� �� ���������� � L[]
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	//������� �������� �� ���������� � R[]
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

PUBLIC void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		//��������� ��������
		int m = l + (r - l) / 2;

		//���������� ������� �� �������
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		//��'������ �����
		merge(arr, l, m, r);
	}
}

PUBLIC void countingSort(int arr[])
{
	//����� ��� ������� �������� �����
	int count[101] = { 0 };

	//� ���� �������� ������ ��������� �����
	for (int i = 0; i < size; ++i)
		count[arr[i]]++;

	//����� �������� ������������� ������
	int element_num = 0;
	
	//� ���� ���������� �����
	for (int i = 0; i <= 100; ++i)
		for (int j = 1; j <= count[i]; ++j)
		{
			arr[element_num] = i;
			element_num++;
		}
}