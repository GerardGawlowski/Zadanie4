#include "../inc/Macierz.hh"
#include <iostream>


std::istream& operator >> (std::istream& Strm, Macierz& Mac)
{
    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor kek;
        Strm >> kek;
        Mac.setWektor(i, kek);
    }
    return Strm;
}

std::ostream& operator << (std::ostream& Strm, const Macierz& Mac)
{
    for (int i = 0; i < ROZMIAR; i++)
    {
        Macierz Cam;
        Cam = Mac;
        Strm << Cam.getWektor(i) << std::endl;
        
    }
    return Strm;
}
/* metoda eliminacji gaussa*/
int Minus;
Macierz Gauss(Macierz Mac)
{
    Wektor Wynik;                           /*wektor pomocniczny*/
    Macierz Kac = Mac;                      /* Macierz pomocnicza taka sama jak Kac*/
    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor temp = Kac.getWektor(i);     /*Pobranie wektora do zmiennej pomocniczej temp*/
        double a=temp.getSkladowa(i);       /*Pobranie odpowiedniej skladowej wektora do eliminacji*/
        
        if (a == 0)                         /* petla sprawdzajaca czy a jest zerem i zamieniajaca odpowiednio wiersze zeby moc kontynuowac obliczanie*/
        {
            
            for ( int y=i+1; a==0; y++)
            {
                if (y < ROZMIAR)
                {
                    Wynik = Kac.getWektor(y);
                    a = Wynik.getSkladowa(i);
                    if (a != 0)
                    {
                        Kac.setWektor(y, (temp * -1));
                        Kac.setWektor(i, Wynik);
                    }
                }
            }
           temp = Kac.getWektor(i);
           a = temp.getSkladowa(i);
        }
        for (int j=i+1;j < ROZMIAR;j++)     /*petla wykonujaca eliminacje gaussa*/
        {
            Wektor temp2 = Kac.getWektor(j);
            double b = temp2.getSkladowa(i);
            double c;
            if (a != 0) {
                c = b / a;
            }
            else
            {
                c = 0;
            }
            Wynik = temp * c;
            temp2 = temp2 - Wynik;
            Kac.setWektor(j, temp2);
        }
    }
    return Kac;
}
double Wyznacznik(Macierz Mac)  
{
    Macierz kek = Gauss(Mac);
    double wynik = 1;
    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor temp = kek.getWektor(i);
        wynik *= temp.getSkladowa(i);
    }
    if (Minus == 1)
    {
       wynik = wynik * (-1);
    }
    return wynik;
}

Macierz root(Macierz Mac)
{
    Macierz Wynik;
    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor temp = Mac.getWektor(i);
        for (int j = 0; j < ROZMIAR; j++)
        {
            double a = temp.getSkladowa(j);
            double b = a * a;
            temp.setSkladowa(j, b);
        }
        Wynik.setWektor(i, temp);
    }
    return Wynik;
}

Wektor operator * (Wektor wk1, Macierz Mac)
{
    Wektor Wynik;
    Wektor doMnozenia;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            Wektor petla=Mac.getWektor(j);
            doMnozenia.setSkladowa(j, petla.getSkladowa(i));
        }
        Wynik.setSkladowa(i, doMnozenia * wk1);
    }
    return Wynik;
}

