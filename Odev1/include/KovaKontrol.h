/**        
 * @file  KovaKontrol.h  
 * @description Girilen adet kadar kova oluşturuluyor ve kovanın içine toplar yerleştirilip, sıraları değiştirilebiliyor.
 * @course  Örgün 2.Sınıf   
 * @assignment  1  
 * @date  20/10/2019  
 * @author  Furkan Ergün(furkan.ergun[et]ogr.sakarya.edu.tr)   
 **/
#ifndef KOVAKONTROL_H
#define KOVAKONTROL_H
#include <iostream>
#include "Kova.h"

using namespace std;

class KovaKontrol
{
private:
    int kovaLength;
    Kova **kovalar;

public:
    //Constructor
    KovaKontrol(int kovaLength)
    {
        kovalar = new Kova *[kovaLength];
        for (int i = 0; i < kovaLength; i++)
        {
            kovalar[i] = new Kova();
        }
        this->kovaLength = kovaLength;
    };

    void KovalariBastir();
    void TopYerlestir();
    void TopYokEt();
    void KovaDegistir(int, int);
    void TopDegistir(int, int);
    void KovalariTersYerlestir();
    void ToplariTersYerlestir();

    ~KovaKontrol()
    {
        for (int i = 0; i < kovaLength; i++)
            delete[] kovalar[i];
        delete[] kovalar;
    }
};

#endif