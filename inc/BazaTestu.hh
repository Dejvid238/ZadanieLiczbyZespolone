#ifndef BAZATESTU_HH
#define BAZATESTU_HH
#include "WyrazenieZesp.hh"


//deklaracja struktury BazaTestu ktora jako argumenty przyjmuje wskaznik na wybrana tablice zawierajaca tresc testu
//calkowita ilosc pytan (bedaca wymiarem tablicy) oraz numer aktualnego pytania

struct BazaTestu {
  WyrazenieZesp  *wskTabTestu;   /* Wskaznik na tablice zawierajaca pytania testu */
  unsigned int    IloscPytan;    /* Ilosc wszystkich pytan */
  unsigned int    IndeksPytania; /* Numer pytania, ktore ma byc pobrane jako nastepne */
};

//deklaracja funkcji ktora ustawia zestaw pytan na podstawie wyboru uzytkownika 

void UstawTest( BazaTestu *wskBazaTestu, WyrazenieZesp *wskTabTestu, unsigned int IloscPytan );

//deklaracja funkcji typu bool odpowiedzialnej za poprawne zainicjalizowanie testu

bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char*  sNazwaTestu );

//deklaracja funkcji ustawiajacej pytanie (poprzez zmiane indeksu pytania)

bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu,  WyrazenieZesp *wskWyr );


#endif
