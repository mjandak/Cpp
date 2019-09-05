#pragma once
#include "Node.h"

class BinaryTree
{
private:
	Node* root;
	unsigned int findR(Node* node, int key);
	Node* buildTree(int orderedArr[], int startIdx, int lastIdx);
public:
	BinaryTree(int numbers[], int startIdx, int lastIdx);
	unsigned int Find(int key);
};

