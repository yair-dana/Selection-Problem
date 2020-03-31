#include "BSTreeNode.h"
#include <iostream>

BSTreeNode::BSTreeNode(int key, Person data, BSTreeNode* parent, BSTreeNode* left, BSTreeNode* right)
	:key(key), data(data), parent(parent), left(left), right(right)
{
}
//-----------------------------------------------------------------------//
BSTreeNode::~BSTreeNode()
{
	delete left;
	delete right;
}
//-----------------------------------------------------------------------//
Person& BSTreeNode::getData()
{
	return data;
}
//-----------------------------------------------------------------------//
void BSTreeNode::setData(const Person& data)
{
	this->data = data;
}
//-----------------------------------------------------------------------//
void BSTreeNode::printInorder() const
{
	if (left != nullptr)
		left->printInorder();
	std::cout << "key: " << key;
	if (right != nullptr)
		right->printInorder();
}
//-----------------------------------------------------------------------//
void BSTreeNode::printPostOrder() const
{
	if (left != nullptr)
		left->printPostOrder();
	if (right != nullptr)
		right->printPostOrder();
	std::cout << "key: " << key;
}
//-----------------------------------------------------------------------//
void BSTreeNode::printPreOrder() const
{
	std::cout << "key: " << key;
	if (left != nullptr)
		left->printPreOrder();
	if (right != nullptr)
		right->printPreOrder();
}
//-----------------------------------------------------------------------//
