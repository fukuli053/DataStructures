/**        
 * @file  Top.h  
 * @description Girilen adet kadar kova oluşturuluyor ve kovanın içine toplar yerleştirilip, sıraları değiştirilebiliyor.  
 * @course  Örgün 2.Sınıf   
 * @assignment  1  
 * @date  20/10/2019  
 * @author  Furkan Ergün(furkan.ergun[et]ogr.sakarya.edu.tr)   
 **/
#ifndef TOP_H
#define TOP_H
#include <iostream>

class Top
{
private:
    char harf;

public:
    //Constructor
    Top()
    {
        harf = 'A' + rand() % 26;
    };

    char getHarf();
};
#endif