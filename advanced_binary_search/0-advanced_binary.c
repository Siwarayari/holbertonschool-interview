#include "search_algos.h"
/**
 * print_array - Prints an array of integers
 * @array: array
 * @left: left
 * @right: right
*/
void print_array(const int *array, int left, int right)
{

	int i;

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}
/**
 * advanced_binarySearch - searches for a value in a sorted array of integers
 * @array: a pointer to the first element of the array to search in
 * @left: is the index of the first element of the array to search in
 * @right: is the index of the last element of the array to search in
 * @value: value is the value to search for
 * Return: return the index where value is located or -1 if not found
*/
int advanced_binarySearch(int *array, int left, int right, int value)
{
	print_array(array, left, right);
	if (right >= left)
	{
		int middle = left + (right - left) / 2;

		if (left == right)
			return (-1);

		if (array[middle] == value && array[middle - 1] != value)
			return (middle);

		if (array[middle] >= value)
			return (advanced_binarySearch(array, left, middle, value));

		if (array[middle] <= value)
			return (advanced_binarySearch(array, middle + 1, right, value));


	}

	return (-1);
}
/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: array is a pointer to the first element of the array to search in
 * @size: size is the number of elements in array
 * @value: value is the value to search for
 * Return: return the index where value is located or -1 if not found
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || !size || !value)
		return (-1);
	return (advanced_binarySearch(array, 0, size - 1, value));
}
