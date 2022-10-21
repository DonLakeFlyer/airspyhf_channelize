//
// Trial License - for use to evaluate programs for possible purchase as
// an end-user only.
// File: AsyncBuffer.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 21-Oct-2022 10:06:11
//

// Include Files
#include "AsyncBuffer.h"
#include "AsyncBuffercgHelper.h"
#include "testChannelize_internal_types.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace coder {
namespace dsp {
void AsyncBuffer::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
  }
}

//
// Arguments    : void
// Return Type  : AsyncBuffer
//
AsyncBuffer::AsyncBuffer()
{
  matlabCodegenIsDeleted = true;
}

//
// Arguments    : void
// Return Type  : void
//
AsyncBuffer::~AsyncBuffer()
{
  matlabCodegenDestructor();
}

//
// Arguments    : void
// Return Type  : void
//
void AsyncBuffer::read()
{
  array<creal32_T, 1U> b_out;
  array<creal32_T, 1U> out;
  int c;
  int q0_tmp;
  int q1_tmp;
  int qY;
  int underrun;
  q0_tmp = pBuffer.WritePointer;
  q1_tmp = pBuffer.ReadPointer;
  if ((q0_tmp >= 0) && (q1_tmp < q0_tmp - MAX_int32_T)) {
    qY = MAX_int32_T;
  } else if ((q0_tmp < 0) && (q1_tmp > q0_tmp - MIN_int32_T)) {
    qY = MIN_int32_T;
  } else {
    qY = q0_tmp - q1_tmp;
  }
  if (qY < -2147483647) {
    qY = MIN_int32_T;
  } else {
    qY--;
  }
  if (q1_tmp < -2147385343) {
    q1_tmp = MAX_int32_T;
  } else {
    q1_tmp = 98304 - q1_tmp;
  }
  if ((q1_tmp < 0) && (q0_tmp < MIN_int32_T - q1_tmp)) {
    q1_tmp = MIN_int32_T;
  } else if ((q1_tmp > 0) && (q0_tmp > MAX_int32_T - q1_tmp)) {
    q1_tmp = MAX_int32_T;
  } else {
    q1_tmp += q0_tmp;
  }
  if (pBuffer.ReadPointer < pBuffer.WritePointer) {
    q1_tmp = qY;
  } else if (pBuffer.ReadPointer == pBuffer.WritePointer) {
    q1_tmp = 98304;
  }
  internal::AsyncBuffercgHelper::ReadSamplesFromBuffer(&pBuffer, q1_tmp, out,
                                                       &underrun, &c);
  b_out.set_size(out.size(0));
  q1_tmp = out.size(0);
  for (q0_tmp = 0; q0_tmp < q1_tmp; q0_tmp++) {
    b_out[q0_tmp] = out[q0_tmp];
  }
  q1_tmp = pBuffer.WritePointer;
  if (q1_tmp < -2147483647) {
    qY = MIN_int32_T;
  } else {
    qY = q1_tmp - 1;
  }
  q1_tmp = pBuffer.CumulativeUnderrun;
  if ((q1_tmp < 0) && (underrun < MIN_int32_T - q1_tmp)) {
    q1_tmp = MIN_int32_T;
  } else if ((q1_tmp > 0) && (underrun > MAX_int32_T - q1_tmp)) {
    q1_tmp = MAX_int32_T;
  } else {
    q1_tmp += underrun;
  }
  pBuffer.CumulativeUnderrun = q1_tmp;
  if (underrun != 0) {
    pBuffer.ReadPointer = qY;
  } else {
    pBuffer.ReadPointer = c;
  }
}

//
// Arguments    : void
// Return Type  : void
//
void AsyncBuffer::write()
{
  internal::AsyncBuffercgHelper *obj;
  array<int, 2U> y;
  array<int, 1U> r;
  int b_qY;
  int i;
  int k;
  int qY;
  int rPtr;
  int wPtr;
  boolean_T exitg1;
  obj = &pBuffer;
  if (pBuffer.isInitialized != 1) {
    cell_wrap_4 varSizes;
    pBuffer.isSetupComplete = false;
    pBuffer.isInitialized = 1;
    for (wPtr = 0; wPtr < 8; wPtr++) {
      varSizes.f1[wPtr] = 1U;
    }
    pBuffer.inputVarSize[0] = varSizes;
    pBuffer.NumChannels = 1;
    pBuffer.AsyncBuffercgHelper_isInitialized = true;
    for (i = 0; i < 98305; i++) {
      pBuffer.Cache[i].re = 0.0F;
      pBuffer.Cache[i].im = 0.0F;
    }
    pBuffer.isSetupComplete = true;
    pBuffer.ReadPointer = 1;
    pBuffer.WritePointer = 2;
    pBuffer.CumulativeOverrun = 0;
    pBuffer.CumulativeUnderrun = 0;
    for (i = 0; i < 98305; i++) {
      pBuffer.Cache[i].re = 0.0F;
      pBuffer.Cache[i].im = 0.0F;
    }
  }
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (obj->inputVarSize[0].f1[k] != 1U) {
      for (wPtr = 0; wPtr < 8; wPtr++) {
        obj->inputVarSize[0].f1[wPtr] = 1U;
      }
      exitg1 = true;
    } else {
      k++;
    }
  }
  wPtr = pBuffer.WritePointer;
  rPtr = pBuffer.ReadPointer;
  qY = 0;
  if (wPtr > 2147483646) {
    b_qY = MAX_int32_T;
  } else {
    b_qY = wPtr + 1;
  }
  if ((wPtr <= rPtr) && (rPtr <= b_qY - 1)) {
    if ((b_qY - 1 >= 0) && (rPtr < b_qY + MIN_int32_T)) {
      qY = MAX_int32_T;
    } else if ((b_qY - 1 < 0) && (rPtr > b_qY + MAX_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY = (b_qY - rPtr) - 1;
    }
    if (qY > 2147483646) {
      qY = MAX_int32_T;
    } else {
      qY++;
    }
  }
  if (b_qY - 1 < wPtr) {
    i = 0;
  } else {
    i = b_qY - wPtr;
  }
  y.set_size(1, i);
  if (i > 0) {
    y[0] = wPtr;
    for (k = 2; k <= i; k++) {
      wPtr++;
      y[k - 1] = wPtr;
    }
  }
  r.set_size(y.size(1));
  i = y.size(1);
  for (wPtr = 0; wPtr < i; wPtr++) {
    r[wPtr] = y[wPtr];
  }
  i = r.size(0);
  for (wPtr = 0; wPtr < i; wPtr++) {
    pBuffer.Cache[r[wPtr] - 1].re = 1.0F;
    pBuffer.Cache[r[wPtr] - 1].im = 1.0F;
  }
  if (b_qY > 98305) {
    wPtr = 1;
  } else {
    wPtr = b_qY;
  }
  if (qY != 0) {
    rPtr = wPtr;
  }
  i = pBuffer.CumulativeOverrun;
  if ((i < 0) && (qY < MIN_int32_T - i)) {
    b_qY = MIN_int32_T;
  } else if ((i > 0) && (qY > MAX_int32_T - i)) {
    b_qY = MAX_int32_T;
  } else {
    b_qY = i + qY;
  }
  pBuffer.CumulativeOverrun = b_qY;
  pBuffer.WritePointer = wPtr;
  pBuffer.ReadPointer = rPtr;
}

//
// Arguments    : const creal32_T in[1024]
// Return Type  : void
//
void AsyncBuffer::write(const creal32_T in[1024])
{
  static const short inSize[8]{1024, 1, 1, 1, 1, 1, 1, 1};
  static const short iv[8]{1024, 1, 1, 1, 1, 1, 1, 1};
  internal::AsyncBuffercgHelper *obj;
  array<int, 2U> bc;
  array<int, 2U> y;
  array<int, 1U> r;
  int b_qY;
  int c;
  int i;
  int k;
  int qY;
  int rPtr;
  int wPtr;
  int yk;
  boolean_T exitg1;
  obj = &pBuffer;
  if (pBuffer.isInitialized != 1) {
    cell_wrap_4 varSizes;
    pBuffer.isSetupComplete = false;
    pBuffer.isInitialized = 1;
    for (yk = 0; yk < 8; yk++) {
      varSizes.f1[yk] = static_cast<unsigned int>(inSize[yk]);
    }
    pBuffer.inputVarSize[0] = varSizes;
    pBuffer.NumChannels = 1;
    pBuffer.AsyncBuffercgHelper_isInitialized = true;
    for (i = 0; i < 98305; i++) {
      pBuffer.Cache[i].re = 0.0F;
      pBuffer.Cache[i].im = 0.0F;
    }
    pBuffer.isSetupComplete = true;
    pBuffer.ReadPointer = 1;
    pBuffer.WritePointer = 2;
    pBuffer.CumulativeOverrun = 0;
    pBuffer.CumulativeUnderrun = 0;
    for (i = 0; i < 98305; i++) {
      pBuffer.Cache[i].re = 0.0F;
      pBuffer.Cache[i].im = 0.0F;
    }
  }
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (obj->inputVarSize[0].f1[k] != static_cast<unsigned int>(iv[k])) {
      for (yk = 0; yk < 8; yk++) {
        obj->inputVarSize[0].f1[yk] = static_cast<unsigned int>(inSize[yk]);
      }
      exitg1 = true;
    } else {
      k++;
    }
  }
  wPtr = pBuffer.WritePointer;
  rPtr = pBuffer.ReadPointer;
  qY = 0;
  if (wPtr > 2147482623) {
    b_qY = MAX_int32_T;
  } else {
    b_qY = wPtr + 1024;
  }
  c = b_qY - 1;
  if (b_qY - 1 > 98305) {
    c = b_qY - 98306;
    i = 98306 - wPtr;
    bc.set_size(1, 98306 - wPtr);
    bc[0] = wPtr;
    yk = wPtr;
    for (k = 2; k <= i; k++) {
      yk++;
      bc[k - 1] = yk;
    }
    y.set_size(1, b_qY - 98306);
    y[0] = 1;
    yk = 1;
    for (k = 2; k <= c; k++) {
      yk++;
      y[k - 1] = yk;
    }
    yk = bc.size(1);
    bc.set_size(1, bc.size(1) + y.size(1));
    i = y.size(1);
    for (k = 0; k < i; k++) {
      bc[k + yk] = y[k];
    }
    if (wPtr <= rPtr) {
      if (rPtr < -2147385342) {
        qY = MAX_int32_T;
      } else {
        qY = 98305 - rPtr;
      }
      if (qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY++;
      }
      if ((qY < 0) && (b_qY - 98306 < MIN_int32_T - qY)) {
        qY = MIN_int32_T;
      } else if ((qY > 0) && (b_qY - 98306 > MAX_int32_T - qY)) {
        qY = MAX_int32_T;
      } else {
        qY = (qY + b_qY) - 98306;
      }
    } else if (rPtr <= b_qY - 98306) {
      if (rPtr < b_qY + 2147385343) {
        b_qY = MAX_int32_T;
      } else {
        b_qY = (b_qY - rPtr) - 98306;
      }
      if (b_qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = b_qY + 1;
      }
    }
  } else {
    if (b_qY - 1 < wPtr) {
      i = 0;
    } else {
      i = b_qY - wPtr;
    }
    bc.set_size(1, i);
    if (i > 0) {
      bc[0] = wPtr;
      yk = wPtr;
      for (k = 2; k <= i; k++) {
        yk++;
        bc[k - 1] = yk;
      }
    }
    if ((wPtr <= rPtr) && (rPtr <= b_qY - 1)) {
      if ((b_qY - 1 >= 0) && (rPtr < b_qY + MIN_int32_T)) {
        b_qY = MAX_int32_T;
      } else if ((b_qY - 1 < 0) && (rPtr > b_qY + MAX_int32_T)) {
        b_qY = MIN_int32_T;
      } else {
        b_qY = (b_qY - rPtr) - 1;
      }
      if (b_qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = b_qY + 1;
      }
    }
  }
  r.set_size(bc.size(1));
  i = bc.size(1);
  for (yk = 0; yk < i; yk++) {
    r[yk] = bc[yk] - 1;
  }
  i = r.size(0);
  for (yk = 0; yk < i; yk++) {
    pBuffer.Cache[r[yk]] = in[yk];
  }
  if (c + 1 > 98305) {
    wPtr = 1;
  } else {
    wPtr = c + 1;
  }
  if (qY != 0) {
    rPtr = wPtr;
  }
  i = pBuffer.CumulativeOverrun;
  if ((i < 0) && (qY < MIN_int32_T - i)) {
    b_qY = MIN_int32_T;
  } else if ((i > 0) && (qY > MAX_int32_T - i)) {
    b_qY = MAX_int32_T;
  } else {
    b_qY = i + qY;
  }
  pBuffer.CumulativeOverrun = b_qY;
  pBuffer.WritePointer = wPtr;
  pBuffer.ReadPointer = rPtr;
}

} // namespace dsp
} // namespace coder

//
// File trailer for AsyncBuffer.cpp
//
// [EOF]
//
