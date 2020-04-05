#include "BazaTestu.hh"

#include <cstring>
#include <stdlib.h>
#include <iostream>

using std::endl;
using std::cout;

//tablica typu struktualnego zawierajaca tresc latwego testu

static WyrazenieZesp  TestLatwy[] =
  { {{2,1}, Op_Dodaj, {1,2}},
    {{1,0}, Op_Odejmij, {0,1}},
    {{3,0}, Op_Mnoz, {0,3}},
    {{4,8}, Op_Dziel, {1,0}},
  };

//tablica typu struktualnego zawierajaca tresc trudnego testu

static WyrazenieZesp  TestTrudny[] =
  { {{2.5,-1}, Op_Dodaj, {-1.2,12}},
    {{0,-5.5}, Op_Odejmij, {13.2,-4.1}},
    {{2.5,-3}, Op_Mnoz, {-2.5,9}},
    {{4,8}, Op_Dziel, {5,-3}},
  };

//cialo funkcji ustawiajacej test wedle wskazania uzytkownika (trudny/latwy)
//jako parametry przyjmuje wskaznik typu BazaTestu (odpowiadajaca za organizacje pytan), wskaznik na tablice reprezentujaca
//tresc testu oraz calkowita ilosc pytan odbierana jako rozmiar tablicy

void UstawTest( BazaTestu *wskBazaTestu, WyrazenieZesp *wskTabTestu, unsigned int IloscPytan )
{
  wskBazaTestu->wskTabTestu = wskTabTestu;
  wskBazaTestu->IloscPytan = IloscPytan;
  wskBazaTestu->IndeksPytania = 0;
}

//cialo funkcji typu bool odpowiadajacej za poprawny uchwyt wybranego testu w ciele programu
//funkcja porownuje wpisany argument z bazowym i przekazuje decyzje uzytkownika do funkcji UstawTest

bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char *sNazwaTestu )
{
  if (!strcmp(sNazwaTestu,"latwy")) {
    BazaTestu BazaL={TestLatwy,sizeof(TestLatwy)/sizeof(WyrazenieZesp),0};
    *wskBazaTestu=BazaL;
    UstawTest(wskBazaTestu,TestLatwy,sizeof(TestLatwy)/sizeof(WyrazenieZesp));
    return true;
  }    
  else if (!strcmp(sNazwaTestu,"trudny")) {
    BazaTestu BazaL={TestTrudny,sizeof(TestTrudny)/sizeof(WyrazenieZesp),0};
    *wskBazaTestu=BazaL;
    UstawTest(wskBazaTestu,TestTrudny,sizeof(TestTrudny)/sizeof(WyrazenieZesp));
    return true;
  }
  cout << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
  return false;
}

//cialo funkcji odpowiadajacej za pobieranie nastepnego pytania
//funkcja sprawdza czy indeks pytania miesci sie w zakresie tablicy w ktorej znajduje sie tresc testu

bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu, WyrazenieZesp *wskWyrazenie )
{
  if (wskBazaTestu->IndeksPytania >= wskBazaTestu->IloscPytan) return false;

  *wskWyrazenie = wskBazaTestu->wskTabTestu[wskBazaTestu->IndeksPytania];
  ++wskBazaTestu->IndeksPytania;
  return true;
}

//cialo funkcji prowadzacej statystki odpowiedzi uzytkownika

void Inicjuj (Statystyki &st)
{
  int pomocnicza;
  pomocnicza=(st.dobre*100)/(st.dobre+st.zle);
  cout<<"Ilosc dobrych odpowiedzi: "<<st.dobre<<endl;
  cout<<"Ilosc zlych odpowiedzi: "<<st.zle<<endl;
  cout<<"Wynik procentowy poprawnych odpowiedzi: "<<pomocnicza<<"%"<<endl;  
}
