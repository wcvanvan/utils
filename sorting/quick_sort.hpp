#include <ctime>
#include <cstdlib>
#include <random>

void quicksort(int* array, int* supportArray, int L, int R) {
	if (L >= R)
	{
		return;
	}
	srand(time(0) + L + R);

	int pivot = L + random(R - L);
	int l = L, r = R;
	for (int i = L; i <= R; i++)
	{
		if (i == pivot)
		{
			continue;
		}
		if (array[i] <= array[pivot])
		{
			supportArray[l++] = array[i];
		}
		else {
			supportArray[r--] = array[i];
		}
	}
	supportArray[l] = array[pivot];
	for (int i = L; i <= R; i++)
	{
		array[i] = supportArray[i];
	}
	quicksort(array, supportArray, L, l - 1);
	quicksort(array, supportArray, l + 1, R);
}