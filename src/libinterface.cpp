#include "libinterface.hh"
#include <string>
#include <iostream>

using std::string;
using std::cerr;
using std::endl;

bool LibInterface::Init4Lib(const char* sLibName)
{
  string Name4Lib="libs/";
Name4Lib+=sLibName;


_pLibHandle=dlopen(Name4Lib.c_str(),RTLD_LAZY);

  if (!_pLibHandle) {
    cerr << "!!! Brak biblioteki: "<<sLibName << endl;
    return false;
  }

pFun = dlsym(_pLibHandle,"GetCmdName"); 
  if (!pFun) {
    cerr << dlerror() << endl;
    return false;
  }
  _pFun_GetCmdName = *reinterpret_cast<const char* (**)()>(&pFun);

pFun = dlsym(_pLibHandle,"CreateCmd");
  if (!pFun) {
    cerr << dlerror() << endl;
    return false;
  }
  _pFun_pCreateCmd = *reinterpret_cast<Command* (**)(void)>(&pFun);


  pFun = dlsym(_pLibHandle,"PrintSyntax"); 
  if (!pFun) {
    cerr << dlerror() << endl;
    return false;
  }
  _pFun_pPrintSyntax = *reinterpret_cast<void (**)()>(&pFun);

    return true;
}
