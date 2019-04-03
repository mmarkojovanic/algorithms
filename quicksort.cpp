#include "stdafx.h"
#include<iostream>
using namespace std;
int partition(int* a, int lo, int hi)
{
	int j = lo;
	int pivot = a[hi - 1];
	for (int i = lo; i < hi; i++)
	{
		if (a[i] < pivot) {
			if (i != j) swap(a[i], a[j]);
			j++;
		}
	}
	swap(a[hi - 1], a[j]);
	return j;
}
void quicksort(int* a, int lo, int hi)
{
	if (lo < hi)
	{
		int p = partition(a, lo, hi);
		quicksort(a, lo, p);
		quicksort(a, p+1, hi);
	}
}
int main()
{
	int size = 50;
	int* a = new int[size];
	for (int i = 0; i < size; i++)
		a[i] = rand() % 500;

	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << std::endl;
	cin.get();
	int lo = 0;
	quicksort(a, lo, size);

	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cin.get();

	delete[] a;
	return 0;
}