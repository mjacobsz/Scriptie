
#include <runtime/base/hphp.h>
#include <sys/global_variables.h>
#include <sys/cpputil.h>

using namespace std;

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

#ifndef OMIT_JUMP_TABLE_GLOBAL_GETINDEX
ssize_t GlobalVariables::getIndex(const char* s, int64 hash) const {
  const GlobalVariables *g __attribute__((__unused__)) = this;
  if (hash < 0) hash = hash_string(s);
  switch (hash & 31) {
    case 1:
      HASH_INDEX(0x50645ABB5EE07801LL, "_POST", 4);
      break;
    case 3:
      HASH_INDEX(0x3760929554A51DA3LL, "_COOKIE", 5);
      HASH_INDEX(0x6649184C41356B03LL, "HTTP_RAW_POST_DATA", 10);
      HASH_INDEX(0x78E4782F5605B123LL, "an_int", 12);
      break;
    case 9:
      HASH_INDEX(0x0759FB4517508949LL, "_GET", 3);
      break;
    case 14:
      HASH_INDEX(0x14297F74B68B58EELL, "_SERVER", 2);
      HASH_INDEX(0x516FBD36FC674A0ELL, "_FILES", 6);
      break;
    case 15:
      HASH_INDEX(0x587FF01B02607E8FLL, "argv", 1);
      break;
    case 16:
      HASH_INDEX(0x7320B4E3FF243290LL, "_ENV", 7);
      break;
    case 17:
      HASH_INDEX(0x29DFC3A6DC027BD1LL, "_SESSION", 9);
      break;
    case 25:
      HASH_INDEX(0x532E5E517D32FCB9LL, "argc", 0);
      break;
    case 30:
      HASH_INDEX(0x066E259A1CC5B17ELL, "i", 13);
      break;
    case 31:
      HASH_INDEX(0x1F878FB806A18D3FLL, "_REQUEST", 8);
      HASH_INDEX(0x6359C77BCA89599FLL, "http_response_header", 11);
      break;
    default:
      break;
  }
  return m_px ? (m_px->getIndex(s) + 14) : -1;
}
#endif // OMIT_JUMP_TABLE_GLOBAL_GETINDEX

///////////////////////////////////////////////////////////////////////////////
}
