TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = linkamT96

DBD += linkamT96.dbd
linkamT96_DBD += base.dbd
linkamT96_DBD += linkamT96Support.dbd

# Add all the support libraries needed by this IOC
#LIBRARY_Linux += ../libLinkamSDK.so
#LinkamSDK_DIR = $(TOP)/linkamT96App/src
linkamT96_SYS_LIBS += usb-1.0 LinkamSDK
linkamT96_LIBS += asyn 

# linkamT96_registerRecordDeviceDriver.cpp derives from linkamT96.dbd
linkamT96_SRCS += linkamT96_registerRecordDeviceDriver.cpp
linkamT96_SRCS += linkamT96.cpp

# Build the main IOC entry point on workstation OSs.
linkamT96_SRCS_DEFAULT += linkamT96Main.cpp
linkamT96_SRCS_vxWorks += -nil-

linkamT96_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

