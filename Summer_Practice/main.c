/**
* @file main.c
* @author �i��i��� �.�, ��. 515-�
* @date 7 �����	 2022
* @brief ��������� ��������.
*
* 22 ���i��� - ��������� ���������� �����i�
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "sort_arr.h"

int main()
{
	setlocale(LC_ALL, "ukr");
	printf("��� ���������� �i��������� ����� ������� ������ ��i� �� ������� ����� � �i������i �i� 0 �� 100\n");
	int user_auto, repeat, same, sort_type, arr[size], copy[size];
	do
	{
	printf("������ ������ ����� ���i �� �����������?\n���i - 1 | ����������� - 0 : ");
	scanf_s("%d", &user_auto);
	if (user_auto) person_input(arr);
	else random_input(arr);
	printf("\n��� �����:\n");
	arr_print(arr);
	do
	{
		arr_copy(arr, copy);
		printf("\n���� �������� ���������� �� ������ �����������?\n");
		printf("���������� ������� - 1 | ���������� �i��������� - 2 | ���������� �� ��������� - 3 : ");
		scanf_s("%d", &sort_type);
		switch (sort_type)
		{
		case 1:
			printf("\n����� �i����������� �������:\n");
			mergeSort(copy, 0, size - 1);
			arr_print(copy);
			break;
		case 2:
			printf("\n����� �i����������� �i���������:\n");
			countingSort(copy);
			arr_print(copy);
			break;
		case 3:
			printf("\n�i������������ �����:\n");
			arr_print(copy);
			break;
		default:
			printf("�� ����� ���������� ��������");
			break;
		}
		printf("\n������ �i���������� ��i���� ����� �����?\n��� - 1 | �i - 0 : ");
		scanf_s("%d", &same);
	} while (same);
	printf("\n������ ����������?\n��� - 1 | �i - 0 : ");
	scanf_s("%d", &repeat);
	} while (repeat);
	return 0;
}