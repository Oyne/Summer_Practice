/**
* @file main.c
* @author Лiтвiнов А.А, гр. 515-В
* @date 7 липня	 2022
* @brief Навчальна практика.
*
* 22 Варiант - Алгоритми сортування масивiв
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "sort_arr.h"

int main()
{
	setlocale(LC_ALL, "ukr");
	printf("Для сортування пiдрахунком треба вибрати ручний ввiд та вводити числа в дiапазонi вiд 0 до 100\n");
	int user_auto, repeat, same, sort_type, arr[size], copy[size];
	do
	{
	printf("Бажаєте ввести масив самi чи автоматично?\nСамi - 1 | Автоматично - 0 : ");
	scanf_s("%d", &user_auto);
	if (user_auto) person_input(arr);
	else random_input(arr);
	printf("\nВаш масив:\n");
	arr_print(arr);
	do
	{
		arr_copy(arr, copy);
		printf("\nЯкий алгоритм сортування ви бажаєте використати?\n");
		printf("сортування злиттям - 1 | сортування пiдрахунком - 2 | сортування за розрядами - 3 : ");
		scanf_s("%d", &sort_type);
		switch (sort_type)
		{
		case 1:
			printf("\nМасив вiдсортований злиттям:\n");
			mergeSort(copy, 0, size - 1);
			arr_print(copy);
			break;
		case 2:
			printf("\nМасив вiдсортований пiдрахунком:\n");
			countingSort(copy);
			arr_print(copy);
			break;
		case 3:
			printf("\nВiдсортованний масив:\n");
			arr_print(copy);
			break;
		default:
			printf("Ви ввели некоректне значення");
			break;
		}
		printf("\nБажаєте вiдсортувати вхiдний масив знову?\nТак - 1 | Нi - 0 : ");
		scanf_s("%d", &same);
	} while (same);
	printf("\nБажаєте продовжити?\nТак - 1 | Нi - 0 : ");
	scanf_s("%d", &repeat);
	} while (repeat);
	return 0;
}