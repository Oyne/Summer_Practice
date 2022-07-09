/**
* @file sort_arr.h
* @author Літвінов А.А, гр. 515-В
* @date 7 липня	 2022
* @brief Навчальна практика.
*
* 22 Варіант - Алгоритми сортування масивів
*/

#ifndef SORT_ARR_H
#define SORT_ARR_H

#define PUBLIC
#define PRIVATE static

//Кількість елементів масиву
#define size 10
#define counting_size 100000

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*Функція для заповнення масиву користувачем*/
PUBLIC void person_input(int arr[]);
/*Функція для заповнення масиву автоматично*/
PUBLIC void random_input(int arr[]);
/*Функція для виводу масиву*/
PUBLIC void arr_print(int arr[]);
/*Функція для копіювання вхідного масиву*/
PUBLIC void arr_copy(int arr[], int copy[]);
/*Функція сортування злиттям*/
PUBLIC void mergeSort(int arr[], int l, int r);
/*Функція сортування підрахунком*/
PUBLIC void countingSort(int arr[]);
/*Функція сортування за розрядом*/
PUBLIC void radixSort(int arr[]);

#endif 
