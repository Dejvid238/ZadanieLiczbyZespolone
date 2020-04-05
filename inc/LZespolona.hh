#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

//tworzenie struktury definiujacej pojecie liczby zespolonej

struct  LZespolona {
  double   re;    // Pole repezentuje czesc rzeczywista
  double   im;    // Pole repezentuje czesc urojona
};


//deklaracja funkcji operujacych na liczbach zespolonych przy wykorzystaniu przeciazen operatorow
//wiecej informacji o nich w pliku naglowkowym

LZespolona  operator + (LZespolona &,LZespolona &);
LZespolona operator - (LZespolona &,LZespolona &);
LZespolona operator * (LZespolona &,LZespolona &);
LZespolona operator / (LZespolona &,LZespolona &);
LZespolona sprzezenie (LZespolona &);
double modul (LZespolona &);

#endif
