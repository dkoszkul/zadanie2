

#ifndef  COMMAND4EYE_HH
#define  COMMAND4EYE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "command.h"
#include "robotfaceInterface.h"

#include <string>

class Command4Mouth: public Command {
	
private:
	double polozenieDolnejWargi;
	double polozenieGornejWargi;
	double oddalenieKacikowUst;
	int szybkoscZmiany;

 public:
  Command4Mouth();  
  virtual void PrintCmd() const;
  virtual int ExecCmd( RobotFace   &pRobFace ) const;
  virtual bool ReadParams(std::istream& Strm_CmdsList);
  static const char* GetCmdName();
  static Command* CreateCmd();
  static void PrintSyntax();
///////////////////////////////////////////////////
///////////////////////////////////////////////////
	double getOddalenieKacikowUst() const;
	void setOddalenieKacikowUst(double oddalenieKacikowUst);
	double getPolozenieDolnejWargi() const;
	void setPolozenieDolnejWargi(double polozenieDolnejWargi);
	double getPolozenieGornejWargi() const;
	void setPolozenieGornejWargi(double polozenieGornejWargi);
	int getSzybkoscZmiany() const;
	void setSzybkoscZmiany(int szybkoscZmiany);
	virtual std::string getFilename();

///////////////////////////////////////////////////
///////////////////////////////////////////////////
 };

#endif
