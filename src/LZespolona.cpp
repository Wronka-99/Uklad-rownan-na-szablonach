#include "LZespolona.hh"
#include <iostream>

using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona &LZespolona::operator=(double Liczba)
{
    this->re= Liczba;
    this->im=0;
    return *this;

}
LZespolona LZespolona::operator += (const LZespolona & Skl1)const
{

    LZespolona Skl2;
    Skl2.re=Skl1.re+Skl1.re;
    Skl2.im=Skl1.im+Skl1.im;

    return Skl2;

}




LZespolona sprzezenie (LZespolona Skl1){

    LZespolona wynik;

    wynik.re=Skl1.re;
    wynik.im=-Skl1.im;

    return wynik;
}


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}



LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}



LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2.re-Skl1.im*Skl2.im;
  Wynik.im = Skl1.im*Skl2.re + Skl1.re*Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  double liczba)
{
    LZespolona  Wynik;
    Wynik.re=Skl1.re*liczba;
    Wynik.im=Skl1.im*liczba;
    return Wynik;
}




LZespolona  operator * (double liczba,  LZespolona  Skl1)
{
    LZespolona  Wynik;
    Wynik.re=Skl1.re*liczba;
    Wynik.im=Skl1.im*liczba;
    return Wynik;

}




LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  double modul;

  modul= Skl2.re*Skl2.re+Skl2.im*Skl2.im;

  if(modul>0)//zabezpieczenie przed dzieleniem przez 0
    {
      
    Wynik.re = (Skl1.re*Skl2.re+Skl1.im*Skl2.im)/modul;
    Wynik.im = (Skl2.re*Skl1.im-Skl1.re*Skl2.im)/modul;
    
    
    
    }

    else
    {
      std::cout<<"Modul drugiej liczby jest ujemny, badz rowny zero."<< std::endl;
    }// stosowny komunikat mowiacy o braku mozliwosci wykonania dzielenia
    
  return Wynik;
}


LZespolona  operator / (LZespolona  Skl1,  double liczba)
{
    LZespolona  Wynik;
    Wynik.re=Skl1.re/liczba;
    Wynik.im=Skl1.im/liczba;
    return Wynik;

}






void Wyswietl(LZespolona Skl1)
{
  cout << "(" << Skl1.re << showpos << Skl1.im << "i" << noshowpos << ")";
}

ostream &operator<<(ostream &StrmWy, LZespolona Lz)
{
  return StrmWy << "(" << Lz.re << showpos << Lz.im << "i)" << noshowpos;
}

istream &operator>>(istream &StrmWe, LZespolona &Lz)

{
  char znak; //Zmienna sluzaca do sprawdzania znakow

  StrmWe >> znak; //Wczytanie znaku z klawiatury i przypisanie do zmiennej znak

  if (znak != '(') //Sprawdzenie, czy na poczatku wyrazenia znajduje sie nawias
  {
    StrmWe.setstate(ios::failbit); //Komunikat o braku oczekiwanego znaku
    return StrmWe;
  }
  else
  {
    StrmWe >> Lz.re; //Wczytanie czesci rzeczywistej

    StrmWe >> znak;

    if ((znak != '+') && (znak != '-')) //Sprawdzenie, czy jest obecny znak plus lub minus
    {
      StrmWe.setstate(ios::failbit); //Komunikat o braku oczekiwanego znaku
      return StrmWe;
    }
    else
    {
      StrmWe >> Lz.im; //Wczytanie czesci urojonej
      if (znak == '-')
      {
        Lz.im = -(Lz.im); //Z racji tego ze wiemy jaki jest znak musimy zmienic znak
                          //czesci urojonej bo znamy tylko jej wartosc bez znaku
      }
      StrmWe >> znak;
      if (znak != 'i') //Sprawdzenie czy jest litera i 
      {
        StrmWe.setstate(ios::failbit);
        return StrmWe;
      }
      else
      {
        StrmWe >> znak;
        if (znak != ')') //Sprawdzenie czy jest nawias zamykajacy wyrazenie
        {
          StrmWe.setstate(ios::failbit);
          return StrmWe;
        }
      }
    }
  }

  return StrmWe; // Jesli wszystko bylo poprawnie funkcja zwraca liczbe zespolona
}


