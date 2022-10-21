//
// Trial License - for use to evaluate programs for possible purchase as
// an end-user only.
// File: testChannelize.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 21-Oct-2022 10:06:11
//

// Include Files
#include "testChannelize.h"
#include "AsyncBuffer.h"
#include "AsyncBuffercgHelper.h"
#include "Channelizer.h"
#include "datetime.h"
#include "testChannelize_data.h"
#include "testChannelize_initialize.h"
#include "tic.h"
#include "toc.h"
#include "udpsendercellforcoder.h"
#include "coder_array.h"
#include "udp.h"
#include <cmath>
#include <stdio.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void testChannelize()
{
  static coder::dsp::AsyncBuffer dataBufferFIFO;
  coder::datetime b;
  coder::datetime b_this;
  coder::dsp::Channelizer channelizer;
  coder::dsp::internal::AsyncBuffercgHelper *obj;
  coder::array<creal32_T, 2U> b_y;
  coder::array<creal32_T, 1U> out;
  coder::array<creal32_T, 1U> varargin_1;
  coder::array<int, 2U> readIdx;
  coder::array<unsigned short, 2U> y;
  double expectedFrameSize;
  double frameIndex;
  float bufferTimeStamp4Sending_im;
  float bufferTimeStamp4Sending_re;
  int udps[256];
  int udpReceive;
  if (!isInitialized_testChannelize) {
    testChannelize_initialize();
  }
  // AIRSPYFHCHANNELIZE48 receives complex (IQ) data over a UDP connection from
  // an Airspy HF+ or Airspy HF+ Discovery SDR, channelizes it, and servers it
  // up over 48 diferent UDP ports.
  //    This function is designed specifically to receive incoming data that
  //    has been passed to it via an interanl UDP connection. The parameters of
  //    the incoming data are specific to the Airspy HF+. The program expects
  //    128 sample frames of 8-byte complex samples (4 real, 4 imaginary) to be
  //    sent over UDP. The program receives that data and fills a buffer until
  //    enough samples have been received that 1024 samples will be generated
  //    on the output channels at the decimated sample rate.
  //
  //    Once the buffer fills, the data is channelized and
  //    served via UDP to corresponding ports. The function opens a command
  //    channel so that integers can be passed to enable basic control
  //    authority over the program operation, enabling starting of data
  //    processing, pausing, and termination of the program.
  //
  //    Note that all UDP ports have been hardcoded for this function because
  //    they are used within the dsp.udpsender and dsp.udpreceiver system
  //    objects. When deploying this code to C via Matlab coder, these system
  //    object arguments must be constants, which limits the ability of this
  //    function to receive ports as arguments and set them at run time. They
  //    must be a constant at compile time.
  //
  //    Normal channelization allows for decimation rates and the number of
  //    channels to be different. This function holds them equal. Therefore,
  //    the decimated rate for each channel is equal to the raw airspy sample
  //    rate divided by the number of channels. Additionally, the center
  //    frequencies of each channel is therefore
  //
  //    Data sent over the UDP output channels are single valued complex
  //    frames. Each output frame contains 1024 complex values, or 2048
  //    individual single precision values. Each frame also contains a
  //    timestamp encoded into a complex number in the first element of the
  //    frame. The received data frame therefore contains 1025 complex values.
  //    The timestamp on each frame is associate with the time of arrival of
  //    the first sample in the frame.
  //
  //    The timestamp is a precision posixtime value in milliseconds. The
  //    timestamp is transmitted as a single precision complex value. The
  //    imaginary part of this timestamp contains the first 7 digits of the
  //    time in milliseconds. The real part contains the upper digits (>=8) of
  //    the timestamp. See the help for int2singlecomplex and singlecomplex2int
  //    for more information on this transmission standard.
  //
  //    PORT LISTING
  //        10000       Receive port for airspy data
  //                       Complex single precision data
  //                       Maximum message size 1024 bytes
  //        10001       Receive port for fucntion control commands
  //                       Real int8 data
  //                       Maximum message size 1024 bytes
  //                       Valid inputs are
  //                            1   Start data reception/transmission
  //                            0   Stop (pause) data reception/transmission
  //                                and flush the buffer
  //                            -1  Terminate the function
  //        20000:20*** Send ports for serving channelized UDP data. The
  //                    center frequency of the channel for port 20000 is the
  //                    center frequency of the incoming data. Subsequent port
  //                    correspond to the increasing channel numbers and
  //                    frequency, eventually wrapping to negative frequencies
  //                    above Fs/2. See notes about channel center frequencies
  //                    below.The max port number is equal to
  //                    20000+numberofchannels-1
  //
  //    INPUTS:
  //        rawSampleRate   A single integer sample rate. Valid entries
  //                        correspond to those available for the Airspy HF+
  //                        radio: [912 768 456 384 256 192] kS/s
  //
  //    OUTPUTS:
  //        none
  //
  // Notes:
  //        ABOUT CHANNEL CENTER FREQUENCIES:
  //        Matlab provides the centerFrequencies function that accepts a
  //        channelizer object and a sample rate, and then specifies the
  //        center frequencies of the associated channel. This list however is
  //        centered at zero and provides negative frequencies. For example a
  //        channelizer with Fs = 48000 and a decimation factor of 3 would
  //        report center frequencies [-24000 -12000 0 12000]. If the fvtool is
  //        used on this channelizer (with the legend turned on) the center
  //        frequencies would be [0 12000 -24000 -12000] for filteres 1-4. The
  //        shifting here reflects a inconsistency in Matlab's channel
  //        reporting. The channelizer outputs follow the latter order, and as
  //        such, so to do the UDP port outputs in this function.
  //        Because the  number of chanels and the decimation are the same,
  //        the frequency of these channels are -Fs/nc*floor(nc/2)<fc<Fs/2,
  //        (where nc is the number of channels), if nc is odd. For even nc
  //        -Fs/2 < fc < Fs/2-Fs/nc. In both cases the frequency steps are
  //        Fs/nc. This was determined by using the centerFrequencies.m
  //        function on example channelizer objects. If using the
  //        centerFrequencies output the circshift command can be used to get
  //        the correct order of channel frequency. For example:
  //        circshift(centerFrequencies(channizerObject,48000),ceil(numChannels/2))
  //
  //        ABOUT INCOMING DATA:
  //        An Airspy HF+ connected to the machine via USB is received using
  //        the airspyhf_rx executable. Using the program with the '-r stdout'
  //        option allows the data to be piped to another program with the |
  //        character. Netcat can then be use to provide the data to this
  //        function via UDP. An example commandline input would be
  //
  //        /usr/local/bin/airspyhf_rx -f 91.7 -m on -a 912000 -n 9120000 -r
  //        stdout -g on -l high -t 0 | netcat -u localhost 10000
  //
  //        Note that this system call must executed after this function is
  //        already running or a 'Connection refused' error will occur in
  //        terminal.
  //        Command signals send via UDP can be entered in the command line as
  //        follows:
  //            Start (send a 1):
  //                echo -e -n '\x01'| netcat -u localhost 10001
  //            Pause (send a 0):
  //                echo -e -n '\x00'| netcat -u localhost 10001
  //            Kill (send a -1):
  //                echo -e -n '\xFF'| netcat -u localhost 10001
  //
  // -------------------------------------------------------------------------
  // Author:    Michael Shafer
  // Date:      2022-01-18
  // -------------------------------------------------------------------------
  printf("Channelizer: Starting up...\n");
  fflush(stdout);
  // Channelization Settings
  // Decimation is currently set to equal nChannels. Must be a factor of
  // rawFrameLength UDP Settings 10000:10039; Incoming Data Variables
  //  SETUP UDP DATA INPUT OBJECT
  //  Airspy sends out 1024 complex samples in each udp packet
  udpReceive = udpReceiverSetup(10000.0);
  //  SETUP UDP OUTPUT OBJECTS
  printf("Channelizer: Setting up output channel UDP ports...\n");
  fflush(stdout);
  //  Must be a multiple of 128
  // Adding 1 for the time stamp items on the front of each message.
  dataBufferFIFO.pBuffer.NumChannels = -1;
  dataBufferFIFO.pBuffer.isInitialized = 0;
  dataBufferFIFO.pBuffer.matlabCodegenIsDeleted = false;
  dataBufferFIFO.matlabCodegenIsDeleted = false;
  dataBufferFIFO.write();
  // Write a single value so the number of channels is specified for coder.
  // Specify complex single for airspy data
  dataBufferFIFO.read();
  // Read out that single sample to empty the buffer.
  udpsendercellforcoder(udps);
  channelizer.numChannels = -1;
  channelizer.isInitialized = 0;
  channelizer.matlabCodegenIsDeleted = false;
  frameIndex = 1.0;
  // Make initial call to udps. First call is very slow and can cause missed
  // samples if left within the while loop
  b.init();
  // int2singlecomplex Converts an integer value to a complex single precision
  // number with a portion of the integer digits in the real and imaginary
  // parts of the output. The input integer is split at the 7th digit. The top
  // digits are then held in the real part of the output, while the lower 7
  // digits are held in the imaginary part of the output.
  //
  // A single precision number has a maximum integer
  // values of flintmax('single') = 16777216. To avoid overrunning the
  // available digits, the input integer is split at digit 7.
  //
  // The max value for each output part would be:  16777216 + 1i * 16777216
  // To avoid overflow, the complex part
  // containing the lower digits only use          16777216 + 1i *  xxxxxxx
  // the first 7 digits available
  //
  // Based on this standard, the maximum value that can be transmitted is
  //    167772169999999 = 1.6777e14;
  //
  // INPUTS:
  //    intIN           Matrix of integer values. If decimal values are
  //                    transmitted, they will be rounded by this program.
  //                    Maximum input value is 167772169999999. Inputs
  //                    exceedign this value will result in an error.
  // OUTPUTS:
  //    singleComplex   Matrix of size of input with first 7 digits of input
  //                    held in the imaginary part and the remaining upper
  //                    digits held in the real part.
  //
  // -------------------------------------------------------------------------
  // Author:    Michael Shafer
  // Date:      2022-08-19
  // -------------------------------------------------------------------------
  // Add one for blank time stamp
  expectedFrameSize = 128.0;
  bufferTimeStamp4Sending_re = 0.0F;
  bufferTimeStamp4Sending_im = 0.0F;
  printf("Channelizer: Setup complete. Awaiting commands...\n");
  fflush(stdout);
  coder::tic();
  while (1) {
    creal32_T complexBuffer[2048];
    double intIn;
    int qY;
    int yk;
    // dataReceived = udpReceive.read();
    udpReceiverRead(udpReceive, &complexBuffer[0], 2048.0);
    if (frameIndex == 1.0) {
      double topDigits;
      b_this.init();
      // int2singlecomplex Converts an integer value to a complex single
      // precision number with a portion of the integer digits in the real and
      // imaginary parts of the output. The input integer is split at the 7th
      // digit. The top digits are then held in the real part of the output,
      // while the lower 7 digits are held in the imaginary part of the output.
      //
      // A single precision number has a maximum integer
      // values of flintmax('single') = 16777216. To avoid overrunning the
      // available digits, the input integer is split at digit 7.
      //
      // The max value for each output part would be:  16777216 + 1i * 16777216
      // To avoid overflow, the complex part
      // containing the lower digits only use          16777216 + 1i *  xxxxxxx
      // the first 7 digits available
      //
      // Based on this standard, the maximum value that can be transmitted is
      //    167772169999999 = 1.6777e14;
      //
      // INPUTS:
      //    intIN           Matrix of integer values. If decimal values are
      //                    transmitted, they will be rounded by this program.
      //                    Maximum input value is 167772169999999. Inputs
      //                    exceedign this value will result in an error.
      // OUTPUTS:
      //    singleComplex   Matrix of size of input with first 7 digits of input
      //                    held in the imaginary part and the remaining upper
      //                    digits held in the real part.
      //
      // -------------------------------------------------------------------------
      // Author:    Michael Shafer
      // Date:      2022-08-19
      // -------------------------------------------------------------------------
      intIn = std::round(1000.0 * (b_this.data.re / 1000.0));
      topDigits = std::floor(intIn * 1.0E-7);
      bufferTimeStamp4Sending_re = static_cast<float>(topDigits);
      bufferTimeStamp4Sending_im =
          static_cast<float>(intIn - topDigits * 1.0E+7);
    }
    // Used to keep a running estimated of the expected frame
    // size to help identifiy subsize frames received.
    if (expectedFrameSize != 1024.0) {
      expectedFrameSize = std::round((expectedFrameSize + 1024.0) / 2.0);
    }
    dataBufferFIFO.write(complexBuffer);
    // Call with (:) to help coder realize it is a single channel
    frameIndex++;
    if ((dataBufferFIFO.pBuffer.WritePointer >= 0) &&
        (dataBufferFIFO.pBuffer.ReadPointer <
         dataBufferFIFO.pBuffer.WritePointer - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((dataBufferFIFO.pBuffer.WritePointer < 0) &&
               (dataBufferFIFO.pBuffer.ReadPointer >
                dataBufferFIFO.pBuffer.WritePointer - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY = dataBufferFIFO.pBuffer.WritePointer -
           dataBufferFIFO.pBuffer.ReadPointer;
    }
    if (qY < -2147483647) {
      qY = MIN_int32_T;
    } else {
      qY--;
    }
    if (dataBufferFIFO.pBuffer.ReadPointer < -2147385343) {
      yk = MAX_int32_T;
    } else {
      yk = 98304 - dataBufferFIFO.pBuffer.ReadPointer;
    }
    if ((yk < 0) && (dataBufferFIFO.pBuffer.WritePointer < MIN_int32_T - yk)) {
      yk = MIN_int32_T;
    } else if ((yk > 0) &&
               (dataBufferFIFO.pBuffer.WritePointer > MAX_int32_T - yk)) {
      yk = MAX_int32_T;
    } else {
      yk += dataBufferFIFO.pBuffer.WritePointer;
    }
    if (dataBufferFIFO.pBuffer.ReadPointer <
        dataBufferFIFO.pBuffer.WritePointer) {
      yk = qY;
    } else if (dataBufferFIFO.pBuffer.ReadPointer ==
               dataBufferFIFO.pBuffer.WritePointer) {
      yk = 98304;
    }
    if (yk >= 49152) {
      int c;
      int c_tmp_tmp;
      int k;
      int n;
      int rPtr;
      int wPtr;
      if (expectedFrameSize < 2.147483648E+9) {
        k = static_cast<int>(expectedFrameSize);
      } else {
        k = MAX_int32_T;
      }
      printf("Channelizer: Running - Buffer filled with %u samples. Flushing "
             "to channels. Currently receiving: %i samples per packet.\n",
             49152U, k);
      fflush(stdout);
      intIn = coder::toc();
      printf("Actual time between buffer flushes: %6.6f.  Expected: %6.6f. \n",
             intIn, 0.256);
      fflush(stdout);
      frameIndex = 1.0;
      coder::tic();
      obj = &dataBufferFIFO.pBuffer;
      wPtr = dataBufferFIFO.pBuffer.WritePointer;
      qY = 0;
      n = dataBufferFIFO.pBuffer.ReadPointer;
      if (n > 2147483646) {
        rPtr = MAX_int32_T;
      } else {
        rPtr = n + 1;
      }
      if (rPtr > 98305) {
        rPtr = 1;
      }
      c = rPtr + 49151;
      if (rPtr + 49151 > 98305) {
        c_tmp_tmp = rPtr - 49154;
        c = rPtr - 49154;
        n = 98306 - rPtr;
        readIdx.set_size(1, 98306 - rPtr);
        readIdx[0] = rPtr;
        yk = rPtr;
        for (k = 2; k <= n; k++) {
          yk++;
          readIdx[k - 1] = yk;
        }
        y.set_size(1, rPtr - 49154);
        y[0] = 1U;
        yk = 1;
        for (k = 2; k <= c_tmp_tmp; k++) {
          yk++;
          y[k - 1] = static_cast<unsigned short>(yk);
        }
        k = readIdx.size(1);
        readIdx.set_size(1, readIdx.size(1) + y.size(1));
        c_tmp_tmp = y.size(1);
        for (n = 0; n < c_tmp_tmp; n++) {
          readIdx[n + k] = y[n];
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
          if ((qY < 0) && (rPtr - 49154 < MIN_int32_T - qY)) {
            qY = MIN_int32_T;
          } else if ((qY > 0) && (rPtr - 49154 > MAX_int32_T - qY)) {
            qY = MAX_int32_T;
          } else {
            qY = (qY + rPtr) - 49154;
          }
        } else if (wPtr <= rPtr - 49154) {
          if ((rPtr - 49154 >= 0) && (wPtr < rPtr + 2147434495)) {
            qY = MAX_int32_T;
          } else if ((rPtr - 49154 < 0) && (wPtr > rPtr + 2147434494)) {
            qY = MIN_int32_T;
          } else {
            qY = (rPtr - wPtr) - 49154;
          }
          if (qY > 2147483646) {
            qY = MAX_int32_T;
          } else {
            qY++;
          }
        }
      } else {
        if (rPtr + 49151 < rPtr) {
          n = 0;
        } else {
          n = 49152;
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
        if ((rPtr <= wPtr) && (wPtr <= rPtr + 49151)) {
          if ((rPtr + 49151 >= 0) && (wPtr < rPtr - 2147434496)) {
            qY = MAX_int32_T;
          } else if ((rPtr + 49151 < 0) && (wPtr > rPtr - 2147434497)) {
            qY = MIN_int32_T;
          } else {
            qY = (rPtr - wPtr) + 49151;
          }
          if (qY > 2147483646) {
            qY = MAX_int32_T;
          } else {
            qY++;
          }
        }
      }
      out.set_size(readIdx.size(1));
      c_tmp_tmp = readIdx.size(1);
      for (k = 0; k < c_tmp_tmp; k++) {
        out[k] = obj->Cache[readIdx[k] - 1];
      }
      if (qY != 0) {
        if (qY < -2147434495) {
          yk = MAX_int32_T;
        } else {
          yk = 49152 - qY;
        }
        if (yk > 2147483646) {
          yk = MAX_int32_T;
        } else {
          yk++;
        }
        if (yk > 49152) {
          yk = 1;
        }
        for (k = 0; k < qY; k++) {
          n = (yk + k) - 1;
          out[n].re = 0.0F;
          out[n].im = 0.0F;
        }
      }
      varargin_1.set_size(out.size(0));
      c_tmp_tmp = out.size(0);
      for (k = 0; k < c_tmp_tmp; k++) {
        varargin_1[k] = out[k];
      }
      n = dataBufferFIFO.pBuffer.WritePointer;
      if (n < -2147483647) {
        yk = MIN_int32_T;
      } else {
        yk = n - 1;
      }
      n = dataBufferFIFO.pBuffer.CumulativeUnderrun;
      if ((n < 0) && (qY < MIN_int32_T - n)) {
        n = MIN_int32_T;
      } else if ((n > 0) && (qY > MAX_int32_T - n)) {
        n = MAX_int32_T;
      } else {
        n += qY;
      }
      dataBufferFIFO.pBuffer.CumulativeUnderrun = n;
      if (qY != 0) {
        dataBufferFIFO.pBuffer.ReadPointer = yk;
      } else {
        dataBufferFIFO.pBuffer.ReadPointer = c;
      }
      channelizer.step(varargin_1, b_y);
      c_tmp_tmp = b_y.size(0);
      n = b_y.size(0) + 1;
      for (yk = 0; yk < 48; yk++) {
        creal32_T data_data[1025];
        data_data[0].re = bufferTimeStamp4Sending_re;
        data_data[0].im = bufferTimeStamp4Sending_im;
        for (k = 0; k < c_tmp_tmp; k++) {
          data_data[k + 1] = b_y[k + b_y.size(0) * yk];
        }
        udpSenderSend(udps[yk], &data_data[0], static_cast<double>(n));
      }
      intIn = coder::toc();
      printf("Time required to channelize: %6.6f \n", intIn);
      fflush(stdout);
    }
  }
}

//
// File trailer for testChannelize.cpp
//
// [EOF]
//
