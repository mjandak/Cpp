// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinarySearch.h"
#include "Tests.h"

int main()
{
	std::cout << Tests::Test1() << std::endl;
	std::cout << Tests::Test2() << std::endl;
	std::cout << Tests::Test3() << std::endl;
	std::cout << Tests::Test4() << std::endl;
	std::cout << Tests::Test5() << std::endl;
	std::cout << Tests::Test6() << std::endl;
	std::cout << Tests::Test7() << std::endl;
    std::cout << "All tests passed.\n";
}

int BinarySearch::Find(int target, int orderedArr[], size_t size)
{
	int firstIdx = 0;
	int lastIdx = size - 1;
	while (true)
	{
		if (firstIdx > lastIdx)
		{
			throw "wtf?";
		}
		if (firstIdx == lastIdx)
		{
			if (orderedArr[firstIdx] == target)
			{
				return firstIdx;
			}

			//throw target + " not found";
			//throw std::exception(target + " not found");
			return -1;
		}
		int middle = firstIdx + (lastIdx - firstIdx) / 2;
		//if (orderedArr[middle] == target) return middle;
		if (target <= orderedArr[middle])
		{
			lastIdx = middle;
		}
		else
		{
			firstIdx = middle + 1;
		}
	}
}
