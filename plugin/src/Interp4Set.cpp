#include <iostream>
#include <memory>
#include "Interp4Set.hh"

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
  return Interp4Set::CreateCmd();
}


/*!
 *
 */
Interp4Set::Interp4Set(): _PosX_m(0), _PosY_m(0), _rotZ_deg(0)
{}


/*!
 *
 */
void Interp4Set::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " "<< _PosX_m << " " << _PosY_m <<" "<< _rotZ_deg << endl;
}


/*!
 *
 */
const char* Interp4Set::GetCmdName() const
{
  return "Set";
}


/*!
 *
 */
bool Interp4Set::ExecCmd(Scene * pScn) const
{
  pScn->UnlockAccess();
  pScn->LockAccess(); // Zamykamy dostęp do sceny, gdy wykonujemy
                           // modyfikacje na obiekcie.
  std::shared_ptr<MobileObj> pObj;
  if(!pScn->FindMobileObject(_ParName, pObj))
  {
    pScn->UnlockAccess();
    std::cerr << "Nie znaleziono obiektu: " <<'\"'<< _ParName <<'\"' << " !!!" << std::endl;
    return false;
  }
  Vector3D positionVector;
  positionVector[0]=_PosX_m;
  positionVector[1]=_PosY_m;
  positionVector[2]=pObj->GetPosition_m()[2];
  pObj->SetPosition_m(positionVector);
  pObj->SetAng_Yaw_deg(_rotZ_deg);
  /*if (!pObj->SetPosition_m(positionVector))
  {
    pScn->UnlockAccess();
    return false;
  }
  if (!pObj->SetAng_Yaw_deg(_rotZ_deg))
  {
    pScn->UnlockAccess();
    return false;
  }*/
  pScn->MarkChange();
  pScn->UnlockAccess();
  usleep(300000);

  return true;
}


/*!
 *
 */
bool Interp4Set::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >> _ParName >>_PosX_m >> _PosY_m  >>  _rotZ_deg;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Set::CreateCmd()
{
  return new Interp4Set();
}


/*!
 *
 */
void Interp4Set::PrintSyntax() const
{
  cout << "   Set  object_name  position_x[m] position_y[m] rotation_angle_OZ[deg]" << endl;
}
