TOP=../..

include $(TOP)/configure/CONFIG

LIBRARY_IOC += linkamT96

DBD += linkamT96Support.dbd
DBD += systemCommandSupport.dbd

LIB_INSTALLS += ../libLinkamSDK.so
LinkamSDK_DIR = $(TOP)/linkamT96App/src

LIB_SYS_LIBS += usb-1.0
LIB_LIBS += asyn LinkamSDK

linkamT96_SRCS += linkamT96.cpp

include $(TOP)/configure/RULES

