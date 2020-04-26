#include <iostream>
#include "Wektor.hh"
#include "LZespolona.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{



SWektor<LZespolona, 2> wynik,wynik2;



cin>>wynik;
cin>>wynik2;
cout << endl << " Wprowadz wierszowo uklad rownan, na koncu wpisujesz wektor wyrazow wolnych."<< endl << endl;
cout<<(wynik*wynik2);

 

 
  
}
