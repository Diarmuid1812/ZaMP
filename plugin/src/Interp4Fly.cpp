#include <iostream>
#include "Interp4Fly.hh"

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
  return Interp4Fly::CreateCmd();
}


/*!
 *
 */
Interp4Fly::Interp4Fly(): _Speed_Hor_mmS(0), _Speed_Ver_mmS(0), _Dist_mm(0)
{}


/*!
 *
 */
void Interp4Fly::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " " << _Speed_Hor_mmS <<" " <<_Speed_Ver_mmS <<" " <<  _Dist_mm << endl;
}


/*!
 *
 */
const char* Interp4Fly::GetCmdName() const
{
  return "Fly";
}


/*!
 *
 */
bool Interp4Fly::ExecCmd( DronPose     *pRobPose,  Visualization *pVis) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
bool Interp4Fly::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >>_Speed_Hor_mmS >> _Speed_Ver_mmS  >>  _Dist_mm;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Fly::CreateCmd()
{
  return new Interp4Fly();
}


/*!
 *
 */
void Interp4Fly::PrintSyntax() const
{
  cout << "   Fly  hor_speed[m/s]  ver_speed[m/s]  dist[m]" << endl;
}
