#ifndef  COMMAND4PAUSE_HH
#define  COMMAND4PAUSE_HH


#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Pause
 *
 * Plik zawiera definicję klasy Interp4Pause, modelującej polecenie zatrzymania
 * się wszystkich robotów mobilnych na scenie symulacji
 */

/*!
 * \brief Modeluje polecenie dla sceny, wymuszające zatrzymanie wszystkich obiektów
 *
 *  Klasa modeluje polecenie, wymuszające zatrzymanie się wszyctkich robotów
 *  mobilnych, znajdujących się na scenie
 */
class Interp4Pause: public Interp4Command {
  /*!
   *  \brief Czas zatrzymania w ms
   *
   *  Czas na jaki mają się zatrzymać wszystkie obiekty, podany w milisekundach
   */
  double  _delay_ms;
 public:
  /*!
   * \brief
   */
  Interp4Pause();
  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
   */
  virtual void PrintCmd() const;
  /*!
   * \brief Wyświetla składnię polecenia
   */
  virtual void PrintSyntax() const;
  /*!
   * \brief Wyświetla nazwę polecenia
   */
  virtual const char* GetCmdName() const;
  /*!
   * \brief Wykonuje polecenie oraz wizualizuje jego realizację
   */
  virtual bool ExecCmd( MobileObj  *pMobObj, int Socket) const;
  /*!
   * \brief Czyta wartości parametrów danego polecenia
   */
  virtual bool ReadParams(std::istream& Strm_CmdsList);
  /*!
   * \brief Wyświetla wartości wczytanych parametrów
   */
  virtual void PrintParams() {}
  /*!
   * \brief
   *
   *  Ta metoda nie musi być zdefiniowna w klasie bazowej.
   */
  static Interp4Command* CreateCmd();
 };

#endif
