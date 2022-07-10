/**
* @file sort_arr.c
* @author Лiтвiнов А.А, гр. 515-В
* @date 7 липня	 2022
* @brief Навчальна практика.
*
* 22 Варiант - Алгоритми сортування масивiв
*/

#include "sort_arr.h"

//Функція для об'єднання масивів при сортуванні злиттям
PRIVATE void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	//Створюємо тимчасові масиви
	int* L = (int*)calloc(n1, sizeof(int));
	int* R = (int*)calloc(n2, sizeof(int));

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

//Функція для знаходження максимального елементу масиву
PRIVATE int getMax(int arr[], unsigned int element_num)
{
	int max = arr[0];
	for (int i = 1; i < element_num; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

//Функція сортуванню підрахунком для сортування за розрядом
PRIVATE void counting_radixSort(int arr[], int place, unsigned int element_num)
{
	int* output = (int*)calloc(element_num, sizeof(int));
	int max = (arr[0] / place) % 10;

	//Знаходимо найбільшие число
	for (int i = 1; i < element_num; i++)
	{
		if (((arr[i] / place) % 10) > max)
			max = arr[i];
	}

	int* count = (int*)calloc(max + 1, sizeof(int));

	for (int i = 0; i < max; i++)
		count[i] = 0;

	//В циклі рахуємо кількість чисел
	for (int i = 0; i < element_num; i++)
		count[(arr[i] / place) % 10]++;

	//Обчислюємо кумулятивну кількість
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	//Поміщаємо елементи в відсортованому порядку
	for (int i = element_num - 1; i >= 0; i--)
	{
		output[count[(arr[i] / place) % 10] - 1] = arr[i];
		count[(arr[i] / place) % 10]--;
	}

	//Заносимо скопійовані значення до головного масиву
	for (int i = 0; i < element_num; i++)
		arr[i] = output[i];
}

//Функція яка знаходить чи є негативний елемент в масиві, для сортування підрахунком та за розрядом
PRIVATE int negative_found(int arr[], unsigned int element_num)
{
	for (int i = 0; i < element_num; i++)
		if (arr[i] < 0) return 0;
	return 1;
}

PUBLIC void person_input(int arr[], unsigned int element_num)
{
	for (int i = 0; i < element_num; i++)
	{
		printf("Введiть arr[%d] = ", i);
		scanf_s("%d", &arr[i]);
	}
	return;
}

PUBLIC void random_input(int arr[], unsigned int element_num)
{
	srand(time(NULL));
	for (int i = 0; i < element_num; i++)
		arr[i] = rand() % 201 - 100;
	return;
}

PUBLIC void arr_print(int arr[], unsigned int element_num)
{
	for (int i = 0; i < element_num; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	return;
}

PUBLIC void arr_copy(int arr[], int copy[], unsigned int element_num)
{
	for (int i = 0; i < element_num; i++)
		copy[i] = arr[i];
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

PUBLIC void countingSort(int arr[], unsigned int element_num)
{
	if (negative_found(arr, element_num))
	{
		int* output = (int*)calloc(element_num, sizeof(int));

		//Знаходимо найбільший елемент масиву
		int max = getMax(arr, element_num);

		int* count = (int*)calloc(max + 1, sizeof(int));

		for (int i = 0; i < max; i++)
			count[i] = 0;

		//Зберігаємо кількість кожного числа
		for (int i = 0; i < element_num; i++)
			count[arr[i]]++;

		//Обчислюємо кумулятивну кількість
		for (int i = 1; i <= max; i++)
			count[i] += count[i - 1];

		//Поміщаємо елементи в відсортованому порядку
		for (int i = size - 1; i >= 0; i--) {
			output[count[arr[i]] - 1] = arr[i];
			count[arr[i]]--;
		}

		//Заносимо скопійовані значення до головного масиву
		for (int i = 0; i < element_num; i++) {
			arr[i] = output[i];
		}
	}
	else
	{
		printf("\nВи ввели негативне значення яке неприпустиме для цього алгоритму сортування");
		exit(negative);
	}
}

PUBLIC void radixSort(int arr[], unsigned int element_num)
{
	if (negative_found(arr, element_num))
	{
		//Знаходимо максимальний елемент
		int max = getMax(arr, element_num);

		//Застосовуємо сортировку підрахунком по місцям
		for (int place = 1; max / place > 0; place *= 10)
			counting_radixSort(arr, place, element_num);

	}
	else
	{
		printf("\nВи ввели негативне значення яке неприпустиме для цього алгоритму сортування");
		exit(negative);
	}
}

