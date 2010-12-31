
#include <runtime/base/hphp.h>
#include <sys/global_variables.h>


using namespace std;

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////


// Function Invoke Table
Variant Eval::invoke_from_eval(const char *s, Eval::VariableEnvironment &env, const Eval::FunctionCallExpression *caller, int64 hash, bool fatal) {
  return invoke_from_eval_builtin(s, env, caller, hash, fatal);
}
bool get_call_info(const CallInfo *&ci, void *&extra, const char *s, int64 hash) {
  extra = NULL;
  return get_call_info_builtin(ci, extra, s, hash);
}

///////////////////////////////////////////////////////////////////////////////
}
