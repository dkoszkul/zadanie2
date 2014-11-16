#ifndef SCENE_HH
#define SCENE_HH


/*!
 * \file
 * 
 * \brief Zawiera ...
 *
 *  ...
 */

/*!
 * \brief Scena robocza, na której działa robot
 *
 *  Klasa ...
 */
#include <map>
#include <string>
#include <iostream>
#include <sstream> 
#include "command.h"
#include "libinterface.hh"
#include "set4libinterfaces.hh"
#include "Wektor2D.hh"
using namespace std;



class Scene {

private:
/*!
 * Mapa polecen, gdzie kluczem jest numer w kolejnosci polecenia a wartoscia jest sama komenda
 */	int numerPolecenia;


	

public:
	map<int,Command*> _mapaPolecen;
	map<string,Command*> aktualnaMapa; //mapa aktualnego polozenia <nazwaPliku, komenda>
	std::string Strm_CmdsList;
	Set4LibInterfaces *_LibsSet;

	Scene(){numerPolecenia = 0;};
	bool AddLibSet(Set4LibInterfaces &LibsSet){_LibsSet=&LibsSet; return true;};
	Command* findCommand(const char* name);

	bool AddCommand(int key, Command *command);
	void refreshActualMap(string nazwaPliku,Command * komenda);
	int getNumerPolecenia(){ return numerPolecenia;};
	void setNumerPolecenia(int n){numerPolecenia=n;};
	map<int,Command*> get_mapaPolecen() {return _mapaPolecen;};

	void resetStrm_CmdsList(){Strm_CmdsList="";};
	void addParameterToString(string parameterName){Strm_CmdsList+=parameterName;Strm_CmdsList+=" ";};
	void showStringParameters(){std::cout<< Strm_CmdsList<<std::endl;};
	void clearMapaPolecen(){
		_mapaPolecen.clear();
	}

};


#endif
