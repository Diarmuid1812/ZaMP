#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include "xmlinterp.hh"
#include "Configuration.hh"

/*!
 * \file
 * \brief Zawiera definicję klasy Sender oraz funkcje do komunikacji.
 *
 * Plik zawiera klasę Sender i inne funkcje służące do komunikacji z serwerem graficznym.
 */

/*!
 * \brief Wczytuje konfigurację z pliku XML
 *
 * Wczytuje z pliku w formacie XML konfigurację programu,
 * zawierającą nazwy bibliotek do wczytania oraz listę obiektów
 * mobilnych na scenie wraz z ich parametrami.
 * \param sFileName - (\b we.) nazwa pliku konfiguracyjnego.
 * \param rConfig - (\b wy.) klasa, przechowująca wczytaną konfigurację.
 * \retval true - jeśli wczytanie zostało zrealizowane poprawnie,
 * \retval false - w przeciwnym przypadku.
 */
bool ReadFile(const char* sFileName, Configuration &rConfig);
