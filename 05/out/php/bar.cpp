
#include <php/bar.h>
#include <php/bar.fws.h>
#include <runtime/ext/ext.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/* preface starts */
extern CallInfo ci_;
/* preface finishes */
Variant pm_php$bar_php(bool incOnce /* = false */, LVariableTable* variables /* = NULL */, Globals *globals /* = get_globals() */) {
  PSEUDOMAIN_INJECTION(run_init::bar.php, pm_php$bar_php);
  LVariableTable *gVariables __attribute__((__unused__)) = (LVariableTable *)g;
  echo(NAMSTR(s_ss7d48369f, "Nu zit ik in Bar\n"));
  echo(NAMSTR(s_ss66d2232c, "\n"));
  return true;
} /* function */

///////////////////////////////////////////////////////////////////////////////
}
