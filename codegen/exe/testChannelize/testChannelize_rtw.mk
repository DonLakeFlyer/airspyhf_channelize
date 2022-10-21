###########################################################################
## Makefile generated for component 'testChannelize'. 
## 
## Makefile     : testChannelize_rtw.mk
## Generated on : Fri Oct 21 10:06:38 2022
## Final product: $(START_DIR)/testChannelize
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = channelize
MAKEFILE                  = testChannelize_rtw.mk
MATLAB_ROOT               = /matlab-extern
MATLAB_BIN                = /usr/local/MATLAB/R2022b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/glnxa64
START_DIR                 = /airspyhf_channelize
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU gcc/g++ | gmake (64-bit Linux)
# Supported Version(s):    
# ToolchainInfo Version:   2022b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS         = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX     = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS     = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC = gcc

# Linker: GNU Linker
LD = g++

# C++ Compiler: GNU C++ Compiler
CPP = g++

# C++ Linker: GNU C++ Linker
CPP_LD = g++

# Archiver: GNU Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/glnxa64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(C_STANDARD_OPTS) -fPIC \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -fPIC \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(START_DIR)/testChannelize
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/codegen/exe/testChannelize -I$(START_DIR) -I$(START_DIR)/codegen/exe/testChannelize/examples -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=testChannelize

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/udp.cpp $(START_DIR)/codegen/exe/testChannelize/coder_posix_time.c $(START_DIR)/codegen/exe/testChannelize/testChannelize_data.cpp $(START_DIR)/codegen/exe/testChannelize/testChannelize_initialize.cpp $(START_DIR)/codegen/exe/testChannelize/testChannelize_terminate.cpp $(START_DIR)/codegen/exe/testChannelize/testChannelize.cpp $(START_DIR)/codegen/exe/testChannelize/getLocalTime.cpp $(START_DIR)/codegen/exe/testChannelize/plus.cpp $(START_DIR)/codegen/exe/testChannelize/tic.cpp $(START_DIR)/codegen/exe/testChannelize/timeKeeper.cpp $(START_DIR)/codegen/exe/testChannelize/toc.cpp $(START_DIR)/codegen/exe/testChannelize/examples/main.cpp $(START_DIR)/codegen/exe/testChannelize/CoderTimeAPI.cpp $(START_DIR)/codegen/exe/testChannelize/udpsendercellforcoder.cpp $(START_DIR)/codegen/exe/testChannelize/AsyncBuffercgHelper.cpp $(START_DIR)/codegen/exe/testChannelize/AsyncBuffer.cpp $(START_DIR)/codegen/exe/testChannelize/Channelizer.cpp $(START_DIR)/codegen/exe/testChannelize/datetime.cpp $(START_DIR)/codegen/exe/testChannelize/FFTImplementationCallback.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = udp.o coder_posix_time.o testChannelize_data.o testChannelize_initialize.o testChannelize_terminate.o testChannelize.o getLocalTime.o plus.o tic.o timeKeeper.o toc.o main.o CoderTimeAPI.o udpsendercellforcoder.o AsyncBuffercgHelper.o AsyncBuffer.o Channelizer.o datetime.o FFTImplementationCallback.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -L"/usr/lib/aarch64-linux-gnu" -lm -lstdc++ -lgomp

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_OPTS = -fopenmp
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_OPTS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_OPTS = -fopenmp
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_OPTS) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/exe/testChannelize/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/exe/testChannelize/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/exe/testChannelize/examples/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/exe/testChannelize/examples/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


udp.o : $(START_DIR)/udp.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


coder_posix_time.o : $(START_DIR)/codegen/exe/testChannelize/coder_posix_time.c
	$(CC) $(CFLAGS) -o "$@" "$<"


testChannelize_data.o : $(START_DIR)/codegen/exe/testChannelize/testChannelize_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


testChannelize_initialize.o : $(START_DIR)/codegen/exe/testChannelize/testChannelize_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


testChannelize_terminate.o : $(START_DIR)/codegen/exe/testChannelize/testChannelize_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


testChannelize.o : $(START_DIR)/codegen/exe/testChannelize/testChannelize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


getLocalTime.o : $(START_DIR)/codegen/exe/testChannelize/getLocalTime.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


plus.o : $(START_DIR)/codegen/exe/testChannelize/plus.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


tic.o : $(START_DIR)/codegen/exe/testChannelize/tic.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


timeKeeper.o : $(START_DIR)/codegen/exe/testChannelize/timeKeeper.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


toc.o : $(START_DIR)/codegen/exe/testChannelize/toc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


main.o : $(START_DIR)/codegen/exe/testChannelize/examples/main.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


CoderTimeAPI.o : $(START_DIR)/codegen/exe/testChannelize/CoderTimeAPI.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


udpsendercellforcoder.o : $(START_DIR)/codegen/exe/testChannelize/udpsendercellforcoder.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


AsyncBuffercgHelper.o : $(START_DIR)/codegen/exe/testChannelize/AsyncBuffercgHelper.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


AsyncBuffer.o : $(START_DIR)/codegen/exe/testChannelize/AsyncBuffer.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Channelizer.o : $(START_DIR)/codegen/exe/testChannelize/Channelizer.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


datetime.o : $(START_DIR)/codegen/exe/testChannelize/datetime.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


FFTImplementationCallback.o : $(START_DIR)/codegen/exe/testChannelize/FFTImplementationCallback.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

#$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)
$(ALL_OBJS) : $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


