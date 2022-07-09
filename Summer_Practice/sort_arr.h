/**
* @file sort_arr.h
* @author ˳����� �.�, ��. 515-�
* @date 7 �����	 2022
* @brief ��������� ��������.
*
* 22 ������ - ��������� ���������� ������
*/

#ifndef SORT_ARR_H
#define SORT_ARR_H

#define PUBLIC
#define PRIVATE static

//ʳ������ �������� ������
#define size 10
#define counting_size 100000

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*������� ��� ���������� ������ ������������*/
PUBLIC void person_input(int arr[]);
/*������� ��� ���������� ������ �����������*/
PUBLIC void random_input(int arr[]);
/*������� ��� ������� ������*/
PUBLIC void arr_print(int arr[]);
/*������� ��� ��������� �������� ������*/
PUBLIC void arr_copy(int arr[], int copy[]);
/*������� ���������� �������*/
PUBLIC void mergeSort(int arr[], int l, int r);
/*������� ���������� ����������*/
PUBLIC void countingSort(int arr[]);
/*������� ���������� �� ��������*/
PUBLIC void radixSort(int arr[]);

#endif 
