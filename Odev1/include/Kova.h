/**        
 * @file  Kova.h
 * @description Girilen adet kadar kova oluşturuluyor ve kovanın içine toplar yerleştirilip, sıraları değiştirilebiliyor.
 * @course  Örgün 2.Sınıf 
 * @assignment  1  
 * @date  19/10/2019  
 * @author  Furkan Ergün(furkan.ergun[et]ogr.sakarya.edu.tr)   
 **/
#ifndef KOVA_H
#define KOVA_H
#include <iostream>
#include "Top.h"

using namespace std;

class Kova
{
private:
    Top *top;
    int renk;
    char Harf;

public:
    //Constructor
    Kova()
    {
        top = nullptr;
        renk = rand() % 13 + 1;
    };

    void KovaBilgisiYazdir();
    void TopOlustur();
    void TopYokEt();
    void setTop(Top *top);
    Top *getTopAdress();
    int getColor();

    ~Kova()
    {
        delete top;
    }
};
#endif