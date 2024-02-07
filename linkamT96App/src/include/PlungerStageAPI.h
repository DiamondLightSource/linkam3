/************************************************************************
*
*   File:           PlungerStageAPI.h
*
*   Description:    This header defines the common stage API used by the
*                   Linkam SDK.
*
*   Copyright © 2018-2023 Linkam Scientific Instruments. All rights reserved
************************************************************************/
#ifndef LINKAM_SDK__PLUNGER_STAGE_API_H
#define LINKAM_SDK__PLUNGER_STAGE_API_H
#include "ExportAPI.h"
#include "CommonTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

namespace LinkamSDK
{
    /*!
     *  \enum       PlungerStageValueType
     *  \brief      This enumerator defines a set of supported value IDs for accessing data fields from the plunger stage.
     *              PlungerStageValueType is used with \b GetValue, \b SetValue, \b GetMaxValue, and \b GetMinValue 
     *              LinkamMessageCodes, but must be converted to the equivilant StageValueType, these use the \b processMessage
     *              function. Each enumerator defines which arguments are used.
     *  \note       The PlungerStageValueType is passed to \b param1 of the \b processMessage function always. Returned values
     *              from the (\b Get) commands are returned in the result Variant parameter. Some \b PlungerStageValueType values
     *              also support an optional parameter for passing a specialised option to the (\b Get) commands. There 
     *              are no optional parameters supported for the (\b Set) command.
     *
     *  @ingroup    Stage_IO_API
     */
    enum PlungerStageValueType
    {

    };


#ifdef __cplusplus
}
#endif


#endif // LINKAM_SDK__PLUNGER_STAGE_API_H


