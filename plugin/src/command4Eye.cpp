#include <iostream>
#include "command4Eye.h"

using std::cout;
using std::endl;


extern "C" {
  const char* GetCmdName(void);
  void PrintSyntax(void);
  Command* CreateCmd(void);
}



const char* GetCmdName(void)
{
  return Command4Eye::GetCmdName();
}

void PrintSyntax(void)
{
  Command4Eye::PrintSyntax();
}

Command* CreateCmd()
{
  return Command4Eye::CreateCmd();
}


////////////////////////////////////////////////////
Command4Eye::Command4Eye()
{}

const char* Command4Eye::GetCmdName() 
{ 
  return "Oko"; 
}

void Command4Eye::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() <<" "<<getIdOka()<<" "<<getPolozenieDolnejPowieki()<<" "<<getPolozenieGornejPowieki()
	<<" "<<getSzybkoscZmiany()  << endl;
}

/*!
 *
 */
int Command4Eye::ExecCmd(RobotFace &RobPose) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return 0;
}


/*!
 *
 */
bool Command4Eye::ReadParams(std::istream& Strm_CmdsList)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
Command* Command4Eye::CreateCmd()
{
  return new Command4Eye();
}


/*!
 *
 */
void Command4Eye::PrintSyntax()
{
  cout << "   Oko "
       << "id_oka, polozenie_dolnej_powieki, polozenie_gornej_powieki,"
       << " szybkosc_zmian;" << endl;
}

//////////////////////
//////////////////////
int Command4Eye::getIdOka() const {
	return idOka;
}

void Command4Eye::setIdOka(double idOka) {
	this->idOka = idOka;
}

double Command4Eye::getPolozenieDolnejPowieki() const {
	return polozenieDolnejPowieki;
}

void Command4Eye::setPolozenieDolnejPowieki(double polozenieDolnejPowieki) {
	this->polozenieDolnejPowieki = polozenieDolnejPowieki;
}

double Command4Eye::getPolozenieGornejPowieki() const {
	return polozenieGornejPowieki;
}

void Command4Eye::setPolozenieGornejPowieki(double polozenieGornejPowieki) {
	this->polozenieGornejPowieki = polozenieGornejPowieki;
}

int Command4Eye::getSzybkoscZmiany() const {
	return szybkoscZmiany;
}

void Command4Eye::setSzybkoscZmiany(double szybkoscZmiany) {
	this->szybkoscZmiany = szybkoscZmiany;
}
///////////////////
///////////////////
