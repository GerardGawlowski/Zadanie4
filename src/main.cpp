#include <iostream>
#include "../inc/wektor.hh"
#include "../inc/Macierz.hh"
#include "../inc/UkladRownanLiniowych.hh"



using namespace std;

int main()
{
    cout << endl << " Start programu " << endl << endl;
    
   UkladRownanLiniowych kek;                
        cin >> kek;
        cout << endl;
        cout << "Macierz A^T:" << endl;
        cout << kek.getMacierz() << endl;
        cout << "Wektor wyrazow wolnych b:" << endl;
        cout << kek.getWektor() << endl;
        cout << "Rozwiazanie x = (";
        for (int i = 0; i < ROZMIAR; i++)
        {
            cout << "x" << i << " ";
        }
        cout << "):" << endl;
        cout << rozwiazcramer(kek);
        Wektor blad = WektorBledu(kek);
        cout << "Wektor bledu:  " << blad << endl;
        cout << "Dlugosc wektora bledu:  " << blad * blad; /*bo blad rodzi blad :-----D */
}
