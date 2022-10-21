//
// Trial License - for use to evaluate programs for possible purchase as
// an end-user only.
// File: FFTImplementationCallback.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 21-Oct-2022 10:06:11
//

// Include Files
#include "FFTImplementationCallback.h"
#include "coder_array.h"
#include "omp.h"
#include <cstring>

// Function Definitions
//
// Arguments    : const ::coder::array<creal32_T, 2U> &x
//                ::coder::array<creal32_T, 2U> &y
// Return Type  : void
//
namespace coder {
namespace internal {
namespace fft {
void FFTImplementationCallback::dobluesteinfft(
    const ::coder::array<creal32_T, 2U> &x, ::coder::array<creal32_T, 2U> &y)
{
  static const creal32_T wwc[95]{{
                                     0.997858942F, // re
                                     0.0654031336F // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     0.831469595F, // re
                                     0.555570245F  // im
                                 },
                                 {
                                     0.49999997F, // re
                                     0.866025448F // im
                                 },
                                 {
                                     -0.0654031634F, // re
                                     0.997858942F    // im
                                 },
                                 {
                                     -0.707106769F, // re
                                     0.707106769F   // im
                                 },
                                 {
                                     -0.997858882F, // re
                                     -0.0654033199F // im
                                 },
                                 {
                                     -0.499999911F, // re
                                     -0.866025448F  // im
                                 },
                                 {
                                     0.555570424F, // re
                                     -0.831469476F // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     -0.0654031634F, // re
                                     0.997858942F    // im
                                 },
                                 {
                                     -1.0F,          // re
                                     -8.74227766E-8F // im
                                 },
                                 {
                                     0.0654034838F, // re
                                     -0.997858882F  // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     -0.555570364F, // re
                                     0.831469536F   // im
                                 },
                                 {
                                     -0.499999911F, // re
                                     -0.866025448F  // im
                                 },
                                 {
                                     0.997858942F, // re
                                     0.0654031336F // im
                                 },
                                 {
                                     -0.707106769F, // re
                                     0.707106769F   // im
                                 },
                                 {
                                     0.0654034838F, // re
                                     -0.997858882F  // im
                                 },
                                 {
                                     0.49999997F, // re
                                     0.866025448F // im
                                 },
                                 {
                                     -0.831469536F, // re
                                     -0.555570304F  // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     -0.997858882F, // re
                                     -0.0654033199F // im
                                 },
                                 {
                                     1.0F, // re
                                     -0.0F // im
                                 },
                                 {
                                     -0.997858882F, // re
                                     -0.0654033199F // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     -0.831469536F, // re
                                     -0.555570304F  // im
                                 },
                                 {
                                     0.49999997F, // re
                                     0.866025448F // im
                                 },
                                 {
                                     0.0654034838F, // re
                                     -0.997858882F  // im
                                 },
                                 {
                                     -0.707106769F, // re
                                     0.707106769F   // im
                                 },
                                 {
                                     0.997858942F, // re
                                     0.0654031336F // im
                                 },
                                 {
                                     -0.499999911F, // re
                                     -0.866025448F  // im
                                 },
                                 {
                                     -0.555570364F, // re
                                     0.831469536F   // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     0.0654034838F, // re
                                     -0.997858882F  // im
                                 },
                                 {
                                     -1.0F,          // re
                                     -8.74227766E-8F // im
                                 },
                                 {
                                     -0.0654031634F, // re
                                     0.997858942F    // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     0.555570424F, // re
                                     -0.831469476F // im
                                 },
                                 {
                                     -0.499999911F, // re
                                     -0.866025448F  // im
                                 },
                                 {
                                     -0.997858882F, // re
                                     -0.0654033199F // im
                                 },
                                 {
                                     -0.707106769F, // re
                                     0.707106769F   // im
                                 },
                                 {
                                     -0.0654031634F, // re
                                     0.997858942F    // im
                                 },
                                 {
                                     0.49999997F, // re
                                     0.866025448F // im
                                 },
                                 {
                                     0.831469595F, // re
                                     0.555570245F  // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     0.997858942F, // re
                                     0.0654031336F // im
                                 },
                                 {
                                     1.0F, // re
                                     0.0F  // im
                                 },
                                 {
                                     0.997858942F, // re
                                     0.0654031336F // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     0.831469595F, // re
                                     0.555570245F  // im
                                 },
                                 {
                                     0.49999997F, // re
                                     0.866025448F // im
                                 },
                                 {
                                     -0.0654031634F, // re
                                     0.997858942F    // im
                                 },
                                 {
                                     -0.707106769F, // re
                                     0.707106769F   // im
                                 },
                                 {
                                     -0.997858882F, // re
                                     -0.0654033199F // im
                                 },
                                 {
                                     -0.499999911F, // re
                                     -0.866025448F  // im
                                 },
                                 {
                                     0.555570424F, // re
                                     -0.831469476F // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     -0.0654031634F, // re
                                     0.997858942F    // im
                                 },
                                 {
                                     -1.0F,          // re
                                     -8.74227766E-8F // im
                                 },
                                 {
                                     0.0654034838F, // re
                                     -0.997858882F  // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     -0.555570364F, // re
                                     0.831469536F   // im
                                 },
                                 {
                                     -0.499999911F, // re
                                     -0.866025448F  // im
                                 },
                                 {
                                     0.997858942F, // re
                                     0.0654031336F // im
                                 },
                                 {
                                     -0.707106769F, // re
                                     0.707106769F   // im
                                 },
                                 {
                                     0.0654034838F, // re
                                     -0.997858882F  // im
                                 },
                                 {
                                     0.49999997F, // re
                                     0.866025448F // im
                                 },
                                 {
                                     -0.831469536F, // re
                                     -0.555570304F  // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     -0.997858882F, // re
                                     -0.0654033199F // im
                                 },
                                 {
                                     1.0F, // re
                                     -0.0F // im
                                 },
                                 {
                                     -0.997858882F, // re
                                     -0.0654033199F // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     -0.831469536F, // re
                                     -0.555570304F  // im
                                 },
                                 {
                                     0.49999997F, // re
                                     0.866025448F // im
                                 },
                                 {
                                     0.0654034838F, // re
                                     -0.997858882F  // im
                                 },
                                 {
                                     -0.707106769F, // re
                                     0.707106769F   // im
                                 },
                                 {
                                     0.997858942F, // re
                                     0.0654031336F // im
                                 },
                                 {
                                     -0.499999911F, // re
                                     -0.866025448F  // im
                                 },
                                 {
                                     -0.555570364F, // re
                                     0.831469536F   // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     0.0654034838F, // re
                                     -0.997858882F  // im
                                 },
                                 {
                                     -1.0F,          // re
                                     -8.74227766E-8F // im
                                 },
                                 {
                                     -0.0654031634F, // re
                                     0.997858942F    // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     0.555570424F, // re
                                     -0.831469476F // im
                                 },
                                 {
                                     -0.499999911F, // re
                                     -0.866025448F  // im
                                 },
                                 {
                                     -0.997858882F, // re
                                     -0.0654033199F // im
                                 },
                                 {
                                     -0.707106769F, // re
                                     0.707106769F   // im
                                 },
                                 {
                                     -0.0654031634F, // re
                                     0.997858942F    // im
                                 },
                                 {
                                     0.49999997F, // re
                                     0.866025448F // im
                                 },
                                 {
                                     0.831469595F, // re
                                     0.555570245F  // im
                                 },
                                 {
                                     0.965925813F, // re
                                     0.258819044F  // im
                                 },
                                 {
                                     0.997858942F, // re
                                     0.0654031336F // im
                                 }};
  static const float b_fv[65]{
      1.0F,          0.99879545F,    0.99518472F,    0.989176512F,
      0.980785251F,  0.970031261F,   0.956940353F,   0.941544056F,
      0.923879504F,  0.903989315F,   0.881921232F,   0.857728601F,
      0.831469595F,  0.803207517F,   0.773010433F,   0.740951121F,
      0.707106769F,  0.671559F,      0.634393334F,   0.59569931F,
      0.555570245F,  0.514102757F,   0.471396744F,   0.427555084F,
      0.382683456F,  0.336889863F,   0.290284663F,   0.242980197F,
      0.195090324F,  0.146730468F,   0.0980171412F,  0.0490676761F,
      0.0F,          -0.0490676761F, -0.0980171412F, -0.146730468F,
      -0.195090324F, -0.242980197F,  -0.290284663F,  -0.336889863F,
      -0.382683456F, -0.427555084F,  -0.471396744F,  -0.514102757F,
      -0.555570245F, -0.59569931F,   -0.634393334F,  -0.671559F,
      -0.707106769F, -0.740951121F,  -0.773010433F,  -0.803207517F,
      -0.831469595F, -0.857728601F,  -0.881921232F,  -0.903989315F,
      -0.923879504F, -0.941544056F,  -0.956940353F,  -0.970031261F,
      -0.980785251F, -0.989176512F,  -0.99518472F,   -0.99879545F,
      -1.0F};
  static const float fv1[65]{
      0.0F,          -0.0490676761F, -0.0980171412F, -0.146730468F,
      -0.195090324F, -0.242980197F,  -0.290284663F,  -0.336889863F,
      -0.382683456F, -0.427555084F,  -0.471396744F,  -0.514102757F,
      -0.555570245F, -0.59569931F,   -0.634393334F,  -0.671559F,
      -0.707106769F, -0.740951121F,  -0.773010433F,  -0.803207517F,
      -0.831469595F, -0.857728601F,  -0.881921232F,  -0.903989315F,
      -0.923879504F, -0.941544056F,  -0.956940353F,  -0.970031261F,
      -0.980785251F, -0.989176512F,  -0.99518472F,   -0.99879545F,
      -1.0F,         -0.99879545F,   -0.99518472F,   -0.989176512F,
      -0.980785251F, -0.970031261F,  -0.956940353F,  -0.941544056F,
      -0.923879504F, -0.903989315F,  -0.881921232F,  -0.857728601F,
      -0.831469595F, -0.803207517F,  -0.773010433F,  -0.740951121F,
      -0.707106769F, -0.671559F,     -0.634393334F,  -0.59569931F,
      -0.555570245F, -0.514102757F,  -0.471396744F,  -0.427555084F,
      -0.382683456F, -0.336889863F,  -0.290284663F,  -0.242980197F,
      -0.195090324F, -0.146730468F,  -0.0980171412F, -0.0490676761F,
      -0.0F};
  static const float fv2[65]{
      0.0F,         0.0490676761F, 0.0980171412F, 0.146730468F,  0.195090324F,
      0.242980197F, 0.290284663F,  0.336889863F,  0.382683456F,  0.427555084F,
      0.471396744F, 0.514102757F,  0.555570245F,  0.59569931F,   0.634393334F,
      0.671559F,    0.707106769F,  0.740951121F,  0.773010433F,  0.803207517F,
      0.831469595F, 0.857728601F,  0.881921232F,  0.903989315F,  0.923879504F,
      0.941544056F, 0.956940353F,  0.970031261F,  0.980785251F,  0.989176512F,
      0.99518472F,  0.99879545F,   1.0F,          0.99879545F,   0.99518472F,
      0.989176512F, 0.980785251F,  0.970031261F,  0.956940353F,  0.941544056F,
      0.923879504F, 0.903989315F,  0.881921232F,  0.857728601F,  0.831469595F,
      0.803207517F, 0.773010433F,  0.740951121F,  0.707106769F,  0.671559F,
      0.634393334F, 0.59569931F,   0.555570245F,  0.514102757F,  0.471396744F,
      0.427555084F, 0.382683456F,  0.336889863F,  0.290284663F,  0.242980197F,
      0.195090324F, 0.146730468F,  0.0980171412F, 0.0490676761F, 0.0F};
  creal32_T fv[128];
  creal32_T fy[128];
  float temp_im;
  float temp_re;
  float temp_re_tmp;
  float twid_im;
  float twid_re;
  int b_temp_re_tmp;
  int i;
  int iheight;
  int ihi;
  int istart;
  int j;
  int ju;
  int k;
  int ub_loop;
  int xoff;
  boolean_T tst;
  y.set_size(48, x.size(1));
  ub_loop = x.size(1) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    xoff, k, ju, temp_im, temp_re, fy, i, tst, temp_re_tmp, twid_im, iheight,  \
    istart, b_temp_re_tmp, j, twid_re, ihi, fv)

  for (int chan = 0; chan <= ub_loop; chan++) {
    xoff = chan * 48;
    for (k = 0; k < 48; k++) {
      ju = xoff + k;
      temp_im = wwc[k + 47].re;
      temp_re = wwc[k + 47].im;
      y[k + 48 * chan].re = temp_im * x[ju].re + temp_re * x[ju].im;
      y[k + 48 * chan].im = temp_im * x[ju].im - temp_re * x[ju].re;
    }
    std::memset(&fy[0], 0, 128U * sizeof(creal32_T));
    xoff = 0;
    ju = 0;
    for (i = 0; i < 47; i++) {
      fy[xoff] = y[i + 48 * chan];
      xoff = 128;
      tst = true;
      while (tst) {
        xoff >>= 1;
        ju ^= xoff;
        tst = ((ju & xoff) == 0);
      }
      xoff = ju;
    }
    fy[xoff] = y[48 * chan + 47];
    for (i = 0; i <= 126; i += 2) {
      temp_re_tmp = fy[i + 1].re;
      temp_re = fy[i + 1].im;
      twid_im = fy[i].re;
      temp_im = fy[i].im;
      fy[i + 1].re = twid_im - temp_re_tmp;
      fy[i + 1].im = temp_im - temp_re;
      fy[i].re = twid_im + temp_re_tmp;
      fy[i].im = temp_im + temp_re;
    }
    xoff = 2;
    ju = 4;
    k = 32;
    iheight = 125;
    while (k > 0) {
      for (i = 0; i < iheight; i += ju) {
        b_temp_re_tmp = i + xoff;
        temp_re = fy[b_temp_re_tmp].re;
        temp_im = fy[b_temp_re_tmp].im;
        fy[b_temp_re_tmp].re = fy[i].re - temp_re;
        fy[b_temp_re_tmp].im = fy[i].im - temp_im;
        fy[i].re += temp_re;
        fy[i].im += temp_im;
      }
      istart = 1;
      for (j = k; j < 64; j += k) {
        twid_re = b_fv[j];
        twid_im = fv1[j];
        i = istart;
        ihi = istart + iheight;
        while (i < ihi) {
          b_temp_re_tmp = i + xoff;
          temp_re_tmp = fy[b_temp_re_tmp].im;
          temp_im = fy[b_temp_re_tmp].re;
          temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
          temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
          fy[b_temp_re_tmp].re = fy[i].re - temp_re;
          fy[b_temp_re_tmp].im = fy[i].im - temp_im;
          fy[i].re += temp_re;
          fy[i].im += temp_im;
          i += ju;
        }
        istart++;
      }
      k /= 2;
      xoff = ju;
      ju += ju;
      iheight -= xoff;
    }
    std::memset(&fv[0], 0, 128U * sizeof(creal32_T));
    xoff = 0;
    ju = 0;
    for (i = 0; i < 94; i++) {
      fv[xoff] = wwc[i];
      xoff = 128;
      tst = true;
      while (tst) {
        xoff >>= 1;
        ju ^= xoff;
        tst = ((ju & xoff) == 0);
      }
      xoff = ju;
    }
    fv[xoff] = wwc[94];
    for (i = 0; i <= 126; i += 2) {
      temp_re_tmp = fv[i + 1].re;
      temp_re = fv[i + 1].im;
      twid_im = fv[i].re;
      temp_im = fv[i].im;
      fv[i + 1].re = twid_im - temp_re_tmp;
      fv[i + 1].im = temp_im - temp_re;
      fv[i].re = twid_im + temp_re_tmp;
      fv[i].im = temp_im + temp_re;
    }
    xoff = 2;
    ju = 4;
    k = 32;
    iheight = 125;
    while (k > 0) {
      for (i = 0; i < iheight; i += ju) {
        b_temp_re_tmp = i + xoff;
        temp_re = fv[b_temp_re_tmp].re;
        temp_im = fv[b_temp_re_tmp].im;
        fv[b_temp_re_tmp].re = fv[i].re - temp_re;
        fv[b_temp_re_tmp].im = fv[i].im - temp_im;
        fv[i].re += temp_re;
        fv[i].im += temp_im;
      }
      istart = 1;
      for (j = k; j < 64; j += k) {
        twid_re = b_fv[j];
        twid_im = fv1[j];
        i = istart;
        ihi = istart + iheight;
        while (i < ihi) {
          b_temp_re_tmp = i + xoff;
          temp_re_tmp = fv[b_temp_re_tmp].im;
          temp_im = fv[b_temp_re_tmp].re;
          temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
          temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
          fv[b_temp_re_tmp].re = fv[i].re - temp_re;
          fv[b_temp_re_tmp].im = fv[i].im - temp_im;
          fv[i].re += temp_re;
          fv[i].im += temp_im;
          i += ju;
        }
        istart++;
      }
      k /= 2;
      xoff = ju;
      ju += ju;
      iheight -= xoff;
    }
    for (ju = 0; ju < 128; ju++) {
      twid_im = fy[ju].re;
      temp_im = fv[ju].im;
      temp_re = fy[ju].im;
      twid_re = fv[ju].re;
      fy[ju].re = twid_im * twid_re - temp_re * temp_im;
      fy[ju].im = twid_im * temp_im + temp_re * twid_re;
    }
    xoff = 0;
    ju = 0;
    for (i = 0; i < 127; i++) {
      fv[xoff] = fy[i];
      xoff = 128;
      tst = true;
      while (tst) {
        xoff >>= 1;
        ju ^= xoff;
        tst = ((ju & xoff) == 0);
      }
      xoff = ju;
    }
    fv[xoff] = fy[127];
    for (i = 0; i <= 126; i += 2) {
      temp_re_tmp = fv[i + 1].re;
      temp_re = fv[i + 1].im;
      twid_im = fv[i].re;
      temp_im = fv[i].im;
      fv[i + 1].re = twid_im - temp_re_tmp;
      fv[i + 1].im = temp_im - temp_re;
      fv[i].re = twid_im + temp_re_tmp;
      fv[i].im = temp_im + temp_re;
    }
    xoff = 2;
    ju = 4;
    k = 32;
    iheight = 125;
    while (k > 0) {
      for (i = 0; i < iheight; i += ju) {
        b_temp_re_tmp = i + xoff;
        temp_re = fv[b_temp_re_tmp].re;
        temp_im = fv[b_temp_re_tmp].im;
        fv[b_temp_re_tmp].re = fv[i].re - temp_re;
        fv[b_temp_re_tmp].im = fv[i].im - temp_im;
        fv[i].re += temp_re;
        fv[i].im += temp_im;
      }
      istart = 1;
      for (j = k; j < 64; j += k) {
        twid_re = b_fv[j];
        twid_im = fv2[j];
        i = istart;
        ihi = istart + iheight;
        while (i < ihi) {
          b_temp_re_tmp = i + xoff;
          temp_re_tmp = fv[b_temp_re_tmp].im;
          temp_im = fv[b_temp_re_tmp].re;
          temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
          temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
          fv[b_temp_re_tmp].re = fv[i].re - temp_re;
          fv[b_temp_re_tmp].im = fv[i].im - temp_im;
          fv[i].re += temp_re;
          fv[i].im += temp_im;
          i += ju;
        }
        istart++;
      }
      k /= 2;
      xoff = ju;
      ju += ju;
      iheight -= xoff;
    }
    for (ju = 0; ju < 128; ju++) {
      fv[ju].re *= 0.0078125F;
      fv[ju].im *= 0.0078125F;
    }
    for (k = 0; k < 48; k++) {
      temp_im = wwc[k + 47].re;
      temp_re = fv[k + 47].im;
      twid_re = wwc[k + 47].im;
      twid_im = fv[k + 47].re;
      y[k + 48 * chan].re = temp_im * twid_im + twid_re * temp_re;
      y[k + 48 * chan].im = temp_im * temp_re - twid_re * twid_im;
    }
  }
}

} // namespace fft
} // namespace internal
} // namespace coder

//
// File trailer for FFTImplementationCallback.cpp
//
// [EOF]
//
