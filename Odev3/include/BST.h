/**
* @file BST.h 
* @description İki farklı dosyadan sayıları okuyoruz ve iki ayrı ikili arama ağacı kullanalarak sıralıyoruz. Alt düğüm sayısı bulunarak farklı işlemler yapılıyor.
* @course Örgün Öğretim 2.Sınıf
* @assignment 3
* @date 9/12/2019
* @author Furkan Ergün furkan.ergun@ogr.sakarya.edu.tr
*/
#ifndef BST_H
#define BST_H
#include "Node.h"
using namespace std;
class BST
{
public:
	BST();
	~BST();
	void insert(int);
	void remove(int);
	void search(int);
	int getNumOfNode();
	int getMax();
	int getMin();
	int getRoot();
	void display();

private:
	Node *root = NULL;
	int numOfNode = 0;

	Node *insert(int, Node *);
	Node *findMin(Node *);
	Node *findMax(Node *);
	Node *remove(int, Node *);
	Node *find(Node *, int);
	Node *makeEmpty(Node *);
	int count(Node *);
	void postOrder(Node *);
};

#endif