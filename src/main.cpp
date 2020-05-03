#include <iostream>
#include "Wektor.hh"
#include "LZespolona.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "rozmiar.hh"

using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{


char znak;

cin>>znak;

if(znak=='z')
{
     UkladRownanLiniowych<LZespolona, ROZMIAR>   UklRown;   // To tylko przykladowe definicje zmiennej
     SWektor<LZespolona, ROZMIAR> wynik;
     cin>>UklRown;//wprowadzanie ukladu rownan z klawiatury
     cout<<UklRown;//wyswietlanie ukladu rownan
     wynik=UklRown.rozwiaz();//rozwiazywanie ukladu rownan
     UklRown.wektorbledu(wynik);//oblicznie i wyswietlanie wektora bledu
}
else if(znak=='r')
{
    UkladRownanLiniowych<double, ROZMIAR>   UklRown;   // To tylko przykladowe definicje zmiennej
    SWektor<double, ROZMIAR> wynik;
    cin>>UklRown;//wprowadzanie ukladu rownan z klawiatury
    cout<<UklRown;//wyswietlanie ukladu rownan
    wynik=UklRown.rozwiaz();//rozwiazywanie ukladu rownan
    UklRown.wektorbledu(wynik);//oblicznie i wyswietlanie wektora bledu

}
else
{
    cout<<"Nie zdecydowales czy chcesz wykonywac obliczenia na liczbach zespolonych, badz rzeczywistych."<<endl;
    cout<<"r -rzeczywiste, z - zespolone"<<endl;
}


 
  
}
