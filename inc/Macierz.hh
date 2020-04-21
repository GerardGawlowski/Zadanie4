#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


/*
 * Klasa modeluje Macierz w postaci tablicy wektorów reprezentuj¹cych kolumny
 */
class Macierz {
public:
    Wektor getWektor(unsigned int index)
    {
        return kolumny[index];
    }

    void setWektor(unsigned int index, Wektor wektor) 
    {
        kolumny[index] = wektor; 
    }
  
private:
    Wektor kolumny[ROZMIAR];
};


/*
 Zapisuje Macierz za pomoc¹ operatora >>
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 Wyœwietla Macierz za pomoc¹ operatora <<
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);
Macierz Gauss(Macierz Mac);                                                 /*Zmienia macierz za pomoc¹ algorytmu gaussa do macierzy trójk¹tnej */
double Wyznacznik(Macierz Mac);                                             /*Oblicza wyznacznik macierzy trójk¹tnej*/
Macierz root(Macierz Mac);                                                  /*Podnosi macierz do kwadratu*/
Wektor operator * (Wektor wk1, Macierz Mac);                                /*Mno¿enie Macierzy przez wektor*/

#endif
