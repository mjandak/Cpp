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
	
	if (res != 0) Failed(__func__);

	return "found " + std::to_string(target) + " at " + std::to_string(res);
}

std::string Tests::Test2()
{
	int target = 2;
	int orderedArr[1] = { 1 };
	size_t size = 1;

	auto res = BinarySearch::Find(target, orderedArr, size);
	if (res != -1) Failed(__func__);
	return std::to_string(target)  + " not found";
}

std::string Tests::Test3()
{
	int target = 2;
	int orderedArr[] = {-3, -2, -1, 0, 1, 2, 3, 4 , 5, 6, 7, 8, 9, 10 };
	size_t size = 14;

	auto res = BinarySearch::Find(target, orderedArr, size);

	if (res != 5) Failed(__func__);

	return "found " + std::to_string(target) + " at " + std::to_string(res);
}

std::string Tests::Test4()
{
	int target = -80;
	int orderedArr[] = { -3, -2, -1, 0, 1, 2, 3, 4 , 5, 6, 7, 8, 9, 10 };
	size_t size = 14;

	auto res = BinarySearch::Find(target, orderedArr, size);
	if (res != -1) Failed(__func__);
	return std::to_string(target) + " not found";
}

std::string Tests::Test5()
{
	int target = 1;
	int orderedArr[] = { 1, 1, 1, 2, 2, 2, 3};
	int size = 7;
	auto res = BinarySearch::Find(target, orderedArr, size);
	if (res != 0) Failed(__func__);
	return "found " + std::to_string(target) + " at " + std::to_string(res);
}

std::string Tests::Test6()
{
	int target = 2;
	int orderedArr[] = { 1, 1, 1, 2, 2, 2, 3 };
	int size = 7;
	auto res = BinarySearch::Find(target, orderedArr, size);
	if (res != 3) Failed(__func__);
	return "found " + std::to_string(target) + " at " + std::to_string(res);
}

std::string Tests::Test7()
{
	int target = 3;
	int orderedArr[] = { 1, 1, 1, 2, 2, 2, 3 };
	int size = 7;
	auto res = BinarySearch::Find(target, orderedArr, size);
	if (res != 6) Failed(__func__);
	return "found " + std::to_string(target) + " at " + std::to_string(res);
}
