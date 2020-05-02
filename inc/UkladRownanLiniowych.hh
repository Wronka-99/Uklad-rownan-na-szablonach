#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH
#include "Macierz.hh"
#include <iostream>
#include "Macierz.hh"
#include <cmath>
#include "rozmiar.hh"
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template<typename STyp, int SWymiar>
class UkladRownanLiniowych {
  
      SWektor<STyp, SWymiar> wektor; //pola prywatne
      MacierzKw<STyp, SWymiar> macierz;

  public:
  
        SWektor<STyp, SWymiar> rozwiaz(); //funkcja rozwiazujaca uklad rownan oraz wyswietlajaca wektor z rozwiazaniem
        SWektor<STyp, SWymiar> wektorbledu(SWektor<STyp, SWymiar> rozwiazanie); // funkcja liczaca oraz wyswietlajaca wektor bledu oraz jego dlugosc

        STyp pobierz_elem(int i) const;// odczytywanie dowolnego elementu z wektora wyrazow wolnych
        void wstaw_elem(STyp elem, int i);// przypisanie wartosci do dowolnego elementu z wektora wyrazow wolnych
        
        SWektor<STyp, SWymiar> operator[](int i) const;//odczytanie dowolnego wektora wspolczynnikow ukladu rownan
        SWektor<STyp, SWymiar> &operator[](int i);    //zmiana dowolnego wektora wspolczynnikow ukladu rownan
        STyp operator()(int i, int j)const;// odczytywanie dowolnego elementu z macierzy wspolczynnikow 
        STyp &operator()(int i, int j);     //zmiana dowolnego elementu z macierzy wspolczynnikow
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */

template<typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<STyp,SWymiar> &UklRown) //wczytywanie ukladu rownan
{
    SWektor<STyp,SWymiar> wektor;
    STyp elem;
    elem=(0);

    for(int i=0; i<SWymiar; ++i)
    {
        Strm>>wektor;
        UklRown[i]=wektor;
    }        


    for(int i=0; i<SWymiar; ++i)
    {
        Strm>>elem;
        UklRown.wstaw_elem(elem,i);

    }

    return Strm;
}


template<typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<STyp,SWymiar> &UklRown)//wyswietlanie ukladu rownan
{


        Strm<<"Uklad rownan: "<<std::endl<<std::endl;

                    for(int i=0; i<SWymiar; i++)
                    {
                        Strm<<"\t";

                        Strm<<"| "<< UklRown[i]<< "| |x_"<< i+1 <<"|  ";

                                if(i==1)
                                {

                                        Strm<<"    |";
                                }
                                else
                                {
                                    
                                        Strm<<"    |";
                                }


                        Strm<< UklRown.pobierz_elem(i)<<" |"<<std::endl<<std::endl;
                    }


                return Strm;

}


template<typename STyp, int SWymiar>
STyp UkladRownanLiniowych<STyp,SWymiar>::pobierz_elem(int i) const//wczytywanie elementu z wektora wyrazow wolnych
{
    return wektor[i];
}  


template<typename STyp, int SWymiar>
void UkladRownanLiniowych<STyp,SWymiar>::wstaw_elem(STyp elem, int i)//przypisywanie wartosci elementowiz wektora wyrazow wolnych

{
      wektor[i]=elem;
}



template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> UkladRownanLiniowych<STyp,SWymiar>::operator[](int i) const// wczytywanie wektora z macierzy wspolczynnikow
{
    return macierz[i];
}



template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> &UkladRownanLiniowych<STyp,SWymiar>::operator[](int i)// wyswietlanie wektora z macierzy wspolczynnikow
{
    return macierz[i];
}



template<typename STyp, int SWymiar>
STyp UkladRownanLiniowych<STyp,SWymiar>::operator()(int i, int j)const//odczytywanie konkretnego elementu z macierzy wspolczynnikow
{
    return macierz[i][j];
}



template<typename STyp, int SWymiar>
STyp &UkladRownanLiniowych<STyp,SWymiar>::operator()(int i, int j)//przypisywanie wartosci konkretnemu elementowi z macierzy wspolczynnikow
{
    return macierz[i][j];
}



template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> UkladRownanLiniowych<STyp,SWymiar>::rozwiaz()// rozwiazywanie ukladu rownan
{
    SWektor<STyp,SWymiar> rozwiazanie;
    SWektor<STyp,SWymiar> wektor_pomocniczy;// zmienne pomocnicze
    STyp wyznacznik_glowny;
    STyp wyznacznik_pomocniczy;

    wyznacznik_glowny=(0);
    wyznacznik_pomocniczy=(0);

    MacierzKw<STyp,SWymiar> macierz_pomocnicza;

    macierz_pomocnicza=macierz;//przypisanie wartosci zmiennym pomocniczym
    wyznacznik_glowny=macierz_pomocnicza.Wyznacznik();//liczenie wyznacznika glownego

    

        for(int i=0; i<SWymiar; i++)
        {   
            macierz_pomocnicza=macierz;//przypisanie wartosci zmiennym pomocniczym
            macierz_pomocnicza[i]=wektor;// wstawianie wektora wyrazow wolnych do macierzy z ktorej liczymy wyznacznik konkretnej zmiennej
            wyznacznik_pomocniczy=macierz_pomocnicza.Wyznacznik();//oblicznie wyznacznika pomocniczego
            rozwiazanie[i]=wyznacznik_pomocniczy/wyznacznik_glowny;//wstawianie rozwiazania do wektora rozwiazan

        

        }
        //wyswietlanie wektora z rozwiazaniami
        //std::cout<< "Rozwiazanie x= (\tx1,\t x2,\t x3)"<<std::endl<<std::endl;
        //std::cout<<"\t\t"<<rozwiazanie[0]<<"\t"<<rozwiazanie[1]<<"\t  "<<rozwiazanie[2]<<std::endl<<std::endl;
        std::cout<< "Rozwiazanie:"<<std::endl;
        std::cout<<"(";

        for(int a=0; a<SWymiar; a++)
        {
            std::cout<<"x_"<<a+1<<", ";
        }
        std::cout<<")";

        std::cout<<std::endl<<"(";

        for(int a=0; a<SWymiar; a++)
        {
            std::cout<<rozwiazanie[a]<<", ";
        }

        std::cout<<")"<<std::endl;

        return rozwiazanie;// zwracanie wektora rozwiazan 



}
        
template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> UkladRownanLiniowych<STyp,SWymiar>::wektorbledu(SWektor<STyp,SWymiar> rozwiazanie)
{

        SWektor<STyp,SWymiar> wektor_bledu,wektor_pomocniczy,wektor_wa;
        MacierzKw<STyp,SWymiar> macierz_pomocnicza;
        double dlugosc_wktora_bledu=0; // zmienne pomocnicze

        macierz_pomocnicza=macierz;
        wektor_pomocniczy=wektor;// przypisanie wartosci zmiennym pomocniczym

        macierz_pomocnicza.transponuj();//transponowanie macierzy wspolczynnikow
        wektor_wa=macierz_pomocnicza*rozwiazanie;//oblicznie wartosci A*x

        wektor_bledu=wektor_wa-wektor_pomocniczy;//oblicznie wektora bledu A*x-b

        
       // dlugosc_wktora_bledu=wektor_bledu.dlugoscWektora();//liczenie dlugosci wektora bledu


        //wyswietlanie wektora bledu oraz jego dlugosci
        //std::cout<< "Wektor bledu Ax-b =("<<wektor_bledu[0]<<","<<wektor_bledu[1]<<","<<wektor_bledu[2]<<")"<<std::endl<<std::endl;
        //std::cout<< "Dlugosc wektora bledu ||Ax-b|| = ("<<dlugosc_wktora_bledu<<")"<<std::endl<<std::endl;
        std::cout<<std::endl;


         std::cout<< "Wektor bledu Ax-b =(";

        

        for(int a=0; a<SWymiar; a++)
        {
            std::cout<<wektor_bledu[a]<<", ";
        }

        std::cout<<")"<<std::endl;

    return wektor_bledu;//zwracanie wektora bledu



}

#endif
