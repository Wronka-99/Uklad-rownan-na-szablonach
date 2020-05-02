#ifndef Macierz_HH
#define Macierz_HH

#include "Wektor.hh"
#include "rozmiar.hh"
#include <iostream>
#include <cmath>
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */

template<typename STyp, int SWymiar>

class MacierzKw
{
  private:
        
        SWektor<STyp,SWymiar> tablica[SWymiar];

  public:
        
        MacierzKw(); // konstruktor macierzy

        void transponuj(); //funkcja do transponowania macierzy
        void zamien_wiersze(int a, int b);
        STyp Wyznacznik();// metoda eliminacji gaussa

        MacierzKw<STyp, SWymiar>  operator* ( MacierzKw<STyp, SWymiar>  Macierz2); //funkcja do mnozenia macierzy przez macierz
        MacierzKw<STyp, SWymiar>  operator+ ( MacierzKw<STyp, SWymiar>   Macierz2); //funkcja do dodawania macierzy
        MacierzKw<STyp, SWymiar>  operator- ( MacierzKw<STyp, SWymiar>   Macierz2); //funkcja do odejmowania macierzy
        MacierzKw<STyp, SWymiar>  operator* (double liczba);              //funkcja do mnozenia macierzy przez liczbe
        SWektor<STyp,SWymiar> operator* (SWektor<STyp,SWymiar>  wektor);       //funkcja do mnozenia macierzy przez wektor

        SWektor<STyp, SWymiar> & operator [] (int indeks); //funkcja do wyciagania wektora
        SWektor<STyp,SWymiar>  operator [] (int indeks) const;   //funkcja do zmieniania wektora macierzy

       
};



 template<typename STyp, int SWymiar>
 MacierzKw<STyp,SWymiar>  operator*(double liczba,  MacierzKw<STyp,SWymiar> macierz2);// funkcja ta pozwala na mnozenie liczby przez macierz


template<typename STyp, int SWymiar>
MacierzKw<STyp,SWymiar>::MacierzKw()// konstruktor macierzy
{

    for(int a=0; a<SWymiar; a++)
    {
        for(int b=0; b<SWymiar; b++)
        {

            tablica[a][b]=0;
        }

    }


}

template<typename STyp, int SWymiar>
std::ostream &operator<<(std::ostream &Strm, const MacierzKw<STyp,SWymiar> &Mac)//przeciazenie operatora << w celu wyswietlania
        {
            for (int i = 0; i < SWymiar; i++)
            {
                Strm << Mac[i] << " " << std::endl;
            }

            return Strm;
        }



template<typename STyp, int SWymiar>
std::istream &operator>>(std::istream &Strm, MacierzKw<STyp,SWymiar> &Mac)//przeciazenie operatora >> w celu wczytywania
        {
            SWektor<STyp,SWymiar> elem;
            for (int i = 0; i < SWymiar; i++)
            {
                Strm >> elem;
                Mac[i] = elem;
            }
            
            return Strm;
        }


template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> & MacierzKw<STyp,SWymiar>::operator [] (int indeks)
        {
            if(indeks<0||indeks>SWymiar)
            {
            std::cerr<<"Indeks jest poza zakresem"<<std::endl;
            exit(1);
            }

            return tablica[indeks]; 
        }
template<typename STyp, int SWymiar>
void MacierzKw<STyp,SWymiar>::zamien_wiersze(int a, int b)
{
      MacierzKw<STyp, SWymiar> macierz_kopia;

      for(int i=0; i<SWymiar;i++)
      {
         macierz_kopia[i]=tablica[i];   
      }
      

      if(a>=0&&b>=0&&a<=(SWymiar-1)&&b<=(SWymiar-1))
      {
            tablica[a]=macierz_kopia[b];
            tablica[b]=macierz_kopia[a];
      }
      else
      {
            std::cout<<"Podales zle argumenty."<<std::endl<<std::endl;
      }
      

     

}

//SWektor<STyp,SWymiar>  operator [] (int indeks) const;
template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar>  MacierzKw<STyp,SWymiar>::operator [] (int indeks) const
        {
            if(indeks<0||indeks>SWymiar)
            {
            std::cerr<<"Indeks jest poza zakresem"<<std::endl;
            exit(1);
            }

            return tablica[indeks];
        }


template<typename STyp, int SWymiar>
 MacierzKw<STyp, SWymiar>  MacierzKw<STyp, SWymiar>::operator* (double liczba)//mnozenie macierzy przez liczbe 
{
    
    MacierzKw<STyp, SWymiar> macierz;

    for(int i=0; i <SWymiar; ++i)
    {
        for(int j=0; j< SWymiar;++j)
        {
            macierz[i][j]=tablica[i][j]*liczba+macierz[i][j];
            
        }
    }

    return macierz;
}

template<typename STyp, int SWymiar>
MacierzKw<STyp, SWymiar>  operator*(double liczba,  MacierzKw<STyp, SWymiar> macierz2)//mnozenie liczby przez macierz
{
     MacierzKw<STyp, SWymiar> macierz;    

    for(int i=0; i <SWymiar; ++i)
    {
        for(int j=0; j< SWymiar;++j)
        {
            macierz[i][j]=macierz2[i][j]*liczba+macierz[i][j];
            
        }
    }

    return macierz;

}



template<typename STyp, int SWymiar>
MacierzKw<STyp, SWymiar>  MacierzKw<STyp, SWymiar>::operator* ( MacierzKw<STyp, SWymiar>  Macierz2)//mnozenie macierzy przez macierz
{
     MacierzKw<STyp, SWymiar> macierz;    


      switch (SWymiar)
      {
      case 1:

            for(int i=0; i <SWymiar; ++i)
                  {
                        for(int j=0; j< SWymiar;++j)
                        {
                              macierz[i][j]=tablica[i][j]*Macierz2[i][j];
                              
                        }
                  }

       break;

       case 2:

            for(int i=0; i <SWymiar; ++i)
                  {
                        for(int j=0; j< SWymiar;++j)
                        {
                              macierz[i][j]=tablica[abs(i-1)][j]*Macierz2[i][abs(j-1)]+tablica[i][j]*Macierz2[i][j];
                              
                        }
                  }

       break;

       case 3:

            for(int i=0; i <SWymiar; ++i)
                  {
                        for(int j=0; j< SWymiar;++j)
                        {
                              macierz[i][j]=tablica[abs(i-2)][j]*Macierz2[i][abs(j-2)]+tablica[abs(i-1)][j]*Macierz2[i][abs(j-1)]+tablica[i][j]*Macierz2[i][j];
                              
                        }
                  }      
       break;

       case 4:

            for(int i=0; i <SWymiar; ++i)
                  {
                        for(int j=0; j< SWymiar;++j)
                        {
                              macierz[i][j]=tablica[abs(i-3)][j]*Macierz2[i][abs(j-3)]+tablica[abs(i-2)][j]*Macierz2[i][abs(j-2)]+tablica[abs(i-1)][j]*Macierz2[i][abs(j-1)]+tablica[i][j]*Macierz2[i][j];
                              
                        }
                  }      

       break;

       case 5:


            for(int i=0; i <SWymiar; ++i)
                              {
                                    for(int j=0; j< SWymiar;++j)
                                    {
                                          macierz[i][j]=tablica[abs(i-4)][j]*Macierz2[i][abs(j-4)]+tablica[abs(i-3)][j]*Macierz2[i][abs(j-3)]+tablica[abs(i-2)][j]*Macierz2[i][abs(j-2)]+tablica[abs(i-1)][j]*Macierz2[i][abs(j-1)]+tablica[i][j]*Macierz2[i][j];
                                          
                                    }
                              }
       break;
      
      
    

    

      }
      return macierz;
}




template<typename STyp, int SWymiar>
SWektor<STyp, SWymiar> MacierzKw<STyp, SWymiar>::operator*(SWektor<STyp, SWymiar> wektor)
{
    
    SWektor<STyp, SWymiar> wynik, pomoc;

    for(int i=0; i <SWymiar; ++i)
    {
        for(int j=0; j< SWymiar;++j)
        {   
            pomoc[i]=tablica[i][j]*wektor[j];
            wynik[i]=pomoc[i]+wynik[i];
            
        }
    }

    return wynik;
}

template<typename STyp, int SWymiar>
MacierzKw<STyp, SWymiar>  MacierzKw<STyp, SWymiar>::operator+ ( MacierzKw<STyp, SWymiar>  Macierz2)// dodawanie macierzy
 {
     MacierzKw<STyp, SWymiar> macierz;

     for(int i=0; i<SWymiar; i++)
     {

         macierz[i]=tablica[i]+Macierz2[i];

     }


    return macierz;


 }



 template<typename STyp, int SWymiar>
 MacierzKw<STyp, SWymiar>  MacierzKw<STyp, SWymiar>::operator- ( MacierzKw<STyp, SWymiar>  Macierz2)// odejmowane macierzy
 {
     MacierzKw<STyp, SWymiar> macierz;

     for(int i=0; i<SWymiar; i++)
     {

         macierz[i]=tablica[i]-Macierz2[i];

     }


    return macierz;


 }




template<typename STyp, int SWymiar>
void MacierzKw<STyp, SWymiar>::transponuj()//Transponowanie macierzy
 {
     STyp tablica_pom[SWymiar][SWymiar];

     for(int a=0; a<SWymiar; a++)
     {
         for(int b=0; b<SWymiar; b++)
         {
            
            tablica_pom[a][b]=tablica[b][a];   // przypisanie wartosci macierzy pomocniczej         
        }
     }

     for(int a=0; a<SWymiar; a++)
     {
         for(int b=0; b<SWymiar; b++)
         {
            
            tablica[a][b]=tablica_pom[a][b];     // transponowanie       
        }
     }
 }



template<typename STyp, int SWymiar>
STyp MacierzKw<STyp, SWymiar>::Wyznacznik()
{
  

  
    STyp Wynik;
    STyp elem;

    Wynik=1;
    elem=0;

    int x=-1;
    
    
    for(int i=0; i<SWymiar-1; ++i)//ta petla porusza sie po kolumnach
    {
        for(int j=i+1; j<SWymiar; ++j)//ta petla porusza sie po wierszach
        {
            elem=tablica[j][i]*x/tablica[i][i];//wartosc ktora bedziemy zerowac kolumne

                  for(int n=i;n<SWymiar; ++n)
                        {
                        tablica[j][n]=tablica[j][n]+(elem*tablica[i][n]);//zerowanie elementow kolumny
                        }    
        }
    }

    for(int q=0; q<SWymiar; ++q)
    {    
      Wynik=tablica[q][q]*Wynik;   
         //obliczanie wartosci wyznacznika
    }
    return Wynik;
    
}


#endif
