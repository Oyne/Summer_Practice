/**
* @file sort_arr.c
* @author Лiтвiнов А.А, гр. 515-В
* @date 7 липня	 2022
* @brief Навчальна практика.
*
* 22 Варiант - Алгоритми сортування масивiв
*/

#include "sort_arr.h"

PUBLIC void person_input(int arr[])
{
		for (int i = 0; i < size; i++)
		{
			printf("Введiть arr[%d] = ", i);
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

//Функція для об'єднання масивів при сортвуанні злиттям
PRIVATE void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	//Створюємо тимчасові масиви
	int *L = malloc(n1), *R = malloc(n2);

	//Копіюємо значення до них
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	//Об'єднємо тимчасові масиви
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

	//Копіюємо елементи які залишилися в L[]
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	//Копіюємо елементи які залишилися в R[]
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
		//Знаходимо середину
		int m = l + (r - l) / 2;

		//Рекурсивно сортуємо обі частини
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		//Об'єднуємо масив
		merge(arr, l, m, r);
	}
}

PUBLIC void countingSort(int arr[])
{
	//Масив для кількості повторнь чисел
	int count[101] = { 0 };

	//В циклі записуємо кілкість повторень чисел
	for (int i = 0; i < size; ++i)
		count[arr[i]]++;

	//Номер елементу відсортованого масиву
	int element_num = 0;
	
	//В циклі заповнюємо масив
	for (int i = 0; i <= 100; ++i)
		for (int j = 1; j <= count[i]; ++j)
		{
			arr[element_num] = i;
			element_num++;
		}
}