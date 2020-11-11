#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <sstream>
#include <string>
#include <cstdio>
#include <memory>
#include "Interp4Command.hh"
#include "Set4Libinterfaces.hh"

using namespace std;

#define LINE_SIZE 500

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

bool ExecActions(istream & rIStrm, Set4Libinterfaces &LibInterfaceSet)
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
    cout << endl;
    delete pInterp;
  }
  return true;
}

int main(int argc, char **argv)
{

  Set4Libinterfaces LibInterfaceSet;

  try{
      string LibNames[4] = {"Interp4Move.so","Interp4Pause.so","Interp4Rotate.so","Interp4Set.so"};

      for(int i=0; i<4;++i){
        shared_ptr<LibInterface> pLibI = make_shared<LibInterface>(LibNames[i]);
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


  if(!ExecActions(IStrm4Cmds, LibInterfaceSet))
  {
    cerr << "Nie można wykonać polecenia!" <<endl;
    return 3;
  }


  return 0;
}
