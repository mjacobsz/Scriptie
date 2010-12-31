
#include <php/echo.h>
#include <php/echo.fws.h>
#include <runtime/ext/ext.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/* preface starts */
extern CallInfo ci_;
/* preface finishes */
Variant pm_php$echo_php(bool incOnce /* = false */, LVariableTable* variables /* = NULL */, Globals *globals /* = get_globals() */) {
  PSEUDOMAIN_INJECTION(run_init::echo.php, pm_php$echo_php);
  LVariableTable *gVariables __attribute__((__unused__)) = (LVariableTable *)g;
  echo(NAMSTR(s_ss39d70fa8, "Dit is een string\n"));
  return true;
} /* function */

///////////////////////////////////////////////////////////////////////////////
}
