#ifndef SCENE
#define SCENE

#include <vector>
#include <map>
#include <memory>
#include "SetOfMobObjects.hh"
#include "MobileObj.hh"
#include "AccessControl.hh"
#include "Configuration.hh"

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
class Scene: public AccessControl
{
  /*!
   * \brief Zbiór obiektów na scenie
   *
   *  Mapa mobilnych obiektów na scenie, której kluczami są nazwy posczególnych
   *  obiektów
   */
  /*std::map<std::string, std::shared_ptr<MobileObj>>*/SetOfMobObjects _Set_of_mobile_Objects;


public:
  /*!
   * \brief Znajduje obiekt na scenie (char*)
   *
   *  Znajduje obiekt, o nazwie podanej w formie ciągu znaków, w zbiorze obiektów,
   *  znajdujących się na scenie i zwraca wskaźnik dzielony na niego.
   * \param[in] sObjName - wskaźnik do tablicy znaków, reprezentujących nazwę obiektu
   * \return Wskaźnik dzielony na znaleziony obiekt
   */
   bool FindMobileObject(const char * sObjName, std::shared_ptr<MobileObj>& pObj)
   {
     SetOfMobObjects::const_iterator Iter = _Set_of_mobile_Objects.find(sObjName);
	   if (Iter == _Set_of_mobile_Objects.end()) return false;
	   pObj = Iter->second;
	   return true;
   }

  /*!
   * \brief Znajduje obiekt na scenie (std::string&)
   *
   *  Znajduje obiekt, o nazwie podanej w formie zmiennej string, w zbiorze obiektów,
   *  znajdujących się na scenie i zwraca wskaźnik dzielony na niego..
   * \param[in] rObjName - referencja do zmiennej std::string, zawierającej nazwę obiektu
   * \return Wskaźnik dzielony na znaleziony obiekt
   */
   bool FindMobileObject(std::string & rObjName, std::shared_ptr<MobileObj>& pObj)
   {
     SetOfMobObjects::const_iterator Iter = _Set_of_mobile_Objects.find(rObjName.c_str());
	   if (Iter == _Set_of_mobile_Objects.end()) return false;
	   pObj = Iter->second;
	   return true;
   }

  /*!
   * \brief Znajduje obiekt na scenie (std::string&)
   *
   *  Znajduje obiekt, o nazwie podanej w formie zmiennej string, w zbiorze obiektów,
   *  znajdujących się na scenie i zwraca wskaźnik dzielony na niego..
   * \param[in] rObjName - referencja do zmiennej std::string, zawierającej nazwę obiektu
   * \return Wskaźnik dzielony na znaleziony obiekt
   */
   bool FindMobileObject(const std::string & rObjName, std::shared_ptr<MobileObj>& pObj)
   {
     SetOfMobObjects::const_iterator Iter = _Set_of_mobile_Objects.find(rObjName.c_str());
	   if (Iter == _Set_of_mobile_Objects.end()) return false;
	   pObj = Iter->second;
	   return true;
   }

  /*!
   * \brief Przekazuje listę obiektów na scenie
   *
   * Tworzy i zwraca listę nazw obiektów mobilnych,
   * znajdujących się na scenie.
   * \return - lista obiektów mobilnych
   *//*
  const std::vector<std::string> getObjList() const
  {
    std::vector<std::string> VectorOfMobObjNames;
    for (const std::pair<std::string,MobileObj> &rObj : _Set_of_mobile_Objects)
    {
      VectorOfMobObjNames.push_back(rObj.first);
    }
    return VectorOfMobObjNames;
  }*/

  /*!
   * \brief Przekazuje listę obiektów na scenie
   *
   * Tworzy i zwraca listę nazw obiektów mobilnych,
   * znajdujących się na scenie.
   * \return - lista obiektów mobilnych
   */
  std::vector<std::string> getObjList() const
  {
    std::vector<std::string> VectorOfMobObjNames;
    for (const std::pair<std::string,std::shared_ptr<MobileObj>> &rObj : _Set_of_mobile_Objects)
    {
      VectorOfMobObjNames.push_back(rObj.first);
    }
    return VectorOfMobObjNames;
  }

  void configureScene(Configuration & rConf)
  {
    _Set_of_mobile_Objects=rConf.UseSetOfMobObjects();
  }
};
/*
std::shared_ptr<MobileObj> Scene::FindMobileObject(char * sObjName)
{
  std::string keyName(sObjName);
  std::shared_ptr<MobileObj> shPtr2Object = _Set_of_mobile_Objects.find(keyName)->second;

  return shPtr2Object;
}


std::shared_ptr<MobileObj> Scene::FindMobileObject(std::string & rObjName)
{
  std::shared_ptr<MobileObj> shPtr2Object = _Set_of_mobile_Objects.find(rObjName)->second;

  return shPtr2Object;
}
*/
#endif //SCENE
