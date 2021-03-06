// SortingAndSearching.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


void merge(int arr[], int start, int middle, int end) {


	int leftSize = middle - start + 1;
	int* lTemp = new int[leftSize];
	for (int k = 0; k < leftSize; k++)
	{
		lTemp[k] = arr[start + k];
	}

	int rightSize = end - middle;
	int* rTemp = new int[rightSize];
	for (int k = 0; k < rightSize; k++)
	{
		rTemp[k] = arr[middle + 1 + k];
	}

	int i = 0, j = 0, tempIndex = start;

	while (i < leftSize && j < rightSize)
	{
		if (lTemp[i] < rTemp[j])
		{
			arr[tempIndex] = lTemp[i];
			i++;
		}
		else
		{
			arr[tempIndex] = rTemp[j];
			j++;
		}

		tempIndex++;
	}

	while (i < leftSize)
	{
		arr[tempIndex] = lTemp[i];
		i++;
		tempIndex++;
	}

	while (j < rightSize)
	{
		arr[tempIndex] = rTemp[j];
		j++;
		tempIndex++;
	}
}

void mergeSort(int arr[], int start, int end) {

	if (start < end)
	{
		int middle = (start + end) / 2;
		mergeSort(arr, start, middle);
		mergeSort(arr, middle + 1, end);
		merge(arr, start, middle, end);
	}
}

int main()
{
	int arr[10] = { 27,254,32,3,5,67,17,6,121,10 };


	mergeSort(arr, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << "Hello World!\n";
}



