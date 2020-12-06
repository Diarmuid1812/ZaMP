#ifndef SET_OF_MOB_OBJECTS_HH
#define SET_OF_MOB_OBJECTS_HH

#include <memory>
#include "MobileObj.hh"

/*!
 *  \file
 *  \brief Definicja typu  SetOfMobObjects.
 *
 *  Plik zawiera definicję typu danych SetOfMobObjects, będącego mapą
 *  wskaźników dzielonych na obiekty mobilne.
 */
/*!
 *  \brief Typ danych dla zestawu obiektów mobilnych.
 *
 *  Typ danych Set4Libinterfaces, realizujący mapę wskaźników dzielonych na obiekty mobilne,
 *  jako klucze przyjmującą nazwy obiektów mobilnych.
 */

typedef std::map<std::string, std::shared_ptr<MobileObj>> SetOfMobObjects;

#endif
