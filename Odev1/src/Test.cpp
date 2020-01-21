/**        
 * @file  Test.cpp  
 * @description Girilen adet kadar kova oluşturuluyor ve kovanın içine toplar yerleştirilip, sıraları değiştirilebiliyor.
 * @course  Örgün 2.Sınıf   
 * @assignment  1  
 * @date  19/10/2019  
 * @author  Furkan Ergün(furkan.ergun[et]ogr.sakarya.edu.tr)   
 **/
#include <iostream>
#include "Kova.h"
#include "KovaKontrol.h"

#include <Windows.h>
HANDLE hConsolea = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

int main()
{
    system("CLS");
    int kova, secim;
    cout << "Kova Sayisi: ";
    cin >> kova;

    KovaKontrol *KovaController = new KovaKontrol(kova);

    KovaController->KovalariBastir();

    do
    {
        SetConsoleTextAttribute(hConsolea, 7);
        cout << "[1] Toplari Yerlestir " << endl;
        cout << "[2] Toplari Yoket " << endl;
        cout << "[3] Kova Degistir " << endl;
        cout << "[4] Top Degistir " << endl;
        cout << "[5] Kovalari Tersten Yerlestir " << endl;
        cout << "[6] Toplari Tersten Yerlestir " << endl;
        cout << "[7] Cikis " << endl;
        cout << "Secim:";
        cin >> secim;
        system("CLS");
        switch (secim)
        {
        case 1:
            KovaController->TopYerlestir();
            system("CLS");
            KovaController->KovalariBastir();
            break;
        case 2:
            KovaController->TopYokEt();
            system("CLS");
            KovaController->KovalariBastir();
            break;
        case 3:
            int kova1, kova2;
            cout << "Hangi Kova: ";
            cin >> kova1;
            cout << "Hangi Kova ile: ";
            cin >> kova2;
            KovaController->KovaDegistir(kova1, kova2);
            system("CLS");
            KovaController->KovalariBastir();
            break;
        case 4:
            cout << "Hangi Kova: ";
            cin >> kova1;
            cout << "Hangi Kova ile: ";
            cin >> kova2;
            KovaController->TopDegistir(kova1, kova2);
            system("CLS");
            KovaController->KovalariBastir();
            break;
        case 5:
            KovaController->KovalariTersYerlestir();
            system("CLS");
            KovaController->KovalariBastir();
            break;
        case 6:
            KovaController->ToplariTersYerlestir();
            system("CLS");
            KovaController->KovalariBastir();
            break;
        case 7:

            break;
        default:
            cout << endl
                 << "Yanlis tercih!" << endl;
            cin.ignore();
            cin.get();
            break;
        }
    } while (secim != 7);
    delete KovaController;
}