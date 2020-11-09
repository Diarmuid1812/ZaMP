#include "LibInterface.hh"


LibInterface::LibInterface(const std::string LibName)
{
  void *pLibHnd = dlopen(LibName.c_str(),RTLD_LAZY);

  //Interp4Command *(*pCreateCmd)(void);
  void *pFun;

  std::cerr << "Ładowanie biblioteki: "   <<LibName<< std::endl;
  if (!pLibHnd) {
    std::cerr << "!!! Brak biblioteki: " <<LibName<< std::endl;
    throw LIB_LOAD_EXCEPTION;
  }

  pFun = dlsym(pLibHnd,"CreateCmd");
  if (!pFun) {
    std::cerr << "!!! Nie znaleziono funkcji CreateCmd" << std::endl;
    throw LIB_LOAD_EXCEPTION;
  }

  _pCreateCmd = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);

  this->_LibHandler = _pCreateCmd();
  this->_CmdName=_pCreateCmd()->GetCmdName();


}
