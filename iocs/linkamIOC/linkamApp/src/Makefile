TOP = ../..
include $(TOP)/configure/CONFIG

PROD_IOC = example
DBD += example.dbd
example_DBD += base.dbd
example_DBD += asyn.dbd
example_DBD += linkamT96Support.dbd
example_SRCS += example_registerRecordDeviceDriver.cpp
example_LIBS += linkamT96
example_LIBS += asyn
example_LIBS += $(EPICS_BASE_IOC_LIBS)
example_SRCS += linkamMain.cpp

include $(TOP)/configure/RULES

