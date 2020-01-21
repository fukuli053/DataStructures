/**
* @file BST.cpp 
* @description İki farklı dosyadan sayıları okuyoruz ve iki ayrı ikili arama ağacı kullanalarak sıralıyoruz. Alt düğüm sayısı bulunarak farklı işlemler yapılıyor.
* @course Örgün Öğretim 2.Sınıf
* @assignment 3
* @date 9/12/2019
* @author Furkan Ergün furkan.ergun@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"
#include "Node.h"
using namespace std;
Node *BST::insert(int x, Node *tree)
{
	if (tree == NULL)
	{
		tree = new Node;
		tree->data = x;
		tree->left = tree->right = NULL;
	}
	else if (x <= tree->data)
		tree->left = insert(x, tree->left);
	else
		tree->right = insert(x, tree->right);

	numOfNode = 0;
	return tree;
}

Node *BST::findMin(Node *tree)
{
	if (tree == NULL)
		return NULL;
	else if (tree->left == NULL)
		return tree;
	else
		return findMin(tree->left);
}

Node *BST::findMax(Node *t)
{
	if (t == NULL)
		return NULL;
	else if (t->right == NULL)
		return t;
	else
		return findMax(t->right);
}

Node *BST::remove(int x, Node *t)
{
	Node *temp;
	if (t == NULL)
		return NULL;
	else if (x < t->data)
		t->left = remove(x, t->left);
	else if (x > t->data)
		t->right = remove(x, t->right);
	else if (t->left && t->right)
	{
		temp = findMax(t->left);
		t->data = temp->data;
		t->left = remove(t->data, t->left);
	}
	else
	{
		temp = t;
		if (t->left == NULL)
			t = t->right;
		else if (t->right == NULL)
			t = t->left;
		delete temp;
	}

	numOfNode = 0;
	return t;
}

Node *BST::find(Node *tree, int x)
{
	if (tree == NULL)
		return NULL;
	else if (x < tree->data)
		return find(tree->left, x);
	else if (x > tree->data)
		return find(tree->right, x);
	else
		return tree;
}

Node *BST::makeEmpty(Node *tree)
{
	if (tree == NULL)
		return NULL;
	else
	{
		makeEmpty(tree->left);
		makeEmpty(tree->right);
		delete tree;
	}
	return NULL;
}

int BST::count(Node *tree)
{
	int c = 1; //Node itself should be counted
	if (tree == NULL)
		return 0;
	else
	{
		c += count(tree->left);
		c += count(tree->right);
		return c;
	}
}

void BST::postOrder(Node *tree)
{
	if (tree == NULL)
		return;
	postOrder(tree->left);
	postOrder(tree->right);

	cout << "<" << tree->data << ",";
	numOfNode += count(tree) - 1;
	cout << count(tree) - 1 << "> ";
}

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	root = makeEmpty(root);
}

void BST::insert(int x)
{
	root = insert(x, root);
}

void BST::remove(int x)
{
	root = remove(x, root);
}

void BST::display()
{
	postOrder(root);
	cout << endl;
	cout << "Toplam Soy Sayisi: " << numOfNode << endl;
}

void BST::search(int x)
{
	root = find(root, x);
}

int BST::getNumOfNode()
{
	return numOfNode;
}

int BST::getMax()
{
	return findMax(root)->data;
}

int BST::getMin()
{
	return findMin(root)->data;
}

int BST::getRoot()
{
	return root->data;
}