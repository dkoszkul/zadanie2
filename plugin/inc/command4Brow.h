#ifndef  COMMAND4EYE_HH
#define  COMMAND4EYE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "command.h"
#include "robotfaceInterface.h"

#include <string>

class Command4Brow: public Command {
	
private:
	int idBrwi;
	double polozenieBrwi;
	double polozenieKatNachylenia;
	int szybkoscZmiany;
	
	std::string filename;

public:
  Command4Brow();  
  virtual void PrintCmd() const;
  virtual int ExecCmd( RobotFace   &pRobFace ) const;
  virtual bool ReadParams(std::istream& Strm_CmdsList);
  static const char* GetCmdName();
  static Command* CreateCmd();
  static void PrintSyntax();

///////////////////////////////////////////////////
///////////////////////////////////////////////////
	int getIdBrwi() const;
	void setIdBrwi(double idOka);
	double getPolozenieBrwi() const;
	void setPolozenieBrwi(double polozenieBrwi);
	double getPolozenieKatNachylenia() const;
	void setPolozenieKatNachylenia(double polozenieKatNachylenia);
	virtual int getSzybkoscZmiany() const;
	void setSzybkoscZmiany(double szybkoscZmiany);
	virtual std::string getFilename();
	virtual std::string getCommandName(){return "Brew";};
///////////////////////////////////////////////////
///////////////////////////////////////////////////

 };

#endif
