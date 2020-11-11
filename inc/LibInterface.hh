#ifndef LIBINTERFACE
#define LIBINTERFACE

 /*!
  * \file
  * \brief Definicja klasy LibInterface
  *
  * Plik zawiera definicję klasy Libinterace, modelującej interfejs
  * dla pluginu wykonującego polecenie
  */

  /*!
   * \brief Wyjątek wczytania biblioteki
   *
   * Numer wyjątku, oznaczającego brak poprawnego wczytania biblioteki (pluginu)
   */
#define LIB_LOAD_EXCEPTION 411

#include <dlfcn.h>

#include "Interp4Command.hh"


/*!
 * \brief Klasa modelująca interfejs dla pluginu
 *
 * Klasa, służąca jako interfejs dla bibliotek (pluginów), realizujących
 * polecenia dla robota mobilnego.
 */
class LibInterface
{
  /*!
   * \brief Uchwyt dla biblioteki
   *
   * Wskażnik, będący uchwytem do otwartej biblioteki
   */
  void * _LibHandler;
  /*!
   * \brief Nazwa polecenia
   *
   * Nazwa polecenia realizowanego przez bibliotekę (plugin)
   */
  std::string _CmdName;
public:

  /*!
   * \brief Stworzenie interpretera
   *
   * Wskażnik do funkcji, tworzącej nową instancję klay interpretera, modelującego polecenie
   * dla robota mobilnego
   */
  Interp4Command *(*_pCreateCmd)(void);



  /*!
   * \brief Zwraca nazwę polecenia
   *
   * Funkcja zwracająca nazwę polecenia, realizowanego przez bibliotekę
   */
  const std::string GetCmdName(){return _CmdName;}
  /*!
   * \brief Konstruktor interfejsu dla danej biblioteki
   *
   * Wczytuje bibliotekę o podanej nazwie i wczytuje odpowiednie
   * wartości do pól klasy.
   * \param[in] LibPath - nazwa biblioteki
   */
  explicit LibInterface(const std::string LibPath);

  /*!
   * \brief Destruktor zamykający bibliotekę
   *
   * Zamyka wczytaną bibliotekę przed usunięciem klasy
   */
  ~LibInterface();

};



#endif //LIBINTERFACE
