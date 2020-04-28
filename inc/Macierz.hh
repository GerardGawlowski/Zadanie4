#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


/*
 * Klasa modeluje Macierz w postaci tablicy wektorów reprezentuj¹cych kolumny
 */
template<typename xD>
class Macierz {
public:
    Wektor<xD> getWektor(unsigned int index)
    {
        return kolumny[index];
    }

    void setWektor(unsigned int index, Wektor<xD> wektor) 
    {
        kolumny[index] = wektor; 
    }
  
private:
    Wektor<xD> kolumny[ROZMIAR];
};


/*
 Zapisuje Macierz za pomoc¹ operatora >>
 */
template<typename xD>
std::istream& operator >> (std::istream& Strm, Macierz<xD>& Mac)
{
    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor<xD> kek;
        Strm >> kek;
        Mac.setWektor(i, kek);
    }
    return Strm;
}

/*
 Wyœwietla Macierz za pomoc¹ operatora <<
 */
template<typename xD>
std::ostream& operator << (std::ostream& Strm, const Macierz<xD>& Mac)
{
    for (int i = 0; i < ROZMIAR; i++)
    {
        Macierz<xD> Cam;
        Cam = Mac;
        Strm << Cam.getWektor(i) << std::endl;

    }
    return Strm;
}

template<typename xD>
Macierz<xD> Gauss(Macierz<xD> Mac)                              /*Zmienia macierz za pomoc¹ algorytmu gaussa do macierzy trójk¹tnej */
{
    Wektor<xD> Wynik;                           /*wektor pomocniczny*/
    Macierz<xD> Kac = Mac;                      /* Macierz pomocnicza taka sama jak Kac*/
    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor<xD> temp = Kac.getWektor(i);     /*Pobranie wektora do zmiennej pomocniczej temp*/
        xD a = temp.getSkladowa(i);       /*Pobranie odpowiedniej skladowej wektora do eliminacji*/

        if (a == 0)                         /* petla sprawdzajaca czy a jest zerem i zamieniajaca odpowiednio wiersze zeby moc kontynuowac obliczanie*/
        {

            for (int y = i + 1; a == 0; y++)
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
        for (int j = i + 1; j < ROZMIAR; j++)     /*petla wykonujaca eliminacje gaussa*/
        {
            Wektor<xD> temp2 = Kac.getWektor(j);
            xD b = temp2.getSkladowa(i);
            xD c;
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

template <typename xD>
xD Wyznacznik(Macierz<xD> Mac)                                              /*Oblicza wyznacznik macierzy trójk¹tnej*/
{
    Macierz<xD> kek = Gauss(Mac);
    xD elem;
    xD wynik;
    wynik = 1;
    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor<xD> temp = kek.getWektor(i);
        wynik = wynik * temp.getSkladowa(i);
    }
    return wynik;
}
                                                                            
template <typename xD>
Macierz<xD> root(Macierz<xD> Mac)                               /*Podnosi macierz do kwadratu*/
{
    Macierz<xD> Wynik;
    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor<xD> temp = Mac.getWektor(i);
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

template <typename xD>
Wektor<xD> operator * (Macierz<xD> Mac,Wektor<xD> wk1)                  /*Mno¿enie Macierzy przez wektor*/
{
    Wektor<xD> Wynik;
    Wektor<xD> doMnozenia;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            Wektor<xD> petla = Mac.getWektor(j);
            doMnozenia.setSkladowa(j, petla.getSkladowa(i));
        }
        Wynik.setSkladowa(i, doMnozenia * wk1);
    }
    return Wynik;
}   
template <typename xD>
Macierz<xD> operator - (Macierz<xD> Mac1, Macierz<xD> Mac2)
{
    Macierz<xD> Wynik;
    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor<xD> Obrobka = Mac1.getWektor(i) - Mac2.getWektor(i);
        Wynik.setWektor(i, Obrobka);
    }
    return Wynik;
}

template <typename xD>
Macierz<xD> operator * (Macierz<xD> Mac1, Macierz<xD> Mac2)
{
    Macierz<xD> Wynik;
    Wektor<xD> doMnozenia;
    Wektor<xD> malywynik;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            Wektor<xD> petla = Mac1.getWektor(j);
            doMnozenia.setSkladowa(j, petla.getSkladowa(i));
            for (int x = 0; x < ROZMIAR; x++)
            {
                malywynik.setSkladowa(x, doMnozenia * Mac2.getWektor(x));
            }
        }
        Wynik.setWektor(i, malywynik);
    }
    return Wynik;
}
#endif
