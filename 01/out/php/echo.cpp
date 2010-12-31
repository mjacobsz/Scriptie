
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
  Variant &v_begin __attribute__((__unused__)) = (variables != gVariables) ? variables->get(NAMSTR(s_ss0532f99d, "begin")) : g->GV(begin);
  Variant &v_end __attribute__((__unused__)) = (variables != gVariables) ? variables->get(NAMSTR(s_ss47721d89, "end")) : g->GV(end);
  Variant &v_elapsed_time __attribute__((__unused__)) = (variables != gVariables) ? variables->get(NAMSTR(s_ss40b2980a, "elapsed_time")) : g->GV(elapsed_time);

  {
    LINE(3,0);
    const Variant &tmp1((x_microtime(true)));
    v_begin = tmp1;
  }
  echo(NAMSTR(s_ss6527707f, "Bonjour, Monde!"));
  {
    LINE(8,0);
    const Variant &tmp2((x_microtime(true)));
    v_end = tmp2;
  }
  v_elapsed_time = (v_end - v_begin);
  {
    print(NAMSTR(s_ss5b2434a3, "Elapsed time: "));
    print(toString(v_elapsed_time));
    ;
  }
  return true;
} /* function */

///////////////////////////////////////////////////////////////////////////////
}
