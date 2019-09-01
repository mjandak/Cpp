// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <Windows.h>
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
	node->value = numbers[node->idx];
	node->left = buildTree(numbers, startIdx, node->idx);
	node->right = buildTree(numbers, node->idx + 1, lastIdx);
	return node;
}

std::string treeToJson(Node* node)
{
	std::ostringstream output;
	output << "{idx:" << node->idx << ",val:" << node->value;
	//if (!node->left && !node->right)
	//{
	//	//output << ",val:" << node->value;
	//}
	//else
	//{
	//	if (node->left)
	//	{
	//		output << ",";
	//		output << "L:" << treeToJson(node->left);
	//	}
	//	if (node->right)
	//	{
	//		output << ",";
	//		output << "R:" << treeToJson(node->right);
	//	}
	//}
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
	output << "}";
	return output.str();
}

int find(Node* node, int key)
{
	if (!node->left && !node->right)
	{
		if (node->value == key)
		{
			return node->idx;
		}
		return -1;
	}
	if (key > node->value)
	{
		if (!node->right) return -1;
		std::ostringstream log;
		log << node->value << "=>R ";
		OutputDebugStringA(log.str().c_str());
		//OutputDebugString(L"right:" + *std::to_wstring(node->value).c_str());
		//std::cerr << "R:" + node->value;
		return find(node->right, key);
	}
	else
	{
		if (!node->left) return -1;
		std::ostringstream log;
		log << node->value << "=>L ";
		OutputDebugStringA(log.str().c_str());
		//OutputDebugString(L"left:" + *std::to_wstring(node->value).c_str());
		return find(node->left, key);
	}
}

int main()
{
	int numbers[] = { 1,2,3,4 };

	auto tree = buildTree(numbers, 0, 3);
	auto json = treeToJson(tree);
	auto b = find(tree, 1) == 0;
	b = find(tree, 2) == 1;
	b = find(tree, 3) == 2;
	b = find(tree, 4) == 3;

	int numbers2[] = { 1,2,3,4,5 };
	tree = buildTree(numbers2, 0, 4);
	json = treeToJson(tree);

	int numbers3[] = { -5,-1,0,1,3,4,5,6,7,8,9,10,13,15,16 };
	tree = buildTree(numbers3, 0, (sizeof(numbers3) / sizeof(*numbers3)) - 1);
	json = treeToJson(tree);


}
