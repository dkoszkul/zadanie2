#ifndef  ROBOTFACE_H
#define  ROBOTFACE_H

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include "lacze_do_gnuplota.hh"
#include "Wektor2D.hh"

#include "robotfaceInterface.h"


#define NEUTRALNE_POLOZENIE_KACIKOW_UST 20
#define NEUTRALNE_POLOZENIE_KACIKOW_POWIEK 12
#define STR(x) #x

using namespace std;

class RobotFace : public RobotFaceInterface{

private:
	PzG::LaczeDoGNUPlota Lacze;

/////////////USTA/////////////////
std::vector<Wektor2D> GornaWarga;
std::vector<Wektor2D> DolnaWarga;

////////////OKO///////////////////
std::vector<Wektor2D> GornaPowieka;
std::vector<Wektor2D> DolnaPowieka;

public:
	PzG::LaczeDoGNUPlota getLacze();
	

/////////////USTA/////////////////
	bool Usta_zapisz(int szybkoscZmian);
	void Usta_zbudujPolecenieDlaGnuplota(
		double polozenieDolnejWargi,
		double polozenieDolnejPowieki,
		double polozenieGornejPowieki); 
	const char* Usta_getFilename();

////////////OKO///////////////////
	bool Oko_zapisz(int idOka,int szybkoscZmian);
	void Oko_zbudujPolecenieDlaGnuplota(double polozenieDolnejPowieki,double polozenieGornejPowieki); 
	const char* Oko_getFilename();
////////////BREW//////////////////
//	void zapiszBrew();
//	void Brew_zbudujPolecenieDlaGnuplota(); 

};

#endif
