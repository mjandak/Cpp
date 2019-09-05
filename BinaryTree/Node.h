#pragma once
class Node
{
public:
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int idx;
	int value;

	Node();
};
