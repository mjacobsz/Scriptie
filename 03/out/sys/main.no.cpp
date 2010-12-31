
#include <runtime/base/hphp.h>
#include <sys/global_variables.h>
#include <sys/cpputil.h>

using namespace std;

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////


IMPLEMENT_SMART_ALLOCATION_NOCALLBACKS(GlobalVariables)
GlobalVariables::GlobalVariables() {
  memset(&tgv_bool, 0, sizeof(tgv_bool));
  memset(&tgv_CallInfoPtr, 0, sizeof(tgv_CallInfoPtr));
  memset(&tgv_ObjectStaticCallbacksPtr, 0, sizeof(tgv_ObjectStaticCallbacksPtr));

  // Primitive Function/Method Static Variables

  // Primitive Class Static Variables

  // Redeclared Classes
}

void GlobalVariables::initialize() {
  SystemGlobals::initialize();
}

void init_static_variables() {
  ScalarArrays::initialize();
  StaticString::FinishInit();
}
static ThreadLocalSingleton<GlobalVariables> g_variables;
static IMPLEMENT_THREAD_LOCAL(GlobalArrayWrapper, g_array_wrapper);
GlobalVariables *get_global_variables() {
  return g_variables.get();
}
void init_global_variables() {
  ThreadInfo::s_threadInfo->m_globals =
    get_global_variables();
  GlobalVariables::initialize();
}
void free_global_variables() {
  g_variables.reset();
  g_array_wrapper.reset();
}
LVariableTable *get_variable_table() { return (LVariableTable*)get_global_variables();}
Globals *get_globals() { return (Globals*)get_global_variables();}
SystemGlobals *get_system_globals() { return (SystemGlobals*)get_global_variables();}
Array get_global_array_wrapper(){ return g_array_wrapper.get();}

///////////////////////////////////////////////////////////////////////////////
}

#ifndef HPHP_BUILD_LIBRARY
int main(int argc, char** argv) {
  return HPHP::execute_program(argc, argv);
}
#endif
