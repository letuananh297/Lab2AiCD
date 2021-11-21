#include<iostream>
#include "algorithm.h"
using namespace std;

int main() {
	int* array1 = new int[8] { 2, 4, 6, 7, 10, 22, 29, 36 };
	cout << "The first array:  ";
	for (int i = 0; i < 8; i++)
		cout << array1[i] << "  ";
	if (BinarySearch(array1, 8, 29) == -1)
		cout << "\nThere is no element 29 in the array.\n";
	else
		cout << "\nElement 29 is at position: " << BinarySearch(array1, 8, 29) << endl;
	delete[] array1;

	int* array2 = new int[8] { 29, 6, 11, 10, 17, 13, 14, 27 };
	cout << "\nThe second array before using QuickSort: ";
	for (int i = 0; i < 8; i++)
		cout << array2[i] << "  ";
	QuickSort(array2, 0, 7);
	cout << "\nThe second array after using QuickSort:  ";
	for (int i = 0; i < 8; i++)
		cout << array2[i] << "  ";
	cout << endl;
	delete[] array2;

	int* array3 = new int[8] { 19, 2, 16, 18, 7, 8, 4, 13 };
	cout << "\nThe third array before using InsertionSort: ";
	for (int i = 0; i < 8; i++)
		cout << array3[i] << "  ";
	InsertionSort(array3, 8);
	cout << "\nThe third array after using InsertionSort:  ";
	for (int i = 0; i < 8; i++)
		cout << array3[i] << "  ";
	cout << endl;
	delete[] array3;

	int* array4 = new int[8] { 13, 17, 20, 9, 6, 3, 13, 27 };
	cout << "\nThe fourth array before using BogoSort: ";
	for (int i = 0; i < 8; i++)
		cout << array4[i] << "  ";
	BogoSort(array4, 8);
	cout << "\nThe fourth array after using BogoSort:  ";
	for (int i = 0; i < 8; i++)
		cout << array4[i] << "  ";
	cout << endl;
	delete[] array4;

	string str = "ltayeuphma";
	cout << "\nThe string before using CountingSort:  " << str << endl;
	CountingSort(str);
	cout << "The string before using CountingSort:  " << str << endl;

	cout << "\nCompare Quicksort and Insertionsort:" << endl << endl;
	CompareQuickSortAndInsertionSort();

	return 0;
}