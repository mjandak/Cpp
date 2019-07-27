#include "Tests.h"
#include "BinarySearch.h"

void Tests::Failed(std::string testName)
{
	std::string msg;
	msg.append(testName);
	msg.append("  failed");
	throw msg;
}

std::string Tests::Test1()
{
	int target = 1;
	int orderedArr[1] = { 1 };
	size_t size = 1;
	auto res = BinarySearch::Find(target, orderedArr, size);
	
	if (res != target)
	{
		Failed(__func__);
	}

	return "found " + target;
}

std::string Tests::Test2()
{
	int target = 2;
	int orderedArr[1] = { 1 };
	size_t size = 1;

	try
	{
		BinarySearch::Find(target, orderedArr, size);
	}
	catch (const std::exception&)
	{
		return target + " not found";
	}

	Failed(__func__);
}

std::string Tests::Test3()
{
	int target = 2;
	int orderedArr[] = {-3, -2, -1, 0, 1, 2, 3, 4 , 5, 6, 7, 8, 9, 10 };
	size_t size = 14;

	auto res = BinarySearch::Find(target, orderedArr, size);

	if (res != target)
	{
		Failed(__func__);
	}

	return "found " + target;
}

std::string Tests::Test4()
{
	int target = -80;
	int orderedArr[] = { -3, -2, -1, 0, 1, 2, 3, 4 , 5, 6, 7, 8, 9, 10 };
	size_t size = 14;

	try
	{
		BinarySearch::Find(target, orderedArr, size);
	}
	catch (const std::exception&)
	{
		return target + " not found";
	}

	Failed(__func__);
}
