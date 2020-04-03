#include <iostream>
#include "BazaTestu.hh"

//deklaracja przestrzeni ktore beda uzyte w programie

using std::cout;
using std::cin;
using std::string;
using std::ostream;
using std::endl;

int main(int argc, char **argv)
{
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

BazaTestu *BazaT = new BazaTestu;

InicjalizujTest(BazaT,argv[1]);
  if (InicjalizujTest(BazaT,argv[1] == true) 
    {
      cout << endl;
      cout << " Start testu arytmetyki zespolonej. Wybrana opcja: Test " << argv[1] << endl << endl;
    }
  else 
    {
      cerr<<"Test nie moze zostac rozpoczety..."<<endl;
      exit(0);
    }






WyrazenieZesp   WyrZ_PytanieTestowe;

while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) 
{
  cout << "Podaj wynik operacji: ";
  cout << WyrZ_PytanieTestowe.Arg1.re << endl;
}

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
