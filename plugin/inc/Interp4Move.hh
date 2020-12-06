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
 *  o zadany dystans przy zadanej prędkości.
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
   * \brief Konstruktor klasy
   *
   * Konstruktor klasy. Inicjalizuje parametry liczbowe zerowymi wartościami.
   */
  Interp4Move();
  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów).
   *
   * Wyświetla całe wczytane polecenie razem z wartościami parametrów ruchu.
   */
  virtual void PrintCmd() const;
  /*!
   * \brief Wyświetla składnię polecenia.
   *
   * Wyświetla składnię polecenia Move.
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
   * \brief Wykonuje polecenie Move.
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
   * Wczytuje wartości parametrów ruchu dla polecenia.
   * \param[in] Strm_CmdsList - strumień do wczytania parametrów.
   * \retval true - jeśli wczyttwanie się powiodło.
   * \retva false - w przeciwnym wypadku.
   */
  virtual bool ReadParams(std::istream& Strm_CmdsList);
  /*!
   * \brief Wyświetla wartości parametrów polecenia.
   *
   * Wyświetla wartości parametrów ruchu.
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
