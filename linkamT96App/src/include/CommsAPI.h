/************************************************************************
*
*   File:           CommsAPI.h
*
*   Description:    This header defines the communication port handling
*                   API used by the Linkam SDK.
*
*   Copyright © 2018-2019 Linkam Scientific Instruments. All rights reserved
************************************************************************/
#ifndef LINKAM_SDK__COMMS_API_H
#define LINKAM_SDK__COMMS_API_H
#include "ExportAPI.h"
#include "CommonTypes.h"
#include "Serial.h"
#include "USB.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  \brief      The USB HID vendor ID for Linkam Scientific Instruments.
 *
 *  Use this vendor ID when creating connection requests to USB controller devices. This is
 *  the registered vendor ID for Linkam Scientific Instruments.
 *
 *  @ingroup    Comms_API
 */
#define LINKAM_SDK__USB_HID__VENDOR_ID          (0x16DA)

/*!
 *  \brief      The USB HID product ID for Linkam ...
 *
 *  Use this product ID to command the LinkamSDK library to automatically detect the type of
 *  controller device connected to the host machine. If you are connecting multiple controller
 *  devices then you must specify the serial number for the specific device you wish to connect
 *  to.
 *
 *  @ingroup    Comms_API
 */
#define LINKAM_SDK__USB_HID__AUTO_ID            (0x0001)

/*!
 *  \brief      The USB HID product ID for Linkam ...
 *
 *  Use this product ID to request the LinkamSDK library to connect to a T9x generation controller 
 *  (for example, T95 or T96). If you have multiple T9x controllers connected to the host machine 
 *  then you must specify the serial number of the specific device you wish to connect to.
 *
 *  @ingroup    Comms_API
 */
#define LINKAM_SDK__USB_HID__T9X_ID             (0x0002)

/*!
 *  \brief      The USB HID product ID for Linkam ...
 *
 *  Use this product ID to request the LinkamSDK library to connect to a LNP9x generation pump 
 *  (for example, LNP95 or LNP96). If you have multiple LNP9x pumps connected to the host machine 
 *  then you must specify the serial number of the specific device you wish to connect to.
 *
 *  @ingroup    Comms_API
 */
#define LINKAM_SDK__USB_HID__LNP9X_ID           (0x0003)

/*!
 *  \brief      The USB HID product ID for Linkam ...
 *
 *  Use this product ID to request the LinkamSDK library to connect to a INC95 device.
 *  If you have multiple INC95 devices connected to the host machine then you must specify the serial
 *  number of the specific device you wish to connect to.
 *
 *  @ingroup    Comms_API
 */
#define LINKAM_SDK__USB_HID__INC95_ID           (0x0004)

/*!
 *  \brief      The USB HID product ID for Linkam ...
 *
 *  Use this product ID to request the LinkamSDK library to connect to a D95 device.
 *  If you have multiple DC95 devices connected to the host machine then you must specify the serial
 *  number of the specific device you wish to connect to.
 *
 *  @ingroup    Comms_API
 */
#define LINKAM_SDK__USB_HID__DC95_ID            (0x0005)

/*!
 *  \brief      The USB HID product ID for Linkam ...
 *
 *  Use this product ID to request the LinkamSDK library to connect to a RH95 humidifier device.
 *  If you have multiple RH95 devices connected to the host machine then you must specify the serial
 *  number of the specific device you wish to connect to.
 *
 *  @ingroup    Comms_API
 */
#define LINKAM_SDK__USB_HID__RH95_ID            (0x0006)

/*!
 *  \brief      The USB HID product ID for Linkam ...
 *
 *  Use this product ID to request the LinkamSDK library to connect to a COR95 controller.
 *  If you have multiple COR95 controller connected to the host machine then you must specify the serial
 *  number of the specific device you wish to connect to.
 *
 *  @ingroup    Comms_API
 */
#define LINKAM_SDK__USB_HID__COR95_ID           (0x0007)

/*!
 *  \brief      The USB HID product ID for Linkam ...
 *
 *  Use this product ID to request the LinkamSDK library to connect to a WSC96 device.
 *  If you have multiple WSC96 devices connected to the host machine then you must specify the serial
 *  number of the specific device you wish to connect to.
 *
 *  @ingroup    Comms_API
 */
#define LINKAM_SDK__USB_HID__WSC96_ID           (0x0008)

/*!
 *  \brief      The USB HID product ID for Linkam ...
 *
 *  Use this product ID to request the LinkamSDK library to connect to a joystick.
 *  If you have multiple joystick devices connected to the host machine then you must specify the serial
 *  number of the specific device you wish to connect to.
 *
 *  @ingroup    Comms_API
 */
#define LINKAM_SDK__USB_HID__JOYSTICK_ID        (0x0009)

/*!
 *  \brief      The USB HID product ID for Linkam ...
 *
 *  Use this product ID to request the LinkamSDK library to connect to a Remote Light Source (RLS).
 *  If you have multiple RLS systems connected to the host machine then you must specify the serial
 *  number of the specific device you wish to connect to.
 *
 *  @ingroup    Comms_API
 */
#define LINKAM_SDK__USB_HID__ISRLS_ID           (0x000A)

/*!
 *  \brief      The USB HID product ID for Linkam ...
 *
 *  Use this product ID to request the LinkamSDK library to connect to a IS3TR device.
 *  If you have multiple IS3TR devices connected to the host machine then you must specify the serial
 *  number of the specific device you wish to connect to.
 *
 *  @ingroup    Comms_API
 */
#define LINKAM_SDK__USB_HID__IS3TR_ID           (0x000B)

/*!
 *  \brief      The USB HID product ID for Linkam ...
 *
 *  Use this product ID to request the LinkamSDK library to connect to a Glow Discharge device.
 *  If you have multiple Glow Discharge devices connected to the host machine then you must specify the serial
 *  number of the specific device you wish to connect to.
 *
 *  @ingroup    Comms_API
 */
#define LINKAM_SDK__USB_HID__GLOWDISCHARGE_ID   (0x000C)

/*!
 *  \brief      The USB HID product ID for Linkam ...
 *
 *  Use this product ID to request the LinkamSDK library to connect to a Electron Microscope Plunger device.
 *  If you have multiple Electron Microscope Plunger devices connected to the host machine then you must 
 *  specify the serial number of the specific device you wish to connect to.
 *
 *  @ingroup    Comms_API
 */
#define LINKAM_SDK__USB_HID__PLUNGER_ID         (0x000D)


namespace LinkamSDK
{
    /*!
     *  \enum       CommsType
     *  \brief      Part of the communications group, this enumerator
     *              provides a set of supported communications channel
     *              types.
     *
     *  @ingroup    Comms_API
     */
    enum CommsType
    {
        eCommsTypeNone          = 0,    ///< Invalid type value, use for initialistion of variables.
        eCommsTypeSerial        = 1,    ///< Open a connection to a serial COM port.
        eCommsTypeUSB           = 2     ///< Open a connection to a USB device.
    };

    /*!
     *  \struct     CommsInfo
     *  \brief      This structure defines the parameters 
     *              required to open a connection to a device.
     *              This is the base type for all CommsInfo
     *              structures.
     *
     *  @ingroup    Comms_API
     */
    struct CommsInfo
    {
        CommsType   type;           ///< The type of data held by this structure.
        char        info[124];      ///< Array holding the communication information structure. May be cast to either SerialCommsInfo or USBCommsInfo pointer.
    };

    /*!
     *  \union      ConnectionStatus
     *  \brief      This structure defines a set of flags which detail the connection status.
     *              This structure is passed to a calling program via the controller device,
     *              and defines tits connection status. Use this to determine if you have a
     *              stable connection or what errors occurred during the connection process.
     *
     *  @ingroup    Comms_API
     */
    union ConnectionStatus
    {
        struct
        {
            unsigned    connected                       : 1;    ///< bit  0: Flag defining successful connection (0 = Not Connected, 1 = Connected).
            unsigned    errorNoDeviceFound              : 1;    ///< bit  1: Flag defining vendor ID and/or product ID was not found.
            unsigned    errorMultipleDevicesFound       : 1;    ///< bit  2: Flag defining multiple devices with same vendor ID and/or product ID was not found.
            unsigned    errorTimeout                    : 1;    ///< bit  3: Flag defining time out of connection.
            unsigned    errorHandleRegistrationFailed   : 1;    ///< bit  4: Flag defining registration of the device handle failed.
            unsigned    errorAllocationFailed           : 1;    ///< bit  5: Flag defining allocation of resources failed.
            unsigned    errorSerialNumberRequired       : 1;    ///< bit  6: Flag defining a serial number is required for successful connection.
            unsigned    errorAlreadyOpen                : 1;    ///< bit  7: Flag defining that a valid connection already exists.
            unsigned    errorPropertiesIncorrect        : 1;    ///< bit  8: Flag defining that one or more connection properties are incorrect.
            unsigned    errorPortConfig                 : 1;    ///< bit  9: Flag defining that a general port configuration error occured.
            unsigned    errorCommsStreams               : 1;    ///< bit 10: Flag defining that the comms stream threads failed to start.
            unsigned    errorUnhandled                  : 1;    ///< bit 11: Flag defining that a general port configuration error occured.
            unsigned    unused12                        : 1;    ///< bit 12: Reserved for future use.
            unsigned    unused13                        : 1;    ///< bit 13: Reserved for future use.
            unsigned    unused14                        : 1;    ///< bit 14: Reserved for future use.
            unsigned    unused15                        : 1;    ///< bit 15: Reserved for future use.
            unsigned    unused16                        : 1;    ///< bit 16: Reserved for future use.
            unsigned    unused17                        : 1;    ///< bit 17: Reserved for future use.
            unsigned    unused18                        : 1;    ///< bit 18: Reserved for future use.
            unsigned    unused19                        : 1;    ///< bit 19: Reserved for future use.
            unsigned    unused20                        : 1;    ///< bit 20: Reserved for future use.
            unsigned    unused21                        : 1;    ///< bit 21: Reserved for future use.
            unsigned    unused22                        : 1;    ///< bit 22: Reserved for future use.
            unsigned    unused23                        : 1;    ///< bit 23: Reserved for future use.
            unsigned    unused24                        : 1;    ///< bit 24: Reserved for future use.
            unsigned    unused25                        : 1;    ///< bit 25: Reserved for future use.
            unsigned    unused26                        : 1;    ///< bit 26: Reserved for future use.
            unsigned    unused27                        : 1;    ///< bit 27: Reserved for future use.
            unsigned    unused28                        : 1;    ///< bit 28: Reserved for future use.
            unsigned    unused29                        : 1;    ///< bit 29: Reserved for future use.
            unsigned    unused30                        : 1;    ///< bit 30: Reserved for future use.
            unsigned    unused31                        : 1;    ///< bit 31: Reserved for future use.
        }           flags;                                      ///< Accessor to the flag feilds.
        uint32_t    value;                                      ///< Representation of the flags structure as a single value.
    };
}

#ifdef __cplusplus
}
#endif

#endif // LINKAM_SDK__COMMS_API_H


