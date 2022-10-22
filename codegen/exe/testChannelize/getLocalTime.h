//
// Trial License - for use to evaluate programs for possible purchase as
// an end-user only.
// File: getLocalTime.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 21-Oct-2022 17:09:12
//

#ifndef GETLOCALTIME_H
#define GETLOCALTIME_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace time {
void getLocalTime(double *t_tm_nsec, double *t_tm_sec, double *t_tm_min,
                  double *t_tm_hour, double *t_tm_mday, double *t_tm_mon,
                  double *t_tm_year, boolean_T *t_tm_isdst);

}
} // namespace internal
} // namespace coder

#endif
//
// File trailer for getLocalTime.h
//
// [EOF]
//
