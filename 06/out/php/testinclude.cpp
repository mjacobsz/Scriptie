
#include <php//home/marvin/school/hiphop/util/helper.h>
#include <php/testinclude.h>
#include <php//home/marvin/school/hiphop/util/helper.fws.h>
#include <php/testinclude.fws.h>
#include <runtime/ext/ext.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/* preface starts */
extern CallInfo ci_;
/* preface finishes */
Variant pm_php$testinclude_php(bool incOnce /* = false */, LVariableTable* variables /* = NULL */, Globals *globals /* = get_globals() */) {
  PSEUDOMAIN_INJECTION(run_init::testinclude.php, pm_php$testinclude_php);
  LVariableTable *gVariables __attribute__((__unused__)) = (LVariableTable *)g;
  Variant &v_an_arr __attribute__((__unused__)) = (variables != gVariables) ? variables->get(NAMSTR(s_ss39df3d61, "an_arr")) : g->GV(an_arr);

  v_an_arr = s_sa34df475a;
  LINE(8,f_print_arr(v_an_arr));
  return true;
} /* function */

///////////////////////////////////////////////////////////////////////////////
}
