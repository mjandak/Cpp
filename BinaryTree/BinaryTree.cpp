// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include "Node.h"

Node* buildTree(int numbers[], int startIdx, int lastIdx)
{
	if (startIdx > lastIdx)
	{
		throw std::invalid_argument("wtf?");
	}
	if (startIdx == lastIdx)
	{
		auto node = new Node();
		node->idx = startIdx;
		node->value = numbers[startIdx];
		return node;
	}
	auto node = new Node();
	node->idx = startIdx + (lastIdx - startIdx) / 2;
	node->left = buildTree(numbers, startIdx, node->idx);
	node->right = buildTree(numbers, node->idx + 1, lastIdx);
	return node;
}

std::string treeToJson(Node* node)
{
	std::ostringstream output;
	output << "{idx:" << node->idx;
	if (!node->left && !node->right)
	{
		output << ",val:" << node->value;
	}
	else
	{
		if (node->left)
		{
			output << ",";
			output << "L:" << treeToJson(node->left);
		}
		if (node->right)
		{
			output << ",";
			output << "R:" << treeToJson(node->right);
		}
	}
	output << "}";
	return output.str();
}

int main()
{
	int numbers[] = { 1,2,3,4 };

	auto x = buildTree(numbers, 0, 3);
	auto json = treeToJson(x);

	int numbers2[] = { 1,2,3,4,5 };
	x = buildTree(numbers2, 0, 4);
	json = treeToJson(x);

	int numbers3[] = { -5,-1,0,1,3,4,5,6,7,8,9,10,13,15,16 };
	x = buildTree(numbers3, 0, (sizeof(numbers3) / sizeof(*numbers3)) - 1);
	json = treeToJson(x);
}
