/************************************************************************
*
*   File:           linkamSDK.h
*
*   Description:    This is the Linkam SDK header for interfacing to
*                   Linkam devices. This may be used on Windows and Linux
*                   platforms.
*
*   Copyright © 2018 Linkam Scientific Instruments. All rights reserved
************************************************************************/
#ifndef LINKAM_SDK_H
#define LINKAM_SDK_H
#include <stddef.h>
#include "Message.h"
#include "EventAPI.h"


/*!
 *	\brief		Call this once to initialise the Linkam SDK library.
 *	\return		Returns 'true' if the SDK library was initialised correctly, else false.
 *
 *	This will initialise the SDK library for use; you cannot successfully call any SDK 
 *	function until this function has been called.
 *
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL bool linkamInitialiseSDK();

/*!
 *	\brief		Call this once to initialise the Linkam SDK library.
 *	\return		Returns no value.
 *
 *	This will perform all internal clean-up and will close all currently open connections
 *	to attached devices. Any device handles retained by the caller will no longer be valid.
 *
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamExitSDK();

/*!
 *  \brief      Call this function to obtain the version number for the SDK.
 *  \param[in]  version         A valid char pointer to a buffer large enough to hold the version
 *  \param[in]  length          The size in bytes of the buffer to hold the version number.
 *  \return     Returns 'true' if successful, else 'false'.
 *
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL bool linkamGetVersion(char* version, uint64_t length);

/*!
 *  \brief      Call this function to pass a message to the SDK. Messages are just codes to invoke
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
 *  \brief      This is a helper function for interfacing the SDK with languages that cannot support
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
LINKAM_API_CALL bool linkamProcessMessageCommon(uint32_t msg, CommsHandle hDevice, uint64_t* result, uint64_t param1, uint64_t param2, uint64_t param3);

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
 *  \brief      Helper function, call to initialise a \link LinkamSDK::CommsInfo CommsInfo \endlink structure with require information for a Serial device.
 *  \param[in]  info                    A valid pointer to a \link LinkamSDK::CommsInfo CommsInfo \endlink structure instance defining the connection properties.
 *  \param[in]  port                    A valid pointer to a null terminated char buffer holding the serial port name.
 *
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamInitialiseSerialCommsInfo(LinkamSDK::CommsInfo* info, const char* port);

/*!
 *  \brief      Call this function to add a callback function to receive new value event signals.
 *  \param[in]  callback        A valid function pointer to a new value handler.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamSetCallbackNewValue(EventNewValueCallback callback);

/*!
 *  \brief      Call this function to add a callback function to receive connected event signals.
 *  \param[in]  callback        A valid function pointer to a connected handler.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamSetCallbackControllerConnected(EventCallback callback);

/*!
 *  \brief      Call this function to add a callback function to receive disconnected event signals.
 *
 *  This function allows  developers to register one or more callback functions which will handle
 *  disconnection events thrown by the LinkamSDK library. This allows 3rd party applications to
 *  handle disconnection events in an event driven application design.
 *
 *  \param[in]  callback        A valid function pointer to a disconnected handler.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamSetCallbackControllerDisconnected(EventCallback callback);

/*!
 *  \brief      Call this function to add a callback function to receive error event signals.
 *
 *  This function allows developers to register one or more callback functions which will handle events
 *  thrown by the LinkamSDK library. These events typically require external handling or display using
 *  pop-up dialog boxes. This callback system allows custom handling of these events as the LinkamSDK 
 *  library does not support pop-up dialog boxes directly.
 *
 *  \param[in]  callback        A valid function pointer to an error handler.
 *  @ingroup    Library_Functions
 */
LINKAM_API_CALL void linkamSetCallbackError(EventErrorCallback callback);


#endif // LINKAM_SDK_H


