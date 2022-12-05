
#include <iostream>

template <typename T>
static int partition(T arr[], int idx_start, int idx_end)
{
	
	//рандомный выбор числа pivot
	srand(time(NULL));
	int idx_pivot = (rand() % 4) + 1;

	int pivot = arr[idx_start];

	int counter = 0, i = 0, j = 0;

	for (int i = idx_start + 1; i <= idx_end; ++i)
		if (arr[i] <= pivot)
			counter++;

	idx_pivot = counter + idx_start;

	std::swap(arr[idx_pivot], arr[idx_start]);

	i = idx_start;
	j = idx_end;

	while (i < idx_pivot && j > idx_pivot)
	{
		while (arr[i] <= pivot)
			i++;

		while (arr[j] > pivot)
			j--;

		if (i < idx_pivot && j > idx_pivot)
			std::swap(arr[i], arr[j]);
	}
	return idx_pivot;
}

template <typename T>
void quickSort(T arr[], int idx_start, int idx_end)
{
	if (idx_start >= idx_end)
		return;

	int idx_pivot = partition(arr, idx_start, idx_end);

	quickSort(arr, idx_start, idx_pivot - 1);
	quickSort(arr, idx_pivot + 1, idx_end);

}

int main()
{
	int arr[] = { 1,9,7,4,11 };
	int size_arr = sizeof(arr) / sizeof(arr[0]);
	std::cout << "size_arr = " << size_arr << std::endl;

	quickSort(arr, 0, size_arr - 1);

	for (int i = 0; i < size_arr; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	double arr2[] = { 1.5, 9.5, 7.5, 4.5, 11.5 };
	int size_arr2 = sizeof(arr2) / sizeof(arr2[0]);
	quickSort(arr2, 0, size_arr2 - 1);

	for (int i = 0; i < size_arr2; ++i)
		std::cout << arr2[i] << " ";

	return 0;
}
