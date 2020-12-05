#ifndef SET_OF_MOB_OBJECTS_HH
#define SET_OF_MOB_OBJECTS_HH

#include <memory>
#include "MobileObj.hh"

typedef std::map<std::string, std::shared_ptr<MobileObj>> SetOfMobObjects;

#endif
