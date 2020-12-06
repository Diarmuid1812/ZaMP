#include "ServerConnection.hh"


int Send(int Sk2Server, const char *sMesg)
{
  ssize_t  IlWyslanych;
  ssize_t  IlDoWyslania = (ssize_t) strlen(sMesg);

  while ((IlWyslanych = write(Sk2Server,sMesg,IlDoWyslania)) > 0) {
    IlDoWyslania -= IlWyslanych;
    sMesg += IlWyslanych;
  }
  if (IlWyslanych < 0) {
    cerr << "*** Blad przeslania napisu." << endl;
  }
  return 0;
}

void Sender::Watching_and_Sending() {
  std::string msg;
  while (ShouldCountinueLooping()) {
    if (!_pScn->IsChanged())  { usleep(10000); continue; }
    _pScn->LockAccess();

    //------- Przeglądanie tej kolekcji to uproszczony przykład

    Send(_Socket,"Clear\n"); // To jest konieczne, aby usunąć wcześniejsze obiekty.
    cout << "Clear\n";
    shared_ptr<MobileObj>pObj;
    for (std::string &objName : _pScn->getObjList()) {
      _pScn->FindMobileObject(objName,pObj); //except

      msg =  pObj->GetStateDesc();
      Send(_Socket,msg.c_str());
      cout << msg.c_str();
    }
    Send(_Socket,"Display\n"); // To jest konieczne, aby zobaczyć zmiany
    cout << "Display\n";

    _pScn->CancelChange();
    _pScn->UnlockAccess();
  }
}


bool OpenConnection(int &rSocket)
{
  struct sockaddr_in  DaneAdSerw;

  bzero((char *)&DaneAdSerw,sizeof(DaneAdSerw));

  DaneAdSerw.sin_family = AF_INET;
  DaneAdSerw.sin_addr.s_addr = inet_addr("127.0.0.1");
  DaneAdSerw.sin_port = htons(PORT);


  rSocket = socket(AF_INET,SOCK_STREAM,0);

  if (rSocket < 0) {
     cerr << "*** Blad otwarcia gniazda." << endl;
     return false;
  }

  if (connect(rSocket,(struct sockaddr*)&DaneAdSerw,sizeof(DaneAdSerw)) < 0)
   {
     cerr << "*** Brak mozliwosci polaczenia do portu: " << PORT << endl;
     return false;
   }
  return true;
}

void Fun_CommunicationThread(Sender  *pSender)
{
  pSender->Watching_and_Sending();
}
