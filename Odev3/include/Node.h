/**
* @file Node.h 
* @description İki farklı dosyadan sayıları okuyoruz ve iki ayrı ikili arama ağacı kullanalarak sıralıyoruz. Alt düğüm sayısı bulunarak farklı işlemler yapılıyor.
* @course Örgün Öğretim 2.Sınıf
* @assignment 3
* @date 9/12/2019
* @author Furkan Ergün furkan.ergun@ogr.sakarya.edu.tr
*/
#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *left;
	Node *right;
};

#endif