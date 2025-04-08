#include "Sort.h"

Sort::Sort(int count, int min, int max)
{
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < count; i++)
	{
		numbers.push_back(min + rand() % (max - min + 1));
	}
}

Sort::Sort(std::initializer_list<int> list) : numbers(list) {}

Sort::Sort(int* vector, int size) 
{
	numbers.reserve(size);
	for (int i = 0; i < size; ++i) {
		numbers.push_back(vector[i]);
	}
}


Sort::Sort(int count, ...)
{
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		numbers.push_back(va_arg(args, int));
	}
	va_end(args);
}

Sort::Sort(char* string) 
{
	char* start = string;

	for (char* ptr = string; ; ++ptr) {
		if (*ptr == ',' || *ptr == '\0') 
		{
			*ptr = '\0';
			numbers.push_back(atoi(start));
			if (*ptr == '\0') {
				break;
			}
			start = ptr + 1;
		}
	}
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < numbers.size(); i++) {
		int key = numbers[i];
		int j = i - 1;

		if (ascendent) {
			while (j >= 0 && numbers[j] > key) {
				numbers[j + 1] = numbers[j];
				j--;
			}
		}
		else
		{
			while (j >= 0 && numbers[j] < key) {
				numbers[j + 1] = numbers[j];
				j--;
			}
		}
		numbers[j + 1] = key; 
	}
}

void QuickSortHelper(vector<int>& vec, int low, int high, bool ascendent)
{
	if (low < high) {
		int pivot = vec[high];
		int i = low - 1;

		for (int j = low; j < high; j++) {
			if (ascendent) {
				if (vec[j] < pivot) {
					i++;
					swap(vec[i], vec[j]);
				}
			}
			else {
				if (vec[j] > pivot) {
					i++;
					swap(vec[i], vec[j]);
				}
			}
		}
		swap(vec[i + 1], vec[high]);

		int pi = i + 1;
		QuickSortHelper(vec, low, pi - 1, ascendent);
		QuickSortHelper(vec, pi + 1, high, ascendent);
	}
}


void Sort::QuickSort(bool ascendent)
{
	QuickSortHelper(numbers, 0, numbers.size() - 1, ascendent);
}


void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < numbers.size() - 1; i++) 
	{
		for (int j = 0; j < numbers.size() - i - 1; j++) 
		{
			if (ascendent && numbers[j] > numbers[j + 1]) {
				swap(numbers[j], numbers[j + 1]);
			}
			else if (!ascendent && numbers[j] < numbers[j + 1]) 
			{
				swap(numbers[j], numbers[j + 1]);
			}
		}
	}
}


void Sort::Print()
{
	for (const int& num : numbers) {
		cout << num << " ";
	}
	cout << endl;
}

int Sort::GetElementsCount()
{
	return numbers.size();
}

int Sort::GetElementFromIndex(int index)
{
	if (index >= 0 && index < numbers.size()) {
		return numbers[index];
	}
	else {
		return -1;
	}
}