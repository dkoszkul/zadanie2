#include "scene.hh"

/*!
 * Jeżeli metoda zwróci true - element dodany , jeżeli false - element o podanym kluczu już istnieje
 */
bool Scene::AddCommand(int key, Command *command){
	return (_mapaPolecen.emplace(key,command)).second;
}

Command* Scene::findCommand(const char* name){
const LibInterface *pInterf  = _LibsSet->FindLib4Cmd(name);
	if(pInterf == nullptr){
		cerr<<"Nie ma takiej wtyczki! Wybierz jedna z dostepnych opcji! "<<endl;
		return nullptr;
	} else{
		return pInterf->CreateCmd();
	}		
}
