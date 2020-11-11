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
   * \brief
   */
  Interp4Rotate();
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
