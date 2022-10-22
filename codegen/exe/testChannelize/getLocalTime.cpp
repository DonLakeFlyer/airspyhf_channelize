//
// Trial License - for use to evaluate programs for possible purchase as
// an end-user only.
// File: getLocalTime.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 21-Oct-2022 17:09:12
//

// Include Files
#include "getLocalTime.h"
#include "coder_posix_time.h"

// Function Definitions
//
// Arguments    : double *t_tm_nsec
//                double *t_tm_sec
//                double *t_tm_min
//                double *t_tm_hour
//                double *t_tm_mday
//                double *t_tm_mon
//                double *t_tm_year
//                boolean_T *t_tm_isdst
// Return Type  : void
//
namespace coder {
namespace internal {
namespace time {
void getLocalTime(double *t_tm_nsec, double *t_tm_sec, double *t_tm_min,
                  double *t_tm_hour, double *t_tm_mday, double *t_tm_mon,
                  double *t_tm_year, boolean_T *t_tm_isdst)
{
  coderTm structTm;
  coderLocalTime(&structTm);
  *t_tm_nsec = (double)structTm.tm_nsec;
  *t_tm_sec = structTm.tm_sec;
  *t_tm_min = structTm.tm_min;
  *t_tm_hour = structTm.tm_hour;
  *t_tm_mday = structTm.tm_mday;
  *t_tm_mon = structTm.tm_mon;
  *t_tm_year = structTm.tm_year;
  *t_tm_isdst = (structTm.tm_isdst != 0);
}

} // namespace time
} // namespace internal
} // namespace coder

//
// File trailer for getLocalTime.cpp
//
// [EOF]
//
