#ifndef _BSTreeNode_H
#define _BSTreeNode_H

#include "Person.h"

class BSTreeNode
{
private: //Private var
	Person data;

public://Public var
	int key;
	BSTreeNode* parent;
	BSTreeNode* left, * right;

public: //Public Methos
	BSTreeNode(int key, Person data, BSTreeNode* parent, BSTreeNode* left, BSTreeNode* right);
	~BSTreeNode();

	Person& getData();
	void setData(const Person& data);
	void printInorder() const;
	void printPreOrder() const;
	void printPostOrder() const;
};

#endif // _BSTreeNode_H
