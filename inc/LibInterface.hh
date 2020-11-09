#ifndef LIBINTERFACE
#define LIBINTERFACE

#define LIB_LOAD_EXCEPTION 411
#include <dlfcn.h>

#include "Interp4Command.hh"

class LibInterface
{
public:
  void * _LibHandler;
  std::string _CmdName;
  Interp4Command *(*_pCreateCmd)(void);


  const std::string GetCName(){return _CmdName;}
  explicit LibInterface(const std::string LibPath);
};

#endif //LIBINTERFACE
