#include "../inc/UkladRownanLiniowych.hh"


std::istream& operator >> (std::istream& Strm, UkladRownanLiniowych& UklRown)
{
	Macierz tempm;
	Strm >> tempm;
	UklRown.setMacierz(tempm);
	Wektor temp;
	Strm >> temp;
	UklRown.setWektor(temp);
	return Strm;
}

std::ostream& operator << (std::ostream& Strm, const UkladRownanLiniowych& UklRown)
{
	UkladRownanLiniowych temp;
	temp = UklRown;
	Strm << temp.getMacierz() << temp.getWektor();
	return Strm;
}

Wektor rozwiazcramer(UkladRownanLiniowych Ukl) {
	UkladRownanLiniowych wyniki;
	Macierz Mac = Ukl.getMacierz();
	Wektor Wek = Ukl.getWektor();
	Wektor Wynik{};
	double wyznacznikglowny = Wyznacznik(Mac);
	double wyznacznikzmiennych;
	if (wyznacznikglowny == 0)
	{
		std::cout << "Wyznacznik glowny jest rowny 0, Uklad nie ma rozwi¹zañ";
		return Wynik;
	}
	for (int i = 0; i < ROZMIAR; i++)
	{
		Mac.setWektor(i, Wek);
		wyznacznikzmiennych = Wyznacznik(Mac);
		Wynik.setSkladowa(i, (wyznacznikzmiennych / wyznacznikglowny));
		Mac = Ukl.getMacierz();
	}
	return Wynik;
}

Wektor WektorBledu(UkladRownanLiniowych Ukl1)
{
	Macierz Mac = Ukl1.getMacierz();
	Wektor B = Ukl1.getWektor();
	Wektor bledu;
	Wektor WynikCramera = rozwiazcramer(Ukl1);
	bledu = WynikCramera * Mac;
	bledu = bledu - B;
	return bledu;
}