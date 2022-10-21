//
// Trial License - for use to evaluate programs for possible purchase as
// an end-user only.
// File: Channelizer.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 21-Oct-2022 10:06:11
//

#ifndef CHANNELIZER_H
#define CHANNELIZER_H

// Include Files
#include "rtwtypes.h"
#include "testChannelize_internal_types.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace dsp {
class Channelizer {
public:
  void step(const ::coder::array<creal32_T, 1U> &varargin_1,
            ::coder::array<creal32_T, 2U> &varargout_1);
  void matlabCodegenDestructor();
  void release();
  void releaseWrapper();
  ~Channelizer();
  Channelizer();

protected:
  void releaseImpl();

private:
  void SystemCore_delete();

public:
  boolean_T matlabCodegenIsDeleted;
  int isInitialized;
  short numChannels;

protected:
  creal32_T States[576];
  float PolyphaseMatrix[576];
  float actpmatrix[576];
  int ModuloIdx;
  int StartIdx[48];
  int StopIdx[48];

private:
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_4 inputVarSize[1];
  creal32_T vextra[48];
  float NTPB;
  float numStates;
  int phaseIdx;
  int currentState;
  boolean_T Halideflag;
};

} // namespace dsp
} // namespace coder

#endif
//
// File trailer for Channelizer.h
//
// [EOF]
//
