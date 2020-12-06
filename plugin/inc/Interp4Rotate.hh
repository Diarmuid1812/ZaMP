#ifndef  COMMAND4ROTATE_HH
#define  COMMAND4ROTATE_HH


#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Rotate
 *
 * Plik zawiera definicję klasy Interp4Rotate, modelującej polecenie obrotu
 * dla robota
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego ruch obrotowy
 *
 *  Klasa modeluje polecenie obrotu dla robota mobilnego, wymuszające ruch obrotowy
 *  o zadany kąt przy zadanej prędkości kątowej
 */
class Interp4Rotate : public Interp4Command {
  /*!
   *  \brief Nazwa robota
   *
   *  Nazwa robota mobilnego, który ma się poruszyć
   */
 std::string _ParName;
 /*!
  *  \brief Prędkość obrotu w deg/s
  *
  *  Prędkość z jaką obracać ma się wybrany robot, podana w stopniach na sekundę
  */
 double  _angVelocity_degps;
 /*!
  *  \brief Kąt obrotu w deg
  *
  *  Kąt o jaki ma się obrócić robot mobilny, podany w stopniach
  */
 double  _angleRot_deg;
 public:
   /*!
    * \brief Konstruktor klasy
    *
    * Konstruktor klasy. Inicjalizuje parametry liczbowe zerowymi wartościami.
    */
  Interp4Rotate();
  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów).
   *
   * Wyświetla całe wczytane polecenie razem z wartościami parametrów ruchu.
   */
  virtual void PrintCmd() const;
  /*!
   * \brief Wyświetla składnię polecenia.
   *
   * Wyświetla składnię polecenia Rotate.
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
   * \brief Wykonuje polecenie Rotate.
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
   * Wczytuje wartości parametrów ruchu obrotowego dla polecenia.
   * \param[in] Strm_CmdsList - strumień do wczytania parametrów.
   * \retval true - jeśli wczyttwanie się powiodło.
   * \retval false - w przeciwnym wypadku.
   */
  virtual bool ReadParams(std::istream& Strm_CmdsList);
  /*!
   * \brief Wyświetla wartości parametrów polecenia.
   *
   * Wyświetla wartości parametrów ruchu obrotowego.
   */
  virtual void PrintParams() {}
  /*!
   * \brief Tworzy instancję interpretera polecenia
   *
   * Tworzy instancję interpretera dla polecenia "Rotate".
   * Ta metoda nie musi być zdefiniowna w klasie bazowej.
   * \return - instancja interpretera.
   */
  static Interp4Command* CreateCmd();
 };

#endif
