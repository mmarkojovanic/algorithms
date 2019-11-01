// array_as_btree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void heapify(int* a, int size, int root)
{
	int max = root;
	if (2 * root + 1 < size && a[root] < a[2 * root + 1])
		max = 2 * root + 1;
	if (2 * root + 2 < size && a[root] < a[2 * root + 2])
		max = 2 * root + 2;
	if (max != root) {
		swap(a[root], a[max]);
		heapify(a, size, max);
	}
}

void heapSort(int* a, int& size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(a, size, i);
	for (int i = size - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

int main1()
{
	int* a = new int[50];
	int size = 50;
	for (int i = 0; i < size; i++)
		a[i] = rand() % 500;
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << std::endl;
	cin.get();
	heapSort(a, size);
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cin.get();
	delete[] a;
	return 0;
}

