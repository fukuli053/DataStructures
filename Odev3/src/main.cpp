/**
* @file main.cpp 
* @description İki farklı dosyadan sayıları okuyoruz ve iki ayrı ikili arama ağacı kullanalarak sıralıyoruz. Alt düğüm sayısı bulunarak farklı işlemler yapılıyor.
* @course Örgün Öğretim 2.Sınıf
* @assignment 3
* @date 9/12/2019
* @author Furkan Ergün furkan.ergun@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <conio.h>

#include "Node.h"
#include "BST.h"

using namespace std;
int main()
{
	BST tree1, tree2;
	int myScore = 0, rivalScore = 0;
	int tour = 0;
	char loopContinue;

	ifstream readFile("benim.txt");
	int numberTree1;
	while (readFile >> numberTree1)
	{
		tree1.insert(numberTree1);
	}

	ifstream readFile2("rakip.txt");
	int numberTree2;
	while (readFile2 >> numberTree2)
	{
		tree2.insert(numberTree2);
	}

	do
	{
		tour++;
		system("cls");
		cout << "Benim Agac PostOrder";
		cout << endl;
		tree1.display();
		cout << endl;
		cout << "Rakip Agac PostOrder";
		cout << endl;
		tree2.display();

		if (tree2.getNumOfNode() > tree1.getNumOfNode())
		{ //Benim Listem Kazanıyor
			tree1.insert(tree2.getMax());
			tree2.remove(tree2.getMax());
			tree2.insert(tree1.getRoot());
			tree1.remove(tree1.getRoot());
			myScore++;
		}
		else if (tree1.getNumOfNode() > tree2.getNumOfNode())
		{ //Rakip Kazanıyor
			tree2.insert(tree1.getMax());
			tree1.remove(tree1.getMax());
			tree1.insert(tree2.getRoot());
			tree2.remove(tree2.getRoot());
			rivalScore++;
		}
		else if (tree1.getNumOfNode() == tree2.getNumOfNode())
		{
			int Temp1, Temp2;
			Temp1 = tree1.getRoot();
			Temp2 = tree2.getRoot();
			tree1.insert(Temp2);
			tree2.remove(Temp2);
			tree2.insert(Temp1);
			tree1.remove(Temp1);
		}

		cout << endl;

		cout << "-- TEBRIKLER TURU KAZANDINIZ --" << endl;
		cout << tour << ". TUR" << endl;
		cout << "SKOR" << endl;
		cout << "Benim :" << myScore << endl;
		cout << "Rakip :" << rivalScore << endl;

		loopContinue = _getch();

		if (myScore == 5 || rivalScore == 5)
		{
			break;
		}

	} while (tour <= 19);

	return 0;
}