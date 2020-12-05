#ifndef  COMMAND4SET_HH
#define  COMMAND4SET_HH


#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Set
 *
 * Plik zawiera definicję klasy Interp4Set ustawiającej robota na zadanej pozycji.
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które ustawia go na zadanej pozycji
 *
 *  Klasa modeluje polecenie, ustawiające robota na zadanej pozycji, zdefiniowanej przez
 *  podane wymiary X i Y oraz kąt obrotu wokół osi OZ
 */
class Interp4Set: public Interp4Command {
  /*!
   *  \brief Nazwa robota
   *
   *  Nazwa robota mobilnego, który ma być ustawiony na zadanej pozycji
   */
  std::string _ParName;
  /*!
   *  \brief Współrzędna X [m]
   *
   *  Współrzędna X, określająca ustawienie robota, wyrażona w metrach
   */
  double  _PosX_m;
  /*!
   *  \brief Współrzędna Y [m]
   *
   *  Współrzędna Y, określająca ustawienie robota, wyrażona w metrach
   */
  double  _PosY_m;
  /*!
   *  \brief Rotacja OZ [deg]
   *
   *  Orientacja robota w stopniach, wyrażona jako kąt obrotu wokół osi OZ
   */
  double  _rotZ_deg;
 public:
  /*!
   * \brief
   */
  Interp4Set();
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
  virtual bool ExecCmd(Scene * pScn) const;
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
