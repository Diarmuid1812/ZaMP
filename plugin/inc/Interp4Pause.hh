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
    * \brief Konstruktor klasy
    *
    * Konstruktor klasy. Inicjalizuje parametr liczbowy wartościamą zerową.
    */
  Interp4Pause();
  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów).
   *
   * Wyświetla całe wczytane polecenie razem z wartościamą czasu wstrzymania.
   */
  virtual void PrintCmd() const;
  /*!
   * \brief Wyświetla składnię polecenia.
   *
   * Wyświetla składnię polecenia Pause.
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
   * \brief Wykonuje polecenie Pause.
   *
   * Wykonuje polecenie zatzrzymania sceny i blokuje
   * dostęp do niej na podany parametrem czas.
   * \param[in,out] pScn - wskażnik na scenę,
   *                       dla której wykonywane jest polecenie.
   * \retval true - jeśli wykonanie się powiodło.
   * \retval false - w przeciwnym wypadku.
   */
  virtual bool ExecCmd(Scene * pScn) const;
  /*!
   * \brief Czyta wartości parametrów danego polecenia.
   *
   * Wczytuje wartość parametru czasu zatrzymania.
   *
   * \param[in] Strm_CmdsList - strumień do wczytania parametrów.
   * \param[in,out] pScn - wskażnik na scenę,
   *                       dla której wykonywane jest polecenie.
   */
  virtual bool ReadParams(std::istream& Strm_CmdsList);
  /*!
   * \brief Wyświetla wartości parametrów polecenia.
   *
   * Wyświetla wartość parametru czasu zatrzymania.
   */
  virtual void PrintParams() {}
  /*!
   * \brief Tworzy instancję interpretera polecenia
   *
   * Tworzy instancję interpretera dla polecenia "Pause".
   * Ta metoda nie musi być zdefiniowna w klasie bazowej.
   * \return - instancja interpretera
   */
  static Interp4Command* CreateCmd();
 };

#endif
