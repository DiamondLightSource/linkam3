/************************************************************************
*
*   File:           linkamSDK.h
*
*   Description:    This is the Linkam SDK header for interfacing to
*                   Linkam devices. This may be used on Windows and Linux
*                   platforms.
*
*   Copyright © 2018-2023 Linkam Scientific Instruments. All rights reserved
************************************************************************/
#ifndef LINKAM_SDK_H
#define LINKAM_SDK_H
#include <stddef.h>
#include "Message.h"
#include "EventAPI.h"


/*!
 *	\brief		Call this once to initialise the Linkam SDK library.
 *  \param[in]  logpath     An optional string holding the full path and filename of where the log file should be created. If this parameter is set to NULL, then the driver assumes the log file can be created in the currently set application directory.
 *  \param[in]  licpath     An optional string holding the full path and filename of where the license file should be found, or a valid license code. If this parameter is set to NULL, then the driver assumes looking for a license file in the currently set application directory.
 *  \param[in]  initCOM     The SDK license requires COM, if your application does not use COM then this parameter MUST be set to 'true', else false or leave the default value.
 *	\return		Returns 'true' if the SDK library was initialised correctly, else false.
 *  \note       If logpath is left NULL then the log file will be created under the currently set directory.
 *  \note       If licpath is left NULL then the driver assumes that the license file will be under the currently set directory.
 *
 *	This will initialise the SDK library for use; you cannot successfully call any SDK 
 *	function until this function has been called.
 *
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL bool linkamInitialiseSDK(const char* logpath = NULL, const char* licpath = NULL, bool initCOM = false);

/*!
 *	\brief		Call this once to close and clean-up the Linkam SDK library and all resources consumed.
 *	\return		Returns no value.
 *
 *	This will perform all internal clean-up and will close all currently open connections
 *	to attached devices. Any device handles retained by the caller will no longer be valid.
 *
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamExitSDK();

/*!
 *  \brief      Call this function to obtain the version number for the driver. The version number is no longer than 20 characters.
 *  \param[in]  version         A valid char pointer to a buffer large enough to hold the version
 *  \param[in]  length          The size in bytes of the buffer to hold the version number.
 *  \return     Returns 'true' if successful, else 'false'.
 *
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL bool linkamGetVersion(char* version, uint64_t length);

/*!
 *  \brief      Call this function to pass a message to the driver. Messages are just codes to invoke
 *              function calls in a generic format. This simplifies the Linkam interface to just
 *              four functions within this header file.
 *  \param[in]  msg             A value from \link LinkamSDK::LinkamFunctionMsgCode LinkamFunctionMsgCode \endlink, this will be the command function to invoke.
 *  \param[in]  hDevice         A valid handle to a comms device to invoke the command function on, or zero (0) if the command function is non-device specific.
 *  \param[out] result          Used as a return value, is a pointer to a known Variant instance.
 *  \param[in]  param1          Argument 1 for the message.
 *  \param[in]  param2          Argument 2 for the message.
 *  \param[in]  param2          Argument 3 for the message.
 *  \return     Returns true if the message was processed, else false.
 *  \note       This function will return false if you pass a NULL pointer under the result parameter.
 *              You must pass a valid pointer to a Variant instance for this function to work.
 *
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL bool linkamProcessMessage(LinkamSDK::LinkamFunctionMsgCode msg, CommsHandle hDevice, LinkamSDK::Variant* result, LinkamSDK::Variant param1 = LinkamSDK::Variant(), LinkamSDK::Variant param2 = LinkamSDK::Variant(), LinkamSDK::Variant param3 = LinkamSDK::Variant());

/*!
 *  \brief      This is a helper function for interfacing the driver to languages that cannot support
 *              union type structures. It performs the same operation as linkamProcessMessage.
 *  \param[in]  msg             A value from \link LinkamSDK::LinkamFunctionMsgCode LinkamFunctionMsgCode \endlink, this will be the command function to invoke.
 *  \param[in]  hDevice         A valid handle to a comms device or zero (0).
 *  \param[out] result          Used as a return value, is a pointer to an unsigned 64-bit variable.
 *  \param[in]  param1          Argument 1 for the message as an unsigned 64-bit value.
 *  \param[in]  param2          Argument 2 for the message as an unsigned 64-bit value.
 *  \param[in]  param3          Argument 3 for the message as an unsigned 64-bit value.
 *  \return     Returns true if the message was processed, else false.
 *  \note       This function will return false if you pass a NULL pointer under the result parameter.
 *              You must pass a valid pointer to an unsigned 64-bit integer variable for this function to work.
 *
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL bool linkamProcessMessageCommon(uint32_t msg, CommsHandle hDevice, void* result, uint64_t param1, uint64_t param2, uint64_t param3);

/*!
 *  \brief      Helper function, call to initialise a \link LinkamSDK::CommsInfo CommsInfo \endlink structure with require information for a USB device.
 *  \param[in]  info                    A valid pointer to a \link LinkamSDK::CommsInfo CommsInfo \endlink structure instance defining the connection properties.
 *  \param[in]  serialNumber            A valid pointer to a null terminated wchar_t buffer holding the serial number for the device,
 *                                      may be NULL if only Linkam controller is connected to your machine.
 *
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamInitialiseUSBCommsInfo(LinkamSDK::CommsInfo* info, const char* serialNumber);

/*!
 *  \brief      Helper function, call to initialise a \link LinkamSDK::CommsInfo CommsInfo \endlink structure with require information for a USB device.
 * This is an extended version (Ex) which allows the timeout setting to be modified by call to the initialise function instead of configuring the structure
 * manually.
 *  \param[in]  info                    A valid pointer to a \link LinkamSDK::CommsInfo CommsInfo \endlink structure instance defining the connection properties.
 *  \param[in]  serialNumber            A valid pointer to a null terminated wchar_t buffer holding the serial number for the device,
 *                                      may be NULL if only Linkam controller is connected to your machine.
 *  \param[in]  msgTimeout              Sets the total time to wait for a complete message in (ms) before dropping the message.
 *
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamInitialiseUSBCommsInfoEx(LinkamSDK::CommsInfo* info, const char* serialNumber, uint32_t msgTimeout);

/*!
 *  \brief      Helper function, call to initialise a \link LinkamSDK::CommsInfo CommsInfo \endlink structure with require information for a Serial device.
 *  \param[in]  info                    A valid pointer to a \link LinkamSDK::CommsInfo CommsInfo \endlink structure instance defining the connection properties.
 *  \param[in]  port                    A valid pointer to a null terminated char buffer holding the serial port name.
 *
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamInitialiseSerialCommsInfo(LinkamSDK::CommsInfo* info, const char* port);

/*!
 *  \brief      Helper function, call to initialise a \link LinkamSDK::CommsInfo CommsInfo \endlink structure with require information for a Serial device.
 * This is an extended version (Ex) which allows the timeout settings to be modified by call to the initialise function instead of configuring the structure
 * manually.
 *  \param[in]  info                    A valid pointer to a \link LinkamSDK::CommsInfo CommsInfo \endlink structure instance defining the connection properties.
 *  \param[in]  port                    A valid pointer to a null terminated char buffer holding the serial port name.
 *  \param[in]  msgTimeout              Sets the total time to wait for a complete message in (ms) before dropping the message.
 *  \param[in]  portTimeout             Sets the total time to wait for packet data to arrive at the port in (ms) (Optional, default is set to 5 ms).
 *
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamInitialiseSerialCommsInfoEx(LinkamSDK::CommsInfo* info, const char* port, uint32_t msgTimeout, uint32_t portTimeout=5);

/*!
 *  \brief      Helper function, call to initialise a \link LinkamSDK::CommsInfo CommsInfo \endlink structure with require information for an emulated device.
 *  \param[in]  info                    A valid pointer to a \link LinkamSDK::CommsInfo CommsInfo \endlink structure instance defining the connection properties.
 *	\param[in]	type                    The stage type to emulate.
 *	\param[in]	supportLNP              Boolean flag for single LNP support on emulated stage.
 *	\param[in]	supportRH               Boolean flag for humidiaty support on emulated stage.
 *
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamInitialiseEmulatedCommsInfo(LinkamSDK::CommsInfo* info, LinkamSDK::StageType type, bool supportLNP, bool supportRH);

/*!
 *  \brief      Call this function to add a callback function to receive new value event signals.
 *
 *  This function allows developers to register one or more callback functions which will handle
 *  new value (data) events thrown by the driver. This allows 3rd party applications to handle new
 *  value (data) events in an event dsriven application design.
 *
 *  \param[in]  callback        A valid function pointer to a new value handler.
 *  \warning    Ensure the callback function remains valid until the driver instance is exited or
 *              the callback function is removed from the driver database.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamSetCallbackNewValue(EventNewValueCallback callback);

/*!
 *  \brief      Call this function to add a callback function to receive connected event signals.
 *
 *  This function allows developers to register one or more callback functions which will handle
 *  connection events thrown by the driver. This allows 3rd party applications to handle connection
 *  events in an event driven application design.
 *
 *  \param[in]  callback        A valid function pointer to a connected handler.
 *  \warning    Ensure the callback function remains valid until the driver instance is exited or
 *              the callback function is removed from the driver database.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamSetCallbackControllerConnected(EventCallback callback);

/*!
 *  \brief      Call this function to add a callback function to receive disconnected event signals.
 *
 *  This function allows developers to register one or more callback functions which will handle
 *  disconnection events thrown by the driver. This allows 3rd party applications to
 *  handle disconnection events in an event driven application design.
 *
 *  \param[in]  callback        A valid function pointer to a disconnected handler.
 *  \warning    Ensure the callback function remains valid until the driver instance is exited or
 *              the callback function is removed from the driver database.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamSetCallbackControllerDisconnected(EventCallback callback);

/*!
 *  \brief      Call this function to add a callback function to receive error event signals.
 *
 *  This function allows developers to register one or more callback functions which will handle events
 *  thrown by the driver. These events typically require external handling or display using
 *  pop-up dialog boxes. This callback system allows custom handling of these events as the driver 
 *  does not support pop-up dialog boxes directly.
 *
 *  \param[in]  callback        A valid function pointer to an error handler.
 *  \warning    Ensure the callback function remains valid until the driver instance is exited or
 *              the callback function is removed from the driver database.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamSetCallbackError(EventErrorCallback callback);

/*!
 *  \brief      Call this function to add a callback function to receive log message signals.
 *
 *  This function allows developers to register one or more callback functions which will handle log
 *  message events thrown by the driver. These events only need to be handle if you wish to record 
 *  driver log messages to your own application log. Log message events are only sent if you have 
 *  set the driver to prevent logging.
 *
 *  \param[in]  callback        A valid function pointer to a log message handler.
 *  \warning    Ensure the callback function remains valid until the driver instance is exited or
 *              the callback function is removed from the driver database.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamSetCallbackLog(EventLogCallback callback);

/*!
 *  \brief      Call this function to add a callback function to receive stage event signals.
 *
 *  This function allows developers to register one or more callback functions which will handle stage
 *  events thrown by the driver. These events only need to be handle if you wish to recieve stage events,
 *  and the stage type supports them.
 *
 *  \param[in]  callback        A valid function pointer to a log message handler.
 *  \warning    Ensure the callback function remains valid until the driver instance is exited or
 *              the callback function is removed from the driver database.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamSetCallbackEvent(EventStageEventCallback callback);

/*!
 *  \brief      Call this function to remove a callback function from receiving new value event signals.
 *
 *  This function allows developers to unregister one or more callback functions from the driver.
 *
 *  \param[in]  callback        A valid function pointer to a new value handler.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamRemoveCallbackNewValue(EventNewValueCallback callback);

/*!
 *  \brief      Call this function to remove a callback function from receiving connected event signals.
 *
 *  This function allows developers to unregister one or more callback functions from the driver.
 *
 *  \param[in]  callback        A valid function pointer to a connected handler.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamRemoveCallbackControllerConnected(EventCallback callback);

/*!
 *  \brief      Call this function to remove a callback function from receiving disconnected event signals.
 *
 *  This function allows developers to unregister one or more callback functions from the driver.
 *
 *  \param[in]  callback        A valid function pointer to a disconnected handler.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamRemoveCallbackControllerDisconnected(EventCallback callback);

/*!
 *  \brief      Call this function to remove a callback function from receiving error event signals.
 *
 *  This function allows developers to unregister one or more callback functions from the driver.
 *
 *  \param[in]  callback        A valid function pointer to an error handler.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamRemoveCallbackError(EventErrorCallback callback);

/*!
 *  \brief      Call this function to remove a callback function from receiving log message signals.
 *
 *  This function allows developers to unregister one or more callback functions from the driver.
 *
 *  \param[in]  callback        A valid function pointer to a log message handler.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamRemoveCallbackLog(EventLogCallback callback);

/*!
 *  \brief      Call this function to remove a callback function from receiving stage event signals.
 *
 *  This function allows developers to unregister one or more callback functions from the driver.
 *
 *  \param[in]  callback        A valid function pointer to a log message handler.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamRemoveCallbackEvent(EventStageEventCallback callback);

/*!
 *  \breif      Helper function to get the USB communications structure from a CommsInfo structure.
 *  \param[in]  info        A valid CommsInfo structure pointer.
 *  \return     Returns a pointer to the info region as a SerialCommsInfo structure if successful, else NULL.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL LinkamSDK::USBCommsInfo* linkamGetUSBCommsInfo(LinkamSDK::CommsInfo* info);

/*!
 *  \breif      Helper function to get the serial communications structure from a CommsInfo structure.
 *  \param[in]  info        A valid CommsInfo structure pointer.
 *  \return     Returns a pointer to the info region as a SerialCommsInfo structure if successful, else NULL.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL LinkamSDK::SerialCommsInfo* linkamGetSerialCommsInfo(LinkamSDK::CommsInfo* info);

#endif // LINKAM_SDK_H


