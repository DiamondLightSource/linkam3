/************************************************************************
*
*   File:           EventAPI.h
*
*   Description:    This header defines the controller event API for the
*                   Linkam SDK.
*
*   Copyright © 2018 Linkam Scientific Instruments. All rights reserved
************************************************************************/
#ifndef LINKAM_SDK__EVENT_API_H
#define LINKAM_SDK__EVENT_API_H
#include "ExportAPI.h"
#include "CommonTypes.h"
#include "ControllerAPI.h"

#ifdef __cplusplus
extern "C" {
#endif
namespace LinkamSDK
{
    /*!
     *  \enum       ErrorCode
     *  \brief      This enumerated type defines the current supported public errors
     *              that dependent applications may need to handle or publish in error
     *              event pop-up dialog boxes. These codes are used in conjuction with
     *              the EventErrorCallback callback handler type.
     *  \note       The reserved ID range is 0xECF00000 - 0xECFFFFFF.
     *  @ingroup    Event_API
     */
    enum ErrorCode
    {
        /*!
         *  \brief      This error code defines 'no error'.
         *  \param[in]  data    Ignored, set to NULL.
         */
        errorCodeNone                                   = 0xECF00000,

        /*!
         *  \brief      This error code is issued when trying to use the Linkam SDK library
         *              before the initialisation function has been called. To recover from this
         *              error make a single call to the linkamInitialiseSDK function.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeLibraryNotInitialise                   = 0xECF00001,

        /*!
         *  \brief      This error code is issued when attempting to open a connection to a device but
         *              passed no connection information structure. To recover from this error
         *              pass a valid pointer to a CommsInfo for the type of connection you require
         *              populated with informatin from one of our appropriate helper functions:
         *              linkamInitialiseUSBCommsInfo or linkamInitialiseSerialCommsInfo.
         *
         *  \remark     Recommended action is to investigate where your program interfaces the Linkam
         *              SDK library and check function calls and parameters.
         */
        errorCodeNoConnectionInfo                       = 0xECF00002,

        /*!
         *  \brief      This error code is issued when attemping to open a connection to a device but
         *              the returned device handle was null. A valid device handle is required for nominal
         *              operation. Please report this problem to Linkam Scientific Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeDeviceRegistrationFailed               = 0xECF00003,

        /*!
         *  \brief      This error code is issued when attemping to open a connection to a device but
         *              the library failed to allocate and return a valid device instance. Please report
         *              this problem to Linkam Scientific Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeDeviceCreationFailure                  = 0xECF00004,

        /*!
         *  \brief      This error code is issued when attempting to establish communications with a serial
         *              device. This error event can occur for a number of connected reasons, please review
         *              the runtime log file for details. Please report this problem to Linkam Scientific
         *              Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeSerialCommsInitialisationFailure       = 0xECF00005,

        /*!
         *  \brief      This error code is issued when attempting to establish communications with a serial
         *              device. This error is a result of a failure during the data handshake between the 
         *              host computer and the Linkam controller. To recover from this error check the serial
         *              port cable connection and configuration settings. Please report this problem to Linkam
         *              Scientific Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeSerialCommsHandshakeFailure            = 0xECF00006,

        /*!
         *  \brief      This error code is issued when attempting to establish communications with a serial
         *              device. This occurs when there was an error creating a serial port socket for communications
         *              to a serial controller. Please report this problem to Linkam Scientific Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeSerialPortSocketCreationFailure        = 0xECF00007,

        /*!
         *  \brief      This error code is issued when attempting to establish communications with a serial
         *              device. This occurs when the serial port settings are not supported by the host computer.
         *              Please report this problem to Linkam Scientific Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeSerialPortSocketConfigurationFailure   = 0xECF00008,

        /*!
         *  \brief      This error code is issued when the serial input socket raises a connection error. This error
         *              will force the host-side serial device Rx service to shutdown. To recover from this error 
         *              you are required to shut the serial device connection down and establish a new connection to
         *              the device. Please report this problem to Linkam Scientific Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeSerialCommsRxError                     = 0xECF00009,

        /*!
         *  \brief      This error code is issued when the serial input socket raises an unhandled error. This error
         *              is ignored by the host-side serial device. Please report this problem to Linkam Scientific
         *              Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeSerialCommsUnknownRxError              = 0xECF0000A,

        /*!
         *  \brief      This error code is issued when reading a reply message to a command sent to the connected
         *              device. The error indicated that a reply message exceeded the maximum size of the command
         *              reply buffer. If this occurs then an unaccounted misalignment of the receieved bitstream
         *              has occured due to bitstream corruption, or the device sent an incompatible message. Recovery
         *              from this error event is automatic and the received data will be thrown away. Please report
         *              this problem to Linkam Scientific Instruments.
         *              data
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeCommandBufferLimitReached              = 0xECF0000B,

        /*!
         *  \brief      This error code is issued when attempting to establish communications with a USB
         *              device. This error event can occur for a number of connected reasons, please review
         *              the runtime log file for details. Please report this problem to Linkam Scientific
         *              Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeUSBCommsInitialisationFailure          = 0xECF0000C,

        /*!
         *  \brief      This error code is issued when attempting to establish communications with a USB
         *              device. This error is a result of a failure during the data handshake between the 
         *              host computer and the Linkam controller. To recover from this error check the USB
         *              port cable connection and configuration settings. Please report this problem to Linkam
         *              Scientific Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeUSBCommsHandshakeFailure               = 0xECF0000D,

        /*!
         *  \brief      This error code is issued when attempting to establish communications with a USB
         *              device. This occurs when there was an error creating a USB port socket for communications
         *              to a USB controller. Please report this problem to Linkam Scientific Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeUSBPortSocketCreationFailure           = 0xECF0000E,

        /*!
         *  \brief      This error code is issued when the USB input socket raises a connection error. This error
         *              will force the host-side USB device Rx service to shutdown. To recover from this error 
         *              you are required to shut the USB device connection down and establish a new connection to
         *              the device. Please report this problem to Linkam Scientific Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeUSBCommsRxError                        = 0xECF0000F,

        /*!
         *  \brief      This error code is issued when the USB input socket raises an unhandled error. This error
         *              is ignored by the host-side USB device. Please report this problem to Linkam Scientific
         *              Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeUSBCommsUnknownRxError                 = 0xECF00010,

        /*!
         *  The maximum possible error code ID.
         */
        errorCodeMax                                    = 0xECFFFFFF
    };
}

/*!
 *  \typedef    EventErrorCallback
 *  \brief      This type of function pointer is used to receive general error events.
 *              General errors may require external logging or handling by 3rd party
 *              applications.
 *  \param[in]  hDevice         A valid CommsHandle to the device that raised this event.
 *  \param[in]  err             This error ID for the error event that occured, this can also be used as a string lookup value in a custom string table.
 *  @ingroup    Event_API
 */
typedef void (*EventErrorCallback)(CommsHandle hDevice, uint32_t err);

/*!
 *  \typedef    EventCallback
 *  \brief      This type of function pointer is used to receive status events for
 *              connection and disconnection of the controller. Make sure you assign
 *              your function to the correct registration function for the event
 *              required.
 *  \param[in]  hDevice         A valid CommsHandle to the device that raised this event.
 *  @ingroup    Event_API
 */
typedef void (*EventCallback)(CommsHandle hDevice);

/*!
 *  \typedef    EventNewValueCallback
 *  \brief      This type of function pointer is used to receive status events for
 *              new values that have been received by the controller.
 *  \param[in]  hDevice         A valid CommsHandle to the device that raised this event.
 *  \param[in]  status          The current controller status for what has changed.
 *  @ingroup    Event_API
 */
typedef void (*EventNewValueCallback)(CommsHandle hDevice, LinkamSDK::ControllerStatus status);

/*!
 *  \typedef    eventCallback
 *  \brief      This type of function pointer is used to receive status events for
 *              connection and disconnection of the controller. Make sure you assign
 *              your function to the correct registration function for the event
 *              required.
 *  \note       Switch to the new event API as the deprecated version does not suport
 *              multiple controllers.
 *  \warning    This type will be removed in future versions.
 *  @ingroup    Deprecated_Functions
 */
typedef void (*eventCallback)(void);

/*!
 *  \typedef    eventNewValueCallback
 *  \brief      This type of function pointer is used to receive status events for
 *              new values that have been received by the controller.
 *  \param[in]  status          The current controller status for what has changed.
 *  \note       Switch to the new event API as the deprecated version does not suport
 *              multiple controllers.
 *  \warning    This type will be removed in future versions.
 *  @ingroup    Deprecated_Functions
 */
typedef void (*eventNewValueCallback)(uint64_t status);

#ifdef __cplusplus
}
#endif

#endif // LINKAM_SDK__CONTROLLER_API_H


