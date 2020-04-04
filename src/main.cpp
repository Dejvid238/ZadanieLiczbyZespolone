#include "BazaTestu.hh"

#include <iostream>
#include <cassert>

//deklaracja przestrzeni ktore beda uzyte w programie
using std::string;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char **argv)
{
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

BazaTestu   BazaT = { nullptr, 0, 0 };

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



WyrazenieZesp   WyrZ_PytanieTestowe;


while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) 
{
  cout << "Podaj wynik operacji: ";
  Wyswietl(WyrZ_PytanieTestowe);
  cout<<endl;
}


  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
