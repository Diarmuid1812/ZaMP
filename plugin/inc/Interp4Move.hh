#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Move
 *
 * Plik zawiera definicję klasy Interp4Move, modelującej polecenie ruchu
 * robota.
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego ruch do przodu
 *
 *  Klasa modeluje polecenie dla robota mobilnego, wymuszające jego ruch naprzód
 *  o zadany dystans przy zadanej prędkości
 */
class Interp4Move: public Interp4Command {
  /*!
   *  \brief Nazwa robota
   *
   *  Nazwa robota mobilnego, który ma się poruszyć
   */
  std::string  _ParName;

  /*!
   *  \brief Prędkość ruchu w m/s
   *
   *  Prędkość z jaką ma poruszać się wybrany robot, podana w m/s
   */
  double  _Speed_mps;
  /*!
   *  \brief Dystans ruchu w m
   *
   *  Dystans jaki pokonać ma robot, podany w metrach
   */
  double  _Dist_m;
 public:
  /*!
   * \brief
   */
  Interp4Move();
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
  virtual bool ExecCmd(MobileObj  *pMobObj, int Socket) const;
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
