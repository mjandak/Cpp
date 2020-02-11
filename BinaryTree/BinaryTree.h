#pragma once
#include "Node.h"

class BinaryTree
{
private:
	Node* root;
	int findR(Node* node, int key);
	Node* buildTree(int orderedArr[], int startIdx, int lastIdx);
public:
	BinaryTree(int numbers[], int startIdx, int lastIdx);
	int Find(int key);
	static std::string ToJson(Node* node);
};
