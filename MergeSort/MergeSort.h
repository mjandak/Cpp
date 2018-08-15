#pragma once
class MergeSort
{
public:
	MergeSort();
	~MergeSort();
	static int * Sort(int arr[], int size);
	static int * MergeSorted(int aSorted[], int aSize, int bSorted[], int bSize);
};

