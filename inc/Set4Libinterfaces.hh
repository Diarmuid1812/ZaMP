#ifndef SET_4_LIBINTERFACES
#define SET_4_LIBINTERFACES

#include<map>
#include"LibInterface.hh"

typedef std::map<const std::string, std::shared_ptr<LibInterface>> Set4Libinterfaces;

/*
class Set4Libinterfaces : public std::map<const std::string, std::shared_ptr<Libinterace>>
{

};
*/
#endif //SET_4_LIBINTERFACES
