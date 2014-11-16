#include "robotface.h"

/////////////////USTA//////////////////////

void RobotFace::Usta_zbudujPolecenieDlaGnuplota(double polozenieDolnejWargi,double polozenieGornejWargi,double oddalenieKacikowUst){

	if(!GornaWarga.empty()){
		_PpolozenieDolnejWargi=DolnaWarga[1].y;
		_PpolozenieGornejWargi=GornaWarga[1].y;
		_PoddalenieKacikowUst=GornaWarga[2].x - NEUTRALNE_POLOZENIE_KACIKOW_UST;
	}

	GornaWarga = { {-NEUTRALNE_POLOZENIE_KACIKOW_UST-oddalenieKacikowUst,0}
		, {	0,polozenieGornejWargi}, {NEUTRALNE_POLOZENIE_KACIKOW_UST+oddalenieKacikowUst,0}};

	DolnaWarga = { {NEUTRALNE_POLOZENIE_KACIKOW_UST+oddalenieKacikowUst,0}
		, {	0,polozenieDolnejWargi}, {-NEUTRALNE_POLOZENIE_KACIKOW_UST-oddalenieKacikowUst,0}};

}

bool RobotFace::Usta_zapisz(int szybkoscZmian){

	double translacja_Y = -30;
	std::ofstream StrmWy("dat/Usta.dat");

	if (!StrmWy.is_open())
		return false;

	Wektor2D GW;
	for (auto Iter = GornaWarga.begin(); Iter != GornaWarga.end(); ++Iter) {
		GW = *Iter;
		GW.y += translacja_Y;
		StrmWy << GW << std::endl;
	}
	Wektor2D DW;
	for (auto Iter = DolnaWarga.begin(); Iter != DolnaWarga.end(); ++Iter) {
		DW = *Iter;
		DW.y += translacja_Y;
		StrmWy << DW << std::endl;
	}
	return !StrmWy.fail();

}

void RobotFace::Usta_simulateMovement(double polozenieDolnejWargi,double polozenieGornejWargi,
					double oddalenieKacikowUst,int szybkoscZmiany,std::string filename){

double roznicaGornejWargi = 0;
double roznicaDolnejWargi = 0;
double roznicaOddaleniaKacikowUst = 0;
int iloscRuchow = 0;
double aktualnePolozenieGornejWargi = 0;
double aktualnePolozenieDolnejWargi = 0;
double aktualneOddalenieKacikowUst = 0;

Usta_zbudujPolecenieDlaGnuplota(aktualnePolozenieDolnejWargi,aktualnePolozenieGornejWargi,aktualneOddalenieKacikowUst); 
/*!
 * mikroruch dla gornej wargi
 */

roznicaGornejWargi = (polozenieGornejWargi - this->_PpolozenieGornejWargi) /  (10*(szybkoscZmiany/100)+1);

/*!
 * mikroruch dla dolnej wargi
 */
roznicaDolnejWargi = (polozenieDolnejWargi - this->_PpolozenieDolnejWargi) /  (10*(szybkoscZmiany/100)+1);
	
/*!
 * mikroruch dla odchylenia ust
 */
roznicaOddaleniaKacikowUst = (oddalenieKacikowUst - this->_PoddalenieKacikowUst) /  (10*(szybkoscZmiany/100)+1);

iloscRuchow = 10*(szybkoscZmiany/100)+1;//abs((int)(polozenieGornejWargi - this->_PpolozenieGornejWargi)) /abs(roznicaGornejWargi);
aktualnePolozenieGornejWargi = this->_PpolozenieGornejWargi;
aktualnePolozenieDolnejWargi = this->_PpolozenieDolnejWargi;
aktualneOddalenieKacikowUst = this->_PoddalenieKacikowUst;

for(int i=0;i<iloscRuchow;i++){
	aktualnePolozenieGornejWargi+=roznicaGornejWargi;
	aktualnePolozenieDolnejWargi+=roznicaDolnejWargi;
	aktualneOddalenieKacikowUst+=roznicaOddaleniaKacikowUst;
	Usta_zbudujPolecenieDlaGnuplota(aktualnePolozenieDolnejWargi,aktualnePolozenieGornejWargi,aktualneOddalenieKacikowUst); 

	Usta_zapisz(0);
	getLacze().DodajNazwePliku(filename.c_str(), PzG::RR_Ciagly, 6);
	getLacze().Rysuj();
	 usleep(50 * 1000);
}
}
