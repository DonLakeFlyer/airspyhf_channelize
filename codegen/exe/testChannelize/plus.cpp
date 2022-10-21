//
// Trial License - for use to evaluate programs for possible purchase as
// an end-user only.
// File: plus.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 21-Oct-2022 10:06:11
//

// Include Files
#include "plus.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const creal_T a
//                double b
// Return Type  : creal_T
//
namespace coder {
namespace matlab {
namespace internal {
namespace coder {
namespace doubledouble {
creal_T plus(const creal_T a, double b)
{
  creal_T c;
  double ahi;
  double b_slo;
  double bb;
  double shi;
  double slo;
  int trueCount;
  shi = a.re + b;
  bb = shi - a.re;
  slo = (a.re - (shi - bb)) + (b - bb);
  trueCount = 0;
  if (std::isnan(slo)) {
    trueCount = 1;
  }
  for (int i{0}; i < trueCount; i++) {
    slo = 0.0;
  }
  bb = a.im - a.im;
  b_slo = (a.im - (a.im - bb)) + (0.0 - bb);
  trueCount = 0;
  if (std::isnan(b_slo)) {
    trueCount = 1;
  }
  for (int i{0}; i < trueCount; i++) {
    b_slo = 0.0;
  }
  ahi = shi;
  if (a.im != 0.0) {
    slo += a.im;
    ahi = shi + slo;
    slo -= ahi - shi;
  }
  if (std::isnan(slo)) {
    slo = 0.0;
  }
  bb = ahi;
  if (b_slo != 0.0) {
    slo += b_slo;
    bb = ahi + slo;
    slo -= bb - ahi;
  }
  if (std::isnan(slo)) {
    slo = 0.0;
  }
  c.re = bb;
  c.im = slo;
  return c;
}

} // namespace doubledouble
} // namespace coder
} // namespace internal
} // namespace matlab
} // namespace coder

//
// File trailer for plus.cpp
//
// [EOF]
//
