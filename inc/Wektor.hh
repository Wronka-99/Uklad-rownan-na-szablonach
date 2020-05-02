#ifndef WEKTOR_HH
#define WEKTOR_HH
#include <cmath>
#include "rozmiar.hh"
#include <iostream>
#include "LZespolona.hh"
/*
 *  Klasa modeluje pojęcie wektora,
 *  którego rozmiar jest z góry
 *  zdefiniowany.
 */
template<typename STyp, int SWymiar>

class SWektor
{
private:
  STyp tablica[SWymiar]; //Zmienna przechowująca elementy wektora

public:

 SWektor(){for(int i=0; i<SWymiar; i++){ tablica[i]=0;}}
 
 const SWektor<STyp, SWymiar> operator+(const SWektor<STyp, SWymiar> Wektor2)const;              //Dodawnie wektorow
 const SWektor<STyp, SWymiar> operator-(const SWektor<STyp, SWymiar> Wektor2)const;              //Odejmowanie wektorow
 const SWektor<STyp, SWymiar> operator/(double liczba)const;                     //Iloraz wektora przez liczbe
 const SWektor<STyp, SWymiar> operator*(double liczba)const;                     //Iloczyn wektora przez liczbe
 STyp operator*(SWektor<STyp, SWymiar>Wektor2)const;                         //Iloczyn skalarny
 
const double dlugoscWektora()const;                                    //Oblicza dlugosc wektora
  
bool operator != (const SWektor<STyp, SWymiar> &W2)const;    //przeciazenie operatora != w celu porownywania wektorow
bool operator == (const SWektor<STyp, SWymiar> &W2)const;    //przeciazenie operatora == w celu porownywania wektorow                         
  
  
STyp & operator[] (int indeks);            //przypisywanie wartosci konkretnemu elementowi wektora
STyp  operator[](int indeks) const; //odczytywanie wartosci konkretnego elementu wektora


};







template<typename STyp, int SWymiar>
std::istream &operator>>(std::istream &Strm, SWektor<STyp, SWymiar> &Wek) //przeciazenie operatora << w celu wczytywania wektora
{
    STyp elem;
    for (int i = 0; i < SWymiar; i++)
    {
        Strm >> elem;
        Wek[i] = elem;
    }
    return Strm;
}




template<typename STyp, int SWymiar>
std::ostream &operator<<(std::ostream &Strm, const SWektor<STyp, SWymiar> &Wek) //przeciazenie operatora << w celu wyswietlania wektora
{
    for (int i = 0; i < SWymiar; i++)
    {
        Strm << Wek[i] << " ";
    }

    return Strm;
}
//SWektor<STyp, SWymiar> operator *(double liczba, SWektor<STyp, SWymiar> Wektor2);             //mnozenie liczby przez wektor

template<typename STyp, int SWymiar>
STyp& SWektor<STyp,SWymiar>::operator[] (int indeks)//funkcja przypisujaca  element wektorowi
  {
    if(indeks<0||indeks>SWymiar)
    {
      std::cerr<<"Indeks jest poza zakresem"<<std::endl;
      exit(1);
    }

    return tablica[indeks];
  }

template<typename STyp, int SWymiar>
STyp SWektor<STyp,SWymiar>::operator[](int indeks) const//funkcja zwracajaca element wektora
 {
    if(indeks<0||indeks>SWymiar)
    {
      std::cerr<<"Indeks jest poza zakresem"<<std::endl;
      exit(1);
    }

    return tablica[indeks];
  }


  template<typename STyp, int SWymiar>
bool SWektor<STyp,SWymiar>::operator == ( const SWektor<STyp,SWymiar>  &Wektor2)const//przeciazenie operatora == w celu porownywania wektorow
{

    bool prawda=1;

    for(int indeks=0; indeks<SWymiar; indeks++)
        {
           if( Wektor2[indeks]!=tablica[indeks])
           {
                prawda=0;
           }
        }
    return prawda;
}

template<typename STyp, int SWymiar>
bool SWektor<STyp,SWymiar>::operator != ( const SWektor<STyp,SWymiar>  &Wektor2)const//przeciazenie operatora != w celu porownywania wektorow
{

    bool falsz=0;

    for(int indeks=0; indeks<SWymiar; indeks++)
        {
           if( Wektor2[indeks]!=tablica[indeks])
           {
                falsz=1;
           }
        }
    return falsz;
}

template<typename STyp, int SWymiar>
const SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator+(const SWektor<STyp,SWymiar> Wektor2)const//funkcja dodajaca wektor do wektora
{   
    SWektor<STyp,SWymiar> wektor3;
    for (int indeks = 0; indeks < SWymiar; indeks++)
    {
        wektor3[indeks] = tablica[indeks]+Wektor2[indeks];
    }
    return wektor3;
}



template<typename STyp, int SWymiar>
const  SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator-(const SWektor<STyp,SWymiar> Wektor2)const//funkcja odejmujaca wektor od wektor
{
   SWektor<STyp,SWymiar> wektor3;
    for (int indeks = 0; indeks < SWymiar; indeks++)
    {
        wektor3[indeks] = tablica[indeks]-Wektor2[indeks];
    }
    return wektor3;
}

template<typename STyp, int SWymiar>
STyp SWektor<STyp,SWymiar>::operator*(SWektor<STyp,SWymiar> Wektor2)const//funkcja mnozaca wektor przez wektor
{
    
    STyp Wynik;
    STyp IloczynS;
    IloczynS=0;
    Wynik=0;

    for (int i = 0; i < SWymiar; i++)
    {
        IloczynS = Wektor2[i] * tablica[i];
        Wynik = IloczynS+Wynik;
    }
    return Wynik;
}




template<typename STyp, int SWymiar>
const SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator*(double liczba)const//funkcja mnozaca wektor przez liczbe
{
     SWektor<STyp,SWymiar>Wektor2;
    for (int i = 0; i < SWymiar; i++)
    {
        Wektor2[i] = tablica[i] * liczba;
    }
    return Wektor2;
}



template<typename STyp, int SWymiar>
const SWektor<STyp,SWymiar> operator *(double liczba, SWektor<STyp,SWymiar> Wektor2)//funkcja mnozaca liczbe przez wektor
{
    SWektor<STyp,SWymiar> wektor3;
    for (int i = 0; i < SWymiar; i++)
    {
        wektor3[i] = Wektor2[i] * liczba;
    }
        return wektor3;

}



template<typename STyp, int SWymiar>
const SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator/(double liczba)const//funkcja dzielaca wektor przez liczbe
{
     SWektor<STyp,SWymiar> Wektor2;

    for (int i = 0; i < SWymiar; i++)
    {
        Wektor2[i] = tablica[i] / liczba;
    }
    return Wektor2;
}




template<typename STyp, int SWymiar>
const double SWektor<STyp, SWymiar>::dlugoscWektora()const//funkcja liczaca dlugosc wektora
{
    double Wynik = 0;
    for (int i = 0; i < SWymiar; i++)
    {
        Wynik += pow(tablica[i], 2);
    }
    return sqrt(Wynik);

}
/*
template<>
const double SWektor<LZespolona,ROZMIAR>::dlugoscWektora()const//funkcja liczaca dlugosc wektora
{
    LZespolona Wynik;
    LZespolona elem;
    double dlugosc=0;

    for (int i = 0; i < ROZMIAR; i++)
    {   elem=tablica[i]*sprzezenie(tablica[i]);
        Wynik = Wynik+elem;
    }

    dlugosc=modul(Wynik);
    return sqrt(dlugosc);
}


*/

#endif