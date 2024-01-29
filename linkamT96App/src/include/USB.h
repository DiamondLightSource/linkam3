/************************************************************************
*
*   File:           USB.h
*
*   Description:    This header defines the USB data types used by the
*                   Linkam SDK library.
*
*   Copyright © 2018-2023 Linkam Scientific Instruments. All rights reserved
************************************************************************/
#ifndef LINKAM_SDK__USB_H
#define LINKAM_SDK__USB_H
#include "CommonTypes.h"
#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

namespace LinkamSDK
{
    /*!
     *  \struct     USBCommsInfo
     *  \brief      This structure defines the parameters 
     *              required to open a connection to a USB
     *              device.
     *
     *  \note       124 bytes long.
     *
     *  @ingroup    Comms_API
     */
    struct USBCommsInfo
    {
        uint16_t    vendorID;           ///< The 16 bit value for the vendor ID code for the device.
        uint16_t    productID;          ///< The 16 bit value for the product ID code for the device.
        char        serialNumber[17];   ///< A string holding the serial number for a specific device (optional). Ensure this is null terminated.
        uint8_t     padding[3];         ///< Reserved for internal use.
        uint32_t    timeout;            ///< Number of milliseconds to wait for a complete message.
        uint8_t     padding2[96];       ///< Reserved for internal use.
    };

    /*!
     *  \union      USBDeviceInfo
     *  \brief      This structure defines a structure for holding an enumerated USB device.
     *              This can be used to build a list of discovered devices for an application
     *              to display.
     *
     *  @ingroup    Comms_API
     */
    struct USBDeviceInfo
    {
        uint16_t    vendorID;               ///< The 16 bit value for the vendor ID code for the device.
        uint16_t    productID;              ///< The 16 bit value for the product ID code for the device.
        char        serialNumber[17];       ///< A string holding the serial number for a specific device. Ensure this is null terminated.
        uint8_t     padding1[3];            ///< Reserved for internal use.
        char        manufacturerName[25];   ///< A string holding the name of the manufacturer. Ensure this is null terminated.
        uint8_t     padding2[3];            ///< Reserved for internal use.
        char        productName[25];        ///< A string holding the name of the product. Ensure this is null terminated.
        uint8_t     padding3[3];            ///< Reserved for internal use.
    };
}

#ifdef __cplusplus
}
#endif

#endif // LINKAM_SDK__USB_H


