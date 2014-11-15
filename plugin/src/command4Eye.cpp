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

Command* CreateCmd(void)
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
  cout << GetCmdName() <<" "<<getIdOka()<<" "<<getPolozenieDolnejPowieki()<<" "<<getPolozenieGornejPowieki()
	<<" "<<getSzybkoscZmiany()  << endl;
}

/*!
 *
 */
int Command4Eye::ExecCmd(RobotFace &RobPose) const
{
  RobPose.Oko_zbudujPolecenieDlaGnuplota(getPolozenieDolnejPowieki(),getPolozenieGornejPowieki());
  RobPose.Oko_zapisz(getIdOka(),getSzybkoscZmiany());
  return 0;
}


/*!
 *
 */
bool Command4Eye::ReadParams(std::istream& Strm_CmdsList)
{
	Strm_CmdsList>>idOka;
	Strm_CmdsList>>polozenieDolnejPowieki;
	Strm_CmdsList>>polozenieGornejPowieki;
	Strm_CmdsList>>szybkoscZmiany;

	filename = "Oko";
	filename+=to_string(idOka);
	filename+=".dat";

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

std::string Command4Eye::getFilename(){
	return filename;
}
///////////////////
///////////////////
