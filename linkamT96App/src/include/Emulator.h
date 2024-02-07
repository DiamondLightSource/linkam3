/************************************************************************
*
*   File:           Emulator.h
*
*   Description:    This header defines the Stage Emulator data types used
*                   by the Linkam SDK library.
*
*   Copyright © 2018-2023 Linkam Scientific Instruments. All rights reserved
************************************************************************/
#ifndef LINKAM_SDK__EMULATOR_H
#define LINKAM_SDK__EMULATOR_H
#include "CommonTypes.h"
#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

    namespace LinkamSDK
    {
        /*!
         *  \struct     EmulatorInfo
         *  \brief      This structure defines the parameters
         *              required to open a connection to a stage
         *              emulator.
         *
         *  \note       124 bytes long.
         *
         *  @ingroup    Comms_API
         */
        struct EmulatorInfo
        {
            uint32_t    stageType;
            uint8_t     haveLNP;
            uint8_t     haveHumidity;
            uint8_t     haveWCP;
            uint8_t     haveCoolingPost;
            uint8_t     padding1[116];       ///< Reserved for internal use.
        };
    }

#ifdef __cplusplus
}
#endif

#endif // LINKAM_SDK__EMULATOR_H



