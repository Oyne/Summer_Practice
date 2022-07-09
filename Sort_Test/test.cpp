#include "pch.h"
#include "..\Summer_Practice\sort_arr.c"

//Function that compares two array on identity
int comp(int arr1[], int arr2[])
{
	for (int i = 0; i < size; i++)
	{
		if (arr1[i] != arr2[i]) return 0;
	}
	return 1;
}

TEST(getMax_test, performance)
{
	//Test 1
	int test1[] = { -132, -25, 345, 99, 123, 2004, 9, 0, 3, 10 };
	int max1 = 2004;

	//Test 2
	int test2[] = { 6073, 8277, 4612, 9573, 8443, 6061, 5690, 298, 8860, 2967 };
	int max2 = 9573;

	//Test 3
	int test3[] = { 673, 3125, 215, 9804, 1023, 10, 9, 0, 1011, 54 };
	int max3 = 9804;

	EXPECT_EQ(max1, getMax(test1));
	EXPECT_EQ(max2, getMax(test2));
	EXPECT_EQ(max3, getMax(test3));
}
TEST(mergeSort_test, performance)
{
	//Test 1
	int test1[] = { -132, -25, 345, 99, 123, 2004, 9, 0, 3, 10 };
	int test1_sorted[] = { -132, -25, 0, 3, 9, 10, 99, 123, 345, 2004 };

	//Test 2
	int test2[] = { 6073, 8277, 4612, 9573, 8443, 6061, 5690, 298, 8860, 2967 };
	int test2_sorted[] = { 298, 2967, 4612 ,5690 ,6061 ,6073 ,8277, 8443 ,8860 ,9573 };

	//Test 3
	int test3[] = { 673, 3125, 215, 9804, 1023, 10, 9, 0, 1011, 54 };
	int test3_sorted[] = { 0, 9, 10, 54, 215, 673, 1011, 1023, 3125, 9804 };

	//Sorting test arrays
	mergeSort(test1, 0, size - 1);
	mergeSort(test2, 0, size - 1);
	mergeSort(test3, 0, size - 1);
	
	EXPECT_EQ(1, comp(test1, test1_sorted));
	EXPECT_EQ(1, comp(test2, test2_sorted));
	EXPECT_EQ(1, comp(test3, test3_sorted));

}

TEST(countingSort_test, performance)
{	
	//Test 1
	int test1[] = { 6073, 8277, 4612, 9573, 8443, 6061, 5690, 298, 8860, 2967 };
	int test1_sorted[] = { 298, 2967, 4612 ,5690 ,6061 ,6073 ,8277, 8443 ,8860 ,9573 };

	//Test 2
	int test2[] = { 673, 3125, 215, 9804, 1023, 10, 9, 0, 1011, 54 };
	int test2_sorted[] = { 0, 9, 10, 54, 215, 673, 1011, 1023, 3125, 9804};

	//Sorting test arrays
	countingSort(test1);
	countingSort(test2);

	EXPECT_EQ(1, comp(test1, test1_sorted));
	EXPECT_EQ(1, comp(test2, test2_sorted));
}

TEST(radixSort_test, performance)
{
	//Test 1
	int test1[] = { 6073, 8277, 4612, 9573, 8443, 6061, 5690, 298, 8860, 2967 };
	int test1_sorted[] = { 298, 2967, 4612 ,5690 ,6061 ,6073 ,8277, 8443 ,8860 ,9573 };

	//Test 2
	int test2[] = { 673, 3125, 215, 9804, 1023, 10, 9, 0, 1011, 54 };
	int test2_sorted[] = { 0, 9, 10, 54, 215, 673, 1011, 1023, 3125, 9804 };

	//Sorting test arrays
	radixSort(test1);
	radixSort(test2);
	EXPECT_EQ(1, comp(test1, test1_sorted));
	EXPECT_EQ(1, comp(test2, test2_sorted));
}