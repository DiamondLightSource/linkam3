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

The serial interface is not consistent between generations of controllers.
This driver has been tested with both serial and USB interfaces to the T96,
including using socat to create a virtual port to a port on a Moxa terminal
server.

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

### Using the driver at DLS

As of 2.5, the builder IOC support has the ability to create virtual ports using
socat. This means you can use the driver with controllers connected to terminal
servers like a Moxa. This is optional, and otherwise still works with direct USB
or serial connections (including using extenders).

It does this by adding `registrar(iocshSystemCommand)` via
`systemCommandSupport.dbd`. This allows system commands to be added to the IOC
boot script which will then run when the IOC starts.

If the virtual_port arg is True in the LinkamT96 builder class, then a system
command to instantiate a virtual port using socat is added to the IOC boot file.
