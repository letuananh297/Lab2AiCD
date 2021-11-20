#pragma once
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

void swap(int* a, int* b) {
	int c = *b;
	*b = *a; *a = c;
}


bool isSortedAscending(int* array, int array_size) {
	bool check = 1;
	for (int i = 0; i < array_size - 1; i++) {
		if (array[i] > array[i + 1])
			check = 0;
	}
	return check;
}

int BinarySearch(int* array, int array_size, int search_value) {
	if (array == NULL)
		throw std::runtime_error("Pointer to array is nullptr.");
	if (array_size <= 0)
		throw std::invalid_argument("Size of array is less than zero.");
	if (!isSortedAscending(array, array_size))
		throw std::logic_error("Array is not sorted in ascending order.");
	int left = 0, right = array_size - 1;
	int middle = (left + right) / 2;
	bool check = 0;
	while ((!check) && (left <= right)) {
		if (array[middle] == search_value)
			check = 1;
		else {
			if (array[middle] < search_value)
				left = middle + 1;
			else
				right = middle - 1;
			middle = (left + right) / 2;
		}
	}
	if (check == 1)
		return middle;
	else
		return -1;
}

void QuickSort(int* array, int low, int high) {
	if (array == NULL)
		throw runtime_error("Pointer to array is nullptr.");
	if (low < 0 || high < 0)
		throw invalid_argument("Index low or index high is less than zero.");
	if (low > high)
		throw invalid_argument("Index low is more than index high.");
	int left = low, right = high;
	int middle = (left + right) / 2;
	int pivot = array[middle];
	while (left <= right) {
		while (array[left] < pivot)
			left++;
		while (array[right] > pivot)
			right--;
		if (left <= right) {
			swap(&array[left], &array[right]);
			left++;
			right--;
		}
	}
	if (right > low)
		QuickSort(array, low, right);
	if (left < high)
		QuickSort(array, left, high);
}

void InsertionSort(int* array, int array_size) {
	if (array == NULL)
		throw runtime_error("Pointer to array is nullptr.");
	if (array_size <= 0)
		throw invalid_argument("Size of array is less than zero.");
	int i, j, key;
	for (i = 1; i < array_size; i++)
	{
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

void BogoSort(int* array, int array_size) {
	if (array == NULL)
		throw runtime_error("Pointer to array is nullptr.");
	if (array_size <= 0)
		throw invalid_argument("Size of array is less than zero.");
	while (!isSortedAscending(array, array_size)) {
		mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
		uniform_int_distribution<> range(0, array_size - 1);
		for (int i = 0; i < array_size; i++)
			swap(&array[i], &array[range(generator)]);
	}
}

void CountingSort(char input[]) {
	char output[100];
	int count[256], i;
	for (i = 0; i < 256; ++i)
		count[i] = 0;
	for (i = 0; input[i]; ++i)
		++count[input[i]];
	for (i = 1; i < 256; ++i)
		count[i] += count[i - 1];
	for (i = 0; input[i]; ++i) {
		output[count[input[i]] - 1] = input[i];
		--count[input[i]];
	}
	for (i = 0; input[i]; ++i)
		input[i] = output[i];
}

void CompareQuickSortAndInsertionSort() {
	int data_size = 10;
	int array_size = 100000;
	int* array_QuickSort = new int[array_size];
	int* array_InsertionSort = new int[array_size];

	while (data_size <= 100000) {
		double time_QuickSort = 0;
		double time_InsertionSort = 0;
		for (int i = 0; i < 10; i++) {
			mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
			uniform_int_distribution<> range(-data_size, data_size);

			for (int i = 0; i < data_size; i++) {
				array_QuickSort[i] = range(generator);
				array_InsertionSort[i] = array_QuickSort[i];
			}

			auto start = chrono::high_resolution_clock::now();

			QuickSort(array_QuickSort, 0, array_size - 1);

			auto finish = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start);

			time_QuickSort += finish.count();

			start = chrono::high_resolution_clock::now();

			InsertionSort(array_InsertionSort, array_size);

			finish = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start);

			time_InsertionSort += finish.count();
		}

		cout << "Size of data: [" << -data_size << ";" << data_size << "]" << endl;
		cout << "Time of QuickSort: " << time_QuickSort / 10 << " ns = " << time_QuickSort / 10000000000 << " s." << endl;
		cout << "Time of InsertionSort: " << time_InsertionSort / 10 << " ns = " << time_InsertionSort / 10000000000 << " s." << endl;
		cout << endl;
		data_size *= 10;
	}
}