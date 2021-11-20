#include "pch.h"
#include "gtest/gtest.h"
#include "../Lab2/algorithm.h"

using namespace std;

class Test_Algorithm : public ::testing::Test {
public:
	int array_size = 10;
	int* NewRandomArray() {
		int* array = new int[array_size];
		for (int i = 0; i < array_size; i++)
			array[i] = rand();
		return array;
	}

	int* NewSortedArray() {
		int* array = new int[array_size];
		for (int i = 0; i < array_size; i++)
			array[i] = i;
		return array;
	}
};

TEST_F(Test_Algorithm, Test_BinarySearch) {
	int* array1 = new int[array_size];
	array1 = NULL;
	//When array1 is NULL
	ASSERT_THROW(BinarySearch(array1, array_size, 7), runtime_error);

	int* array2 = new int[4]{ 2, 3, 1, 4 };
	//When size of array <= 0
	ASSERT_THROW(BinarySearch(array2, 0, 4), invalid_argument);
	//When array is not sorted
	ASSERT_THROW(BinarySearch(array2, 4, 4), logic_error);

	int* array3 = NewSortedArray();
	for (int i = 0; i < array_size; i++) {
		ASSERT_NO_THROW(BinarySearch(array3, array_size, i));
		ASSERT_EQ(BinarySearch(array3, array_size, i), i);
	}
	delete[] array1;
	delete[] array2;
	delete[] array3;
}

TEST_F(Test_Algorithm, Test_QuickSort) {
	int* array1 = new int[array_size];
	array1 = NULL;
	//When array1 is NULL
	ASSERT_THROW(QuickSort(array1, array_size, 7), runtime_error);

	int* array2 = new int[4]{ 2, 3, 1, 4 };
	//When low < 0
	ASSERT_THROW(QuickSort(array2, -1, 3), invalid_argument);
	//When high < 0
	ASSERT_THROW(QuickSort(array2, 0, -3), invalid_argument);
	//When low > high
	ASSERT_THROW(QuickSort(array2, 3, 0), invalid_argument);

	int* array3 = NewRandomArray();
	ASSERT_NO_THROW(QuickSort(array3, 0, array_size - 1));
	for (int i = 0; i < array_size - 1; i++)
		ASSERT_LE(array3[i], array3[i + 1]);

	delete[] array1;
	delete[] array2;
	delete[] array3;
}

TEST_F(Test_Algorithm, Test_InsertionSort) {
	int* array1 = new int[array_size];
	array1 = NULL;
	//When array1 is NULL
	ASSERT_THROW(InsertionSort(array1, array_size), runtime_error);

	int* array2 = new int[4]{ 2, 3, 1, 4 };
	//When size of array <= 0
	ASSERT_THROW(InsertionSort(array2, 0), invalid_argument);

	int* array3 = NewRandomArray();
	ASSERT_NO_THROW(InsertionSort(array3, array_size));
	for (int i = 0; i < array_size - 1; i++)
		ASSERT_LE(array3[i], array3[i + 1]);

	delete[] array1;
	delete[] array2;
	delete[] array3;
}

TEST_F(Test_Algorithm, Test_BogoSort) {
	int* array1 = new int[array_size];
	array1 = NULL;
	//When array1 is NULL
	ASSERT_THROW(BogoSort(array1, array_size), runtime_error);

	int* array2 = new int[4]{ 2, 3, 1, 4 };
	//When size of array <= 0
	ASSERT_THROW(BogoSort(array2, 0), invalid_argument);

	int* array3 = NewRandomArray();
	ASSERT_NO_THROW(BogoSort(array3, array_size));
	for (int i = 0; i < array_size - 1; i++)
		ASSERT_LE(array3[i], array3[i + 1]);

	delete[] array1;
	delete[] array2;
	delete[] array3;
}

TEST_F(Test_Algorithm, Test_CountingSort) {
	char array[] = "ltayeuphma";
	CountingSort(array);
	for (int i = 0; i < 8; i++)
		ASSERT_LE(array[i], array[i + 1]);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}