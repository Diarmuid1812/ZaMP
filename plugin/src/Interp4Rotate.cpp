#include <iostream>
#include "Interp4Rotate.hh"

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
  return Interp4Rotate::CreateCmd();
}


/*!
 *
 */
Interp4Rotate::Interp4Rotate(): _angVelocity_degps(0), _angleRot_deg(0)
{}


/*!
 *
 */
void Interp4Rotate::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " "<< _ParName << " " << _angVelocity_degps <<" "<< _angleRot_deg << endl;
}


/*!
 *
 */
const char* Interp4Rotate::GetCmdName() const
{
  return "Rotate";
}


/*!
 *
 */
bool Interp4Rotate::ExecCmd(Scene * pScn) const
{


  std::shared_ptr<MobileObj> pObj;
  if(!pScn->FindMobileObject(_ParName,pObj))
  {
    std::cerr << "Nie znaleziono obiektu: " <<'\"'<< _ParName <<'\"' << " !!!" << std::endl;
    return false;
  }

  //Kąt docelowy [deg]
  double destinationAng_d=pObj->GetAng_Yaw_deg() + _angleRot_deg;
  //Wykonany obrót [deg]
  double rotationMade_d=0;

  while (true) {
    pScn->LockAccess(); // Zamykamy dostęp do sceny, gdy wykonujemy
                             // modyfikacje na obiekcie.
    rotationMade_d+=_angVelocity_degps;
    pObj->SetAng_Yaw_deg(pObj->GetAng_Yaw_deg()+0.1*_angVelocity_degps);
    //Osiągnięto cel, zapobiega przekroczeniu
    if (rotationMade_d > _angleRot_deg) {
      pObj->SetAng_Yaw_deg(destinationAng_d);
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
bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >>_ParName >> _angVelocity_degps  >>  _angleRot_deg;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Rotate::CreateCmd()
{
  return new Interp4Rotate();
}


/*!
 *
 */
void Interp4Rotate::PrintSyntax() const
{
  cout << "   Rotate  object_name  angular_velovity[deg/s]  rotation_angle[deg]" << endl;
}
