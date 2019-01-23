#include "stdafx.h"
#include<iostream>
using namespace std;

void splitMerge(int* a, int start, int end, int* b)
{
	if (end - start < 2)
		return;
	int mid = (start + end) / 2;
	splitMerge(a, start, mid, b);
	splitMerge(a, mid, end, b);
	int i = 0, j = 0;
	while (i < mid - start && j < end - mid) {
		if (a[start + i] < a[mid + j])
			b[start + i + j] = a[start + i++];
		else
			b[start + i + j] = a[mid + j++];
	}
	if (i == mid - start)
		while (j < end - mid) b[start + i + j] = a[mid + j++];
	else
		while (i < mid - start) b[start + i + j] = a[start + i++];
	for (i = start; i < end; i++) a[i] = b[i];
}

void mergeSort(int* a, int& size)
{
	int start = 0;
	int* b = new int[size];
	for (int i = 0; i < size; i++)
		b[i] = a[i];
	splitMerge(a, start, size, b);
	delete[] b;
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

	mergeSort(a, size);

	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cin.get();

	delete[] a;
	return 0;
}