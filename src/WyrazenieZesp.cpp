#include "WyrazenieZesp.hh"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

 /* Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
std::ostream & operator << ( std::ostream & StrmWy, LZespolona Lz)
{
    return StrmWy << "(" << Lz.re << std::showpos << Lz.im << std::noshowpos << 'i' <<")";
}

void Wyswietl (WyrazenieZesp WyrZ){
    char znak;
    switch (WyrZ.Op)
        {
            case Op_Dodaj:
            znak='+';
            break;
            case Op_Odejmij:
            znak='-';
            break;
            case Op_Mnoz:
            znak='*';
            break;
            case Op_Dziel:
            znak='/';
            break;
            default:
            cout<<"  Bledna interpretacja operatora arytmetycznego   "<<endl;
            break;
        }
    cout<<WyrZ.Arg1<<znak<<WyrZ.Arg2;
}

void Oblicz (WyrazenieZesp  WyrZ)
{
    LZespolona TwojWynik;
    switch (WyrZ.Op)
        {
            case Op_Dodaj:
            TwojWynik = operator + (WyrZ.Arg1,WyrZ.Arg2);
            break;
            case Op_Odejmij:
            TwojWynik = operator - (WyrZ.Arg1,WyrZ.Arg2);
            break;
            case Op_Mnoz:
            TwojWynik = operator * (WyrZ.Arg1,WyrZ.Arg2);
            break;
            case Op_Dziel:
            TwojWynik = operator / (WyrZ.Arg1,WyrZ.Arg2);
            break;
            default:
            cout<<"nic tu wiecej nie ma"<<endl;
            break;
        }
        cout << TwojWynik;
}