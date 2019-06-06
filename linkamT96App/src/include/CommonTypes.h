/************************************************************************
*
*   File:           CommonTypes.h
*
*   Description:    This header defines the common data types used by the
*                   Linkam SDK library.
*
*   Copyright © 2018 Linkam Scientific Instruments. All rights reserved
************************************************************************/
#ifndef LINKAM_SDK__COMMON_TYPES_H
#define LINKAM_SDK__COMMON_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
    typedef signed char         int8_t;
    typedef unsigned char       uint8_t;
    typedef short               int16_t;
    typedef unsigned short      uint16_t;
    typedef __int32             int32_t;
    typedef unsigned __int32    uint32_t;
    typedef __int64             int64_t;
    typedef unsigned __int64    uint64_t;
    typedef double              float64_t;
    typedef float               float32_t;
#else
    #include <stdint.h>
    typedef double              float64_t;
    typedef float               float32_t;
#endif


/*!
 *  \typedef    CommsHandle
 *  \brief      Universal handle to a Comms port or device.
 *
 *  @ingroup    Connection_API
 */
typedef uint64_t    CommsHandle;


#ifndef unused
#define unused(inst) inst
#endif

#ifndef NULL
#define NULL (0)
#endif

/*!
 *  \brief      Used in conjuction with the LinkamFunctionMsgCode, this macro
 *              can be passed under param1 of the eLinkamFunctionMsgCode_EnableLogging
 *              command message to set the log output level to minimal. This reduces the
 *              amount of information printed to help reduce to size of log files.
 *  \note       The default level of logging is set to minimal, if you need
 *              to increase the level of information for tracking issues
 *              use the vobose level.
 *  @ingroup    Library_Functions
 */
#define LOGGING_LEVEL_MINIMAL (0)

/*!
 *  \brief      Used in conjuction with the LinkamFunctionMsgCode, this macro
 *              can be passed under param1 of the eLinkamFunctionMsgCode_EnableLogging
 *              command message to set the log output level to informative. This increases the
 *              amount of information printed to help reduce to size of log files for general
 *              responsiveness investigation. Required for soak testing and initial fault finding
 *              for the communications connectivity.
 *  \note       The default level of logging is set to minimal, if you need
 *              to increase the level of information for soak testing or initial comms issue tracking 
 *              the use the informative level.
 *  @ingroup    Library_Functions
 */
#define LOGGING_LEVEL_INFORMATIVE (1)

/*!
 *  \brief      Used in conjuction with the LinkamFunctionMsgCode, this macro
 *              can be passed under param1 of the eLinkamFunctionMsgCode_EnableLogging
 *              command message to set the log output level to vobose. This increases 
 *              the amount of information printed which increases the size of log files.
 *  \note       The default level of logging is set to minimal, if you need
 *              to increase the level of information for tracking issues
 *              use the vobose level.
 *  @ingroup    Library_Functions
 */
#define LOGGING_LEVEL_VOBOSE  (2)

/*!
 *  \brief      Used in conjuction with the LinkamFunctionMsgCode, this macro
 *              can be passed under param1 of the eLinkamFunctionMsgCode_EnableLogging
 *              command message to set the log output level to investigation. This level 
 *              will dramatically increases the amount of information printed to log files.
 *              This level should only be invoked on request by technical support.
 *  \note       The default level of logging is set to minimal, if you need
 *              a detailed fault tracking level of information then set the
 *              level to investigation. Note this mode can reduce performance.
 *  @ingroup    Library_Functions
 */
#define LOGGING_LEVEL_INVESTIGATION  (3)

#ifdef __cplusplus
}
#endif

#endif // LINKAM_SDK__COMMON_TYPES_H


