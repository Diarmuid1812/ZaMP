#ifndef MOBILEOBJ_HH
#define MOBILEOBJ_HH


#include <string>
#include <sstream>
#include "Vector3D.hh"


/*!
 * \file
 * \brief Zawiera definicję klasy MobileObj
 *
 * Plik zawiera definicję klasy MobileObj.
 * Definicja to może być rozszerzona i zmienione mogą
 * być nazwy pól. Obowiązkowe są jedynie nazwy metod.
 */



/*!
* Nazwy pól klasy są jedynie propozycją i mogą być zmienione
* Nazwy metod są obowiązujące.
*/
class MobileObj {
  /*!
   * \brief Kąt \e yaw reprezentuje rotację zgodnie z ruchem wskazówek zegara
   *        wokół osi \e OZ.
   *
   * Kąt \e yaw reprezentuje rotację zgodnie z ruchem wskazówek zegara
   * wokół osi \e OZ. Wartość kąta wyrażona jest w stopniach.
   */
  double _Ang_Yaw_deg = 0;
  /*!
   * \brief Kąt \e pitch reprezentuje rotację zgodnie z ruchem wskazówek zegara
   *        wokół osi \e OY.
	 *
	 * Kąt \e pitch reprezentuje rotację zgodnie z ruchem wskazówek zegara
   * wokół osi \e OY. Wartość kąta wyrażona jest w stopniach.
   */
  double _Ang_Pitch_deg = 0;

  /*!
   * \brief Kąt \e roll reprezentuje rotację zgodnie z ruchem wskazówek zegara
   *        wokół osi \e OX.
	 *
	 * Kąt \e roll reprezentuje rotację zgodnie z ruchem wskazówek zegara
   * wokół osi \e OX. Wartość kąta wyrażona jest w stopniach.
   */
  double _Ang_Roll_deg = 0;

  /*!
   * \brief Współrzędne aktualnej pozycji obiektu.
	 *
	 * Współrzędne aktualnej pozycji obiektu. Przyjmuje się,
	 * że współrzędne wyrażone są w metrach.
   */
  Vector3D  _Position_m;

  /*!
   * \brief Współrzędne aktualnej pozycji obiektu.
	 *
	 * Współrzędne aktualnej pozycji obiektu. Przyjmuje się,
	 * że współrzędne wyrażone są w metrach.
   */
  Vector3D  _Size_m;

  /*!
   * \brief Kolor obiektu.
	 *
	 * Kolor obiektu w formacie RGB. Wartość dla każego koloru
   * reprezentuje liczba całkowita o wartości z przedziału [0, 255].
   */
  int _ColourRGB[3];


  /*!
   * \brief Nazwa obiektu, która go indentyfikuje.
   *
   * Nazwa obiektu, która go indentyfikuje. Z tego względu musi
   * musi to być nazwa unikalna wśród wszystkich obiektów na scenie.
   */
  std::string  _Name;

public:

  /*!
   * \brief Udostępia wartość kąta \e roll.
   *
   * Udostępia wartość kąta \e roll. Jest ona wyrażona w stopniach.
   */
  double GetAng_Roll_deg() const { return _Ang_Roll_deg; }
  /*!
   * \brief Udostępia wartość kąta \e pitch.
   *
   * Udostępia wartość kąta \e pitch. Jest ona wyrażona w stopniach.
   */
  double GetAng_Pitch_deg() const { return _Ang_Pitch_deg; }
  /*!
   * \brief Udostępia wartość kąta \e yaw.
   *
   * Udostępia wartość kąta \e yaw. Jest ona wyrażona w stopniach.
   */
  double GetAng_Yaw_deg() const { return _Ang_Yaw_deg; }

  /*!
   * \brief Zmienia wartość kąta \e roll.
   *
   * Zmienia wartość kąta \e roll.
   * \param[in] Ang_Roll_deg - nowa wartość kąta \e roll wyrażona w stopniach.
   */
  void SetAng_Roll_deg(double Ang_Roll_deg) { _Ang_Roll_deg = Ang_Roll_deg; }
  /*!
   * \brief Zmienia wartość kąta \e pitch.
   *
   * Zmienia wartość kąta \e pitch.
   * \param[in] Ang_Pitch_deg - nowa wartość kąta \e pitch wyrażona w stopniach.
   */
  void SetAng_Pitch_deg(double Ang_Pitch_deg) { _Ang_Pitch_deg = Ang_Pitch_deg; }
  /*!
   * \brief Zmienia wartość kąta \e yaw.
   *
   * Zmienia wartość kąta \e yaw.
   * \param[in] Ang_Yaw_deg - nowa wartość kąta \e yaw wyrażona w stopniach.
   */
  void SetAng_Yaw_deg(double Ang_Yaw_deg) { _Ang_Yaw_deg = Ang_Yaw_deg; }

  /*!
   * \brief Udostępnia współrzędne położenia obiektu w trybie tylko do odczytu.
   *
   * Udostępnia współrzędne punktu, który definiuje położenia obiektu
   * w trybie tylko do odczytu.
   * Domyślnie przyjmuje się, że jest to geometryczny środek bryły.
   */
  const Vector3D & GetPosition_m() const { return _Position_m; }
  /*!
   * \brief Udostępnia współrzędne położenia obiektu w trybie modyfikacji.
   *
   * Udostępnia współrzędne punktu, który definiuje położenia obiektu
   * w trybie modyfikacji.
   * Domyślnie przyjmuje się, że jest to geometryczny środek bryły.
   */
  Vector3D & UsePosition_m() { return _Position_m; }
  /*!
   * \brief Zmienia współrzędne położenia obiektu.
   *
   * Zmienia współrzędne punktu, który definiuje położenia obiektu.
   * Domyślnie przyjmuje się, że jest to geometryczny środek bryły.
   * \param[in] rPos_m - współrzędne nowgo położenia. Przyjmuje się,
   *                     że są one wyrażone w metrach.
   */
  void SetPosition_m(const Vector3D &rPos_m) {std::cout << "Pos" << '\n'; _Position_m = rPos_m; }

  /*!
   * \brief Zmienia współrzędne położenia obiektu.
   *
   * Zmienia współrzędne punktu, który definiuje położenia obiektu.
   * Domyślnie przyjmuje się, że jest to geometryczny środek bryły.
   * \param[in] rPos_m - współrzędne nowgo położenia. Przyjmuje się,
   *                     że są one wyrażone w metrach.
   */
  void SetSize_m(const Vector3D &rParamSize_m) {std::cout << "Siz" << '\n'; _Size_m = rParamSize_m; }

  /*!
   * \brief Udostępnia współrzędne położenia obiektu w trybie tylko do odczytu.
   *
   * Udostępnia współrzędne punktu, który definiuje położenia obiektu
   * w trybie tylko do odczytu.
   * Domyślnie przyjmuje się, że jest to geometryczny środek bryły.
   */
  const Vector3D & GetSize_m() const { return _Size_m; }

  /*!
   * \brief Zmienia kolor obiektu.
   *
   * Zmienia wartość koloru obiektu na wartość wczytaną ze zmiennej tekstowej
   * typu string. Wartości spoza dopuszczalnego zakresu [0, 255] sprowadzane są
   * odpowiednio do wartości maksymalnej lub minimalnej.
   * \pre Zmienna tekstowa zawiera zapis 3 wartości stałyvh, oddzielonych spacjami.
   *
   * \param[in] rColourRGB - zmienna string zawierająca wartości kolorów.
   */
  void SetColour(const std::string & rColourRGB)
  {
    std::istringstream streamColour(rColourRGB);
    int colR, colG, colB;
    streamColour >> colR >> colG >> colB;
    if(colR<=0) {_ColourRGB[0]=0;}
    else {
      if(colR>=255) _ColourRGB[0]=255;
      else _ColourRGB[0]=colR;
    }
    if(colG<=0) {_ColourRGB[1]=0;}
    else {
      if(colG>=255) _ColourRGB[1]=255;
      else _ColourRGB[1]=colG;
    }
    if(colB<=0) {_ColourRGB[2]=0;}
    else {
      if(colB>=255) _ColourRGB[2]=255;
      else _ColourRGB[2]=colB;
    }

  }
  /*!
   * \brief Zmienia kolor obiektu.
   *
   * Zmienia wartość koloru obiektu na wartość wczytaną z ciągu znaków tekstowych.
   * Wartości spoza dopuszczalnego zakresu [0, 255] sprowadzane są
   * odpowiednio do wartości maksymalnej lub minimalnej.
   * \pre Zmienna tekstowa zawiera zapis 3 wartości stałyvh, oddzielonych spacjami.
   *
   * \param[in] sColourRGB - ciąg znaków zawierający wartości kolorów.
   */
  void SetColour(char * sColourRGB)
  {
    std::istringstream streamColour;
    streamColour.str(sColourRGB);
    int colR, colG, colB;
    streamColour >> colR >> colG >> colB;
    if(colR<=0) {_ColourRGB[0]=0;}
    else {
      if(colR>=255) _ColourRGB[0]=255;
      else _ColourRGB[0]=colR;
    }
    if(colG<=0) {_ColourRGB[1]=0;}
    else {
      if(colG>=255) _ColourRGB[1]=255;
      else _ColourRGB[1]=colG;
    }
    if(colB<=0) {_ColourRGB[2]=0;}
    else {
      if(colB>=255) _ColourRGB[2]=255;
      else _ColourRGB[2]=colB;
    }
  }

  /*!
   * \brief Zmienia kolor obiektu.
   *
   * Zmienia wartość koloru obiektu na podane wartości
   * Wartości spoza dopuszczalnego zakresu [0, 255] sprowadzane są
   * odpowiednio do wartości maksymalnej lub minimalnej.
   *
   * \param[in] colR - wartość nasycenia dla koloru czerwonego.
   * \param[in] colG - wartość nasycenia dla koloru zielonego.
   * \param[in] colB - wartość nasycenia dla koloru niebieskiego.
   */
  void SetColour(int colR, int colG, int colB)
  {
    if(colR<=0) {_ColourRGB[0]=0;}
    else {
      if(colR>=255) _ColourRGB[0]=255;
      else _ColourRGB[0]=colR;
    }
    if(colG<=0) {_ColourRGB[1]=0;}
    else {
      if(colG>=255) _ColourRGB[1]=255;
      else _ColourRGB[1]=colG;
    }
    if(colB<=0) {_ColourRGB[2]=0;}
    else {
      if(colB>=255) _ColourRGB[2]=255;
      else _ColourRGB[2]=colB;
    }
  }

  /*!
   * \brief Zmienia nazwę obiektu.
   *
   *  Zmienia nazwę obiektu.
   *  \param[in] sName - nowa nazwa obiektu.
   */
  void SetName(const char* sName) { _Name = sName; }
  /*!
   * \brief Udostępnia nazwę obiektu.
	 *
	 * Udostępnia nazwę obiektu w trybie tylko do odczytu.
   */
  const std::string & GetName() const { return _Name; }

  /*!
   * \brief Generuje opis wyglądu obiektu
   *
   * Generuje opis obiektu dla serwera graficznego.
   * \return - Opis obiektu w formie polecenia dla serwera.
   */
  std::string GetStateDesc()
  {
    std::ostringstream descrStream;

    descrStream << "Cube"
         <<"  " <<_Size_m[0]<< " " <<_Size_m[1]<< " " <<_Size_m[2]
         <<"  " <<_Position_m[0]<< " " <<_Position_m[1]<< " " <<_Position_m[2]
         <<"  " <<GetAng_Roll_deg()<< " " <<GetAng_Pitch_deg()<< " " <<GetAng_Yaw_deg()
         <<"  " <<_ColourRGB[0]<< " " <<_ColourRGB[1]<< " " << _ColourRGB[2]
         << std::endl;

    return descrStream.str();
  }

};


#endif
