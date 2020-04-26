#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  LZespolona &operator = (double Liczba);
  LZespolona operator += (const LZespolona & Skl1)const;
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

LZespolona sprzezenie (LZespolona Skl1);  

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  double liczba);
LZespolona  operator * (double liczba,  LZespolona  Skl1);

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
 


void Wyswietl(LZespolona Skl1);

std::istream &operator>>(std::istream &StrmWe, LZespolona &Lz); //funkcja pobierajaca liczbe zespolona
std::ostream &operator<<(std::ostream &StrmWy, LZespolona Lz); //funkcja zwracajaca liczbe zespolona

#endif
