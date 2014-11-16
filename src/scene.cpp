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
		cerr<<endl<<"Brak wtyczki "<<name<<". Doinstaluj ja lub zmien plik konfiguracyjny."<<endl;
		return nullptr;
	} else{
		return pInterf->CreateCmd();
	}		
}


void Scene::refreshActualMap(string nazwaPliku,Command * komenda){

if (aktualnaMapa.count(nazwaPliku) != 0) {
		aktualnaMapa.erase(nazwaPliku);
		aktualnaMapa.insert(
				std::pair<std::string, Command*>(nazwaPliku, komenda));
	} else {
		aktualnaMapa.insert(
				std::pair<std::string, Command*>(nazwaPliku, komenda));
	}
std::cerr<<"Aktualna mapa posiada: "<<aktualnaMapa.size()<<" elementow."<<std::endl;
}

