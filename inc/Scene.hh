#ifndef SCENE
#define SCENE

#include "MobileObj.hh"


class Libinterace
{
  std::map<std::string, MobileObj> _Set_of_mobile_Objects;

  std::shared_ptr<MobileObj>FindMobileObject(char * sObjName);
  std::shared_ptr<MobileObj>FindMobileObject(std::string & rObjName);
}

#endif //SCENE
