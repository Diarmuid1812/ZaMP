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
   * \brief Konstruktor klasy
   *
   * Konstruktor klasy. Inicjalizuje parametry liczbowe zerowymi wartościami.
   */
  Interp4Set();
  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów).
   *
   * Wyświetla całe wczytane polecenie razem z wartościami parametrów położenia.
   */
  virtual void PrintCmd() const;
  /*!
   * \brief Wyświetla składnię polecenia.
   *
   * Wyświetla składnię polecenia Set.
   */
  virtual void PrintSyntax() const;
  /*!
   * \brief Wyświetla nazwę polecenia.
   *
   * Wyświetla nazwę bieżącego polecenia.
   * \return - Nazwa polecenia.
   */
  virtual const char* GetCmdName() const;
  /*!
   * \brief Wykonuje polecenie Set.
   *
   * Wykonuje polecenie ruchu oraz zaznacza że wprowadzono zmiany,
   * co pozwala na wywołanie wizualizacji.
   * \param[in,out] pScn - wskażnik na scenę,
   *                       dla której wykonywane jest polecenie.
   * \retval true - jeśli wykonanie się powiodło.
   * \retval false - w przeciwnym wypadku.
   */
  virtual bool ExecCmd(Scene * pScn) const;
  /*!
   * \brief Czyta wartości parametrów danego polecenia.
   *
   * Wczytuje wartości parametrów położenia dla polecenia.
   * \param[in] Strm_CmdsList - strumień do wczytania parametrów.
   * \retval true - jeśli wczyttwanie się powiodło.
   * \retval false - w przeciwnym wypadku.
   */
  virtual bool ReadParams(std::istream& Strm_CmdsList);
  /*!
   * \brief Wyświetla wartości parametrów polecenia.
   *
   * Wyświetla wartości parametrów położenia.
   */
  virtual void PrintParams() {}
  /*!
   * \brief Tworzy instancję interpretera polecenia
   *
   * Tworzy instancję interpretera dla polecenia "Move".
   * Ta metoda nie musi być zdefiniowna w klasie bazowej.
   * \return - instancja interpretera
   */
  static Interp4Command* CreateCmd();
 };

#endif
