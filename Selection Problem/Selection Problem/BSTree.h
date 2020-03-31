#ifndef _BSTree_H
#define _BSTree_H

#include "BSTreeNode.h"

class BSTree
{
private:
	BSTreeNode* root;

public:
	static int numComp;

public: //Public Methods
	BSTree();
	~BSTree();
	BSTreeNode* Find(int key);
	void Insert(const Person item, const int key);
	void Delete(const Person& item);
	BSTreeNode* Min(BSTreeNode* node);
	BSTreeNode* Max(BSTreeNode* node);
	void PrintTreeInorder() const;
	void PrintKValue(BSTreeNode* node, int& k, BSTreeNode** res);
	void DeleteRec(BSTreeNode* curr);
	BSTreeNode* getRoot() const;
	bool isEmpty();
	void MakeEmpty();
};
#endif // _BSTree_H
