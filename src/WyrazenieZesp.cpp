#include "WyrazenieZesp.hh"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//dyrektywa dla strumienia wyjsciowego przeksztalcajaca wybrane wyrazenia wedle okreslonego schematu
//w tym wypadku jest to operacja na liczbie zespolonej: przy wykryciu struktury liczby zespolonej
//dyrektywa umieszcza ja w nawiasach polokraglych oraz dopisuje 'i' przy liczbie reprezentujacej czesc urojona

std::ostream & operator << ( std::ostream & StrmWy, LZespolona Lz)
{
    return StrmWy << "(" << Lz.re << std::showpos << Lz.im << std::noshowpos << 'i' <<")";
}

//cialo funkcji wyswietlajacej wyrazenie zespolone uprzednio wczytane z tablicy reprezentujacej baze testu

void Wyswietl (WyrazenieZesp &WyrZ){
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

//cialo funkcji wyswietlajacej liczbe zespolona 

void Wyswietl(LZespolona &skl)
{
    cout<<skl;
}

//cialo funkcji obliczajacej wartosc dzialania matematycznego na liczbach zespolonych po jego wczesniejszej interpretacji
//z wykorzystaniem funkcji switch

LZespolona Oblicz (WyrazenieZesp  &WyrZ)
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
        return TwojWynik;
}

//cialo funkcji porownujacej wynik wyrazenia wpisanego przez uzytkownika z wartoscia poprawna
//w przypadku braku ktoregokolwiek elementu w zapisie wyniku program informuje o tym uzytkownika

bool Wczytaj (LZespolona &skl)
{
    LZespolona Odpowiedz;
    int ZmPomocnik;
    cout<<"Twoja odpowiedz: ";
    char znak;
    cin>>znak;
    if (znak!='(') ZmPomocnik=1;
    cin>>Odpowiedz.re>>Odpowiedz.im;
    if((skl.re!=Odpowiedz.re) || (skl.im!=Odpowiedz.im)) ZmPomocnik=2;
    cin>>znak;
    if (znak!='i') ZmPomocnik=1;
    cin>>znak;
    if (znak!=')') ZmPomocnik=1;
        switch(ZmPomocnik)
        {
            case 1:
            cout<<"Blad w zapisie liczby. Upewnij sie czy liczba jest umieszczona w nawiasach i posiada identyfikator 'i'";
            cout<<" dla czesci urojonej. ";
            cout<<endl;
            return false;
            break;
            case 2:
            cout<<"Blad. Nieprawidlowy wynik. ";
            return false;
            break;
            default:
            return true;
            break;
        }
}