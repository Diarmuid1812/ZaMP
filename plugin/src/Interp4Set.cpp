#include <iostream>
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
bool Interp4Set::ExecCmd( MobileObj  *pMobObj, int Socket) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
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
