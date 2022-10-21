//
// Trial License - for use to evaluate programs for possible purchase as
// an end-user only.
// File: Channelizer.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 21-Oct-2022 10:06:11
//

// Include Files
#include "Channelizer.h"
#include "FFTImplementationCallback.h"
#include "testChannelize_internal_types.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Declarations
static int div_s32(int numerator, int denominator);

static int div_s32_floor(int numerator, int denominator);

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace coder {
namespace dsp {
void Channelizer::SystemCore_delete()
{
  release();
}

//
// Arguments    : void
// Return Type  : void
//
void Channelizer::matlabCodegenDestructor()
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
void Channelizer::release()
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
void Channelizer::releaseImpl()
{
  numChannels = -1;
}

//
// Arguments    : void
// Return Type  : void
//
void Channelizer::releaseWrapper()
{
  if (isSetupComplete) {
    releaseImpl();
  }
}

//
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
} // namespace dsp
} // namespace coder
static int div_s32(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int tempAbsQuotient;
    unsigned int u;
    if (numerator < 0) {
      tempAbsQuotient = ~static_cast<unsigned int>(numerator) + 1U;
    } else {
      tempAbsQuotient = static_cast<unsigned int>(numerator);
    }
    if (denominator < 0) {
      u = ~static_cast<unsigned int>(denominator) + 1U;
    } else {
      u = static_cast<unsigned int>(denominator);
    }
    tempAbsQuotient /= u;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -static_cast<int>(tempAbsQuotient);
    } else {
      quotient = static_cast<int>(tempAbsQuotient);
    }
  }
  return quotient;
}

//
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
static int div_s32_floor(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int absDenominator;
    unsigned int absNumerator;
    unsigned int tempAbsQuotient;
    boolean_T quotientNeedsNegation;
    if (numerator < 0) {
      absNumerator = ~static_cast<unsigned int>(numerator) + 1U;
    } else {
      absNumerator = static_cast<unsigned int>(numerator);
    }
    if (denominator < 0) {
      absDenominator = ~static_cast<unsigned int>(denominator) + 1U;
    } else {
      absDenominator = static_cast<unsigned int>(denominator);
    }
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
      quotient = -static_cast<int>(tempAbsQuotient);
    } else {
      quotient = static_cast<int>(tempAbsQuotient);
    }
  }
  return quotient;
}

//
// Arguments    : void
// Return Type  : Channelizer
//
namespace coder {
namespace dsp {
Channelizer::Channelizer()
{
  matlabCodegenIsDeleted = true;
}

//
// Arguments    : void
// Return Type  : void
//
Channelizer::~Channelizer()
{
  matlabCodegenDestructor();
}

//
// Arguments    : const ::coder::array<creal32_T, 1U> &varargin_1
//                ::coder::array<creal32_T, 2U> &varargout_1
// Return Type  : void
//
void Channelizer::step(const ::coder::array<creal32_T, 1U> &varargin_1,
                       ::coder::array<creal32_T, 2U> &varargout_1)
{
  static const float fv[576]{0.0F,
                             -2.15386919E-7F,
                             -4.76195652E-7F,
                             -7.8479826E-7F,
                             -1.14327383E-6F,
                             -1.55336375E-6F,
                             -2.01642752E-6F,
                             -2.53339749E-6F,
                             -3.10473683E-6F,
                             -3.73039575E-6F,
                             -4.40977237E-6F,
                             -5.14167323E-6F,
                             -5.92427887E-6F,
                             -6.7551091E-6F,
                             -7.63099615E-6F,
                             -8.54805876E-6F,
                             -9.50167941E-6F,
                             -1.04864939E-5F,
                             -1.14963732E-5F,
                             -1.2524426E-5F,
                             -1.35629971E-5F,
                             -1.46036737E-5F,
                             -1.56373044E-5F,
                             -1.66540158E-5F,
                             -1.76432495E-5F,
                             -1.85937861E-5F,
                             -1.9493802E-5F,
                             -2.03309191E-5F,
                             -2.10922572E-5F,
                             -2.1764512E-5F,
                             -2.23340212E-5F,
                             -2.27868568E-5F,
                             -2.31089052E-5F,
                             -2.32859784E-5F,
                             -2.33039045E-5F,
                             -2.31486447E-5F,
                             -2.28064164E-5F,
                             -2.22638E-5F,
                             -2.1507878E-5F,
                             -2.05263659E-5F,
                             -1.9307734E-5F,
                             -1.78413593E-5F,
                             -1.61176522E-5F,
                             -1.41282017E-5F,
                             -1.18659091E-5F,
                             -9.32513E-6F,
                             -6.50180527E-6F,
                             -3.39359394E-6F,
                             0.0F,
                             3.67750772E-6F,
                             7.63538083E-6F,
                             1.18678854E-5F,
                             1.63670065E-5F,
                             2.11223596E-5F,
                             2.61211208E-5F,
                             3.13479613E-5F,
                             3.67849934E-5F,
                             4.2411757E-5F,
                             4.82051837E-5F,
                             5.4139593E-5F,
                             6.01867359E-5F,
                             6.63158E-5F,
                             7.24934871E-5F,
                             7.8684061E-5F,
                             8.48494892E-5F,
                             9.09495066E-5F,
                             9.69417742E-5F,
                             0.000102782033F,
                             0.000108424305F,
                             0.000113821043F,
                             0.000118923395F,
                             0.000123681428F,
                             0.000128044368F,
                             0.000131960915F,
                             0.000135379494F,
                             0.000138248608F,
                             0.000140517135F,
                             0.000142134697F,
                             0.000143051991F,
                             0.000143221143F,
                             0.000142596124F,
                             0.000141133103F,
                             0.000138790827F,
                             0.000135531038F,
                             0.000131318811F,
                             0.000126123F,
                             0.000119916614F,
                             0.000112677131F,
                             0.000104386934F,
                             9.50336471E-5F,
                             8.46104522E-5F,
                             7.31164255E-5F,
                             6.05568421E-5F,
                             4.6943449E-5F,
                             3.22947162E-5F,
                             1.66360496E-5F,
                             0.0F,
                             -1.7573595E-5F,
                             -3.60374834E-5F,
                             -5.53369173E-5F,
                             -7.54096109E-5F,
                             -9.61857586E-5F,
                             -0.000117588039F,
                             -0.000139531752F,
                             -0.000161924952F,
                             -0.000184668577F,
                             -0.000207656791F,
                             -0.00023077715F,
                             -0.000253911072F,
                             -0.000276934094F,
                             -0.000299716427F,
                             -0.00032212332F,
                             -0.000344015745F,
                             -0.000365250889F,
                             -0.000385682768F,
                             -0.00040516298F,
                             -0.00042354138F,
                             -0.000440666801F,
                             -0.000456387934F,
                             -0.000470554165F,
                             -0.000483016309F,
                             -0.000493627624F,
                             -0.000502244628F,
                             -0.000508728204F,
                             -0.000512944302F,
                             -0.000514765037F,
                             -0.000514069747F,
                             -0.000510745682F,
                             -0.000504689175F,
                             -0.000495806511F,
                             -0.000484014832F,
                             -0.000469243125F,
                             -0.000451432978F,
                             -0.000430539483F,
                             -0.000406532F,
                             -0.000379395F,
                             -0.000349128619F,
                             -0.000315749436F,
                             -0.000279290922F,
                             -0.000239804096F,
                             -0.000197357804F,
                             -0.000152039211F,
                             -0.000103953993F,
                             -5.32265185E-5F,
                             0.0F,
                             5.55635597E-5F,
                             0.000113283459F,
                             0.000172960485F,
                             0.00023437725F,
                             0.000297298597F,
                             0.000361472106F,
                             0.000426628743F,
                             0.00049248361F,
                             0.000558736734F,
                             0.000625074143F,
                             0.000691168883F,
                             0.000756682F,
                             0.000821264228F,
                             0.00088455691F,
                             0.000946193701F,
                             0.00100580219F,
                             0.0010630053F,
                             0.00111742329F,
                             0.00116867537F,
                             0.00121638144F,
                             0.00126016443F,
                             0.00129965181F,
                             0.00133447803F,
                             0.00136428629F,
                             0.0013887306F,
                             0.00140747812F,
                             0.00142021105F,
                             0.00142662867F,
                             0.00142645F,
                             0.00141941488F,
                             0.00140528684F,
                             0.00138385477F,
                             0.00135493476F,
                             0.0013183722F,
                             0.00127404311F,
                             0.00122185657F,
                             0.00116175541F,
                             0.00109371846F,
                             0.00101776153F,
                             0.000933938369F,
                             0.000842342619F,
                             0.000743107754F,
                             0.000636408513F,
                             0.000522461371F,
                             0.000401524769F,
                             0.000273899699F,
                             0.0001399295F,
                             0.0F,
                             -0.000145460974F,
                             -0.000295984F,
                             -0.000451058761F,
                             -0.000610135F,
                             -0.000772623403F,
                             -0.000937897363F,
                             -0.00110529398F,
                             -0.00127411587F,
                             -0.00144363334F,
                             -0.00161308632F,
                             -0.00178168644F,
                             -0.00194861961F,
                             -0.00211304869F,
                             -0.0022741165F,
                             -0.00243094796F,
                             -0.00258265436F,
                             -0.00272833533F,
                             -0.0028670833F,
                             -0.00299798604F,
                             -0.00312013109F,
                             -0.00323260878F,
                             -0.0033345155F,
                             -0.00342495902F,
                             -0.00350306067F,
                             -0.00356796035F,
                             -0.00361881917F,
                             -0.00365482457F,
                             -0.00367519306F,
                             -0.00367917493F,
                             -0.00366605702F,
                             -0.00363516714F,
                             -0.00358587666F,
                             -0.00351760513F,
                             -0.00342982262F,
                             -0.00332205324F,
                             -0.00319387787F,
                             -0.00304493774F,
                             -0.00287493551F,
                             -0.00268363976F,
                             -0.0024708854F,
                             -0.00223657629F,
                             -0.00198068772F,
                             -0.0017032664F,
                             -0.00140443293F,
                             -0.00108438195F,
                             -0.000743383367F,
                             -0.000381782476F,
                             0.0F,
                             0.000401468016F,
                             0.00082205073F,
                             0.00126110332F,
                             0.00171790819F,
                             0.00219167606F,
                             0.00268154778F,
                             0.00318659702F,
                             0.00370583124F,
                             0.00423819572F,
                             0.00478257425F,
                             0.00533779524F,
                             0.00590263307F,
                             0.00647581089F,
                             0.00705600716F,
                             0.00764185749F,
                             0.00823195931F,
                             0.00882487744F,
                             0.00941914786F,
                             0.0100132804F,
                             0.0106057692F,
                             0.0111950906F,
                             0.0117797162F,
                             0.0123581085F,
                             0.0129287373F,
                             0.0134900734F,
                             0.0140406042F,
                             0.0145788314F,
                             0.0151032815F,
                             0.0156125072F,
                             0.0161050949F,
                             0.016579669F,
                             0.0170348976F,
                             0.0174694918F,
                             0.0178822242F,
                             0.0182719156F,
                             0.0186374523F,
                             0.0189777836F,
                             0.0192919318F,
                             0.0195789877F,
                             0.0198381189F,
                             0.0200685728F,
                             0.0202696808F,
                             0.0204408541F,
                             0.0205815937F,
                             0.0206914879F,
                             0.0207702126F,
                             0.0208175424F,
                             0.020833334F,
                             0.0208175424F,
                             0.0207702126F,
                             0.0206914879F,
                             0.0205815937F,
                             0.0204408541F,
                             0.0202696808F,
                             0.0200685728F,
                             0.0198381189F,
                             0.0195789877F,
                             0.0192919318F,
                             0.0189777836F,
                             0.0186374523F,
                             0.0182719156F,
                             0.0178822242F,
                             0.0174694918F,
                             0.0170348976F,
                             0.016579669F,
                             0.0161050949F,
                             0.0156125072F,
                             0.0151032815F,
                             0.0145788314F,
                             0.0140406042F,
                             0.0134900734F,
                             0.0129287373F,
                             0.0123581085F,
                             0.0117797162F,
                             0.0111950906F,
                             0.0106057692F,
                             0.0100132804F,
                             0.00941914786F,
                             0.00882487744F,
                             0.00823195931F,
                             0.00764185749F,
                             0.00705600716F,
                             0.00647581089F,
                             0.00590263307F,
                             0.00533779524F,
                             0.00478257425F,
                             0.00423819572F,
                             0.00370583124F,
                             0.00318659702F,
                             0.00268154778F,
                             0.00219167606F,
                             0.00171790819F,
                             0.00126110332F,
                             0.00082205073F,
                             0.000401468016F,
                             0.0F,
                             -0.000381782476F,
                             -0.000743383367F,
                             -0.00108438195F,
                             -0.00140443293F,
                             -0.0017032664F,
                             -0.00198068772F,
                             -0.00223657629F,
                             -0.0024708854F,
                             -0.00268363976F,
                             -0.00287493551F,
                             -0.00304493774F,
                             -0.00319387787F,
                             -0.00332205324F,
                             -0.00342982262F,
                             -0.00351760513F,
                             -0.00358587666F,
                             -0.00363516714F,
                             -0.00366605702F,
                             -0.00367917493F,
                             -0.00367519306F,
                             -0.00365482457F,
                             -0.00361881917F,
                             -0.00356796035F,
                             -0.00350306067F,
                             -0.00342495902F,
                             -0.0033345155F,
                             -0.00323260878F,
                             -0.00312013109F,
                             -0.00299798604F,
                             -0.0028670833F,
                             -0.00272833533F,
                             -0.00258265436F,
                             -0.00243094796F,
                             -0.0022741165F,
                             -0.00211304869F,
                             -0.00194861961F,
                             -0.00178168644F,
                             -0.00161308632F,
                             -0.00144363334F,
                             -0.00127411587F,
                             -0.00110529398F,
                             -0.000937897363F,
                             -0.000772623403F,
                             -0.000610135F,
                             -0.000451058761F,
                             -0.000295984F,
                             -0.000145460974F,
                             0.0F,
                             0.0001399295F,
                             0.000273899699F,
                             0.000401524769F,
                             0.000522461371F,
                             0.000636408513F,
                             0.000743107754F,
                             0.000842342619F,
                             0.000933938369F,
                             0.00101776153F,
                             0.00109371846F,
                             0.00116175541F,
                             0.00122185657F,
                             0.00127404311F,
                             0.0013183722F,
                             0.00135493476F,
                             0.00138385477F,
                             0.00140528684F,
                             0.00141941488F,
                             0.00142645F,
                             0.00142662867F,
                             0.00142021105F,
                             0.00140747812F,
                             0.0013887306F,
                             0.00136428629F,
                             0.00133447803F,
                             0.00129965181F,
                             0.00126016443F,
                             0.00121638144F,
                             0.00116867537F,
                             0.00111742329F,
                             0.0010630053F,
                             0.00100580219F,
                             0.000946193701F,
                             0.00088455691F,
                             0.000821264228F,
                             0.000756682F,
                             0.000691168883F,
                             0.000625074143F,
                             0.000558736734F,
                             0.00049248361F,
                             0.000426628743F,
                             0.000361472106F,
                             0.000297298597F,
                             0.00023437725F,
                             0.000172960485F,
                             0.000113283459F,
                             5.55635597E-5F,
                             0.0F,
                             -5.32265185E-5F,
                             -0.000103953993F,
                             -0.000152039211F,
                             -0.000197357804F,
                             -0.000239804096F,
                             -0.000279290922F,
                             -0.000315749436F,
                             -0.000349128619F,
                             -0.000379395F,
                             -0.000406532F,
                             -0.000430539483F,
                             -0.000451432978F,
                             -0.000469243125F,
                             -0.000484014832F,
                             -0.000495806511F,
                             -0.000504689175F,
                             -0.000510745682F,
                             -0.000514069747F,
                             -0.000514765037F,
                             -0.000512944302F,
                             -0.000508728204F,
                             -0.000502244628F,
                             -0.000493627624F,
                             -0.000483016309F,
                             -0.000470554165F,
                             -0.000456387934F,
                             -0.000440666801F,
                             -0.00042354138F,
                             -0.00040516298F,
                             -0.000385682768F,
                             -0.000365250889F,
                             -0.000344015745F,
                             -0.00032212332F,
                             -0.000299716427F,
                             -0.000276934094F,
                             -0.000253911072F,
                             -0.00023077715F,
                             -0.000207656791F,
                             -0.000184668577F,
                             -0.000161924952F,
                             -0.000139531752F,
                             -0.000117588039F,
                             -9.61857586E-5F,
                             -7.54096109E-5F,
                             -5.53369173E-5F,
                             -3.60374834E-5F,
                             -1.7573595E-5F,
                             0.0F,
                             1.66360496E-5F,
                             3.22947162E-5F,
                             4.6943449E-5F,
                             6.05568421E-5F,
                             7.31164255E-5F,
                             8.46104522E-5F,
                             9.50336471E-5F,
                             0.000104386934F,
                             0.000112677131F,
                             0.000119916614F,
                             0.000126123F,
                             0.000131318811F,
                             0.000135531038F,
                             0.000138790827F,
                             0.000141133103F,
                             0.000142596124F,
                             0.000143221143F,
                             0.000143051991F,
                             0.000142134697F,
                             0.000140517135F,
                             0.000138248608F,
                             0.000135379494F,
                             0.000131960915F,
                             0.000128044368F,
                             0.000123681428F,
                             0.000118923395F,
                             0.000113821043F,
                             0.000108424305F,
                             0.000102782033F,
                             9.69417742E-5F,
                             9.09495066E-5F,
                             8.48494892E-5F,
                             7.8684061E-5F,
                             7.24934871E-5F,
                             6.63158E-5F,
                             6.01867359E-5F,
                             5.4139593E-5F,
                             4.82051837E-5F,
                             4.2411757E-5F,
                             3.67849934E-5F,
                             3.13479613E-5F,
                             2.61211208E-5F,
                             2.11223596E-5F,
                             1.63670065E-5F,
                             1.18678854E-5F,
                             7.63538083E-6F,
                             3.67750772E-6F,
                             0.0F,
                             -3.39359394E-6F,
                             -6.50180527E-6F,
                             -9.32513E-6F,
                             -1.18659091E-5F,
                             -1.41282017E-5F,
                             -1.61176522E-5F,
                             -1.78413593E-5F,
                             -1.9307734E-5F,
                             -2.05263659E-5F,
                             -2.1507878E-5F,
                             -2.22638E-5F,
                             -2.28064164E-5F,
                             -2.31486447E-5F,
                             -2.33039045E-5F,
                             -2.32859784E-5F,
                             -2.31089052E-5F,
                             -2.27868568E-5F,
                             -2.23340212E-5F,
                             -2.1764512E-5F,
                             -2.10922572E-5F,
                             -2.03309191E-5F,
                             -1.9493802E-5F,
                             -1.85937861E-5F,
                             -1.76432495E-5F,
                             -1.66540158E-5F,
                             -1.56373044E-5F,
                             -1.46036737E-5F,
                             -1.35629971E-5F,
                             -1.2524426E-5F,
                             -1.14963732E-5F,
                             -1.04864939E-5F,
                             -9.50167941E-6F,
                             -8.54805876E-6F,
                             -7.63099615E-6F,
                             -6.7551091E-6F,
                             -5.92427887E-6F,
                             -5.14167323E-6F,
                             -4.40977237E-6F,
                             -3.73039575E-6F,
                             -3.10473683E-6F,
                             -2.53339749E-6F,
                             -2.01642752E-6F,
                             -1.55336375E-6F,
                             -1.14327383E-6F,
                             -7.8479826E-7F,
                             -4.76195652E-7F,
                             -2.15386919E-7F};
  static const unsigned short inSize[8]{49152U, 1U, 1U, 1U, 1U, 1U, 1U, 1U};
  static const unsigned short uv[8]{49152U, 1U, 1U, 1U, 1U, 1U, 1U, 1U};
  static const unsigned short uv1[8]{49152U, 1U, 1U, 1U, 1U, 1U, 1U, 1U};
  array<creal32_T, 2U> b_v;
  array<creal32_T, 2U> r;
  array<creal32_T, 2U> v;
  creal32_T obj[528];
  float b_obj_re;
  float b_obj_re_tmp;
  float obj_im;
  float obj_re;
  float obj_re_tmp;
  int K;
  int b_i;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int phIdx;
  int qY;
  int t;
  boolean_T exitg1;
  if (isInitialized != 1) {
    isInitialized = 1;
    for (i = 0; i < 8; i++) {
      inputVarSize[0].f1[i] = uv[i];
    }
    numChannels = 1;
    NTPB = 12.0F;
    for (i = 0; i < 576; i++) {
      obj_re = fv[i];
      PolyphaseMatrix[i] = obj_re;
      actpmatrix[i] = obj_re;
    }
    Halideflag = false;
    phaseIdx = 1;
    ModuloIdx = 0;
    numStates = 1.0F;
    for (b_i = 0; b_i < 48; b_i++) {
      StopIdx[b_i] = 0;
      if (b_i == 0) {
        t = 0;
      } else {
        t = b_i;
      }
      StartIdx[b_i] =
          static_cast<int>(std::ceil(static_cast<double>(t) / 48.0));
      if (t == 47) {
        StopIdx[b_i] = 1;
      } else {
        StopIdx[b_i] = static_cast<int>(
            std::ceil(std::fmod(static_cast<double>(b_i) + 1.0, 48.0) / 48.0));
      }
    }
    isSetupComplete = true;
    TunablePropsChanged = false;
    std::memset(&States[0], 0, 576U * sizeof(creal32_T));
    std::memset(&vextra[0], 0, 48U * sizeof(creal32_T));
    currentState = 1;
  }
  if (TunablePropsChanged) {
    TunablePropsChanged = false;
    std::copy(&PolyphaseMatrix[0], &PolyphaseMatrix[576], &actpmatrix[0]);
  }
  t = 0;
  exitg1 = false;
  while ((!exitg1) && (t < 8)) {
    if (inputVarSize[0].f1[t] != uv1[t]) {
      for (i = 0; i < 8; i++) {
        inputVarSize[0].f1[i] = inSize[i];
      }
      exitg1 = true;
    } else {
      t++;
    }
  }
  phIdx = phaseIdx;
  v.set_size(1024, 48);
  for (i = 0; i < 48; i++) {
    v[v.size(0) * i] = vextra[i];
    for (i1 = 0; i1 < 1023; i1++) {
      v[(i1 + v.size(0) * i) + 1].re = 0.0F;
      v[(i1 + v.size(0) * i) + 1].im = 0.0F;
    }
  }
  obj_re = std::round(numStates);
  if (obj_re < 2.14748365E+9F) {
    if (obj_re >= -2.14748365E+9F) {
      K = static_cast<int>(obj_re);
    } else {
      K = MIN_int32_T;
    }
  } else if (obj_re >= 2.14748365E+9F) {
    K = MAX_int32_T;
  } else {
    K = 0;
  }
  if (phIdx < 1) {
    i = 0;
    i1 = 1;
    i2 = -1;
  } else {
    i = phIdx - 1;
    i1 = -1;
    i2 = 0;
  }
  loop_ub = div_s32(i2 - i, i1);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    States[i2] = varargin_1[i + i1 * i2];
  }
  for (loop_ub = 0; loop_ub < 48; loop_ub++) {
    obj_re = 0.0F;
    obj_im = 0.0F;
    for (i = 0; i < 12; i++) {
      t = loop_ub + 48 * i;
      b_obj_re = actpmatrix[t];
      obj_re_tmp = States[t].im;
      b_obj_re_tmp = States[t].re;
      obj_re += b_obj_re * b_obj_re_tmp - 0.0F * obj_re_tmp;
      obj_im += b_obj_re * obj_re_tmp + 0.0F * b_obj_re_tmp;
    }
    if (loop_ub + 1 == 1) {
      i = 0;
    } else {
      i = 48 - loop_ub;
    }
    v[v.size(0) * i].re = obj_re;
    if (loop_ub + 1 == 1) {
      i = 0;
    } else {
      i = 48 - loop_ub;
    }
    v[v.size(0) * i].im = obj_im;
  }
  t = currentState;
  if (t > 2147483646) {
    qY = MAX_int32_T;
  } else {
    qY = t + 1;
  }
  if (K != 0) {
    qY -= div_s32_floor(qY, K) * K;
  }
  if (qY == 0) {
    qY = K;
  }
  b_i = 1;
  t = 0;
  i = phIdx + 1;
  for (phIdx = i; phIdx <= 49105; phIdx += 48) {
    std::copy(&States[0], &States[528], &obj[0]);
    std::copy(&obj[0], &obj[528], &States[48]);
    for (t = 0; t < 48; t++) {
      States[t] = varargin_1[(phIdx - t) + 46];
    }
    for (loop_ub = 0; loop_ub < 48; loop_ub++) {
      obj_re = 0.0F;
      obj_im = 0.0F;
      for (i1 = 0; i1 < 12; i1++) {
        t = loop_ub + 48 * i1;
        b_obj_re = actpmatrix[t];
        obj_re_tmp = States[t].im;
        b_obj_re_tmp = States[t].re;
        obj_re += b_obj_re * b_obj_re_tmp - 0.0F * obj_re_tmp;
        obj_im += b_obj_re * obj_re_tmp + 0.0F * b_obj_re_tmp;
      }
      if (loop_ub + 1 == 1) {
        i1 = 0;
      } else {
        i1 = 48 - loop_ub;
      }
      v[b_i + v.size(0) * i1].re = obj_re;
      if (loop_ub + 1 == 1) {
        i1 = 0;
      } else {
        i1 = 48 - loop_ub;
      }
      v[b_i + v.size(0) * i1].im = obj_im;
    }
    if (qY > 2147483646) {
      qY = MAX_int32_T;
    } else {
      qY++;
    }
    if (K != 0) {
      qY -= div_s32_floor(qY, K) * K;
    }
    if (qY == 0) {
      qY = K;
    }
    b_i++;
    t = phIdx;
  }
  if (t + 47 < -2147434496) {
    t = MIN_int32_T;
  } else {
    t -= 49105;
  }
  std::copy(&States[0], &States[528], &obj[0]);
  std::copy(&obj[0], &obj[528], &States[48]);
  if (t + 49153 > 49152) {
    i = 0;
    i1 = 1;
    i2 = -49105;
  } else {
    i = 49151;
    i1 = -1;
    i2 = t + 48;
  }
  if (t + 49 > 48) {
    b_i = 0;
  } else {
    b_i = t + 48;
  }
  loop_ub = div_s32((i2 - i) + 49104, i1);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    States[b_i + i2] = varargin_1[i + i1 * i2];
  }
  b_v.set_size(48, 1024);
  for (i = 0; i < 1024; i++) {
    for (i1 = 0; i1 < 48; i1++) {
      b_v[i1 + 48 * i] = v[i + v.size(0) * i1];
    }
  }
  ::coder::internal::fft::FFTImplementationCallback::dobluesteinfft(b_v, r);
  varargout_1.set_size(r.size(1), 48);
  loop_ub = r.size(1);
  for (i = 0; i < 48; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargout_1[i1 + varargout_1.size(0) * i] = r[i + 48 * i1];
    }
  }
  phaseIdx = t + 48;
  currentState = qY;
}

} // namespace dsp
} // namespace coder

//
// File trailer for Channelizer.cpp
//
// [EOF]
//
