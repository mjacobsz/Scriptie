
#include <runtime/base/hphp.h>


using namespace std;

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

typedef Variant (*pm_t)(bool incOnce, LVariableTable* variables, Globals *globals);

// File Invoke Table
Variant pm_php$testinclude_php(bool incOnce = false, LVariableTable* variables = NULL, Globals *globals = get_globals());
Variant pm_php$$home$marvin$school$hiphop$util$helper_php(bool incOnce = false, LVariableTable* variables = NULL, Globals *globals = get_globals());

class hashNodeFile {
public:
  hashNodeFile() {}
  hashNodeFile(int64 h, const char *n, const void *p) :
    hash(h), name(n), ptr(p), next(NULL) {}
  int64 hash;
  const char *name;
  const void *ptr;
  hashNodeFile *next;
};
static hashNodeFile *fileMapTable[4];
static hashNodeFile fileBuckets[2];

static class FileTableInitializer {
  public: FileTableInitializer() {
    const char *fileMapData[] = {
      (const char *)"testinclude.php", (const char *)&pm_php$testinclude_php,
      (const char *)"/home/marvin/school/hiphop/util/helper.php", (const char *)&pm_php$$home$marvin$school$hiphop$util$helper_php,
      NULL, NULL,
    };
    hashNodeFile *b = fileBuckets;
    for (const char **s = fileMapData; *s; s++, b++) {
      const char *name = *s++;
      const void *ptr = *s;
      int64 hash = hash_string(name, strlen(name));
      hashNodeFile *node = new(b) hashNodeFile(hash, name, ptr);
      int h = hash & 3;
      if (fileMapTable[h]) node->next = fileMapTable[h];
      fileMapTable[h] = node;
    }
  }
} file_table_initializer;

static inline pm_t findFile(const char *name, int64 hash) {
  for (const hashNodeFile *p = fileMapTable[hash & 3 ]; p; p = p->next) {
    if (p->hash == hash && !strcmp(p->name, name)) return (pm_t)p->ptr;
  }
  return NULL;
}

Variant invoke_file(CStrRef s, bool once /* = false */, LVariableTable* variables /* = NULL */,const char *currentDir /* = NULL */) {
  pm_t ptr = findFile(s.c_str(), s->hash());
  if (ptr) return ptr(once, variables, get_globals());
  return throw_missing_file(s.c_str());
}

///////////////////////////////////////////////////////////////////////////////
}
