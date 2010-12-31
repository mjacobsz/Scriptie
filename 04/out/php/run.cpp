
#include <php/run.h>
#include <php/run.fws.h>
#include <runtime/ext/ext.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/* preface starts */
extern CallInfo ci_;
/* preface finishes */
Variant pm_php$run_php(bool incOnce /* = false */, LVariableTable* variables /* = NULL */, Globals *globals /* = get_globals() */) {
  PSEUDOMAIN_INJECTION(run_init::run.php, pm_php$run_php);
  LVariableTable *gVariables __attribute__((__unused__)) = (LVariableTable *)g;
  Variant &v_an_int __attribute__((__unused__)) = (variables != gVariables) ? variables->get(NAMSTR(s_ss5605b123, "an_int")) : g->GV(an_int);
  Variant &v_i __attribute__((__unused__)) = (variables != gVariables) ? variables->get(NAMSTR(s_ss1cc5b17e, "i")) : g->GV(i);

  v_an_int = 0LL;
  {
    LOOP_COUNTER(1);
    for (v_i = 0LL; (less(v_i, 100LL)); v_i++) {
      LOOP_COUNTER_CHECK(1);
      {
        v_an_int += 1LL;
      }
    }
  }
  return true;
} /* function */

///////////////////////////////////////////////////////////////////////////////
}
