#ifndef VSA_RESULT_VALUE_H_
#define VSA_RESULT_VALUE_H_

#include "../fixpoint/state.h"
#include "../util/util.h"
#include "llvm/Analysis/LazyValueInfo.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/ADT/APSInt.h"
#include <stdlib.h>

#include "../util/util.h"

using namespace llvm;

namespace pcpo {
class VsaResultValue {

public:
  VsaResultValue(std::shared_ptr<AbstractDomain> abstractValue)
      : abstractValue(abstractValue) {}

  /// compare abstract value with a constant int
  /// \param predicate
  /// \param C constant (please be aware that we only support ConstantInt)
  /// \return 
  LazyValueInfo::Tristate testIf(CmpInst::Predicate predicate, Constant *C);

  bool isConstant();
  APInt getConstant();
  APInt getNumValues();

  /// Values > uint64_t not working
  APInt getValueAt(uint64_t i);
  APInt getUMin();
  APSInt getSMin();
  APInt getUMax();
  APSInt getSMax();

private:
  std::shared_ptr<AbstractDomain> abstractValue;
};
}

#endif