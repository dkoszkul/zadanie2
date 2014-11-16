#ifndef  ROBOTFACEINTERFACE_H
#define  ROBOTFACEINTERFACE_H
#include <string>
class RobotFaceInterface{

public:
RobotFaceInterface(){};
virtual ~RobotFaceInterface(){};

virtual void Oko_simulateMovement(double polozenieDolnejPowieki,double polozenieGornejPowieki,
			int szybkoscZmiany,int idOka,std::string filename)=0;	

virtual void Usta_simulateMovement(double polozenieDolnejWargi,double polozenieGornejWargi,
					double oddalenieKacikowUst,int szybkoscZmiany,std::string filename)=0;

virtual void Brew_simulateMovement(double polozenieBrwi,double polozenieKatNachylenia,int szybkoscZmiany,
					int idBrwi,std::string filename)=0;
};

#endif
