
#include <runtime/base/hphp.h>
#include <sys/global_variables.h>
#include <sys/cpputil.h>

using namespace std;

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

CVarRef GlobalVariables::getRefByIdx(ssize_t idx, Variant &k) {
  GlobalVariables *g __attribute__((__unused__)) = this;
  static const char *names[] = {
    "argc",
    "argv",
    "_SERVER",
    "_GET",
    "_POST",
    "_COOKIE",
    "_FILES",
    "_ENV",
    "_REQUEST",
    "_SESSION",
    "HTTP_RAW_POST_DATA",
    "http_response_header",
  };
  if (idx >= 0 && idx < 12) {
    k = names[idx];
    switch (idx) {
    case 0: return GV(argc);
    case 1: return GV(argv);
    case 2: return GV(_SERVER);
    case 3: return GV(_GET);
    case 4: return GV(_POST);
    case 5: return GV(_COOKIE);
    case 6: return GV(_FILES);
    case 7: return GV(_ENV);
    case 8: return GV(_REQUEST);
    case 9: return GV(_SESSION);
    case 10: return GV(HTTP_RAW_POST_DATA);
    case 11: return GV(http_response_header);
    }
  }
  return Globals::getRefByIdx(idx, k);
}

///////////////////////////////////////////////////////////////////////////////
}
