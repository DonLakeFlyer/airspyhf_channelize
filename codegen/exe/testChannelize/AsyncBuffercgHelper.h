//
// Trial License - for use to evaluate programs for possible purchase as
// an end-user only.
// File: AsyncBuffercgHelper.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 21-Oct-2022 10:06:11
//

#ifndef ASYNCBUFFERCGHELPER_H
#define ASYNCBUFFERCGHELPER_H

// Include Files
#include "rtwtypes.h"
#include "testChannelize_internal_types.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace dsp {
namespace internal {
class AsyncBuffercgHelper {
public:
  static void ReadSamplesFromBuffer(const AsyncBuffercgHelper *obj,
                                    int numRowsCast,
                                    ::coder::array<creal32_T, 1U> &out,
                                    int *underrun, int *c);
  void matlabCodegenDestructor();
  void release();
  void releaseWrapper();
  ~AsyncBuffercgHelper();
  AsyncBuffercgHelper();

protected:
  void releaseImpl();

private:
  void SystemCore_delete();

public:
  boolean_T matlabCodegenIsDeleted;
  int isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_4 inputVarSize[1];
  int NumChannels;
  creal32_T Cache[98305];
  int CumulativeOverrun;
  int CumulativeUnderrun;
  int ReadPointer;
  int WritePointer;
  boolean_T AsyncBuffercgHelper_isInitialized;
};

} // namespace internal
} // namespace dsp
} // namespace coder

#endif
//
// File trailer for AsyncBuffercgHelper.h
//
// [EOF]
//
