TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = linkamT96
# linkamT96.dbd will be created and installed
DBD += linkamT96.dbd

# linkamT96.dbd will be made up from these files:
linkamT96_DBD += base.dbd

# Include dbd files from all support applications:
#linkamT96_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#linkamT96_LIBS += xxx

# linkamT96_registerRecordDeviceDriver.cpp derives from linkamT96.dbd
linkamT96_SRCS += linkamT96_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
linkamT96_SRCS_DEFAULT += linkamT96Main.cpp
linkamT96_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#linkamT96_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
linkamT96_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

