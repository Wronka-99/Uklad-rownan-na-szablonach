



/*
double MacierzKw::Wyznacznik()
{
    double wynik=1;
    double elem=0;

    for(int i=0; i<ROZMIAR-1; ++i)//ta petla porusza sie po kolumnach
    {

        for(int j=i+1; j<ROZMIAR; ++j)//ta petla porusza sie po wierszach
        {

            elem=-tablica[j][i]/tablica[i][i];//wartosc ktora bedziemy zerowac kolumne


            for(int n=i;n<ROZMIAR; ++n)
            {

                tablica[j][n]+=(elem*tablica[i][n]);//zerowanie elementow kolumny

            }    
        }
    }

    for(int q=0; q<ROZMIAR; ++q)
    {
         wynik=(tablica[q][q]*wynik);//obliczanie wartosci wyznacznika
    }


    return wynik;
}












 

 */