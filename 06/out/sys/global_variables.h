
#ifndef __GENERATED_sys_global_variables_h3635be65__
#define __GENERATED_sys_global_variables_h3635be65__

#include <runtime/base/hphp.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////


// Class Forward Declarations

class GlobalVariables : public SystemGlobals {
DECLARE_SMART_ALLOCATION_NOCALLBACKS(GlobalVariables);
public:
  GlobalVariables();
  ~GlobalVariables();
  static GlobalVariables *Create() { return NEW(GlobalVariables)(); }
  static void Delete(GlobalVariables *p) { DELETE(GlobalVariables)(p); }
  static void OnThreadExit(GlobalVariables *p) {}
  static void initialize();

  virtual bool class_exists(const char *name);
  CallInfo* tgv_CallInfoPtr[1];
  ClassStaticsPtr tgv_ClassStaticsPtr[1];
  ObjectStaticCallbacks* tgv_ObjectStaticCallbacksPtr[1];
  Variant tgv_Variant[1];
  #define gvm_an_arr tgv_Variant[0]
  bool tgv_bool[2];
  #define run_pm_php$testinclude_php tgv_bool[0]
  #define run_pm_php$$home$marvin$school$hiphop$util$helper_php tgv_bool[1]

  // Global Array Wrapper Methods
  virtual ssize_t staticSize() const {
    return 13;
  }

  // LVariableTable Methods
  virtual CVarRef getRefByIdx(ssize_t idx, Variant &k);
  virtual ssize_t getIndex(const char *s, int64 prehash) const;
  virtual Variant &getImpl(CStrRef s);
  virtual bool exists(CStrRef s) const;
};

// Scalar Arrays
class ScalarArrays : public SystemScalarArrays {
public:
  static void initialize();
  static void initializeNamed();

  static StaticArray sa_[1];
};


LVariableTable *get_variable_table();

///////////////////////////////////////////////////////////////////////////////
}

#endif // __GENERATED_sys_global_variables_h3635be65__
