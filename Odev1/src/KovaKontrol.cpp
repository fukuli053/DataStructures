/**        
 * @file  KovaKontrol.cpp  
 * @description Girilen adet kadar kova oluşturuluyor ve kovanın içine toplar yerleştirilip, sıraları değiştirilebiliyor.
 * @course  Örgün 2.Sınıf
 * @assignment  1  
 * @date  20/10/2019  
 * @author  Furkan Ergün(furkan.ergun[et]ogr.sakarya.edu.tr)   
 **/
#ifndef KOVAKONTROL_H
#include "KovaKontrol.h"
#endif
#include <iostream>

#include <Windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

void KovaKontrol::KovalariBastir()
{
    for (int i = 0; i < kovaLength; i++)
    {
        SetConsoleTextAttribute(hConsole, kovalar[i]->getColor());
        cout << i + 1 << ". Kova" << endl;
        kovalar[i]->KovaBilgisiYazdir();
        cout << "Kovanin Adresi: " << kovalar[i] << endl;
        cout << "Topun Adresi: " << kovalar[i]->getTopAdress() ? kovalar[i]->getTopAdress() : nullptr;
        cout << endl
             << endl;
    }
}

void KovaKontrol::TopYerlestir()
{
    for (int i = 0; i < kovaLength; i++)
    {
        kovalar[i]->TopOlustur();
    }
}

void KovaKontrol::TopYokEt()
{
    for (int i = 0; i < kovaLength; i++)
    {
        kovalar[i]->TopYokEt();
    }
}

void KovaKontrol::KovaDegistir(int kova1, int kova2)
{
    Kova *kova11 = kovalar[kova1 - 1];
    Kova *kova22 = kovalar[kova2 - 1];
    kovalar[kova2 - 1] = kova11;
    kovalar[kova1 - 1] = kova22;
}

void KovaKontrol::TopDegistir(int kova1, int kova2)
{
    Top *top1 = kovalar[kova1 - 1]->getTopAdress();
    Top *top2 = kovalar[kova2 - 1]->getTopAdress();
    kovalar[kova1 - 1]->setTop(top2);
    kovalar[kova2 - 1]->setTop(top1);
}

void KovaKontrol::KovalariTersYerlestir()
{
    int first, last;
    first = 0;
    last = kovaLength - 1;
    while (first < last)
    {
        Kova *temp = kovalar[first];
        kovalar[first] = kovalar[last];
        kovalar[last] = temp;
        first++;
        last--;
    }
}

void KovaKontrol::ToplariTersYerlestir()
{
    int first, last;
    first = 0;
    last = kovaLength - 1;
    while (first < last)
    {
        Top *temp = kovalar[first]->getTopAdress();
        kovalar[first]->setTop(kovalar[last]->getTopAdress());
        kovalar[last]->setTop(temp);
        first++;
        last--;
    }
}