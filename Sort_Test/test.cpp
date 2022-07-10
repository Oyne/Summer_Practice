/**
* @file test.cpp
* @author Лiтвiнов А.А, гр. 515-В
* @date 8 липня	 2022
* @brief Навчальна практика.
*
* 22 Варiант - Алгоритми сортування масивiв
*/

#include "pch.h"
#include "..\Summer_Practice\sort_arr.c"

//Функція яка перевіряє два масива на ідентичність
int comp(int arr1[], int arr2[], unsigned int element_num)
{
	for (int i = 0; i < element_num; i++)
		if (arr1[i] != arr2[i]) return 0;
	return 1;
}

TEST(negative_found_test, performance)
{
	//Тест 1
	int test1[] = { -132, -25, 345, 99, 123, 2004, 9, 0, 3, 10 };
	size_t test1_size = sizeof test1 / sizeof * test1;

	//Тест 2
	int test2[] = { 6073, 8277, 4612, 9573, 8443, 6061, 5690, 298, 8860, 2967 };
	size_t test2_size = sizeof test2 / sizeof * test2;

	//Тест 3
	int test3[] = { 673, 3125, 215, 9804, 1023, 10, 9, 0, 1011, 54 };
	size_t test3_size = sizeof test3 / sizeof * test3;

	EXPECT_EQ(0, negative_found(test1, test1_size));
	EXPECT_EQ(1, negative_found(test2, test2_size));
	EXPECT_EQ(1, negative_found(test3, test3_size));
}

TEST(getMax_test, performance)
{
	//Тест 1
	int test1[] = { -132, -25, 345, 99, 123, 2004, 9, 0, 3, 10 };
	int max1 = 2004;
	size_t test1_size = sizeof test1 / sizeof * test1;

	//Тест 2
	int test2[] = { 6073, 8277, 4612, 9573, 8443, 6061, 5690, 298, 8860, 2967 };
	int max2 = 9573;
	size_t test2_size = sizeof test2 / sizeof * test2;

	//Тест 3
	int test3[] = { 673, 3125, 215, 9804, 1023, 10, 9, 0, 1011, 54 };
	int max3 = 9804;
	size_t test3_size = sizeof test3 / sizeof * test3;

	EXPECT_EQ(max1, getMax(test1, test1_size));
	EXPECT_EQ(max2, getMax(test2, test2_size));
	EXPECT_EQ(max3, getMax(test3, test3_size));
}

TEST(mergeSort_test, performance)
{
	//Тест 1
	int test1[] = { -132, -25, 345, 99, 123, 2004, 9, 0, 3, 10 };
	int test1_sorted[] = { -132, -25, 0, 3, 9, 10, 99, 123, 345, 2004 };
	size_t test1_size = sizeof test1 / sizeof * test1;

	//Тест 2
	int test2[] = { 6073, 8277, 4612, 9573, 8443, 6061, 5690, 298, 8860, 2967 };
	int test2_sorted[] = { 298, 2967, 4612 ,5690 ,6061 ,6073 ,8277, 8443 ,8860 ,9573 };
	size_t test2_size = sizeof test2 / sizeof * test2;

	//Тест 3
	int test3[] = { 673, 3125, 215, 9804, 1023, 10, 9, 0, 1011, 54 };
	int test3_sorted[] = { 0, 9, 10, 54, 215, 673, 1011, 1023, 3125, 9804 };
	size_t test3_size = sizeof test3 / sizeof * test3;

	//Сортуємо масиви
	mergeSort(test1, 0, test1_size - 1);
	mergeSort(test2, 0, test2_size - 1);
	mergeSort(test3, 0, test3_size - 1);

	EXPECT_EQ(1, comp(test1, test1_sorted, test1_size));
	EXPECT_EQ(1, comp(test2, test2_sorted, test2_size));
	EXPECT_EQ(1, comp(test3, test3_sorted, test3_size));
}

TEST(countingSort_test, performance)
{
	//Тест 1
	int test1[] = { 6073, 8277, 4612, 9573, 8443, 6061, 5690, 298, 8860, 2967 };
	int test1_sorted[] = { 298, 2967, 4612 ,5690 ,6061 ,6073 ,8277, 8443 ,8860 ,9573 };
	size_t test1_size = sizeof test1 / sizeof * test1;

	//Тест 2
	int test2[] = { 673, 3125, 215, 9804, 1023, 10, 9, 0, 1011, 54 };
	int test2_sorted[] = { 0, 9, 10, 54, 215, 673, 1011, 1023, 3125, 9804 };
	size_t test2_size = sizeof test2 / sizeof * test2;

	//Сортуємо масиви
	countingSort(test1, test1_size);
	countingSort(test2, test2_size);

	EXPECT_EQ(1, comp(test1, test1_sorted, test1_size));
	EXPECT_EQ(1, comp(test2, test2_sorted, test2_size));
}

TEST(radixSort_test, performance)
{
	//Тест 1
	int test1[] = { 6073, 8277, 4612, 9573, 8443, 6061, 5690, 298, 8860, 2967 };
	int test1_sorted[] = { 298, 2967, 4612 ,5690 ,6061 ,6073 ,8277, 8443 ,8860 ,9573 };
	size_t test1_size = sizeof test1 / sizeof * test1;

	//Тест 2
	int test2[] = { 673, 3125, 215, 9804, 1023, 10, 9, 0, 1011, 54 };
	int test2_sorted[] = { 0, 9, 10, 54, 215, 673, 1011, 1023, 3125, 9804 };
	size_t test2_size = sizeof test2 / sizeof * test2;

	//Сортуємо масиви
	radixSort(test1, test1_size);
	radixSort(test2, test2_size);

	EXPECT_EQ(1, comp(test1, test1_sorted, test1_size));
	EXPECT_EQ(1, comp(test2, test2_sorted, test2_size));
}