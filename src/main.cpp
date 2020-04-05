#include "BazaTestu.hh"

#include <iostream>
#include <cassert>

//deklaracja przestrzeni nazw ktore beda uzyte w programie

using std::string;
using std::endl;
using std::cout;
using std::cin;

//deklaracja zmiennych pomocniczych programu:

LZespolona Wynik;                       //dla wartosci wyrazenia arytmetycznego
Statystyki Zlicz = {0,0};               //dla zliczania statystyk
WyrazenieZesp WyrZ_PytanieTestowe;      //dla okreslenia wyrazenia ktore trzeba obliczyc
BazaTestu   BazaT = { nullptr, 0, 0 };  //dla inicjacji struktury aby nie byla pustym wskaznikiem

int main(int argc, char **argv)
{

//warunek sprawdzajacy czy wybrano wersje testu, za mala liczba argumentow skutkuje odpowiednim komunikatem

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

//warunek sprawdzjacy poprawnosc wpisanego argumentu z dopuszalnymi nazwami

  if (InicjalizujTest(&BazaT,argv[1]) == true) 
    {
      cout << endl;
      cout << " Start testu arytmetyki zespolonej. Wybrana opcja: Test " << argv[1] << endl << endl;
    }
  else 
    {
      cout<<"Test nie moze zostac rozpoczety..."<<endl;
      exit(0);
    }

//inicjacja petli ktora wczytuje kolejne wyrazenia dopoki jest taka mozliwosc
//po udzieleniu prawidlowej odpowiedzi (lub 3 bledynych) wyswietlone zostaje kolejne pytanie
//zmienna prowadzaca statystki w miedzyczasie zlicza wynik

while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) 
{
  cout << "Podaj wynik operacji: ";
  Wyswietl(WyrZ_PytanieTestowe);
  cout<<" = "<<endl;
  Wynik=Oblicz(WyrZ_PytanieTestowe);
  for (int i=0;i<3;)
    { 
      if(Wczytaj(Wynik)==true)
      {
        cout<<"Odpowiedz poprawna"<<endl<<endl;
        Zlicz.dobre++;
        break;
      }
      else        
      { 
        if (i<2)
      {
        cout<<"Sprobuj jeszcze raz."<<endl<<endl;
        i++;
      }
        else
        {
          cout<<" Prawidlowym wynikiem jest: ";
          Wyswietl(Wynik);
          cout<<endl<<endl;
          Zlicz.zle++;
          i++;
        }
      }
    }      
  }
  
  //uruchomienie funkcji zliczajacej ilosc poprawnych i niepoprawnych odpowiedzi

  Inicjuj(Zlicz);
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

return 0;
}
