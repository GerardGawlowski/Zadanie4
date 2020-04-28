#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>



template <typename xD>
class Wektor {
 
  public:
      xD getSkladowa(unsigned int index) 
      {
          return skladowa[index];
      }
      void setSkladowa(unsigned int index, xD wartosc) 
      {
          skladowa[index] = wartosc;
      }
      
private:
    xD skladowa[ROZMIAR];
};

template <typename xD>
std::istream& operator >> (std::istream& Strm, Wektor<xD>& Wek)
{
    for (int i = 0; i < ROZMIAR; i++)
    {
        xD a;
        Strm >> a;
        Wek.setSkladowa(i, a);
    }

    return Strm;
}

template <typename xD>
std::ostream& operator << (std::ostream& Strm, const Wektor<xD>& Wek)
{
    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor<xD> kek;
        kek = Wek;
        xD a;
        a = kek.getSkladowa(i);
        Strm << a << ' ';
    }
    return Strm;
}

template <typename xD>
Wektor<xD> operator - (Wektor<xD> wk1, Wektor<xD> wk2)                   /*Ró¿nica wektorów*/
{
    Wektor<xD> Wynik;
    for (int i = 0; i < ROZMIAR; i++)
    {
        xD a, b, c;
        a = wk1.getSkladowa(i);
        b = wk2.getSkladowa(i);
        c = a - b;
        Wynik.setSkladowa(i, c);
    }
    return Wynik;
}      

template <typename xD>
Wektor<xD> operator + (Wektor<xD> wk1, Wektor<xD> wk2)
{
    Wektor<xD> Wynik;
    for (int i = 0; i < ROZMIAR; i++)
    {
        xD a, b, c;
        a = wk1.getSkladowa(i);
        b = wk2.getSkladowa(i);
        c = a + b;
        Wynik.setSkladowa(i, c);
    }
    return Wynik;
}                 /*Suma wektorów*/

template <typename xD>
xD operator * (Wektor<xD> wk1, Wektor<xD> wk2)
{
    xD wynik{};
    wynik = wynik * 0;
    for (int i = 0; i < ROZMIAR; i++)
    {
        xD a, b, c;
        a = wk1.getSkladowa(i);
        b = wk2.getSkladowa(i);
        c = a * b;
        wynik = c + wynik;
    }
    return wynik;
}                 /*iloczyn skalarny wektorów*/

template <typename xD, typename T>
Wektor<xD> operator * (Wektor<xD> wk1, T wk2)
{
    Wektor<xD> wynik;
    for (int i = 0; i < ROZMIAR; i++)
    {
        xD a;
        a = wk1.getSkladowa(i);
        wynik.setSkladowa(i, a * wk2);
    }
    return wynik;
}                /*Mno¿enie wektora przez liczbê*/

template <typename xD>
Wektor<xD> IloczynWR3(Wektor<xD> wk1, Wektor<xD> wk2)
{
    Wektor<xD> Wynik;
    xD a = (wk1.getSkladowa(1) * wk2.getSkladowa(2)) - (wk1.getSkladowa(2) * wk2.getSkladowa(1));
    xD b = (((wk1.getSkladowa(0) * wk2.getSkladowa(2)) - (wk1.getSkladowa(2) * wk2.getSkladowa(0))) * (-1));
    xD c = (wk1.getSkladowa(0) * wk2.getSkladowa(1)) - (wk1.getSkladowa(1) * wk2.getSkladowa(0));
    Wynik.setSkladowa(0, a);
    Wynik.setSkladowa(1, b);
    Wynik.setSkladowa(2, c);
    return Wynik;
}







#endif
