//
// Trial License - for use to evaluate programs for possible purchase as
// an end-user only.
// File: testChannelize_terminate.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 21-Oct-2022 17:09:12
//

// Include Files
#include "testChannelize_terminate.h"
#include "testChannelize_data.h"
#include "omp.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void testChannelize_terminate()
{
  omp_destroy_nest_lock(&testChannelize_nestLockGlobal);
  isInitialized_testChannelize = false;
}

//
// File trailer for testChannelize_terminate.cpp
//
// [EOF]
//
