
#include <php/../../util/helper.h>
#include <php/../../util/helper.fws.h>
#include <runtime/ext/ext.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/* preface starts */
extern CallInfo ci_print_arr;
extern CallInfo ci_;
/* preface finishes */
/* SRC: ../../util/helper.php line 3 */
void f_print_arr(CVarRef v_the_arr) {
  FUNCTION_INJECTION(print_arr);
  INTERCEPT_INJECTION("print_arr", (Array(ArrayInit(1, true).set(0, v_the_arr).create())), r);
  String v_to_print;
  Variant v_element;

  v_to_print = NAMSTR(s_ss00000000, "");
  {
    LOOP_COUNTER(1);
    for (ArrayIterPtr iter3 = v_the_arr.begin(null_string, true); !iter3->end(); iter3->next()) {
      LOOP_COUNTER_CHECK(1);
      iter3->second(v_element);
      {
        v_to_print = concat3(v_to_print, toString(v_element), NAMSTR(s_ss00000000_1, " "));
      }
    }
  }
  v_to_print = concat(v_to_print, NAMSTR(s_ss66d2232c, "\n"));
  print(v_to_print);
} /* function */
Variant i_print_arr(void *extra, CArrRef params) {
  int count __attribute__((__unused__)) = params.size();
  if (count < 1) throw_missing_arguments("print_arr", count+1);
  {
    ArrayData *ad(params.get());
    ssize_t pos = ad ? ad->iter_begin() : ArrayData::invalid_index;
    CVarRef arg0(count <= 0 ? null_variant : (ad->getValue(pos)));
    return (f_print_arr(arg0), null);
  }
}
Variant ifa_print_arr(void *extra, int count, INVOKE_FEW_ARGS_IMPL_ARGS) {
  if (count < 1) throw_missing_arguments("print_arr", count+1);
  return (f_print_arr(a0), null);
}
CallInfo ci_print_arr((void*)&i_print_arr, (void*)&ifa_print_arr, 1, 0, 0x0000000000000000LL);
Variant pm_php$__$__$util$helper_php(bool incOnce /* = false */, LVariableTable* variables /* = NULL */, Globals *globals /* = get_globals() */) {
  PSEUDOMAIN_INJECTION(run_init::../../util/helper.php, pm_php$__$__$util$helper_php);
  LVariableTable *gVariables __attribute__((__unused__)) = (LVariableTable *)g;
  return true;
} /* function */

///////////////////////////////////////////////////////////////////////////////
}
