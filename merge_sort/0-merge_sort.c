#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#define SIZE 99999
/**
 * merge - sorts an array in ascending order the Merge Sort algorithm
 * @arr: an array of integers
 * @left: beginning of array
 * @right: right
 * @size: size of array
*/
void merge(int *arr, int *left, int *right, size_t size)
{
	int i = 0;
	int j = 0, k = 0;
	int l = size / 2;
	int r = size - l;

	printf("Merging...");
	printf("\n");
	printf("[left]: ");
	print_array(left, l);
	printf("[right]: ");
	print_array(right, r);

	while (i < l && j < r)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while (j < r)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
	while (i < l)
	{
		arr[k] = left[i];
		i++;
		k++;
	}
	printf("[Done]: ");
	print_array(arr, size);
}
/**
 * merge_sort - sorts an array in ascending order the Merge Sort algorithm
 * @array: an array of integers
 * @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
		size_t mid = size / 2;
		size_t i;
		size_t j;
		int left[SIZE];
		int right[SIZE];

		if (!array)
			return;
		if (size < 2)
			return;
		for (i = 0; i < mid; i++)
			left[i] = array[i];

		for (j = mid; j < size; j++)
			right[j - mid] = array[j];
		merge_sort(left, mid);
		merge_sort(right, size - mid);
		merge(array, left, right, size);
}
