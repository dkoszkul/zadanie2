#include <iostream>
#include <map>
#include <string>
#include "libinterface.hh"
#include "set4libinterfaces.hh"


using namespace std;




int main (int argc, char* args[]) 
{

  Set4LibInterfaces  LibsSet;

  if (!LibsSet.AddLib("libPolecenie_Oko.so")) return 1;
  if (!LibsSet.AddLib("libPolecenie_Usta.so")) return 1;

  const LibInterface *pInterf  = LibsSet.FindLib4Cmd("Oko");

  cout << endl;
  cout << "Nazwa znalezionego polecenia: " << pInterf->GetCmdName() << endl;
  cout << endl;

  cout << "Listing wszystkich polecen:" << endl;
  for (map<string,LibInterface*>::const_iterator Iter = LibsSet.begin();
       Iter != LibsSet.end();  ++Iter) {
    cout << "     " << Iter->second->GetCmdName() << endl;
  }
  cout << endl;
}
