/**
* @file sort_arr.c
* @author �i��i��� �.�, ��. 515-�
* @date 7 �����	 2022
* @brief ��������� ��������.
*
* 22 ���i��� - ��������� ���������� �����i�
*/

#include "sort_arr.h"

//������� ��� ��'������� ������ ��� ��������� �������
PRIVATE void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	//��������� �������� ������
	int* L = (int*)calloc(n1, sizeof(int));
	int* R = (int*)calloc(n2, sizeof(int));

	//������� �������� �� ���
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	//��'����� �������� ������
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

//�������� ��� ����������� ������������� �������� ������
PRIVATE int getMax(int arr[]) 
{
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

//������� ���������� ���������� ��� ���������� �� ��������
PRIVATE void counting_radixSort(int arr[], int place)
{
	int output[size];
	int max = (arr[0] / place) % 10;

	//��������� ��������� �����
	for (int i = 1; i < size; i++)
	{
		if (((arr[i] / place) % 10) > max)
			max = arr[i];
	}
	int count[size] = { 0 };

	//� ���� ������ ������� �����
	for (int i = 0; i < size; i++)
		count[(arr[i] / place) % 10]++;

	//���������� ����������� �������
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	//������� �������� � ������������� �������
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(arr[i] / place) % 10] - 1] = arr[i];
		count[(arr[i] / place) % 10]--;
	}

	//�������� ��������� �������� �� ��������� ������
	for (int i = 0; i < size; i++)
		arr[i] = output[i];
}

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

	int output[size];

	//��������� ��������� ������� ������
	int max = getMax(arr);

	int count[counting_size] = { 0 };

	//�������� ������� ������� �����
	for (int i = 0; i < size; i++) 
		count[arr[i]]++;
	
	//���������� ����������� �������
	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];
	
	//������� �������� � ������������� �������
	for (int i = size - 1; i >= 0; i--) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	//�������� ��������� �������� �� ��������� ������
	for (int i = 0; i < size; i++) {
		arr[i] = output[i];
	}
}

PUBLIC void radixSort(int arr[]) {
	//��������� ������������ �������
	int max = getMax(arr);

	//����������� ���������� ���������� �� �����
	for (int place = 1; max / place > 0; place *= 10)
		counting_radixSort(arr, place);
}

