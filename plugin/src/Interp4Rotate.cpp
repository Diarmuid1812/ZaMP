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
bool Interp4Rotate::ExecCmd( DronPose     *pRobPose,  Visualization *pVis) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
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
