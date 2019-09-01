#include "pch.h"
#include "CppUnitTest.h"
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
		}
	};
}
