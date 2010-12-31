
#include <php/foo.h>
#include <php/foo.fws.h>
#include <runtime/ext/ext.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/* preface starts */
extern CallInfo ci_;
/* preface finishes */
Variant pm_php$foo_php(bool incOnce /* = false */, LVariableTable* variables /* = NULL */, Globals *globals /* = get_globals() */) {
  PSEUDOMAIN_INJECTION(run_init::foo.php, pm_php$foo_php);
  LVariableTable *gVariables __attribute__((__unused__)) = (LVariableTable *)g;
  echo(NAMSTR(s_ss29d0c58f, "Nu zit ik in Foo\n"));
  echo(NAMSTR(s_ss66d2232c, "\n"));
  return true;
} /* function */

///////////////////////////////////////////////////////////////////////////////
}
