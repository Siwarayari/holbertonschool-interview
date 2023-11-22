#include "sort.h"
/**
 * count_Sort - function to count the number of elements in a sorted array
 * @array: array to sort
 * @size: size of the array
 * @pos: position of the element
*/
void count_Sort(int *array, int size, int pos)
{

	int i;
	int *output = malloc(size * sizeof(int));
	int count[10] = { 0 };

	for (i = 0; i < size; i++)
		count[(array[i] / pos) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / pos) % 10] - 1] = array[i];
		count[(array[i] / pos) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}
/**
 * radix_sort - sorts an array in ascending order using Radix sort algorithm
 * @array: array to sort
 * @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	int max;
	size_t i;
	int pos;

	if (array == NULL || size == 0)
	{
		return;
	}

	max = array[0];
	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (pos = 1; max / pos > 0; pos *= 10)
	{
		count_Sort(array, size, pos);
		print_array(array, size);
	}
}
