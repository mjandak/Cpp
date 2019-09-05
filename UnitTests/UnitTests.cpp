#include "pch.h"
#include "CppUnitTest.h"
#include "../BinaryTree/BinaryTree.h"
#include "../BinaryTree/BinaryTree.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int numbers[] = { 1,2,3,4 };

			auto tree = buildTree(numbers, 0, 3);
			auto json = treeToJson(tree);

			Assert::AreEqual(find(tree, 1), 0);
			Assert::AreEqual(find(tree, 2), 1);
			Assert::AreEqual(find(tree, 3), 2);
			Assert::AreEqual(find(tree, 4), 3);

			int numbers2[] = { 1,2,3,4,5 };
			tree = buildTree(numbers2, 0, 4);
			json = treeToJson(tree);
			Assert::AreEqual(numbers[find(tree, 1)], 1);
			Assert::AreEqual(numbers[find(tree, 2)], 2);
			Assert::AreEqual(numbers[find(tree, 3)], 3);
			Assert::AreEqual(numbers[find(tree, 4)], 4);
			Assert::AreEqual(numbers[find(tree, 5)], 5);

			int numbers3[] = { -5,-1,0,1,3,4,5,6,7,8,9,10,13,15,16 };
			size_t size = (sizeof(numbers3) / sizeof(*numbers3));
			tree = buildTree(numbers3, 0,  - 1);
			json = treeToJson(tree);
			for (size_t i = 0; i < size; i++)
			{
				Assert::AreEqual(numbers3[i], numbers3[find(tree, numbers3[i])]);
			}
		}
		
		TEST_METHOD(TestMethod2)
		{
			int numbers[] = { 1,2,3,4 };
			BinaryTree tree(numbers, 0, 3);
			Assert::AreEqual(numbers[0], numbers[tree.Find(1)]);
			Assert::AreEqual(numbers[1], numbers[tree.Find(2)]);
			Assert::AreEqual(numbers[2], numbers[tree.Find(3)]);
			Assert::AreEqual(numbers[3], numbers[tree.Find(4)]);
		}
	};
}
