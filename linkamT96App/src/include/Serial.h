/************************************************************************
*
*   File:           Serial.h
*
*   Description:    This header defines the serial data types used by the
*                   Linkam SDK library.
*
*   Copyright © 2018-2019 Linkam Scientific Instruments. All rights reserved
************************************************************************/
#ifndef LINKAM_SDK__SERIAL_H
#define LINKAM_SDK__SERIAL_H
#include "CommonTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

namespace LinkamSDK
{
    /*!
     *  \enum       ByteSize
     *  \brief      Part of the serial communications group, this enumerator
     *              defines a set of supported byte sizes for the serial port.
     *              ByteSize is used to determine the size of the data portion
     *              of the frame, the number of payload bits sent in the frame.
     *              This proterty instructs to port controller which is to be used.
     *
     *  @ingroup    Comms_API
     */
    enum ByteSize
    {
        eByteSizeFiveBits       = 5,    ///< Used to set the byte size for a word to 5 bits.
        eByteSizeSixBits        = 6,    ///< Used to set the byte size for a word to 6 bits.
        eByteSizeSevenBits      = 7,    ///< Used to set the byte size for a word to 7 bits.
        eByteSizeEightBits      = 8     ///< Used to set the byte size for a word to 8 bits.
    };

    /*!
     *  \enum       Parity
     *  \brief      Part of the serial communications group, this enumerator
     *              defines a set of supported parity types for the serial port.
     *              Parity is an error check value used to determine if the frame
     *              is safe or corrupted. This proterty instructs to port controller
     *              which is to be used.
     *
     *  @ingroup    Comms_API
     */
    enum Parity
    {
        eParityNone             = 0,    ///< Used to ignore parity check.
        eParityOdd              = 1,    ///< Used to check for an ODD value, when there are less 1's than 0's in the data.
        eParityEven             = 2,    ///< Used to check for an EVEN value, when there are more 1's than 0's in the data.
        eParityMark             = 3,    ///< Used to check for a MARK value or last bit of logical 1.
        eParitySpace            = 4     ///< Used to check for a SPACE value or last bit of logical 0.
    };

    /*!
     *  \enum       Stopbits
     *  \brief      Part of the serial communications group, this enumerator
     *              defines a set of supported stop bit types for the serial
     *              port. The stop bit defines the end of a frame and is a 
     *              number of consecutive bits after the parity. Used in bit
     *              syncronisation. This proterty instructs to port controller
     *              which is to be used.
     *
     *  @ingroup    Comms_API
     */
    enum Stopbits
    {
        eStopbitsOne            = 1,    ///< Used to denote stop is determined by the last bit of the frame held at MARK (logical 1) (timed).
        eStopbitsTwo            = 2,    ///< Used to denote stop is determined by the last 2 bits of the frame held at MARK (logical 1) (timed).
        eStopbitsOnePointFive   = 3     ///< Used to denote stop is determined by the last 1.5 bits of the frame held at MARK (logical 1) (timed).
    };

    /*!
     *  \enum       FlowControl
     *  \brief      Part of the serial communications group, this enumerator
     *              defines a set of supported flow control types for the serial
     *              port. Flow control is the ability to pause/resume transission
     *              of the data stream. This can be handled by the hardware or
     *              within the software, typically driver layer. Software will
     *              send one of two special codes XOFF or XON to signal transmission
     *              pause or resumption. This proterty instructs to port controller
     *              which is to be used.
     *
     *  @ingroup    Comms_API
     */
    enum FlowControl
    {
        eFlowControlNone        = 0,    ///< Used to denote that flow control is ignored.
        eFlowControlSoftware    = 1,    ///< Used to denote that flow control is handled by software (use of code XOFF/XON for transmission pause/resume).
        eFlowControlHardware    = 2     ///< Used to denote that flow control is handled by hardware.
    };

    /*!
     *  \struct     SerialCommsInfo
     *  \brief      This structure defines the parameters 
     *              required to open a connection to a serial
     *              COMS port.
     *
     *  \note       124 bytes long.
     *
     *  @ingroup    Comms_API
     */
    struct SerialCommsInfo
    {
        char            port[64];     ///< Array used to hold a string for the name of the serial port to connect to. Ensure this is null terminated.
        uint32_t        baudrate;     ///< The speed of the connection required.
        ByteSize        bytesize;     ///< The number of bits which determine a byte over the serial connection.
        Parity          parity;       ///< The parity setting for the port.
        Stopbits        stopbits;     ///< The number of bits which determine a stop for the port.
        FlowControl     flowcontrol;  ///< The flow control setting for the port.
        uint32_t        timeout;      ///< Number of milliseconds to wait for a connection.
        uint8_t         padding[36];  ///< Reserved for internal use.
    };
}

#ifdef __cplusplus
}
#endif

#endif // LINKAM_SDK__SERIAL_H


