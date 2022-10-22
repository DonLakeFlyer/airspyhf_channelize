//
// Trial License - for use to evaluate programs for possible purchase as
// an end-user only.
// File: testChannelize_initialize.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 21-Oct-2022 17:09:12
//

// Include Files
#include "testChannelize_initialize.h"
#include "CoderTimeAPI.h"
#include "testChannelize_data.h"
#include "timeKeeper.h"
#include "omp.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void testChannelize_initialize()
{
  omp_init_nest_lock(&testChannelize_nestLockGlobal);
  savedTime_not_empty_init();
  freq_not_empty_init();
  isInitialized_testChannelize = true;
}

//
// File trailer for testChannelize_initialize.cpp
//
// [EOF]
//
