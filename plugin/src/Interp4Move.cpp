#include <iostream>
#include <cmath>
#include "Interp4Move.hh"

#define PI 3.14159265

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Move::CreateCmd();
}


/*!
 *
 */
Interp4Move::Interp4Move(): _Speed_mps(0), _Dist_m(0)
{}


/*!
 *
 */
void Interp4Move::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " "<< _ParName << " " << _Speed_mps <<" "<< _Dist_m << endl;
}


/*!
 *
 */
const char* Interp4Move::GetCmdName() const
{
  return "Move";
}


/*!
 *
 */
bool Interp4Move::ExecCmd(Scene * pScn) const
{
  std::shared_ptr<MobileObj> pObj;
  if(!pScn->FindMobileObject(_ParName,pObj))
  {
    std::cerr << "Nie znaleziono obiektu: " <<'\"'<< _ParName <<'\"' << " !!!" << std::endl;
    return false;
  }

  //Pozycja początkowa
  Vector3D initPos=pObj->GetPosition_m();

  //Kąt yaw
  double yaw_deg=pObj->GetAng_Yaw_deg();


  //Pozycja docelowa
  Vector3D destinationPos=initPos;
  destinationPos[0]+=_Dist_m*cos(PI*yaw_deg/180);
  destinationPos[1]+=_Dist_m*sin(PI*yaw_deg/180);

  //Wykonany obrót [deg]
  //double rotationMade_d=0;

  //Wektor tranformacji dla pojedynczego kroku
  Vector3D stepChange=initPos;
  stepChange[0]+=0.1*_Speed_mps*cos(PI*yaw_deg/180);
  stepChange[1]+=0.1*_Speed_mps*sin(PI*yaw_deg/180);

  //Granice ruchu do sprawdzenia
  Vector3D minPoint, maxPoint;
  for (int i=0;i<3;++i)
  {
    if(initPos[i]<=destinationPos[i])
    {
      minPoint[i]=initPos[i];
      maxPoint[i]=destinationPos[i];
    }
    else
    {
      maxPoint[i]=initPos[i];
      minPoint[i]=destinationPos[i];
    }
  }
  while (true) {
    pScn->LockAccess(); // Zamykamy dostęp do sceny, gdy wykonujemy
                             // modyfikacje na obiekcie.

    pObj->SetPosition_m(pObj->GetPosition_m()+stepChange);
    //Osiągnięto cel, zapobiega przekroczeniu
    if (!(pObj->GetPosition_m().IsInside(minPoint,maxPoint))) {
      pObj->SetPosition_m(destinationPos);
      pScn->MarkChange();
      pScn->UnlockAccess();
      break;
    }
    pScn->MarkChange();
    pScn->UnlockAccess();
    usleep(100000);
  }
  usleep(300000);
  return true;
}


/*!
 *
 */
bool Interp4Move::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >>_ParName >> _Speed_mps >>  _Dist_m;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Move::CreateCmd()
{
  return new Interp4Move();
}


/*!
 *
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  object_name  speed[m/s]  dist[m]" << endl;
}
