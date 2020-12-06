#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <sstream>
#include <string>
#include <cstdio>
#include <memory>
#include <thread>
#include "Interp4Command.hh"
#include "Set4Libinterfaces.hh"
#include "XML_ReadFile.hh"
#include "Configuration.hh"
#include "Port.hh"
#include "Scene.hh"
#include "ServerConnection.hh"


using namespace std;

#define LINE_SIZE 500

/*!
 * \brief Wykonuje preprocesor na podanym pliku.
 *
 * Funkcja wpisuje do zawartość podanego pliku, po interpretacji przez
 * preprocesor języka C.
 * \param[in] NazwaPliku - Nazwa pliku do interpratacji.
 * \param[out] IStrm4Cmds - Strumień, do któregoi wczytywana jest zinterpretowana zawartość.
 * \retval true - jeśli preprocesor został wykonany poprawnie, a plik został zamknięy.
 * \retval false - przy niepowodzeniu wykonania.
 */

bool ExecPreprocesor(const   char * NazwaPliku, istringstream & IStrm4Cmds )
{
  string Cmd4Preproc = "cpp -P ";
  char Line[LINE_SIZE];
  ostringstream OTmpStrm;
  Cmd4Preproc += NazwaPliku;
  FILE * pProc = popen(Cmd4Preproc.c_str(),"r");
  if(!pProc)
    return false;
  while(fgets(Line,LINE_SIZE,pProc)){
    OTmpStrm<<Line;
  }
  IStrm4Cmds.str(OTmpStrm.str());
  return pclose(pProc) == 0;
}

/*!
 * \brief Wykonuje polecenia ze strumienia.
 *
 * Funkcja wykonuje polecenia wczytane ze strumienia, wykorzystując
 * do tego odpowiednią bibliotekę.
 * \param[in] rIStrm - Strumień zawierający polecenie.
 * \param[in] LibInterfaceSet - zestaw bibliotek,
 *                              umożliwiających wykonanie polecenia.
 * \param[in,out] pScn - wskażnik na scenę,
 *                       dla której wykonywane jest polecenie.
 * \retval true - jeśli polecenie zostało wykonane poprawnie.
 * \retval false - przy niepowodzeniu wykonania.
 */
bool ExecActions(istream & rIStrm, Set4Libinterfaces &LibInterfaceSet, Scene * pScn)
{
  string CmdKey;

  while(rIStrm >> CmdKey)
  {
    cout << "Polecenie:" << CmdKey << endl;

    Set4Libinterfaces::const_iterator Iter = LibInterfaceSet.find(CmdKey);
    if (Iter == LibInterfaceSet.end()) {
      cout << "Nieznana komenda: " << CmdKey << endl;
      return false;
    }

    Interp4Command *pInterp = Iter->second->_pCreateCmd();
    if(!pInterp->ReadParams(rIStrm))
    {
      cout << "Nie można wczytać parametrów" << endl;
      delete pInterp;
      return false;
    }
    cout << "------Parametry:--------" << endl;
    pInterp->PrintCmd();

    if(!pInterp->ExecCmd(pScn))
    {
      cout << "Błąd wykonywania polecenia" << endl;
      delete pInterp;
      return false;
    }
    cout << endl;
    delete pInterp;
  }
  return true;
}

int main(int argc, char **argv)
{

  Set4Libinterfaces LibInterfaceSet;

  Configuration   Config;

  if (!ReadFile("config/config.xml", Config))
  {
    return 1;
  }

  try{
      std::vector<string> LibList = Config.getLibList();


      for(const string& sLibNameI : LibList){
        shared_ptr<LibInterface> pLibI = make_shared<LibInterface>(sLibNameI);
        LibInterfaceSet.insert(pair<string,shared_ptr<LibInterface>>(pLibI->GetCmdName(),pLibI));
      }
    }
  catch(int e)
    {
      cerr << "Wyjątek nr " << e << endl;
      if(e==LIB_LOAD_EXCEPTION)
      {
        cerr << "Nie można wczytać biblioteki" << endl;
        return 1;
      }
    }
  if(argc<2){
    std::cerr << "Too few parameters" <<endl;
    return 1;
  }

  istringstream IStrm4Cmds;

  if(!ExecPreprocesor(argv[1],IStrm4Cmds))
  {
    cerr << "Błąd wykonywania preprocesora!" <<endl;
    return 2;
  }

  cout << endl << endl << IStrm4Cmds.str() << endl << endl;


  cout << "Port: " << PORT << endl;
  Scene               Scn;
  int                 Socket4Sending;

  Scn.configureScene(Config);
  shared_ptr<MobileObj> pObj;
  std::cout << "Check" << Scn.FindMobileObject("obj1", pObj) << '\n';

  if (!OpenConnection(Socket4Sending))
  {
    cerr << "Nie można połączyć z serwerem!" << endl;
    return 3;
  }

  Sender   ClientSender(Socket4Sending,&Scn);

  thread   Thread4Sending(Fun_CommunicationThread,&ClientSender);

  if(!ExecActions(IStrm4Cmds, LibInterfaceSet, &Scn))
  {
    cerr << "Nie można wykonać polecenia!" <<endl;
    return 4;
  }



  //-------------------------------------
  // Należy pamiętać o zamknięciu połączenia.
  // Bez tego serwer nie będzie reagował na
  // nowe połączenia.
  //
  Send(Socket4Sending,"Close\n");
  ClientSender.CancelCountinueLooping();
  Thread4Sending.join();
  close(Socket4Sending);
  //-------------------------------------

  return 0;
}
