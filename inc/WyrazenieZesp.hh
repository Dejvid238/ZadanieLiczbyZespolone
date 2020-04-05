#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"

//inicjacja typu wyliczeniowego enum ktory definiuje zbior mozliwosci do wyboru

enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

//model dwuargumentowego wyrazenia zespolonego z operatorem matematycznym pomiedzy argumentami

struct WyrazenieZesp 
{
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


//deklaracja dwoch funkcji operujacych na strumieniu wyjsciowym: pierwsza wyswietla liczbe zespolona, druga - wyrazenie zespolone

void Wyswietl(LZespolona &);
void Wyswietl(WyrazenieZesp  &);

//deklaracja dwoch funkcji: pierwsza oblicza wartosc dzialania arytmetycznego, druga natomiast porownuje jego wartosc
//z tym co wpisze uzytkownik

LZespolona Oblicz(WyrazenieZesp  &);
bool Wczytaj(LZespolona &);
#endif
