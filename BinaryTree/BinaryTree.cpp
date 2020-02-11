// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <Windows.h>
#include "Node.h"
#include "BinaryTree.h"

std::string BinaryTree::ToJson(Node* node)
{
	std::ostringstream output;
	output << "{idx:" << node->idx << ",val:" << node->value;
	if (node->left)
	{
		output << ",";
		output << "L:" << ToJson(node->left);
	}
	if (node->right)
	{
		output << ",";
		output << "R:" << ToJson(node->right);
	}
	output << "}";
	return output.str();
}

int BinaryTree::findR(Node* node, int key)
{
	if (!node->left && !node->right)
	{
		if (node->value == key) return node->idx;
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
		return findR(node->right, key);
	}
	else
	{
		if (!node->left) return -1;
		std::ostringstream log;
		log << node->value << "=>L ";
		OutputDebugStringA(log.str().c_str());
		//OutputDebugString(L"left:" + *std::to_wstring(node->value).c_str());
		return findR(node->left, key);
	}
}

Node* BinaryTree::buildTree(int numbers[], int startIdx, int lastIdx)
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

BinaryTree::BinaryTree(int numbers[], int startIdx, int lastIdx)
{
	root = buildTree(numbers, startIdx, lastIdx);
}

int BinaryTree::Find(int key)
{
	return findR(root, key);
}
