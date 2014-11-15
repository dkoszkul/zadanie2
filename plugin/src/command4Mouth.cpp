
#include <iostream>
#include "command4Mouth.h"

using std::cout;
using std::endl;


extern "C" {
  const char* GetCmdName(void);
  void PrintSyntax(void);
  Command* CreateCmd(void);
}



const char* GetCmdName(void)
{
  return Command4Mouth::GetCmdName();
}

void PrintSyntax(void)
{
  Command4Mouth::PrintSyntax();
}

Command* CreateCmd()
{
  return Command4Mouth::CreateCmd();
}

//////////////////////////////////////////////////////

Command4Mouth::Command4Mouth()
{}

const char* Command4Mouth::GetCmdName() 
{ 
  return "Usta"; 
}

void Command4Mouth::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() <<" "<<getPolozenieDolnejWargi()<<" "<<getPolozenieGornejWargi()<<" "<<getOddalenieKacikowUst()<<" "<< getSzybkoscZmiany() << endl;
}

int Command4Mouth::ExecCmd(RobotFace &RobPose) const
{
  RobPose.Usta_zbudujPolecenieDlaGnuplota(getPolozenieDolnejWargi(),getPolozenieGornejWargi(),getOddalenieKacikowUst());
  RobPose.Usta_zapisz(getSzybkoscZmiany());

  return 0;
}

bool Command4Mouth::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList>> polozenieDolnejWargi;
  Strm_CmdsList>> polozenieGornejWargi;
  Strm_CmdsList>> oddalenieKacikowUst;
  Strm_CmdsList>> szybkoscZmiany;

  return true;
}

Command* Command4Mouth::CreateCmd()
{
  return new Command4Mouth();
}

void Command4Mouth::PrintSyntax()
{
  cout << "   Usta "
       <<"cos z ustami"
       << " szybkosc_zmian;" << endl;
}



////////////////////////////////////
////////////////////////////////////

double Command4Mouth::getOddalenieKacikowUst() const {
	return oddalenieKacikowUst;
}

void Command4Mouth::setOddalenieKacikowUst(double oddalenieKacikowUst) {
	this->oddalenieKacikowUst = oddalenieKacikowUst;
}

double Command4Mouth::getPolozenieDolnejWargi() const {
	return polozenieDolnejWargi;
}

void Command4Mouth::setPolozenieDolnejWargi(double polozenieDolnejWargi) {
	this->polozenieDolnejWargi = polozenieDolnejWargi;
}

double Command4Mouth::getPolozenieGornejWargi() const {
	return polozenieGornejWargi;
}

void Command4Mouth::setPolozenieGornejWargi(double polozenieGornejWargi) {
	this->polozenieGornejWargi = polozenieGornejWargi;
}

int Command4Mouth::getSzybkoscZmiany() const {
	return szybkoscZmiany;
}

void Command4Mouth::setSzybkoscZmiany(int szybkoscZmiany) {
	this->szybkoscZmiany = szybkoscZmiany;
}

std::string Command4Mouth::getFilename(){
	return "Usta.dat";
}

