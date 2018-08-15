#include "stdafx.h"
#include "Tests.h"
#include "MergeSort.h"


Tests::Tests()
{
}

Tests::~Tests()
{
}

bool Tests::AreSame(int a[], int b[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] != b[i])
		{
			throw std::exception("Arrays are not equal.");
		}
	}
	return true;
}

void Tests::Test1()
{
	int aSorted[] = { 0,1,2,3,7,8,10,11,12,15 };
	int bSorted[] = { 4,5,6,7,8,9,10,13,14,15 };
	int abSortedMerged[] = { 0,1,2,3,4,5,6,7,7,8,8,9,10,10,11,12,13,14,15,15 };

	int * merged = MergeSort::MergeSorted(aSorted, 10, bSorted, 10);

	bool t = AreSame(merged, abSortedMerged, 20);
}

void Tests::Test2()
{
	int aSorted[] = { 0,0,0,0,0,0,0,0,0,0 };
	int bSorted[] = { 4,4,4,4,4,4,4,4,4,4 };
	int abSortedMerged[] = { 0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4 };

	int * merged = MergeSort::MergeSorted(aSorted, 10, bSorted, 10);

	bool t = AreSame(merged, abSortedMerged, 20);
}

void Tests::Test3()
{
	int aSorted[] = { 0,10,20,40 };
	int bSorted[] = { 0,5,6,15,19,20,24,30};
	int abSortedMerged[] = { 0,0,5,6,10,15,19,20,20,24,30,40 };

	int * merged = MergeSort::MergeSorted(aSorted, sizeof(aSorted) / sizeof(aSorted[0]), bSorted, sizeof(bSorted) / sizeof(bSorted[0]));

	bool t = AreSame(merged, abSortedMerged, sizeof(abSortedMerged) / sizeof(abSortedMerged[0]));
}

void Tests::Test4()
{
	int aSorted[] = { 0 };
	int bSorted[] = { 5 };
	int abSortedMerged[] = { 0,5 };

	int * merged = MergeSort::MergeSorted(aSorted, sizeof(aSorted) / sizeof(aSorted[0]), bSorted, sizeof(bSorted) / sizeof(bSorted[0]));

	bool t = AreSame(merged, abSortedMerged, sizeof(abSortedMerged) / sizeof(abSortedMerged[0]));
}

void Tests::Test5()
{
	int arr[] = { 10,11,8,9,50,2,0 };
	int arrSorted[] = { 0,2,8,9,10,11,50 };
	int * merged = MergeSort::Sort(arr, sizeof(arr) / sizeof(arr[0]));

	bool t = AreSame(merged, arrSorted, sizeof(arr) / sizeof(arr[0]));

	int arr2[] = { 126,100,5,1,287,8 };
	int arrSorted2[] = { 1,5,8,100,126,287 };
	int * merged2 = MergeSort::Sort(arr2, sizeof(arr2) / sizeof(arr2[0]));

	bool t2 = AreSame(merged2, arrSorted2, sizeof(arr2) / sizeof(arr2[0]));

	int arr3[] = { 123,123,123,123,123 };
	int arrSorted3[] = { 123,123,123,123,123 };
	int * merged3 = MergeSort::Sort(arr3, sizeof(arr3) / sizeof(arr3[0]));
	bool t3 = AreSame(merged3, arrSorted3, sizeof(arr3) / sizeof(arr3[0]));

	int arr4[] = { 567};
	int arrSorted4[] = { 567 };
	int * merged4 = MergeSort::Sort(arr4, sizeof(arr4) / sizeof(arr4[0]));
	bool t4 = AreSame(merged4, arrSorted4, sizeof(arr4) / sizeof(arr4[0]));
}