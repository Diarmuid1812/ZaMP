#ifndef SET_4_LIBINTERFACES
#define SET_4_LIBINTERFACES

#include<map>
#include"LibInterface.hh"

/*!
 *  \file
 *  \brief Definicja typu  Set4Libinterfaces
 *
 *  Plik zawiera definicję typu danych Set4Libinterfaces, będącego mapą
 *  wskaźników dzielonych do klasy LibInterface
 */
/*!
 *  \brief Typ danych dla zestawu bibliotek.
 *
 *  Typ danych Set4Libinterfaces, realizujący mapę wskaźników dzielonych na interfejsy
 *  wczytywanych dynamicznie bibliotek, jako klucz przyjmującą nazwy poleceń dla robota
 *  mobilnego, realizowanych przez daną bibliotekę.
 */

typedef std::map<const std::string, std::shared_ptr<LibInterface>> Set4Libinterfaces;

#endif //SET_4_LIBINTERFACES
