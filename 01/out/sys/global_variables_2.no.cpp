
#include <runtime/base/hphp.h>
#include <sys/global_variables.h>
#include <sys/cpputil.h>
#include <sys/literal_strings.h>

using namespace std;

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

#ifndef OMIT_JUMP_TABLE_GLOBAL_EXISTS
bool GlobalVariables::exists(CStrRef s) const {
  const GlobalVariables *g __attribute__((__unused__)) = this;
  int64 hash = s->hash();
  switch (hash & 31) {
    case 1:
      HASH_INITIALIZED_NAMSTR(0x50645ABB5EE07801LL, s_ss5ee07801, g->GV(_POST),
                         5);
      break;
    case 3:
      HASH_INITIALIZED_NAMSTR(0x3760929554A51DA3LL, s_ss54a51da3, g->GV(_COOKIE),
                         7);
      HASH_INITIALIZED_NAMSTR(0x6649184C41356B03LL, s_ss41356b03, g->GV(HTTP_RAW_POST_DATA),
                         18);
      break;
    case 9:
      HASH_INITIALIZED_NAMSTR(0x0759FB4517508949LL, s_ss17508949, g->GV(_GET),
                         4);
      HASH_INITIALIZED_NAMSTR(0x230E7AD147721D89LL, s_ss47721d89, g->GV(end),
                         3);
      break;
    case 10:
      HASH_INITIALIZED_NAMSTR(0x15F2515C40B2980ALL, s_ss40b2980a, g->GV(elapsed_time),
                         12);
      break;
    case 14:
      HASH_INITIALIZED_NAMSTR(0x14297F74B68B58EELL, s_ss4974a712, g->GV(_SERVER),
                         7);
      HASH_INITIALIZED_NAMSTR(0x516FBD36FC674A0ELL, s_ss0398b5f2, g->GV(_FILES),
                         6);
      break;
    case 15:
      HASH_INITIALIZED_NAMSTR(0x587FF01B02607E8FLL, s_ss02607e8f, g->GV(argv),
                         4);
      break;
    case 16:
      HASH_INITIALIZED_NAMSTR(0x7320B4E3FF243290LL, s_ss00dbcd70, g->GV(_ENV),
                         4);
      break;
    case 17:
      HASH_INITIALIZED_NAMSTR(0x29DFC3A6DC027BD1LL, s_ss23fd842f, g->GV(_SESSION),
                         8);
      break;
    case 25:
      HASH_INITIALIZED_NAMSTR(0x532E5E517D32FCB9LL, s_ss7d32fcb9, g->GV(argc),
                         4);
      break;
    case 29:
      HASH_INITIALIZED_NAMSTR(0x35F78B4D0532F99DLL, s_ss0532f99d, g->GV(begin),
                         5);
      break;
    case 31:
      HASH_INITIALIZED_NAMSTR(0x1F878FB806A18D3FLL, s_ss06a18d3f, g->GV(_REQUEST),
                         8);
      HASH_INITIALIZED_NAMSTR(0x6359C77BCA89599FLL, s_ss3576a661, g->GV(http_response_header),
                         20);
      break;
    default:
      break;
  }
  if (!LVariableTable::exists(s)) return false;
  return isInitialized(const_cast<GlobalVariables*>(this)->get(s));
}
#endif // OMIT_JUMP_TABLE_GLOBAL_EXISTS

///////////////////////////////////////////////////////////////////////////////
}
