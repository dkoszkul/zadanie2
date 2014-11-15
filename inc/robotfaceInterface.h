#ifndef  ROBOTFACEINTERFACE_H
#define  ROBOTFACEINTERFACE_H
#include <string>
class RobotFaceInterface{

public:
RobotFaceInterface(){};
virtual ~RobotFaceInterface(){};

virtual void Oko_zbudujPolecenieDlaGnuplota(double polozenieDolnejPowieki,double polozenieGornejPowieki)=0; 
virtual bool Oko_zapisz(int idOka,int szybkoscZmian)=0;
virtual void Oko_simulateMovement(double polozenieDolnejPowieki,double polozenieGornejPowieki,
			int szybkoscZmiany,int idOka,std::string filename)=0;	


virtual bool Usta_zapisz(int szybkoscZmian)=0;
virtual void Usta_zbudujPolecenieDlaGnuplota(
		double polozenieDolnejWargi,
		double polozenieDolnejPowieki,
		double polozenieGornejPowieki)=0; 

};

#endif
