#include <iostream>
#include "Interp4Pause.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
 const char* GetCmdName(void);
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Pause::CreateCmd();
}


/*!
 *
 */
Interp4Pause::Interp4Pause(): _delay_ms(0)
{}


/*!
 *
 */
void Interp4Pause::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " "<< _delay_ms << endl;
}


/*!
 *
 */
const char* Interp4Pause::GetCmdName() const
{
  return "Pause";
}


/*!
 *
 */
bool Interp4Pause::ExecCmd(Scene * pScn) const
{

  pScn->LockAccess(); // Uniemożliwienie zmian w trakcie zamrożenia
  usleep(_delay_ms*1000);
  pScn->UnlockAccess();
  usleep(300000);

  return true;
}


/*!
 *
 */
bool Interp4Pause::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >>_delay_ms;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Pause::CreateCmd()
{
  return new Interp4Pause();
}


/*!
 *
 */
void Interp4Pause::PrintSyntax() const
{
  cout << "Pause  delay[ms]" << endl;
}
