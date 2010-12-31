
#include <runtime/base/hphp.h>
#include <sys/global_variables.h>


using namespace std;

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////


// Get Constant Table
Variant get_constant(CStrRef name) {
  DECLARE_GLOBAL_VARIABLES(g);
  return get_builtin_constant(name);
}

///////////////////////////////////////////////////////////////////////////////
}
