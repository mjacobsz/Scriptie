
#include <runtime/base/hphp.h>
#include <sys/global_variables.h>


using namespace std;

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////


// Function Invoke Table
Variant Eval::invoke_from_eval(const char *s, Eval::VariableEnvironment &env, const Eval::FunctionCallExpression *caller, int64 hash, bool fatal) {
  return invoke_from_eval_builtin(s, env, caller, hash, fatal);
}
extern CallInfo ci_foo;
bool get_call_info(const CallInfo *&ci, void *&extra, const char *s, int64 hash) {
  extra = NULL;
  if (hash < 0) hash = hash_string(s);
  switch (hash & 1) {
    case 0:
      HASH_GUARD(0x6176C0B993BF5914LL, foo) {
        ci = &ci_foo;
        return true;
      }
      break;
    default:
      break;
  }
  return get_call_info_builtin(ci, extra, s, hash);
}

///////////////////////////////////////////////////////////////////////////////
}
