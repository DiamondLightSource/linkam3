/************************************************************************
*
*   File:           EventAPI.h
*
*   Description:    This header defines the controller event API for the
*                   Linkam SDK.
*
*   Copyright © 2018-2023 Linkam Scientific Instruments. All rights reserved
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
         *  \brief      This error code is issued when the USB output socket raises a connection error. This error
         *              will force the host-side USB device Tx service to shutdown. To recover from this error 
         *              you are required to shut the USB device connection down and establish a new connection to
         *              the device. Please report this problem to Linkam Scientific Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeUSBCommsTxError                        = 0xECF00011,

        /*!
         *  \brief      This error code is issued when the USB output socket raises an unhandled error. This error
         *              is ignored by the host-side USB device. Please report this problem to Linkam Scientific
         *              Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeUSBCommsUnknownTxError                 = 0xECF00012,

        /*!
         *  \brief      This error code is issued when the Serial output socket raises a connection error. This error
         *              will force the host-side Serial device Tx service to shutdown. To recover from this error 
         *              you are required to shut the Serial device connection down and establish a new connection to
         *              the device. Please report this problem to Linkam Scientific Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeSerialCommsTxError                     = 0xECF00013,

        /*!
         *  \brief      This error code is issued when the Serial output socket raises an unhandled error. This error
         *              is ignored by the host-side Serial device. Please report this problem to Linkam Scientific
         *              Instruments.
         *
         *  \remark     Recommended action is to launch an error pop-up dialog box detailing the issue.
         */
        errorCodeSerialCommsUnknownTxError              = 0xECF00014,

        /*!
         *  \brief      This error code is issued when a device fails to recieve a complete reply message from the device
         *              before the timeout limit occurs. If a complete reply fails to be recieved within the timeout limit
         *              the driver will resend the last command message again to the device. This will occur up to 3 times
         *              before the driver drops the command message and moves on.
         *
         *  \remark     Dropped messages are not considered reportable failures to Linkam Scientific Instruments. These can
         *              occur for a multitude of reasons, most commonly due to disruption of network traffic, or bandwidth
         *              optimisation protocols. Linkam devices require raw unmanaged network connections to maintain high
         *              performance data transfer. If you suffer significant message dropout errors, we recommend increasing
         *              the Rx comms timeout setting; this can be done at connection by setting the timeout on the appropriate
         *              CommsInfo structure or after connection using the \link LinkamSDK::eLinkamFunctionMsgCode_SetCommsRxTimeout eLinkamFunctionMsgCode_SetCommsRxTimeout \endlink
         *              command message.
         */
        errorCodeRxRecieveReplyError                    = 0xECF00015,

        /*!
         *  \brief      This error code is issued when a device fails 3 times to recieve a complete reply message for the current
         *              command message sent to the device. This event is sent after the command message has been dropped. The system
         *              is capable of recovering from this error if a valid connection has already been established. If the error occurs
         *              within the connection process, then the connection process will fail, resulting in a disconnection event.
         *
         *  \remark     Command message drop errors are not typically critical errors, they indicate potential bottlenecks in the
         *              communications network between the driver and the device. If a direct USB or serial connection is in place then
         *              there may be either a program slowing driver services down, or a problem at the controller side, such as an error.
         *              You should check the controller status and/or increase the Rx comms timeout.
         *
         *              Increasing the Rx comms timeout can be done at connection by setting the timeout on the appropriate CommsInfo structure
         *              or after connection using the \link LinkamSDK::eLinkamFunctionMsgCode_SetCommsRxTimeout eLinkamFunctionMsgCode_SetCommsRxTimeout \endlink
         *              command message.
         *
         *              If this error occurs during the connection process then connection will fail as replies to connection command messages
         *              are critical. Ensure you first try increasing the Rx comms timeout to see if this resolves the problem. If not
         *              please report this problem to Linkam Scientific Instruments.
         */
        errorCodeCommandMessageDroppedError             = 0xECF00016,

        /*!
         *  \brief      This error code is issued when the driver detects packets out of order from a specific device. This indicates that
         *              a packet was missed and probably was rejected at the network protocol level. It can also be interpreted as a packet
         *              corruption error. This is a recoverable error. The driver will attempt 3 transmissions of the command message to which
         *              error relates to before dropping the command message and moving on to the next command message.
         *
         *  \remark     Recommended action is to ignore but record.
         */
        errorCodeMissalignedPacketStreamError           = 0xECF00017,

        /*!
            *  \brief      This error code is issued when connecting to the T9X controller. If the version number is less than 1.17 the firmware uses a 3 packet
            *              system. Post 1.17 we only support a 4 packet system. 
            *
            *  \remark     This error will abort the connection
            */
        errorCodeUnsuportedFirmwareVersionError         = 0xECF00018,

        /*!
         *  The maximum possible error code ID.
         */
        errorCodeMax                                    = 0xECFFFFFF
    };

    /*!
     *  \enum       LogSeverityCode
     *  \brief      This enumerated type defines the current supported log message severity codes.
     *              These codes are used in conjuction with the EventLogCallback callback handler
     *              type. These codes define the severity of the message and may be used by 3rd
     *              parties to log Linkam driver information to their own application log, rather
     *              than using the default driver log.
     *  @ingroup    Event_API
     */
    enum LogSeverityCode
    {
        /*!
         *  Used to provide a message which should be treated as information only.
         */
        eLogSeverityCodeInformation     = 1,

        /*!
         *  Used to provide a message which should be treated as a warning.
         */
        eLogSeverityCodeWarning         = 2,

        /*!
         *  Used to provide a message which should be treated as an error.
         */
        eLogSeverityCodeError           = 3
    };
}

/*!
 *  \typedef    EventStageEventCallback
 *  \brief      This type of function pointer is used to receive stage specifc events.
 *              Not all stages support this feature.
 *  \param[in]  hDevice         A valid CommsHandle to the device that raised this event.
 *  \param[in]  message         The event message code.
 *  \param[in]  param1          An event paramater.
 *  \param[in]  param2          An event paramater.
 *  \param[in]  param3          An event paramater.
 *  @ingroup    Event_API
 */
typedef void (*EventStageEventCallback)(CommsHandle hDevice, uint32_t message, uint32_t param1, uint32_t param2, uint32_t param3);

/*!
 *  \typedef    EventErrorCallback
 *  \brief      This type of function pointer is used to receive general error events.
 *              General errors may require external logging or handling by 3rd party
 *              applications.
 *  \param[in]  severity        The severity of the message.
 *  \param[in]  message         Pointer to the string holding the message.
 *  @ingroup    Event_API
 */
typedef void (*EventLogCallback)(LinkamSDK::LogSeverityCode severity, const char* message);

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


