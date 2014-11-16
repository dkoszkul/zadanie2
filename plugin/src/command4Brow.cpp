#include <iostream>
#include "command4Brow.h"

using std::cout;
using std::endl;


extern "C" {
  const char* GetCmdName(void);
  void PrintSyntax(void);
  Command* CreateCmd(void);
}

const char* GetCmdName(void)
{
  return Command4Brow::GetCmdName();
}

void PrintSyntax(void)
{
  Command4Brow::PrintSyntax();
}

Command* CreateCmd(void)
{
  return Command4Brow::CreateCmd();
}


////////////////////////////////////////////////////
Command4Brow::Command4Brow()
{}

const char* Command4Brow::GetCmdName() 
{ 
  return "Brew"; 
}

void Command4Brow::PrintCmd() const
{
  cout << GetCmdName() <<" "<<getIdBrwi()<<" "<<getPolozenieBrwi()<<" "<<getPolozenieKatNachylenia()
	<<" "<<getSzybkoscZmiany()  << endl;
}

/*!
 *
 */
int Command4Brow::ExecCmd(RobotFace &RobPose) const
{
string filenameT = "dat/"+filename;
	RobPose.Brew_simulateMovement(getPolozenieBrwi(),getPolozenieKatNachylenia(),getSzybkoscZmiany(),getIdBrwi(),filenameT);	

  return 0;
}


/*!
 *
 */
bool Command4Brow::ReadParams(std::istream& Strm_CmdsList)
{
	Strm_CmdsList>>idBrwi;
	Strm_CmdsList>>polozenieBrwi;
	Strm_CmdsList>>polozenieKatNachylenia;
	Strm_CmdsList>>szybkoscZmiany;

	filename = "Brew";
	filename+=to_string(idBrwi);
	filename+=".dat";

  return true;
}
/*!
 *
 */
Command* Command4Brow::CreateCmd()
{
  return new Command4Brow();
}


/*!
 *
 */
void Command4Brow::PrintSyntax()
{
  cout << "   Brew "
       << "id_brwi, polozenie_brwi, polozenie_kat_nachylenia,"
       << " szybkosc_zmiany;" << endl;
}

//////////////////////
//////////////////////


int Command4Brow::getIdBrwi() const {
	return idBrwi;
}

void Command4Brow::setIdBrwi(double idBrwi) {
	this->idBrwi = idBrwi;
}

double Command4Brow::getPolozenieBrwi() const {
	return polozenieBrwi;
}

void Command4Brow::setPolozenieBrwi(double polozenieBrwi) {
	this->polozenieBrwi = polozenieBrwi;
}

double Command4Brow::getPolozenieKatNachylenia() const {
	return polozenieKatNachylenia;
}

void Command4Brow::setPolozenieKatNachylenia(double polozenieKatNachylenia) {
	this->polozenieKatNachylenia = polozenieKatNachylenia;
}

int Command4Brow::getSzybkoscZmiany() const {
	return szybkoscZmiany;
}

void Command4Brow::setSzybkoscZmiany(double szybkoscZmiany) {
	this->szybkoscZmiany = szybkoscZmiany;
}

std::string Command4Brow::getFilename(){
	return filename;
}
///////////////////
///////////////////





