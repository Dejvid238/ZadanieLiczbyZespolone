#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"

//inicjacja typu wyliczeniowego enum ktory definiuje zbior mozliwosci wyboru

enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

//model dwuargumentowego wyrazenia zespolonego z operatorem matematycznym pomiedzy argumentami

struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};

//deklaracja dwoch funkcji operujacych na liczbach zespolonych: pierwsza - wyswietlajaca wyrazenie zespolone na strumien wyjsciowy
//oraz druga ktora oblicza wartosc tego wyrazenia

void Wyswietl(WyrazenieZesp  WyrZ);
void Oblicz(WyrazenieZesp  WyrZ);

#endif
