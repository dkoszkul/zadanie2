#include "metodyMain.h"

int main (int argc, char* args[]) 
{
	Scene  Scn;
	RobotFace robotFace;
  	Set4LibInterfaces  LibsSet;
char Opcja;

  if (!LibsSet.AddLib("libPolecenie_Oko.so")) return 1;
  if (!LibsSet.AddLib("libPolecenie_Usta.so")) return 1;
  if (!LibsSet.AddLib("libPolecenie_Brew.so")) return 1;
  listing(LibsSet);
Scn.AddLibSet(LibsSet);
/*
	displayMenu();
displayMenu_CaseI(LibsSet);
displayMenu_CaseD(LibsSet);
displayMenu_CaseU(LibsSet);
*/

displayMenu_CaseW(Scn,robotFace);

cout << "Aby zakonczyc nacisnij ENTER ..." << flush;
	cin >> noskipws >> Opcja;


	cin >> noskipws >> Opcja;


return 0;
}
