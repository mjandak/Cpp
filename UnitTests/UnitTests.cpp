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
			BinaryTree tree(numbers, 0, 3);
			Assert::AreEqual(numbers[0], numbers[tree.Find(1)]);
			Assert::AreEqual(numbers[1], numbers[tree.Find(2)]);
			Assert::AreEqual(numbers[2], numbers[tree.Find(3)]);
			Assert::AreEqual(numbers[3], numbers[tree.Find(4)]);

			int numbers2[] = { 100,200 };
			tree = BinaryTree(numbers2, 0, 1);
			Assert::AreEqual(numbers2[0], numbers2[tree.Find(100)]);
			Assert::AreEqual(numbers2[1], numbers2[tree.Find(200)]);
			Assert::AreEqual(-1, tree.Find(1000));
			Assert::AreEqual(-1, tree.Find(-1000));

			int numbers3[] = { -5,-1,0,1,3,4,5,6,7,8,9,10,13,15,16 };
			size_t size = (sizeof(numbers3) / sizeof(*numbers3));
			tree = BinaryTree(numbers3, 0, size - 1);
			for (size_t i = 0; i < size; i++)
			{
				Assert::AreEqual(numbers3[i], numbers3[tree.Find(numbers3[i])]);
			}
			Assert::AreEqual(-1, tree.Find(1000));
			Assert::AreEqual(-1, tree.Find(-1000));

			int numbers4[] = { 1 };
			tree = BinaryTree(numbers4, 0, 0);
			Assert::AreEqual(numbers4[0], numbers4[tree.Find(1)]);
			Assert::AreEqual(-1, tree.Find(1000));
			Assert::AreEqual(-1, tree.Find(-1000));
		}
	};
}
