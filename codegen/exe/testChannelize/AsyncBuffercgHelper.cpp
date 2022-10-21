//
// Trial License - for use to evaluate programs for possible purchase as
// an end-user only.
// File: AsyncBuffercgHelper.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 21-Oct-2022 10:06:11
//

// Include Files
#include "AsyncBuffercgHelper.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace coder {
namespace dsp {
namespace internal {
void AsyncBuffercgHelper::SystemCore_delete()
{
  release();
}

//
// Arguments    : void
// Return Type  : void
//
void AsyncBuffercgHelper::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    SystemCore_delete();
  }
}

//
// Arguments    : void
// Return Type  : void
//
void AsyncBuffercgHelper::release()
{
  if (isInitialized == 1) {
    isInitialized = 2;
    releaseWrapper();
  }
}

//
// Arguments    : void
// Return Type  : void
//
void AsyncBuffercgHelper::releaseImpl()
{
  ReadPointer = 1;
  WritePointer = 2;
  CumulativeOverrun = 0;
  CumulativeUnderrun = 0;
  AsyncBuffercgHelper_isInitialized = false;
  NumChannels = -1;
}

//
// Arguments    : void
// Return Type  : void
//
void AsyncBuffercgHelper::releaseWrapper()
{
  if (isSetupComplete) {
    releaseImpl();
  }
}

//
// Arguments    : const AsyncBuffercgHelper *obj
//                int numRowsCast
//                ::coder::array<creal32_T, 1U> &out
//                int *underrun
//                int *c
// Return Type  : void
//
void AsyncBuffercgHelper::ReadSamplesFromBuffer(
    const AsyncBuffercgHelper *obj, int numRowsCast,
    ::coder::array<creal32_T, 1U> &out, int *underrun, int *c)
{
  array<int, 2U> readIdx;
  array<int, 2U> y;
  int b_qY;
  int k;
  int n;
  int qY;
  int rPtr;
  int wPtr;
  int yk;
  wPtr = obj->WritePointer;
  qY = 0;
  n = obj->ReadPointer;
  if (n > 2147483646) {
    rPtr = MAX_int32_T;
  } else {
    rPtr = n + 1;
  }
  if (rPtr > 98305) {
    rPtr = 1;
  }
  if ((rPtr < 0) && (numRowsCast < MIN_int32_T - rPtr)) {
    b_qY = MIN_int32_T;
  } else if ((rPtr > 0) && (numRowsCast > MAX_int32_T - rPtr)) {
    b_qY = MAX_int32_T;
  } else {
    b_qY = rPtr + numRowsCast;
  }
  if (b_qY < -2147483647) {
    b_qY = MIN_int32_T;
  } else {
    b_qY--;
  }
  *c = b_qY;
  if (b_qY > 98305) {
    *c = b_qY - 98305;
    n = 98306 - rPtr;
    readIdx.set_size(1, 98306 - rPtr);
    readIdx[0] = rPtr;
    yk = rPtr;
    for (k = 2; k <= n; k++) {
      yk++;
      readIdx[k - 1] = yk;
    }
    y.set_size(1, b_qY - 98305);
    y[0] = 1;
    yk = 1;
    for (k = 2; k <= *c; k++) {
      yk++;
      y[k - 1] = yk;
    }
    yk = readIdx.size(1);
    readIdx.set_size(1, readIdx.size(1) + y.size(1));
    n = y.size(1);
    for (k = 0; k < n; k++) {
      readIdx[k + yk] = y[k];
    }
    if (rPtr <= wPtr) {
      if (wPtr < -2147385342) {
        qY = MAX_int32_T;
      } else {
        qY = 98305 - wPtr;
      }
      if (qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY++;
      }
      if ((qY < 0) && (b_qY - 98305 < MIN_int32_T - qY)) {
        qY = MIN_int32_T;
      } else if ((qY > 0) && (b_qY - 98305 > MAX_int32_T - qY)) {
        qY = MAX_int32_T;
      } else {
        qY = (qY + b_qY) - 98305;
      }
    } else if (wPtr <= b_qY - 98305) {
      if (wPtr < b_qY + 2147385344) {
        b_qY = MAX_int32_T;
      } else {
        b_qY = (b_qY - wPtr) - 98305;
      }
      if (b_qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = b_qY + 1;
      }
    }
  } else {
    if (b_qY < rPtr) {
      n = 0;
    } else {
      n = (b_qY - rPtr) + 1;
    }
    readIdx.set_size(1, n);
    if (n > 0) {
      readIdx[0] = rPtr;
      yk = rPtr;
      for (k = 2; k <= n; k++) {
        yk++;
        readIdx[k - 1] = yk;
      }
    }
    if ((rPtr <= wPtr) && (wPtr <= b_qY)) {
      if ((b_qY >= 0) && (wPtr < b_qY - MAX_int32_T)) {
        b_qY = MAX_int32_T;
      } else if ((b_qY < 0) && (wPtr > b_qY - MIN_int32_T)) {
        b_qY = MIN_int32_T;
      } else {
        b_qY -= wPtr;
      }
      if (b_qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = b_qY + 1;
      }
    }
  }
  out.set_size(readIdx.size(1));
  n = readIdx.size(1);
  for (yk = 0; yk < n; yk++) {
    out[yk] = obj->Cache[readIdx[yk] - 1];
  }
  if (qY != 0) {
    if ((numRowsCast >= 0) && (qY < numRowsCast - MAX_int32_T)) {
      b_qY = MAX_int32_T;
    } else if ((numRowsCast < 0) && (qY > numRowsCast - MIN_int32_T)) {
      b_qY = MIN_int32_T;
    } else {
      b_qY = numRowsCast - qY;
    }
    if (b_qY > 2147483646) {
      b_qY = MAX_int32_T;
    } else {
      b_qY++;
    }
    if (b_qY > numRowsCast) {
      b_qY = 1;
    }
    for (yk = 0; yk < qY; yk++) {
      k = (b_qY + yk) - 1;
      out[k].re = 0.0F;
      out[k].im = 0.0F;
    }
  }
  *underrun = qY;
}

//
// Arguments    : void
// Return Type  : AsyncBuffercgHelper
//
AsyncBuffercgHelper::AsyncBuffercgHelper()
{
  matlabCodegenIsDeleted = true;
}

//
// Arguments    : void
// Return Type  : void
//
AsyncBuffercgHelper::~AsyncBuffercgHelper()
{
  matlabCodegenDestructor();
}

} // namespace internal
} // namespace dsp
} // namespace coder

//
// File trailer for AsyncBuffercgHelper.cpp
//
// [EOF]
//
