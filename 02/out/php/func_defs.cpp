
#include <php/func_defs.h>
#include <php/func_defs.fws.h>
#include <runtime/ext/ext.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/* preface starts */
extern CallInfo ci_;
extern CallInfo ci_foo;
/* preface finishes */
/* SRC: func_defs.php line 3 */
void f_foo() {
  FUNCTION_INJECTION(foo);
  INTERCEPT_INJECTION("foo", null_array, r);
  echo(NAMSTR(s_ss3b2fb7e7, "Foo\n"));
} /* function */
Variant i_foo(void *extra, CArrRef params) {
  int count __attribute__((__unused__)) = params.size();
  return (f_foo(), null);
}
Variant ifa_foo(void *extra, int count, INVOKE_FEW_ARGS_IMPL_ARGS) {
  return (f_foo(), null);
}
CallInfo ci_foo((void*)&i_foo, (void*)&ifa_foo, 0, 0, 0x0000000000000000LL);
Variant pm_php$func_defs_php(bool incOnce /* = false */, LVariableTable* variables /* = NULL */, Globals *globals /* = get_globals() */) {
  PSEUDOMAIN_INJECTION(run_init::func_defs.php, pm_php$func_defs_php);
  LVariableTable *gVariables __attribute__((__unused__)) = (LVariableTable *)g;
  return true;
} /* function */

///////////////////////////////////////////////////////////////////////////////
}
