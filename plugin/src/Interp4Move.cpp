#include <iostream>
#include "Interp4Move.hh"

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
bool Interp4Move::ExecCmd( DronPose     *pRobPose,  Visualization *pVis) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
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
