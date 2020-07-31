Linkam3
=======

EPICS asyn driver for Linkam T96 controllers.

Credits and licensing
---------------------

Original development of source code in this module from Diamond Light Source. Released under 
the Apache V2 license. See LICENSE.

Supported platforms
-------------------

This driver has been tested with RHEL6 and RHEL7 using EPICS BASE R3.14.12.3
and R3.14.12.7 respectively. We have used version 3-0-4 of the SDK.

Known issues
------------

We have encountered problems when trying to use this driver over the serial 
interface to the controller, and have been unable to resolve this. Thus we
reccommend using the USB interface if available.

SDK
---

If you want to change the version of the SDK:

* Replace include files in linkamT96App/src/include
* Replace libLinkamSDK.so in linkamT96App/src

Instructions
------------

To use this driver do the following:

* Set paths to dependencies in configure/RELEASE
* Set path to licence file at line 471 of linkamT96App/src/linkamT96.cpp (or leave blank to search current directory)

An example IOC is included at iocs/linkamIOC.

