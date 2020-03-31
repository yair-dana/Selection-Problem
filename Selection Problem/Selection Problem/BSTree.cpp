#include "BSTree.h"
#include <iostream>

BSTree::BSTree() { this->root = nullptr; }
//-----------------------------------------------------------------------//
BSTree::~BSTree() { delete root; }
//-----------------------------------------------------------------------//
BSTreeNode* BSTree::Find(int key)
{
	BSTreeNode* temp = root;
	while (temp != nullptr)
	{
		if (key == temp->key)
		{//The key is the id of data (person)
			numComp++;
			return temp;
		}
		else if (key < temp->key)
		{
			numComp += 2;
			temp = temp->left;
		}
		else
		{
			numComp += 2;
			temp = temp->right;
		}

	}
	return nullptr;
}
//-----------------------------------------------------------------------//
void BSTree::Insert(const Person item, int key)
{	//Efficiency:
	//Worst- Teta (n), Average -Teta (logn)

	if (Find(key) != nullptr)
	{// Teta (n) for the worst
	// Teta (log n) for the Average
		cout << "error key allready exists" << endl;;
		return;
	}
	BSTreeNode* parent = nullptr;
	BSTreeNode* temp = root;
	BSTreeNode* newnode = nullptr;

	while (temp != nullptr)
	{//O(n) for worst case
	 //Teta(log n) for average case 
		parent = temp;
		numComp++;

		if (key < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	newnode = new BSTreeNode(key, item, parent, nullptr, nullptr);

	if (parent == nullptr)
		root = newnode;
	else if (key < parent->key)
	{
		parent->left = newnode;
		numComp++;
	}
	else
	{
		parent->right = newnode;
		numComp++;
	}
}
//-----------------------------------------------------------------------//
void BSTree::Delete(const Person& item)
{
	BSTreeNode* curr = Find(item.getId());
	BSTreeNode* parent = curr->parent;
	DeleteRec(curr);
}
//-----------------------------------------------------------------------//
void BSTree::DeleteRec(BSTreeNode* curr)
{
	// node with only one child or no child 
	if (curr->left == nullptr)
	{

		curr->parent = curr->right;
		curr->left = curr->right = nullptr;
		delete(curr);
	}
	else if (curr->right == nullptr)
	{
		curr->parent = curr->left;
		curr->left = curr->right = nullptr;
		delete(curr);
	}
	// node with two children
	else
	{
		BSTreeNode* temp = Max(root->left);
		curr->key = temp->key;
		curr->setData(temp->getData());
		DeleteRec(curr);
	}
}
//-----------------------------------------------------------------------//
BSTreeNode* BSTree::Min(BSTreeNode* node)
{
	BSTreeNode* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}
//-----------------------------------------------------------------------//
BSTreeNode* BSTree::Max(BSTreeNode* node)
{
	BSTreeNode* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->right != NULL)
		current = current->right;

	return current;
}
//-----------------------------------------------------------------------//
void BSTree::PrintTreeInorder() const
{
	root->printInorder();
}
//-----------------------------------------------------------------------//
void BSTree::PrintKValue(BSTreeNode* node, int& k, BSTreeNode** res)
{
	//Worst - Teta(n)
	//Avarge - Teta(logn)
	if ((*res) != nullptr)
		return;

	if (node->left)
		PrintKValue(node->left, k, res);
	k--;
	if (k == 0)
		(*res) = node;
	if (node->right)
		PrintKValue(node->right, k, res);
}
//-----------------------------------------------------------------------//
bool BSTree::isEmpty()
{
	if (this->root == NULL)
		return true;
	//else
	return false;
}
//-----------------------------------------------------------------------//
void BSTree::MakeEmpty()
{
	if (!isEmpty())
	{
		delete(root);
	}
}
//-----------------------------------------------------------------------//
BSTreeNode* BSTree::getRoot() const
{
	return root;
}
//-----------------------------------------------------------------------//
int BSTree::numComp = 0;
//-----------------------------------------------------------------------//
