#ifndef  INTERP4COMMAND_HH
#define  INTERP4COMMAND_HH

#include <iostream>
#include <unistd.h>
#include "MobileObj.hh"
#include "Scene.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Command
 *
 * Plik zawiera definicję klasy Interp4Command, modelującej abstrakcyjne polecenie
 * dla robota mobilnego i metody wirtualne umożliwiające jego realizację.
 */

/*!
 * \brief Modeluje abstrakcyjne polecenie dla robota mobilnego
 *
 *  Klasa modeluje abstrakcyjne, ogólne polecenie dla robota mobilnego.
 *  Umożliwia wykonanie dowolnego polecenia, poprzez wykorystanie metod wirtualnych,
 *  uszczególnionych w klasach dziedziczących po niej.
 *
 */
 class Interp4Command {
  public:
   /*!
    * \brief Destruktor wirtualny ze wzgledu na klasy pochodne
    *
    * Wirtualny destruktor klasy.
    */
   virtual ~Interp4Command() {}
   /*!
    * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów).
    *
    * Wyświetla całe wczytane polecenie razem z wartościami parametrów.
    */
   virtual void PrintCmd() const = 0;
   /*!
    * \brief Wyświetla składnię polecenia.
    *
    * Wyświetla składnię bieżącego polecenia.
    */
   virtual void PrintSyntax() const = 0;
   /*!
    * \brief Wyświetla nazwę polecenia.
    *
    * Wyświetla nazwę bieżącego polecenia.
    * \return - Nazwa polecenia.
    */
   virtual const char* GetCmdName() const = 0;
   /*!
    * \brief Wykonuje polecenie.
    *
    * Wykonuje bieżące polecenie oraz zaznacza że wprowadzono zmiany,
    * co pozwala na wywołanie wizualizacji.
    */
   virtual bool ExecCmd(Scene * pScn) const = 0;
   /*!
    * \brief Czyta wartości parametrów danego polecenia.
    *
    * Wczytuje wartości parametrów dla wykonywanego polecenia.
    */
   virtual bool ReadParams(std::istream& Strm_CmdsList) = 0;
 };

#endif
