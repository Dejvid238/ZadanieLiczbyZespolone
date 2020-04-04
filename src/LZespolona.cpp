#include "LZespolona.hh"

#include <cmath>
using std::sqrt;

//opisane ponizej funkcje jako argumenty przyjmuja liczby typu LZespolona oraz zwracaja tenze typ (z wyjatkiem modulu)

//funkcja dodajaca do siebie 2 liczby zespolone, jako wynik zwraca sume

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

//funkcja odejmujaca 2 liczby zespolone od siebie, jako wynik zwraca roznice

LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
    LZespolona Wynik;
    Wynik.re = Skl1.re - Skl2.re;
    Wynik.im = Skl1.im - Skl2.im;
    return Wynik;
}

//funkcja ktora mnozy 2 liczby zespolone przez siebie, jako wynik zwraca iloczyn 

LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
    LZespolona Wynik;
    Wynik.re=(Skl1.re*Skl2.re)-(Skl1.im*Skl2.im);
    Wynik.im=(Skl1.re*Skl2.im)+(Skl1.im*Skl2.re);
    return Wynik;
}

//funkcja wykonujaca dzielenie 2 liczb zespolonych, jako wynik zwraca iloraz 

LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
    LZespolona Wynik;

    if ((Skl2.re!=0) || (Skl2.im!=0))
        {
            Wynik.re=((Skl1.re*Skl2.re)-(Skl1.im*Skl2.im))/modul(Skl2);
            Wynik.im=((Skl1.re*Skl2.im)+(Skl1.im*Skl2.re))/modul(Skl2);
            return Wynik;
        }
    else
        {

        }
}

//funkcja zwracajaca sprzezenie liczby zespolonej podanej jako argument

LZespolona sprzezenie (LZespolona Skl1)
{

        LZespolona Wynik;
        Wynik.re=Skl1.re;
        Wynik.im=-Skl1.im;
     return Wynik;
}

//funkcja wyliczajaca modul z liczby zespolonej podanej jako argument

double modul(LZespolona Skl1)
{
    LZespolona Wynik;
    Wynik.re=sqrt((Skl1.re*Skl1.re)+(Skl1.im*Skl1.im));
    Wynik.im=0;
    return Wynik.re;
}