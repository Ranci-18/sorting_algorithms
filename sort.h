#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void shell_sort(int *array, size_t size);
int lomut_partition(int *array, int strt, int nd, int size);
void quick_sort2(int *array, int start, int end, int size);
void counting_sort(int *array, size_t size);
int largest_int(int *array, size_t size);
void init_count_inst(int *array, int *count_arr, size_t size, int k);
void sum_ints(int *count_arr, int k);
void fill_output_arr(int *array, int *output_arr, int *count_arr, size_t size);

#endif
