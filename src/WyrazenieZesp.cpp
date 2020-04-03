#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
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

LZespolona Oblicz (WyrazenieZesp  WyrZ)
{
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