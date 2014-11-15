#ifndef LIBINTERFACE_HH
#define LIBINTERFACE_HH

#include <dlfcn.h>
#include <iostream>
#include "command.h"

/*!
 * \file
 * 
 * \brief Zawiera definicję klasy LibInterface
 *
 *  Plik zawiera definicję klasy LibInterface, która modeluje
 *  interfejs biblioteki zawierającej implementację polecenia
 *  dla manipulatora.
 */

/*!
 * \brief Klasa modeluje interfejs wtyczki 
 * 
 * Klasa modeluje listę interfejs biblioteki dynamicznie konsolidowanej,
 * która stanowi wtyczkę dla programu głównego, który umożliwia
 * egzekujcję poleceń. Wspomniana wtyczkę zawiera implementację
 * nowego polecenia.
 */
class LibInterface {
  public:

    LibInterface(): _pLibHandle(NULL), _pFun_GetCmdName(NULL), _pFun_pCreateCmd(NULL),
			_pFun_pPrintSyntax(NULL), pFun(NULL) {}
    ~LibInterface() { if (_pLibHandle) dlclose(_pLibHandle); }
    bool Init4Lib(const char* sLibName);
    void Detach() { _pLibHandle = NULL; _pFun_GetCmdName=NULL; _pFun_pCreateCmd=NULL;_pFun_pPrintSyntax=NULL;pFun=NULL;}
    const char*  GetCmdName() const { return _pFun_GetCmdName(); }
    Command*  CreateCmd() const { return _pFun_pCreateCmd(); }
    void  PrintSyntax() const { return _pFun_pPrintSyntax(); }

  private:
    void  *_pLibHandle; 
    const char* (*_pFun_GetCmdName)();
    Command *(*_pFun_pCreateCmd)();
    void (*_pFun_pPrintSyntax)();
    void *pFun;


};


#endif
