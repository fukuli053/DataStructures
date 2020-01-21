/**        
 * @file  Kova.cpp
 * @description Girilen adet kadar kova oluşturuluyor ve kovanın içine toplar yerleştirilip, sıraları değiştirilebiliyor.
 * @course  Örgün 2.Sınıf   
 * @assignment  1  
 * @date  19/10/2019  
 * @author  Furkan Ergün(furkan.ergun[et]ogr.sakarya.edu.tr)   
 **/

#ifndef KOVA_H
#include "Kova.h"
#include "Top.h"
#endif

using namespace std;

void Kova::KovaBilgisiYazdir()
{
    if (top != nullptr)
    {
        Harf = top->getHarf();
    }
    else
    {
        Harf = '-';
    }
    cout << "   .|.   " << endl;
    cout << "  .   .  " << endl;
    cout << ".       ." << endl;
    cout << "#   " << Harf << "   #" << endl;
    cout << "#       #" << endl;
    cout << "#       #" << endl;
    cout << "#########" << endl;
}

void Kova::TopOlustur()
{
    if (top == nullptr)
    {
        top = new Top();
    }
}

void Kova::TopYokEt()
{
    if (top != nullptr)
    {
        delete top;
        top = nullptr;
    }
}

void Kova::setTop(Top *top)
{
    this->top = top;
}

Top *Kova::getTopAdress()
{
    return top;
}

int Kova::getColor()
{
    return renk;
}