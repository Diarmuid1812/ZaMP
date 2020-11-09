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

bool ExecActions(istream & rIStrm, Set4Libinterfaces &LibInterfaceSet)//Interp4Command &rInterp
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
  /*if(CmdKey == "Fly"){
    if(!rInterp.ReadParams(rIStrm)) return false;
    cout << "------Parametry:--------" << endl;
    rInterp.PrintCmd();
    return true;
  }
  else{
    cout << "Nieznana komenda" << endl;
  }*/

}

int main(int argc, char **argv)
{

  Set4Libinterfaces LibInterfaceSet;
/*
  void *pLibHnd_Fly = dlopen("Interp4Fly.so",RTLD_LAZY);

  Interp4Command *(*pCreateCmd_Fly)(void);
  void *pFun;


  if (!pLibHnd_Fly) {
    cerr << "!!! Brak biblioteki: Interp4Fly.so" << endl;
    return 1;
  }

  pFun = dlsym(pLibHnd_Fly,"CreateCmd");
  if (!pFun) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }

  pCreateCmd_Fly = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);

  Interp4Command *pInterp = pCreateCmd_Fly();
*/
  try{
    shared_ptr<LibInterface> pLibMoveI = make_shared<LibInterface>("Interp4Move.so");
    shared_ptr<LibInterface> pLibPauseI = make_shared<LibInterface>("Interp4Pause.so");
    shared_ptr<LibInterface> pLibRotateI = make_shared<LibInterface>("Interp4Rotate.so");
    shared_ptr<LibInterface> pLibSetI = make_shared<LibInterface>("Interp4Set.so");



  LibInterfaceSet.insert(pair<string,shared_ptr<LibInterface>>(pLibMoveI->GetCName(),pLibMoveI));
  LibInterfaceSet.insert(pair<string,shared_ptr<LibInterface>>(pLibPauseI->GetCName(),pLibPauseI));
  LibInterfaceSet.insert(pair<string,shared_ptr<LibInterface>>(pLibRotateI->GetCName(),pLibRotateI));
  LibInterfaceSet.insert(pair<string,shared_ptr<LibInterface>>(pLibSetI->GetCName(),pLibSetI));


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

  cout << IStrm4Cmds.str() << endl;


  if(!ExecActions(IStrm4Cmds, LibInterfaceSet))//*pInterp)
  {
    cerr << "Nie można wykonać polecenia!" <<endl;
    return 3;
  }
/*
  delete pInterp;

  dlclose(pLibHnd_Fly);
*/
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
  return 0;
}
