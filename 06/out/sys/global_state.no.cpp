
#include <runtime/base/hphp.h>
#include <sys/global_variables.h>
#include <sys/cpputil.h>

using namespace std;

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

static void get_static_global_variables(Array &res) {
  DECLARE_GLOBAL_VARIABLES(g);
  Array static_global_variables;
  static_global_variables.set("gv_argc", g->GV(argc));
  static_global_variables.set("gv_argv", g->GV(argv));
  static_global_variables.set("gv__SERVER", g->GV(_SERVER));
  static_global_variables.set("gv__GET", g->GV(_GET));
  static_global_variables.set("gv__POST", g->GV(_POST));
  static_global_variables.set("gv__COOKIE", g->GV(_COOKIE));
  static_global_variables.set("gv__FILES", g->GV(_FILES));
  static_global_variables.set("gv__ENV", g->GV(_ENV));
  static_global_variables.set("gv__REQUEST", g->GV(_REQUEST));
  static_global_variables.set("gv__SESSION", g->GV(_SESSION));
  static_global_variables.set("gv_HTTP_RAW_POST_DATA", g->GV(HTTP_RAW_POST_DATA));
  static_global_variables.set("gv_http_response_header", g->GV(http_response_header));
  static_global_variables.set("gv_an_arr", g->GV(an_arr));
  res.set("static_global_variables", static_global_variables);
}

static void get_dynamic_global_variables(Array &res) {
  DECLARE_GLOBAL_VARIABLES(g);
  Array dynamic_global_variables;
  dynamic_global_variables = *get_variable_table();
  res.set("dynamic_global_variables", dynamic_global_variables);
}

static void get_method_static_variables(Array &res) {
  DECLARE_GLOBAL_VARIABLES(g);
  Array method_static_variables;
  res.set("method_static_variables", method_static_variables);
}

static void get_method_static_inited(Array &res) {
  DECLARE_GLOBAL_VARIABLES(g);
  Array method_static_inited;
  res.set("method_static_inited", method_static_inited);
}

static void get_class_static_variables(Array &res) {
  DECLARE_GLOBAL_VARIABLES(g);
  Array class_static_variables;
  res.set("class_static_variables", class_static_variables);
}

static void get_dynamic_constants(Array &res) {
  DECLARE_GLOBAL_VARIABLES(g);
  Array dynamic_constants;
  dynamic_constants.set("k_SID", g->k_SID);
  res.set("dynamic_constants", dynamic_constants);
}

static void get_pseudomain_variables(Array &res) {
  DECLARE_GLOBAL_VARIABLES(g);
  Array pseudomain_variables;
  pseudomain_variables.set("run_pm_php$testinclude_php", g->run_pm_php$testinclude_php);
  pseudomain_variables.set("run_pm_php$$home$marvin$school$hiphop$util$helper_php", g->run_pm_php$$home$marvin$school$hiphop$util$helper_php);
  res.set("pseudomain_variables", pseudomain_variables);
}

static void get_redeclared_functions(Array &res) {
  DECLARE_GLOBAL_VARIABLES(g);
  Array redeclared_functions;
  res.set("redeclared_functions", redeclared_functions);
}

static void get_redeclared_classes(Array &res) {
  DECLARE_GLOBAL_VARIABLES(g);
  Array redeclared_classes;
  res.set("redeclared_classes", redeclared_classes);
}

Array get_global_state() {
  Array res(Array::Create());
  get_static_global_variables(res);
  get_dynamic_global_variables(res);
  get_dynamic_constants(res);
  get_method_static_variables(res);
  get_method_static_inited(res);
  get_class_static_variables(res);
  get_pseudomain_variables(res);
  get_redeclared_functions(res);
  get_redeclared_classes(res);
  return res;
}


///////////////////////////////////////////////////////////////////////////////
}
