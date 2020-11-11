#ifndef SCENE
#define SCENE

#include "MobileObj.hh"

/*!
 * \file
 * \brief Definicja klasy Scene
 *
 * Plik zawiera definicję klasy Scene, moedelującej scenę, po której
 * poruszają się obiekty
 */

/*!
 * \brief Modeluje scenę dla obiektów mobilnych
 *
 *  Klasa modeluje scenę, po której poruszać mogą się obiekty mobilne,
 *  przechowuje mapę znajdujących się na niej obiektów.
 *
 */
class Scene
{
  /*!
   * \brief Zbiór obiektów na scenie
   *
   *  Mapa mobilnych obiektów na scenie, której kluczami są nazwy posczególnych
   *  obiektów
   */
  std::map<std::string, MobileObj> _Set_of_mobile_Objects;

  /*!
   * \brief Znajduje obiekt na scenie (char*)
   *
   *  Znajduje obiekt, o nazwie podanej w formie ciągu znaków, w zbiorze obiektów,
   *  znajdujących się na scenie i zwraca wskaźnik dzielony na niego.
   * \param[in] sObjName - wskaźnik do tablicy znaków, reprezentujących nazwę obiektu
   * \return Wskaźnik dzielony na znaleziony obiekt
   */
  std::shared_ptr<MobileObj>FindMobileObject(char * sObjName);

  /*!
   * \brief Znajduje obiekt na scenie (std::string&)
   *
   *  Znajduje obiekt, o nazwie podanej w formie zmiennej string, w zbiorze obiektów,
   *  znajdujących się na scenie i zwraca wskaźnik dzielony na niego..
   * \param[in] rObjName - referencja do zmiennej std::string, zawierającej nazwę obiektu
   * \return Wskaźnik dzielony na znaleziony obiekt
   */
  std::shared_ptr<MobileObj>FindMobileObject(std::string & rObjName);
}

#endif //SCENE
