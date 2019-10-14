/************************************************************************
*
*   File:           CommonStageAPI.h
*
*   Description:    This header defines the common stage API used by the
*                   Linkam SDK.
*
*   Copyright © 2018-2019 Linkam Scientific Instruments. All rights reserved
************************************************************************/
#ifndef LINKAM_SDK__COMMON_STAGE_API_H
#define LINKAM_SDK__COMMON_STAGE_API_H
#include "ExportAPI.h"
#include "CommonTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

namespace LinkamSDK
{
    /*!
     *  \brief      The limit on the vacuum sensor which determines we have atmospheric perssure.
     *              This is messaured in millbars (mBar). Used in conjunction with eStageValueTypeVacuumLimit.
     *  @ingroup    Stage_Config_API
     */
    #define AtmosphericLimit (2e3f)

    /*!
     *  \brief      The limit on the vacuum sensor which determines we have vacuum perssure.
     *              This is messaured in millbars (mBar). Used in conjunction with eStageValueTypeVacuumLimit.
     *  @ingroup    Stage_Config_API
     */
    #define MaxVacuumLimit (5e-4f)

    /*!
     *  \enum       StageValueType
     *  \brief      This enumerator defines a set of supported value IDs for accessing data fields from the stage.
     *              StageValueType is used with \b GetValue, \b SetValue, \b GetMaxValue, and \b GetMinValue LinkamMessageCodes,
     *              these use the \b processMessage function. Each enumerator defines which arguments are used.
     *  \note       The StageValueType is passed to \b param1 of the \b processMessage function always. Returned values
     *              from the (\b Get) commands are returned in the result Variant parameter. Some \b StageValueType values
     *              also support an optional parameter for passing a specialised option to the (\b Get) commands. There 
     *              are no optional parameters supported for the (\b Set) command.
     *
     *  @ingroup    Stage_IO_API
     */
    enum StageValueType
    {
        /*!
         *  \brief          The primary sensor temperature reading (°C). For all stages this 
         *                  is the main stage temperature reading, except for the CMS stage 
         *                  where this is the bridge temperature.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeHeater1Temp                                  =  0,

        /*!
         *  \brief          The universal heater rate (°C/min). This value defines the speed at 
         *                  which the temperature changes.
         *  \param[in]      param2      Is a 32bit floating point value (°C/min) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C/min) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired
         *                  by the GetValue command.
         *  \remark         Linkam stages support up to two active heaters, depending on stage type. Heaters are controlled in
         *                  unison, you cannot control heaters independently.
         */
        eStageValueTypeHeaterRate                                   =  1,

        /*!
         *  \brief          The universal heater set point (°C), this value defines the temperature
         *                  to obtain.
         *  \param[in]      param2      Is a 32bit floating point value (°C) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \remark         Linkam stages support up to two active heaters, depending on stage type. Heaters are controlled in
         *                  unison, you cannot control heaters independently.
         */
        eStageValueTypeHeaterSetpoint                               =  2,

        /*!
         *  \brief          The primary heater power (%). This value defines the power consumption
         *                  of the heater.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (%).
         *  \note           This value may be set using the SetValue command or acquired by the 
         *                  GetValue command.
         */
        eStageValueTypeHeater1Power                                 =  3,
        
        /*!
         *  \brief          The primary heater LNP speed (%), this value defines the amount of
         *                  cooling power deployed.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (%).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeHeater1LNPSpeed                              =  4,

        /*!
         *  \brief          The secondary sensor temperature reading (°C). For stages that 
         *                  support a secondary temperature reading. For the CMS stage 
         *                  this is the chamber temperature.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeHeater2Temp                                  =  5,
#if 0
        /*!
         *  \brief          Reserved for future use.
         */
        eStageValueTypeReserved1                                    =  6,

        /*!
         *  \brief          Reserved for future use.
         */
        eStageValueTypeReserved2                                    =  7,
#endif
        /*!
         *  \brief          The secondary heater power (%). This value defines the power consumption
         *                  of the heater.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (%).
         *  \note           This value may be set using the SetValue command or acquired by the 
         *                  GetValue command.
         */
        eStageValueTypeHeater2Power                                 =  8,

        /*!
         *  \brief          The secondary heater LNP speed (%), this value defines the amount of
         *                  cooling power deployed.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (%).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeHeater2LNPSpeed                              =  9,

        /*!
         *  \brief          The water temperature from the cooling unit pump.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C).
         *  \note           This value may be acquired by the GetValue command.
         *  \note           Only applicible if a connected water cooling unit is present.
         */
        eStageValueTypeWaterCoolingTemp                             = 10,

        /*!
         *  \brief          The water temperature as reported from the humidity unit.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C).
         *  \note           This value may be acquired by the GetValue command.
         *  \note           Only applicible if a connected humidity unit is present.
         */
        eStageValueTypeHumidityTemp                                 = 11,

        /*!
         *  \brief          The primary vacuum pressure within the stage sample chamber.
         *  \param[in]      param2      The vacuum sensor to get (0= primary, 1=primary, 2=secondary).
         *  \param[out]     result      Returns a 32bit floating point value, check the vacuum unit
         *                              of measure set to determine what this value is.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           Only applicible if the connected stage is a vacuum based stage.
         *                  This will be the primary vacuum sensor if two vacuum sensors are
         *                  supported, else this will be the only vacuum sensor within the
         *                  stage.
         *  \see            eStageValueTypeVacuumBoardUnitOfMeasure
         *  \see            eStageValueTypeSecondaryVacuum
         */
        eStageValueTypeVacuum                                       = 12,

        /*!
         *  \brief          The vacuum pressure set point within the stage sample chamber.
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), check the vacuum unit
         *                              of measure set to determine what this value is. If calling (\b Set) this is ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Only applicible if the connected stage is a vacuum based stage.
         *  \see            eStageValueTypeVacuumBoardUnitOfMeasure
         */
        eStageValueTypeVacuumSetpoint                               = 13,

        /*!
         *  \brief          The humidity % as reported from the humidity unit.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (%).
         *  \note           This value may be acquired by the GetValue command.
         *  \note           Only applicible if a connected humidity unit is present.
         */
        eStageValueTypeHumidity                                     = 14,

        /*!
         *  \brief          The humidity % set point within the humidity unit.
         *  \param[in]      param2      Is a 32bit floating point value (%) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (%) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Only applicible if a connected humidity unit is present.
         */
        eStageValueTypeHumiditySetpoint                             = 15,

        /*!
         *  \brief          The X axis motor position for stages that either use X motor option boards
         *                  or have integrated motor systems.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm).
         *  \note           This value may be acquired by the GetValue command.
         *  \note           Only applicible if an X axis motor option board is installed
         *                  in the controller, or uses an integrated motor systems such as
         *                  the CMS stage.
         */
        eStageValueTypeMotorPosX                                    = 16,

        /*!
         *  \brief          The X axis motor velocity for stages that either
         *                  use X motor option boards or have integrated motor systems.
         *  \param[in]      param2      Is a 32bit floating point value (μm/s) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm/s) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Only applicible if an X axis motor option board is installed
         *                  in the controller, or uses an integrated motor systems such as
         *                  the CMS stage.
         */
        eStageValueTypeMotorVelX                                    = 17,
        
        /*!
         *  \brief          The X axis motor distance set point for stages that either
         *                  use X motor option boards or have integrated motor systems. Use this
         *                  to program a maximum distance to travel.
         *  \param[in]      param2      Is a 32bit floating point value (μm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Only applicible if an X axis motor option board is installed
         *                  in the controller, or uses an integrated motor systems such as
         *                  the CMS stage.
         */
        eStageValueTypeMotorSetpointX                               = 18,

        /*!
         *  \brief          The Y axis motor position for stages that either
         *                  use Y motor option boards or have integrated motor systems.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm).
         *  \note           This value may be acquired by the GetValue command.
         *  \note           Only applicible if an Y axis motor option board is installed
         *                  in the controller, or uses an integrated motor systems such as
         *                  the CMS stage.
         */
        eStageValueTypeMotorPosY                                    = 19,
        
        /*!
         *  \brief          The Y axis motor velocity for stages that either
         *                  use Y motor option boards or have integrated motor systems.
         *  \param[in]      param2      Is a 32bit floating point value (μm/s) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm/s) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Only applicible if an Y axis motor option board is installed
         *                  in the controller, or uses an integrated motor systems such as
         *                  the CMS stage.
         */
        eStageValueTypeMotorVelY                                    = 20,
        
        /*!
         *  \brief          The Y axis motor distance set point for stages that either
         *                  use Y motor option boards or have integrated motor systems. Use this
         *                  to program a maximum distance to travel.
         *  \param[in]      param2      Is a 32bit floating point value (μm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Only applicible if an Y axis motor option board is installed
         *                  in the controller, or uses an integrated motor systems such as
         *                  the CMS stage.
         */
        eStageValueTypeMotorSetpointY                               = 21,

        /*!
         *  \brief          The Z axis motor position for stages that either
         *                  use Z motor option boards or have integrated motor systems.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           Only applicible if an Z axis motor option board is installed
         *                  in the controller, or uses an integrated motor systems.
         */
        eStageValueTypeMotorPosZ                                    = 22,

        /*!
         *  \brief          The Z axis motor velocity for stages that either
         *                  use Z motor option boards or have integrated motor systems.
         *  \param[in]      param2      Is a 32bit floating point value (μm/s) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm/s) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Only applicible if an Z axis motor option board is installed
         *                  in the controller, or uses an integrated motor systems.
         */
        eStageValueTypeMotorVelZ                                    = 23,

        /*!
         *  \brief          The Z axis motor distance set point for stages that either
         *                  use Z motor option boards or have integrated motor systems. Use this
         *                  to program a maximum distance to travel.
         *  \param[in]      param2      Is a 32bit floating point value (μm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Only applicible if an Z axis motor option board is installed
         *                  in the controller, or uses an integrated motor systems.
         */
        eStageValueTypeMotorSetpointZ                               = 24,

        /*!
         *  \brief          The motor status for stages that either
         *                  use motor option boards or have integrated motor systems.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a MDSStatus value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           Only applicible if a motor option board is installed
         *                  in the controller, or uses an integrated motor systems.
         */
        eStageValueTypeMotorDrivenStageStatus                       = 25,

        /*!
         *  \brief          The unit of measure for the vacuum card.
         *  \param[in]      param2      Is a 32bit unsigned integer (BAR (mBar) = 15, PASCALS (kPa) = 16, TORR (mTorr) = 17) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit unsigned integer (BAR (mBar) = 15, PASCALS (kPa) = 16, TORR (mTorr) = 17) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeVacuumBoardUnitOfMeasure                     = 26,

        /*!
         *  \brief          The vacuum motor valve status.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a MVStatus value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeVacMotorValveStatus                          = 27,

        /*!
         *  \brief          The vacuum valve motor position for stages that
         *                  use vacuum motor option boards.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           Only applicible if an vacuum motor option board is installed
         *                  in the controller.
         */
        eStageValueTypeVacMotorValvePos                             = 28,

        /*!
         *  \brief          The vacuum valve motor velocity for stages that either
         *                  use vacuum motor option boards.
         *  \param[in]      param2      Is a 32bit floating point value (μm/s) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm/s) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Only applicible if an vacuum motor option board is installed
         *                  in the controller.
         */
        eStageValueTypeVacMotorValveVel                             = 29,

        /*!
         *  \brief          The vacuum valve motor set point for stages that either
         *                  use vacuum motor option boards. Use this to program a maximum distance
         *                  to travel.
         *  \param[in]      param2      Is a 32bit floating point value (μm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Only applicible if an vacuum motor option board is installed
         *                  in the controller.
         */
        eStageValueTypeVacMotorValveSetpoint                        = 30,

        /*!
         *  \brief          The graded stage motor position.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           Only applicible if a graded stage is used with the
         *                  controller. Graded stages use integrated motor systems.
         */
        eStageValueTypeGradedMotorPos                               = 31,

        /*!
         *  \brief          The graded stage motor velocity.
         *  \param[in]      param2      Is a 32bit floating point value (μm/s) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm/s) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Only applicible if a graded stage is used with the
         *                  controller. Graded stages use integrated motor systems.
         */
        eStageValueTypeGradedMotorVel                               = 32,

        /*!
         *  \brief          The graded stage motor distance limit. Use this to
         *                  program a maximum distance
         *                  to travel.
         *  \param[in]      param2      Is a 32bit floating point value (μm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Only applicible if a graded stage is used with the
         *                  controller. Graded stages use integrated motor systems.
         */
        eStageValueTypeGradedMotorDistanceSetpoint                  = 33,

        /*!
         *  \brief          The stages' reference value for sample 1, the first calibration point.
         *                  Reference calibration points are either 'known recorded' or 'theoretical' temperature
                            points of specific properties of a matrial.
         *  \param[in]      param2      Is a 32bit floating point value (°C) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           The default value is programmed to the stage in-factory. This value may be
         *                  independently set and saved to the stage if required.
         *  \warning        Linkam Scientific Instruments do not recommended the replacement of the in-factory
         *                  calibrated reference values. Only qualified individual should attempt this. Linkam
         *                  Scientific Instruments does not accept any liability if these values are replaced.
         */
        eStageValueTypeSampleRef1                                   = 34,

        /*!
         *  \brief          The stages' actual (stage measured) value for sample 1, the first calibration
         *                  point. Actual sample calibration points are used as baselines for measuring calibrated
         *                  temperatures acording to the stages' sensors. Actual calibration points can be safely
         *                  replace by individuals.
         *  \param[in]      param2      Is a 32bit floating point value (°C) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           The default value is programmed to the stage in-factory. This value may be
         *                  independently set and saved to the stage if required.
         */
        eStageValueTypeSampleAct1                                   = 35,

        /*!
         *  \brief          The stages' reference value for sample 1, the second calibration point.
         *                  Reference calibration points are either 'known recorded' or 'theoretical' temperature
                            points of specific properties of a matrial.
         *  \param[in]      param2      Is a 32bit floating point value (°C) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           The default value is programmed to the stage in-factory. This value may be
         *                  independently set and saved to the stage if required.
         *  \warning        Linkam Scientific Instruments do not recommended the replacement of the in-factory
         *                  calibrated reference values. Only qualified individual should attempt this. Linkam
         *                  Scientific Instruments does not accept any liability if these values are replaced.
         */
        eStageValueTypeSampleRef2                                   = 36,

        /*!
         *  \brief          The stages' actual (stage measured) value for sample 2, the second calibration
         *                  point. Actual sample calibration points are used as baselines for measuring calibrated
         *                  temperatures acording to the stages' sensors. Actual calibration points can be safely
         *                  replace by individuals.
         *  \param[in]      param2      Is a 32bit floating point value (°C) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           The default value is programmed to the stage in-factory. This value may be
         *                  independently set and saved to the stage if required.
         */
        eStageValueTypeSampleAct2                                   = 37,

        /*!
         *  \brief          The stages' reference value for sample 3, the third calibration point.
         *                  Reference calibration points are either 'known recorded' or 'theoretical' temperature
                            points of specific properties of a matrial.
         *  \param[in]      param2      Is a 32bit floating point value (°C) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           The default value is programmed to the stage in-factory. This value may be
         *                  independently set and saved to the stage if required.
         *  \warning        Linkam Scientific Instruments do not recommended the replacement of the in-factory
         *                  calibrated reference values. Only qualified individual should attempt this. Linkam
         *                  Scientific Instruments does not accept any liability if these values are replaced.
         */
        eStageValueTypeSampleRef3                                   = 38,

        /*!
         *  \brief          The stages' actual (stage measured) value for sample 3, the third calibration
         *                  point. Actual sample calibration points are used as baselines for measuring calibrated
         *                  temperatures acording to the stages' sensors. Actual calibration points can be safely
         *                  replace by individuals.
         *  \param[in]      param2      Is a 32bit floating point value (°C) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           The default value is programmed to the stage in-factory. This value may be
         *                  independently set and saved to the stage if required.
         */
        eStageValueTypeSampleAct3                                   = 39,

        /*!
         *  \brief          Ehe stages' reference value for sample 4, the fourth calibration point.
         *                  Reference calibration points are either 'known recorded' or 'theoretical' temperature
                            points of specific properties of a matrial.
         *  \param[in]      param2      Is a 32bit floating point value (°C) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           The default value is programmed to the stage in-factory. This value may be
         *                  independently set and saved to the stage if required.
         *  \warning        Linkam Scientific Instruments do not recommended the replacement of the in-factory
         *                  calibrated reference values. Only qualified individual should attempt this. Linkam
         *                  Scientific Instruments does not accept any liability if these values are replaced.
         */
        eStageValueTypeSampleRef4                                   = 40,

        /*!
         *  \brief          The stages' actual (stage measured) value for sample 4, the fourth calibration
         *                  point. Actual sample calibration points are used as baselines for measuring calibrated
         *                  temperatures acording to the stages' sensors. Actual calibration points can be safely
         *                  replace by individuals.
         *  \param[in]      param2      Is a 32bit floating point value (°C) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           The default value is programmed to the stage in-factory. This value may be
         *                  independently set and saved to the stage if required.
         */
        eStageValueTypeSampleAct4                                   = 41,

        /*!
         *  \brief          The stages' reference value for sample 5, the fifth calibration point.
         *                  Reference calibration points are either 'known recorded' or 'theoretical' temperature
                            points of specific properties of a matrial.
         *  \param[in]      param2      Is a 32bit floating point value (°C) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           The default value is programmed to the stage in-factory. This value may be
         *                  independently set and saved to the stage if required.
         *  \warning        Linkam Scientific Instruments do not recommended the replacement of the in-factory
         *                  calibrated reference values. Only qualified individual should attempt this. Linkam
         *                  Scientific Instruments does not accept any liability if these values are replaced.
         */
        eStageValueTypeSampleRef5                                   = 42,

        /*!
         *  \brief          The stages' actual (stage measured) value for sample 5, the fifth calibration
         *                  point. Actual sample calibration points are used as baselines for measuring calibrated
         *                  temperatures acording to the stages' sensors. Actual calibration points can be safely
         *                  replace by individuals.
         *  \param[in]      param2      Is a 32bit floating point value (°C) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           The default value is programmed to the stage in-factory. This value may be
         *                  independently set and saved to the stage if required.
         */
        eStageValueTypeSampleAct5                                   = 43,

        /*!
         *  \brief          The third sensor temperature reading (°C). For stages that 
         *                  support a third temperature reading. For the CMS stage 
         *                  this is the bottom dewar temperature, the temperature at the
         *                  bottom of the dewar.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (°C) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeHeater3Temp                                  = 44,

        /*!
         *  \brief          The current DSC (Differential Scanning Calorimetry) count value.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit unsigned integer value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeDsc                                          = 45,

        /*!
         *  \brief          The current value of the blue trigger channel.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           Trigger signals are user programmable signals which can be
         *                  be used to either send or receive a signals from the controller.
         *                  These may be used in conjuction with any stage for custom
         *                  control of an experiment, such as invoking a 3rd party device
         *                  or sensor.
         *  \note           The blue channel is used to receive a single only.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTriggerSignalBlue                            = 46,

        /*!
         *  \brief          The current value of the green trigger channel.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           Trigger signals are user programmable signals which can be
         *                  be used to either send or receive a signals from the controller.
         *                  These may be used in conjuction with any stage for custom
         *                  control of an experiment, such as invoking a 3rd party device
         *                  or sensor.
         *  \note           The green channel is used to transmit a signal only.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTriggerSignalGreen                            = 47,

        /*!
         *  \brief          The current value of the pink trigger channel.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           Trigger signals are user programmable signals which can be
         *                  be used to either send or receive a signals from the controller.
         *                  These may be used in conjuction with any stage for custom
         *                  control of an experiment, such as invoking a 3rd party device
         *                  or sensor.
         *  \note           The pink channel is used to transmit a signal only.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTriggerSignalPink                            = 48,

        /*!
         *  \brief          The enabled state of the trigger signals.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTriggerSignalsEnabled                        = 49,

        /*!
         *  \brief          The current temperature resoultion on the controller.
         *  \param[in]      param2      Is a 32bit unsigned integer value defining the resolution setting (0 = 0.1, 1 = 0.01, 2 = 0.001) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit unsigned integer value defining the resolution setting (0 = 0.1, 1 = 0.01, 2 = 0.001) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeTemperatureResolution                        = 50,

        /*!
         *  \brief          The forth sensor temperature reading (°C). For stages that 
         *                  support a forth temperature reading. For the CMS stage 
         *                  this is the base temperature.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeHeater4Temp                                  = 51,

        /*!
         *  \brief          The CMS sample chamber light state.
         *  \param[in]      param2      Is a Boolean value (false = OFF, true = ON) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a Boolean value (false = OFF, true = ON) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeCmsLight                                     = 52,

        /*!
         *  \brief          The CMS warming heater state.
         *  \param[in]      param2      Is a Boolean value (false = OFF, true = ON) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the SetValue command.
         */
        eStageValueTypeCmsWarmingHeater                             = 53,

        /*!
         *  \brief          The CMS solenoid refill state.
         *  \param[in]      param2      Is a Boolean value (false = OFF, true = ON) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the SetValue command.
         */
        eStageValueTypeCmsSolenoidRefill                            = 54,

        /*!
         *  \brief          The CMS sample dewar filling signal state.
         *  \param[in]      param2      Is a Boolean value (false = Stop, true = Fill) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a Boolean value (false = Stop, true = Fill) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeCmsSampleDewarFillSig                        = 55,

        /*!
         *  \brief          The current CMS operational status flags. These can be used 
         *                  to determine what the CMS is doing, or has finished doing.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a CMSStatus value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeCmsStatus                                    = 56,

        /*!
         *  \brief          The current CMS error flags.These can be used to determine what 
         *                  errors the CMS has encountered.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a CMSError value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeCmsError                                     = 57,

        /*!
         *  \brief          The primary ramp for the primary heater hold time.
         *  \param[in]      param2      Is a 32bit floating point value (sec) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (sec) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Future versions will support additional parallel ramp profilers
         *                  for the additional heaters. These ramps will allow the heaters 
         *                  to be controlled independently.
         *  \note           The time value may be between 0s and 3599999s (0s - 999h 59m 59s or 41 days).
         */
        eStageValueTypeRampHoldTime                                 = 58,

        /*!
         *  \brief          The primary ramp hold time remaining value.
         *  \param[in]      param2      Is a 32bit floating point value (sec) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (sec) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           Future versions will support additional parallel ramp profilers
         *                  for the additional heaters. These ramps will allow the heaters 
         *                  to be controlled independently.
         */
        eStageValueTypeRampHoldRemaining                            = 59,

        /*!
         *  \brief          The CMS main dewar filling signal state.
         *  \param[in]      param2      Is a Boolean value (false = Stop, true = Fill) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a Boolean value (false = Stop, true = Fill) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeCmsMainDewarFillSig                          = 60,

        /*!
         *  \brief          The CMS condenser led level.
         *  \param[in]      param2      Is a 16bit unsigned integer value (0-100, 0 = OFF, 100 = Full Brightness) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 16bit unsigned integer value (0-100, 0 = OFF, 100 = Full Brightness) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeCmsCondenserLEDLevel                         = 61,

        /*!
         *  \brief          The test motion command  (\b linkam \b only), used on motion capable stages.
         *  \param[in]      param2      Is a 16bit unsigned integer value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 16bit unsigned integer value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \warning        Linkam Scientific Instruments do not recommend
         *                  third parties to use this stage value. It is used
         *                  in diagnositic modes. Call this at your own risk.
         */
        eStageValueTypeTestMotion                                   = 62,

        /*!
         *  \brief          X & Y Motor feedback mode (\b linkam \b only).
         *  \param[in]      param2      Is a 16bit unsigned integer value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 16bit unsigned integer value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \warning        Linkam Scientific Instruments do not recommend
         *                  third parties to use this stage value. It is used
         *                  drive motors in a feedback mode.
         *                  Call this at your own risk.
         */
        eStageValueTypeMotorFeedbackYX                              = 63,

        /*!
         *  \brief          The tensile motor position.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTstMotorPos                                  = 64,

        /*!
         *  \brief          The tensile motor velocity.
         *  \param[in]      param2      Is a 32bit floating point value (μm/s) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm/s) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeTstMotorVel                                  = 65,

        /*!
         *  \brief          The tensile motor distance set point.
         *  \param[in]      param2      Is a 32bit floating point value (μm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           (\b Set) this parameter to be the distance you would like the jaws to open when "StartMotors" is called.
         *                  A positive to close jaws, else negative to open.
         *  \note           (\b Get) the current distance limit of the jaws.
         */
        eStageValueTypeTstMotorDistanceSetpoint                     = 66,

        /*!
         *  \brief          The tensile force as measured by the stage.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (N).
         *  \note           This value may be acquired by the GetValue command. The maximum force value can be acquired by the 
         *                  GetMaxValue command. The maximum force is not the same as the value obtained by eStageValueTypeTstForceGauge,
         *                  this returns the rated value of the transducer (beam).
         */
        eStageValueTypeTstForce                                     = 67,

        /*!
         *  \brief         The tensile Force set-point.
         *  \param[in]      param2      Is a 32bit floating point value (N) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (N) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeTstForceSetpoint                             = 68,

        /*!
         *  \brief          The tensile proportional gain factor tuning constant (Kp), part of the proportional–integral–derivative (PID) controller.
         *
         * Term \b P is proportional to the current value of the <b>SP − PV error e(t)</b>. error value <b>e ( t )</b> as the 
         * difference between a desired setpoint <b>SP = r ( t )</b> and a measured process variable <b>PV = y ( t )</b>.
         * For example, if the error is large and positive, the control output will be proportionately large and positive, taking
         * into account the gain factor \b K. Using proportional control alone will result in an error between the setpoint and the
         * actual process value, because it requires an error to generate the proportional response. If there is no error, there 
         * is no corrective response.
         *
         * It is important that the tuning constants are derived for each control application, as they depend on the response 
         * characteristics of the complete loop external to the controller. These are dependent on the behaviour of the measuring
         * sensor, the final control element (such as a control valve), any control signal delays and the process itself. Approximate 
         * values of constants can usually be initially entered knowing the type of application, but they are normally refined, or 
         * tuned, by "bumping" the process in practice by introducing a setpoint change and observing the system response. 
         *
         *  \param[in]      param2      Is a 32bit floating point value (proportional gain factor tuning constant (Kp)) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (proportional gain factor tuning constant (Kp)) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \see            https://en.wikipedia.org/wiki/PID_controller
         */
        eStageValueTypeTstPidKp                                     = 69,

        /*!
         *  \brief          The tensile integral gain factor tuning constant (Ki), part of the proportional–integral–derivative (PID) controller.
         *
         * Term \b I accounts for past values of the <b>SP − PV</b> error and integrates them over time to produce the I term. For example, if there 
         * is a residual <b>SP − PV</b> error after the application of proportional control, the integral term seeks to eliminate the residual error 
         * by adding a control effect due to the historic cumulative value of the error. When the error is eliminated, the integral term will cease 
         * to grow. This will result in the proportional effect diminishing as the error decreases, but this is compensated for by the growing 
         * integral effect.
         *
         * It is important that the tuning constants are derived for each control application, as they depend on the response 
         * characteristics of the complete loop external to the controller. These are dependent on the behaviour of the measuring
         * sensor, the final control element (such as a control valve), any control signal delays and the process itself. Approximate 
         * values of constants can usually be initially entered knowing the type of application, but they are normally refined, or 
         * tuned, by "bumping" the process in practice by introducing a setpoint change and observing the system response. 
         *
         *  \param[in]      param2      Is a 32bit floating point value (integral gain factor tuning constant (Ki)) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (integral gain factor tuning constant (Ki)) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \see            https://en.wikipedia.org/wiki/PID_controller
         */
        eStageValueTypeTstPidKi                                     = 70,

        /*!
         *  \brief          The tensile derivative gain factor tuning constant (Kd), part of the proportional–integral–derivative (PID) controller.
         *
         * Term \b D is a best estimate of the future trend of the <b>SP − PV</b> error, based on its current rate of change. It is sometimes called 
         * "anticipatory control", as it is effectively seeking to reduce the effect of the <b>SP − PV</b> error by exerting a control influence 
         * generated by the rate of error change. The more rapid the change, the greater the controlling or dampening effect.
         *
         * It is important that the tuning constants are derived for each control application, as they depend on the response 
         * characteristics of the complete loop external to the controller. These are dependent on the behaviour of the measuring
         * sensor, the final control element (such as a control valve), any control signal delays and the process itself. Approximate 
         * values of constants can usually be initially entered knowing the type of application, but they are normally refined, or 
         * tuned, by "bumping" the process in practice by introducing a setpoint change and observing the system response. 
         *
         *  \param[in]      param2      Is a 32bit floating point value (derivative gain factor tuning constant (Kd)) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (derivative gain factor tuning constant (Kd)) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \see            https://en.wikipedia.org/wiki/PID_controller
         */
        eStageValueTypeTstPidKd                                     = 71,

        /*!
         *  \brief          The tensile stage force transducer size.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (N).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTstForceGauge                                = 72,

        /*!
         *  \brief          The CSS mode of operation. 
         *  \param[in]      param2      Is a CSSMode value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a CSSMode value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeCssMode                                      = 73,

        /*!
         *  \brief          The CSS gap distance set point, the target distance. 
         *  \param[in]      param2      Is a 32bit floating point value (µm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (µm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeCssGapSetpoint                               = 74,

        /*!
         *  \brief          The CSS stage current gap distance.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (µm).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeCssGapPos                                    = 75,

        /*!
         *  \brief          The CSS shear strain; valid on Step and Osc modes only. 
         *  \param[in]      param2      Is a 32bit floating point value (?) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (?) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeCssStrainSetpoint                            = 76,

        /*!
         *  \brief          The CSS shear rate set point.
         *  \param[in]      param2      Is a 32bit floating point value (S-1) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (S-1) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           S - is shear strain.
         */
        eStageValueTypeCssRateSetpoint                              = 77,

        /*!
         *  \brief          The CSS oscillation frequency; valid in oscillatory mode only.
         *  \param[in]      param2      Is a 32bit floating point value (Hz) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (Hz) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeCssOcsFreq                                   = 78,

        /*!
         *  \brief          The direction of the CSS rotational motor.
         *  \param[in]      param2      Is a boolean value (Anti-Clockwise = true, Clockwise = false) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (Anti-Clockwise = true, Clockwise = false) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeCssDirn                                      = 79,

        /*!
         *  \brief          The CSS rotational velocity for jog mode.
         *  \param[in]      param2      Is a 32bit floating point value (?) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (?) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Set a negative velocity to reverse direction.
         */
        eStageValueTypeCssJogRotVel                                 = 80,

        /*!
         *  \brief          The CSS gap distance for jog mode.
         *  \param[in]      param2      Is a 32bit floating point value (µm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (µm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeCssJogGapDis                                 = 81,

        /*!
         *  \brief          The CSS default Gap motor velocity.
         *  \param[in]      param2      Is a 32bit floating point value (µm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (µm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Default: 300µm/s
         */
        eStageValueTypeCssDefaultGapRefVel                          = 82,

        /*!
         *  \brief          The CSS default rotational motor velocity.
         *  \param[in]      param2      Is a 32bit floating point value (?) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (?) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeCssDefaultRotRefVel                          = 83,

        /*!
         *  \brief          The step done/completed state.
         *  \param[in]      param2      Is a boolean value (0 = not done, 1 = done) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (0 = not done, 1 = done) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the SetValue command.
         */
        eStageValueTypeCssStepDone                                  = 84,

        /*!
         *  \brief          The success status of the step done.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (success = true, failure = false) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeCssStepSuccess                               = 85,

        /*!
         *  \brief          The CSS stage status. This is a set of flags used to
         *                  provide status information about operation of the stage.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a CSSStatus value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeCssStatus                                    = 86,

        /*!
         *  \brief          The CSS stage force value applied.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (Nm?) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeCssForce                                     = 87,

        /*!
         *  \brief          The CSS stage shear time.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (s) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeCssShareTime                                 = 88,

        /*!
         *  \brief          The CSS stage rotational motor velocity set point, use in conjunction with
         *                  the GetMaxValue and GetMinValue commands.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm/s) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeCssRotMotorVelocitySetpoint                  = 89,

        /*!
         *  \brief          The CSS stage gap motor velocity set point, use in conjunction with
         *                  the GetMaxValue and GetMinValue commands.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm/s) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeCssGapMotorVelocitySetpoint                  = 90,

        /*!
         *  \brief          The CSS sensor data. The CSS sensor data provides configuration 
         *                  information and status information about the CSS sensor system.
         *  \param[in]      param2      Provide a pointer to a buffer, large enough to hold the CSSSensorData structure 
         *                              if calling (\b Get), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \warning        Not compatible with depricated API. Linkam Scientific Instruments recommends
         *                  switching to the new API.
         */
        eStageValueTypeCssOptionBoardSensorData                     = 91,
            
        /*!
         *  \brief          The RS232 option board sensor enabled state. This can be used to determine 
         *                  if the RS232 option board is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeRS232OptionBoardSensorEnabled                = 92,

        /*!
         *  \brief          The vacuum sensor 1 data. The vacuum sensor data provides configuration 
         *                  information about a sensor connected to a vacuum option board. This can be 
         *                  used to determine supported features.
         *  \param[in]      param2      Provide a pointer to a buffer, large enough to hold the VacuumSensorData structure 
         *                              if calling (\b Get), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \warning        Not compatible with depricated API. Linkam Scientific Instruments recommends
         *                  switching to the new API.
         */
        eStageValueTypeVacuumOptionBoardSensor1Data                 = 93,
            
        /*!
         *  \brief          The vacuum option board sensor 1 enabled state. This can be used to determine 
         *                  if the sensor is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeVacuumOptionBoardSensor1Enabled              = 94,

        /*!
         *  \brief          The vacuum sensor 1 data. The vacuum sensor data provides configuration 
         *                  information about a sensor connected to a vacuum option board. This can be 
         *                  used to determine supported features.
         *  \param[in]      param2      Provide a pointer to a buffer, large enough to hold the VacuumSensorData structure 
         *                              if calling (\b Get), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \warning        Not compatible with depricated API. Linkam Scientific Instruments recommends
         *                  switching to the new API.
         */
        eStageValueTypeVacuumOptionBoardSensor2Data                 = 95,
            
        /*!
         *  \brief          The vacuum option board sensor 1 enabled state. This can be used to determine 
         *                  if the sensor is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeVacuumOptionBoardSensor2Enabled              = 96,

        /*!
         *  \brief          The VTO (Video Text Overlay) option board enabled state. This can be used to determine 
         *                  if the VTO option board is enabled for use. VTO option boards do not support
         *                  sensors, this is a video on-screen-display (Video OSD) card which allows textural overlays
         *                  to be added to video.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeVtoOptionBoardEnabled                        = 97,

        /*!
         *  \brief          The fith sensor temperature reading (°C). For stages that 
         *                  support a fith temperature reading. For the CMS stage 
         *                  this is the top dewar temperature, the temperature at the
         *                  top of the dewar.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeCmsDewarTopTemperature                       = 98,

        /*!
         *  \brief          Use to start or stop the auto filling feature of the dewar on the CMS .
         *  \param[in]      param2      Is a Boolean value (false = stop, true = start) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the SetValue command.
         */
        eStageValueTypeCmsAutoDewarFill                             = 99,

        /*!
         *  \brief          The DSC power.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value.
         *  \note           This value may be acquired by the GetValue command.
         *  \note           This is only valid on DSC version 2 stages.
         */
        eStageValueTypeDscPower                                     = 100,

        /*!
         *  \brief          The 1st gain value for the DSC. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscGain1                                     = 101,

        /*!
         *  \brief          The 2nd gain value for the DSC. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscGain2                                     = 102,

        /*!
         *  \brief          The 3rd gain value for the DSC. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscGain3                                     = 103,

        /*!
         *  \brief          The constant term value for the DSC powers. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscConstantTerm                              = 104,

        /*!
         *  \brief          The 1st power term value for the DSC. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscPowerTerm1                                = 105,

        /*!
         *  \brief          The 2nd power term value for the DSC. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscPowerTerm2                                = 106,

        /*!
         *  \brief          The 3rd power term value for the DSC. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscPowerTerm3                                = 107,

        /*!
         *  \brief          The 4th power term value for the DSC. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscPowerTerm4                                = 108,

        /*!
         *  \brief          The 5th power term value for the DSC. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscPowerTerm5                                = 109,

        /*!
         *  \brief          The 6th power term value for the DSC. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscPowerTerm6                                = 110,

        /*!
         *  \brief          The baseline constant term value for the DSC baseline powers. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscBaselineConstTerm                         = 111,

        /*!
         *  \brief          The 1st baseline power term value for the DSC baseline powers. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscBaselinePowerTerm1                        = 112,

        /*!
         *  \brief          The 2nd baseline power term value for the DSC baseline powers. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscBaselinePowerTerm2                        = 113,

        /*!
         *  \brief          The 3rd baseline power term value for the DSC baseline powers. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscBaselinePowerTerm3                        = 114,

        /*!
         *  \brief          The 4th baseline power term value for the DSC baseline powers. 
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscBaselinePowerTerm4                        = 115,

        /*!
         *  \brief          The 1st TUA constant value for the DSC.
         *                  Kendall's TUA coefficient, is a statistic used to measure the ordinal association 
         *                  between two measured quantities. A tau test is a non-parametric hypothesis test 
         *                  for statistical dependence based on the tau coefficient.
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscTuaConst1                                 = 116,

        /*!
         *  \brief          The 2nd TUA constant value for the DSC.
         *                  Kendall's TUA coefficient, is a statistic used to measure the ordinal association 
         *                  between two measured quantities. A tau test is a non-parametric hypothesis test 
         *                  for statistical dependence based on the tau coefficient.
         *  \param[in]      param2      Is a 32bit floating point value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeDscTuaConst2                                 = 117,

        /*!
         *  \brief          The DSC option board sensor enabled state. This can be used to determine 
         *                  if the DSC option board sensor is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeDscOptionBoardSensorEnabled                  = 118,

        /*!
         *  \brief          The TST jaw to jaw gap size, used in calculating strain for the test rig setup.
         *  \param[in]      param2      Is a 32bit floating point value (μm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeTstJawToJawSize                              = 119,

        /*!
         *  \brief          The TST table direction.
         *  \param[in]      param2      Is a boolean value (1 = closing, 0 = opening) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (1 = closing, 0 = opening) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeTstTableDirection                            = 120,

        /*!
         *  \brief          Obtain or set the Tensile stage sample size.
         *  \param[in]      param2      A TSTSampleSize structure if calling (Set), else if calling (Get) ignored, set to 0.
         *  \param[out]     result      Returns a TSTSampleSize structure if calling (Get), else a boolean if calling (Set) (set = true, not set = false).
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeTstSampleSize                                = 121,

        /*!
         *  \brief          The TST strain engineering or true units.
         *  \param[in]      param2      Is a boolean value (Engineering = 1, True = 0) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (Engineering = 1, True = 0) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeTstStrainEngineeringUnits                    = 122,

        /*!
         *  \brief          The TST strain percentage mode.
         *  \param[in]      param2      Is a boolean value (set = true, not set = false) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (set = true, not set = false) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeTstStrainPercentage                          = 123,

        /*!
         *  \brief          The TST show as force or distance.
         *  \param[in]      param2      Is a boolean value (Distaince = true, Force = false) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (Distaince = true, Force = false) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeTstShowAsForceDistance                       = 124,

        /*!
         *  \brief          The TST calibration force value. This is used to configure or check
         *                  the force to be applied during calibration of the sensors.
         *  \param[in]      param2      Is a 32bit floating point value (N) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the SetValue command.
         */
        eStageValueTypeTstCalForceValue                             = 125,

        /*!
         *  \brief          The TST option board sensor enabled state. This can be used to determine
         *                  if the tensile test option board is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTstOptionBoardSensorEnabled                  = 126,
            
        /*!
         *  \brief          Allows the Tensile stage to show calibration data.
         *  \param[in]      param2      Is a boolean value (On = 1, Off = 0) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (On = 1, Off = 0) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeTstShowCalbData                              = 127,

        /*!
         *  \brief          The Tensile stage status. This is a set of flags used to
         *                  provide status information about operation of the stage.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a TSTStatus value.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTstStatus                                    = 128,

        /*!
         *  \brief          The Tensile stage jaw position.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTstJawPosition                               = 129,

        /*!
         *  \brief          The Tensile stage strain value.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (No unit, scalar?).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTstStrain                                    = 130,

        /*!
         *  \brief          The Tensile stage stress value.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (Nm-2 or pascals (Pa)?).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTstStress                                    = 131,

        /*!
         *  \brief          The TST table mode.
         *  \param[in]      param2      Is a TSTMode if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Is a TSTMode is calling (\b Get), else returns a boolean value (set = true, not set = false).
         *  \note           This value may be acquired by the GetValue command, or set by the SetValue command.
         *  \remark         The table mode defines how the tensile stage table will operate, this can be one of the following modes:
         *                  - Velocity
         *                  - Step
         *                  - Cycle
         *                  - Force
         *                  - Relax
         *                  - Stop
         */
        eStageValueTypeTstTableMode                                = 132,

        /*!
         *  \brief          The stage humidity unit data. This obtains the humidity data
         *                  directly from the connected stage.
         *  \param[in]      param2      Provide a pointer to a buffer, large enough to hold the RHUnit structure 
         *                              if calling (\b Get), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \warning        Not compatible with depricated API. Linkam Scientific Instruments recommends
         *                  switching to the new API.
         */
        eStageValueTypeStageHumidityUnitData                        = 133,

        /*!
         *  \brief          The pressure within the stage sample chamber.
         *  \param[in]      param2      The pressure sensor to get (0 = primary, 1 = primary, 2 = secondary).
         *  \param[out]     result      Returns a 32bit floating point value (mBar).
         *  \note           This value may be acquired by the GetValue command.
         *  \note           Only applicible if the connected stage supports pressurization
         *                  of the sample chamber, such as a pressure stage.
         */
        eStageValueTypePressure                                     = 134,

        /*!
         *  \brief          The motor option board sensor enabled state. This can be used to determine
         *                  if the motor option board sensor is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeMotorXOptionBoardSensorEnabled               = 135,

        /*!
         *  \brief          The motor option board sensor enabled state. This can be used to determine
         *                  if the motor option board sensor is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeMotorYOptionBoardSensorEnabled               = 136,

        /*!
         *  \brief          The motor option board sensor enabled state. This can be used to determine
         *                  if the motor option board sensor is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeMotorZOptionBoardSensorEnabled               = 137,

        /*!
         *  \brief          The motor option board sensor enabled state. This can be used to determine
         *                  if the motor option board sensor is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeMotorVacuumOptionBoardSensorEnabled          = 138,

        /*!
         *  \brief          The motor option board sensor enabled state. This can be used to determine
         *                  if the motor option board sensor is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeMotorFDVacuumOptionBoardSensorEnabled        = 139,

        /*!
         *  \brief          The motor option board sensor enabled state. This can be used to determine
         *                  if the motor option board sensor is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeMotorTstOptionBoardSensorEnabled             = 140,

        /*!
         *  \brief          The motor option board sensor enabled state. This can be used to determine
         *                  if the motor option board sensor is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeMotorGradientOptionBoardSensorEnabled        = 141,

        /*!
         *  \brief          The motor option board sensor data. This can be used to determine limits and
         *                  supported features.
         *  \param[in]      param2      Provide a pointer to a buffer, large enough to hold the MotorSensorData structure 
         *                              if calling (\b Get), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \warning        Not compatible with depricated API. Linkam Scientific Instruments recommends
         *                  switching to the new API.
         */
        eStageValueTypeMotorXOptionBoardSensorData                  = 142,

        /*!
         *  \brief          The motor option board sensor data. This can be used to determine limits and
         *                  supported features.
         *  \param[in]      param2      Provide a pointer to a buffer, large enough to hold the MotorSensorData structure 
         *                              if calling (\b Get), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \warning        Not compatible with depricated API. Linkam Scientific Instruments recommends
         *                  switching to the new API.
         */
        eStageValueTypeMotorYOptionBoardSensorData                  = 143,

        /*!
         *  \brief          The motor option board sensor data. This can be used to determine limits and
         *                  supported features.
         *  \param[in]      param2      Provide a pointer to a buffer, large enough to hold the MotorSensorData structure 
         *                              if calling (\b Get), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \warning        Not compatible with depricated API. Linkam Scientific Instruments recommends
         *                  switching to the new API.
         */
        eStageValueTypeMotorZOptionBoardSensorData                  = 144,

        /*!
         *  \brief          The motor option board sensor data. This can be used to determine limits and
         *                  supported features.
         *  \param[in]      param2      Provide a pointer to a buffer, large enough to hold the MotorSensorData structure 
         *                              if calling (\b Get), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \warning        Not compatible with depricated API. Linkam Scientific Instruments recommends
         *                  switching to the new API.
         */
        eStageValueTypeMotorVacuumOptionBoardSensorData             = 145,

        /*!
         *  \brief          The motor option board sensor data. This can be used to determine limits and
         *                  supported features.
         *  \param[in]      param2      Provide a pointer to a buffer, large enough to hold the MotorSensorData structure 
         *                              if calling (\b Get), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \warning        Not compatible with depricated API. Linkam Scientific Instruments recommends
         *                  switching to the new API.
         */
        eStageValueTypeMotorFDVacuumOptionBoardSensorData           = 146,

        /*!
         *  \brief          The motor option board sensor data. This can be used to determine limits and
         *                  supported features.
         *  \param[in]      param2      Provide a pointer to a buffer, large enough to hold the MotorSensorData structure 
         *                              if calling (\b Get), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \warning        Not compatible with depricated API. Linkam Scientific Instruments recommends
         *                  switching to the new API.
         */
        eStageValueTypeMotorTstOptionBoardSensorData                = 147,

        /*!
         *  \brief          The motor option board sensor data. This can be used to determine limits and
         *                  supported features.
         *  \param[in]      param2      Provide a pointer to a buffer, large enough to hold the MotorSensorData structure 
         *                              if calling (\b Get), else ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         *  \warning        Not compatible with depricated API. Linkam Scientific Instruments recommends
         *                  switching to the new API.
         */
        eStageValueTypeMotorGradientOptionBoardSensorData           = 148,

        /*!
         *  \brief          The tripple thermocouple (TTC) option board sensor enabled state. This can be used to determine
         *                  if the option board is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTtcOptionBoardEnabled                        = 149,

        /*!
         *  \brief          The tripple thermocouple (TTC) option board sensor 1 enabled state. This can be used to determine
         *                  if the option board sensor 1 is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTtcOptionBoardSensor1Enabled                 = 150,

        /*!
         *  \brief          The tripple thermocouple (TTC) option board sensor 2 enabled state. This can be used to determine
         *                  if the option board sensor 2 is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTtcOptionBoardSensor2Enabled                 = 151,

        /*!
         *  \brief          The tripple thermocouple (TTC) option board sensor 3 enabled state. This can be used to determine
         *                  if the option board sensor 3 is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTtcOptionBoardSensor3Enabled                 = 152,

        /*!
         *  \brief          The DSC option board sensor enabled state. This can be used to determine 
         *                  if the DSC option board sensor is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeDtcOptionBoardSensor1Enabled                 = 153,

        /*!
         *  \brief          The DSC option board sensor enabled state. This can be used to determine 
         *                  if the DSC option board sensor is enabled for use.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (enabled = true, disabled = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeDtcOptionBoardSensor2Enabled                 = 154,

        /*!
         *  \brief          Obtain or set the default motor speed on the motor X board.
         *  \param[in]      param2      A 32bit float value as the default speed if calling (Set), else if calling (Get) ignored, set to 0.
         *  \param[out]     result      Returns a 32bit float value as the default speed if calling (Get), else a boolean if calling (Set) (set = true, not set = false).
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeMotorXDefaultSpeed                           = 155,

        /*!
         *  \brief          Obtain or set the default motor speed on the motor Y board.
         *  \param[in]      param2      A 32bit float value as the default speed if calling (Set), else if calling (Get) ignored, set to 0.
         *  \param[out]     result      Returns a 32bit float value as the default speed if calling (Get), else a boolean if calling (Set) (set = true, not set = false).
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeMotorYDefaultSpeed                           = 156,

        /*!
         *  \brief          Obtain or set the default motor speed on the motor Z board.
         *  \param[in]      param2      A 32bit float value as the default speed if calling (Set), else if calling (Get) ignored, set to 0.
         *  \param[out]     result      Returns a 32bit float value as the default speed if calling (Get), else a boolean if calling (Set) (set = true, not set = false).
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeMotorZDefaultSpeed                           = 157,

        /*!
         *  \brief          Obtain or set the default motor speed on the motor TST board.
         *  \param[in]      param2      A 32bit float value as the default speed if calling (Set), else if calling (Get) ignored, set to 0.
         *  \param[out]     result      Returns a 32bit float value as the default speed if calling (Get), else a boolean if calling (Set) (set = true, not set = false).
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeMotorTstDefaultSpeed                         = 158,

        /*!
         *  \brief          Obtain or set the default motor speed on the motor GS board.
         *  \param[in]      param2      A 32bit float value as the default speed if calling (Set), else if calling (Get) ignored, set to 0.
         *  \param[out]     result      Returns a 32bit float value as the default speed if calling (Get), else a boolean if calling (Set) (set = true, not set = false).
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeMotorGsDefaultSpeed                          = 159,

        /*!
         *  \brief          Obtain or set the default motor speed on the motor vacuum board.
         *  \param[in]      param2      A 32bit float value as the default speed if calling (Set), else if calling (Get) ignored, set to 0.
         *  \param[out]     result      Returns a 32bit float value as the default speed if calling (Get), else a boolean if calling (Set) (set = true, not set = false).
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeMotorVacDefaultSpeed                         = 160,

        /*!
         *  \brief          Obtain or set the default motor speed on the motor Freeze Drying Vial vacuum board.
         *  \param[in]      param2      A 32bit float value as the default speed if calling (Set), else if calling (Get) ignored, set to 0.
         *  \param[out]     result      Returns a 32bit float value as the default speed if calling (Get), else a boolean if calling (Set) (set = true, not set = false).
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         */
        eStageValueTypeMotorFDVacDefaultSpeed                       = 161,

        /*!
         *  \brief          The humidity device drying time.
         *  \param[in]      param2      A 32bit signed integer value (s) if calling (Set), else if calling (Get) ignored, set to 0.
         *  \param[out]     result      Returns a 32bit signed integer value (s) if calling (Get), else a boolean if calling (Set) (set = true, not set = false).
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \remark         The humidity device makes use of two column chambers to produce humid air which is feed to the outgoing pipe. Only one chamber is used
         *                  to actively generate humidity at any time. The inactive chamber is put through a drying cycle to remove humidity absorbed by the desiccated
         *                  tablets. This stage value allows you to specify the time in seconds to run a drying cycle for.
         */
        eStageValueTypeHumidityDryingTimeSetpoint                   = 162,

        /*!
         *  \brief          The humidity device swap time.
         *  \param[in]      param2      A 32bit signed integer value (s) if calling (Set), else if calling (Get) ignored, set to 0.
         *  \param[out]     result      Returns a 32bit signed integer value (s) if calling (Get), else a boolean if calling (Set) (set = true, not set = false).
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \remark         The humidity device makes use of two column chambers to produce humid air which is feed to the outgoing pipe. Only one chamber is used
         *                  to actively generate humidity at any time. The inactive chamber is put through a drying cycle to remove humidity absorbed by the desiccated
         *                  tablets. This stage value allows you to specify the time in seconds before switching the two columns between active and drying modes.
         */
        eStageValueTypeHumiditySwapTimeSetpoint                     = 163,

        /*!
         *  \brief          The humidity device outgoing pipe heater temperature.
         *  \param[in]      param2      A 32bit float value (°C) if calling (Set), else if calling (Get) ignored, set to 0.
         *  \param[out]     result      Returns a 32bit float value (°C) if calling (Get), else a boolean if calling (Set) (set = true, not set = false).
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \remark         The humidity device feeds humid air via a pipe to the output port which you connect a tube between the humidity unit and the stage.
         *                  The pipe leading to the port makes use of a heater to prevent condensation build-up and maintain humidity. This stage value allows
         *                  you to specify the temperature this heater should be set at.
         */
        eStageValueTypeHumidityPipeTempSetpoint                     = 164,

        /*!
         *  \brief          The humidity device water reservoir heater temperature.
         *  \param[in]      param2      A 32bit float value (°C) if calling (Set), else if calling (Get) ignored, set to 0.
         *  \param[out]     result      Returns a 32bit float value (°C) if calling (Get), else a boolean if calling (Set) (set = true, not set = false).
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \remark         The humidity device generates humid air by heating a small reservoir of water. This stage value allows you to specify the 
         *                  temperature this heater should be set at.
         */
        eStageValueTypeHumidityWaterTempSetpoint                    = 165,

        /*!
         *  \brief          The humidity device drying time left.
         *  \param[in]      param2      ignored, set to 0.
         *  \param[out]     result      Returns a 32bit signed integer value (s).
         *  \note           This value is acquired by the GetValue command.
         *  \see            eStageValueTypeHumidityDryingTimeSetpoint.
         */
        eStageValueTypeHumidityDryingTimeLeft                       = 166,

        /*!
         *  \brief          The humidity device swap time left.
         *  \param[in]      param2      ignored, set to 0.
         *  \param[out]     result      Returns a 32bit signed integer value (s).
         *  \note           This value is acquired by the GetValue command.
         *  \see            eStageValueTypeHumiditySwapTimeSetpoint.
         */
        eStageValueTypeHumiditySwapTimeLeft                         = 167,

        /*!
         *  \brief          The humidity device water reservoir temperature.
         *  \param[in]      param2      ignored, set to 0.
         *  \param[out]     result      Returns a 32bit float value (°C).
         *  \note           This value is acquired by the GetValue command.
         *  \see            eStageValueTypeHumidityWaterTempSetpoint.
         */
        eStageValueTypeHumidityWaterTemp                            = 168,

        /*!
         *  \brief          The video standard for the VTO board.
         *  \param[in]      param2      (\b Get) ignored, set to 0, (\b Set) a 32bit unsigned integer value (NTSC = 0, PAL = 64).
         *  \param[out]     result      Returns a 32bit unsigned integer value (NTSC = 0, PAL = 64) if calling (\b Get),
         *                              else returns a boolean value (true = success, false = failure) if calling (\b Set).
         *  \note           This value is acquired by the GetValue command and set by the SetValue command.
         */
        eStageValueTypeVtoVideoStandard                             = 169,

        /*!
         *  \brief          The trigger signal pulse width.
         *  \param[in]      param2      ignored, set to 0.
         *  \param[out]     result      Returns a 32bit unsigned integer value which is time of the duration of the pulse width (s).
         *  \note           This value is acquired by the GetValue command.
         */
        eStageValueTypeTriggerSignalPulseWidth                      = 170,

        /*!
         *  \brief          The controller connection type (USB or Serial).
         *  \param[in]      param2      ignored, set to 0.
         *  \param[out]     result      Returns a CommsType value for the device connection.
         *  \note           This value is acquired by the GetValue command.
         */
        eStageValueTypeConnectionType                               = 171,

        /*!
         *  \brief          The vacuum card simulated vacuum gauge plug.
         *  \param[in]      param2      A 32-bit unsigned integer used to specify the sensor socket to check (0=ignore, 1=socket 1, 2=socket 2).
         *  \param[out]     result      Returns a boolean value (true=installed false=not installed).
         *  \note           This value is acquired by the GetValue command.
         *  \note           This value can be used on both single and dual vacuum cards, \b param2 is used
         *                  to specify which sensor socket/cable to check. If you have a dual vacuum card
         *                  installed then \b param2 is used, else param2 is ignored.
         *  \remark         It is possible to install a simulator plug to mimic a gauge that reads
         *                  vacuum for diagnostic purposes. Get the value of this flag to see if a
         *                  vacuum gauge simulator plug is installed on the vacuum card.
         */
        eStageValueTypeVacuumSimulatorPlug                          = 172,

        /*!
         *  \brief          The vacuum card simulated pressure gauge plug.
         *  \param[in]      param2      A 32-bit unsigned integer used to specify the sensor socket to check (0=ignore, 1=socket 1, 2=socket 2).
         *  \param[out]     result      Returns a boolean value (true=installed false=not installed).
         *  \note           This value is acquired by the GetValue command.
         *  \note           This value can be used on both single and dual vacuum cards, \b param2 is used
         *                  to specify which sensor socket/cable to check. If you have a dual vacuum card
         *                  installed then \b param2 is used, else param2 is ignored.
         *  \remark         It is possible to install a simulator plug to mimic a gauge that reads
         *                  pressure for diagnostic purposes. Get the value of this flag to see if a
         *                  pressure gauge simulator plug is installed on the vacuum card.
         */
        eStageValueTypePressureSimulatorPlug                        = 173,

        /*!
         *  \brief          Single LNP status.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value (true=single false=not single).
         *  \note           This value is acquired by the GetValue command.
         *  \remark         Use this value to see if the LNP is a single pump system.
         */
        eStageValueTypeLNPSingle                                    = 174,

        /*!
         *  \brief          Dual LNP status.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value (true=dual false=not dual).
         *  \note           This value is acquired by the GetValue command.
         *  \remark         Use this value to see if the LNP is a dual pump system.
         */
        eStageValueTypeLNPDual                                      = 175,

        /*!
         *  \brief          95 LNP status.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value (true=95 LNP false=not 95 LNP).
         *  \note           This value is acquired by the GetValue command.
         *  \remark         Use this value to see if the LNP is a 95 LNP model.
         */
        eStageValueTypeLNP95                                        = 176,

        /*!
         *  \brief          96 LNP status.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value (true=96 LNP false=not 96 LNP).
         *  \note           This value is acquired by the GetValue command.
         *  \remark         Use this value to see if the LNP is a 96 LNP model.
         */
        eStageValueTypeLNP96                                        = 177,

        /*!
         *  \brief          Xenocs use only.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value.
         *  \note           This value is acquired by the GetValue command.
         *  \warning        This command is provide for Xenocs use only.
         */
        eStageValueTypeUsingXenocsStageTestCables                   = 178,

        /*!
         *  \brief          Xenocs use only.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value.
         *  \note           This value is acquired by the GetValue command.
         *  \warning        This command is provide for Xenocs use only.
         */
        eStageValueTypeUsingXenocsStageTestCableType1               = 179,

        /*!
         *  \brief          Xenocs use only.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value.
         *  \note           This value is acquired by the GetValue command.
         *  \warning        This command is provide for Xenocs use only.
         */
        eStageValueTypeUsingXenocsStageTestCableType2               = 180,

        /*!
         *  \brief          Linkam use only.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value.
         *  \note           This value is acquired by the GetValue command.
         *  \warning        This command is provide for Linkam use only.
         */
        eStageValueTypeUsingCalibrationPlug                         = 181,

        /*!
         *  \brief          Linkam use only.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value.
         *  \note           This value is acquired by the GetValue command.
         *  \warning        This command is provide for Linkam use only.
         */
        eStageValueTypeUsingCalibrationCableB                       = 182,

        /*!
         *  \brief          Linkam use only.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value.
         *  \note           This value is acquired by the GetValue command.
         *  \warning        This command is provide for Linkam use only.
         */
        eStageValueTypeUsingCalibrationCableC                       = 183,

        /*!
         *  \brief          Linkam use only.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value.
         *  \note           This value is acquired by the GetValue command.
         *  \warning        This command is provide for Linkam use only.
         */
        eStageValueTypeUsingCalibrationCableA                       = 184,

        /*!
         *  \brief          The video overlay text.
         *  \param[in]      param2      A pointer to a 28 byte fixed length ansi character array.
         *  \param[out]     result      Returns a boolean value (true = success, false = failure).
         *  \note           This value is set by the SetValue command.
         */
        eStageValueTypeVtoText                                      = 185,

        /*!
         *  \brief          The video overlay time.
         *  \param[in]      param2      A pointer to a 10 byte fixed length ansi character array.
         *  \param[out]     result      Returns a boolean value (true = success, false = failure).
         *  \note           This value is set by the SetValue command.
         */
        eStageValueTypeVtoTime                                      = 186,

        /*!
         *  \brief          The x axis motor card zero reference command. This is used to set the
         *                  the current position to the zero reference. Once comlete the current motor 
         *                  position will read zero.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value (true = success, false = failure).
         *  \note           This value is set by the SetValue command.
         */
        eStageValueTypeMotorZeroRefX                                = 187,

        /*!
         *  \brief          The y axis motor card zero reference command. This is used to set the
         *                  the current position to the zero reference. Once comlete the current motor 
         *                  position will read zero.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value (true = success, false = failure).
         *  \note           This value is set by the SetValue command.
         */
        eStageValueTypeMotorZeroRefY                                = 188,

        /*!
         *  \brief          CMS assessor to the X axis motor grid centre positions, there are 4
         *                  programmed grid centre reference positions.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value (true = success, false = failure).
         *  \note           This value is acquired by the GetValue command.
         */
        eStageValueTypeCmsXaxisGridCentre                           = 189,

        /*!
         *  \brief          CMS assessor to the Y axis motor grid centre positions, there are 4
         *                  programmed grid centre reference positions.
         *  \param[in]      param2      Ignored, set to zero.
         *  \param[out]     result      Returns a boolean value (true = success, false = failure).
         *  \note           This value is acquired by the GetValue command.
         */
        eStageValueTypeCmsYaxisGridCentre                           = 190,

        /*!
         *  \brief          The CMS back-lash warning command, use this to enable of disable the back-lash
         *                  warning. Back-lash is created by the motor settling.
         *  \param[in]      param2      A boolean value (true = NO, flase = OFF) if calling (\b Set), else ignored, set to zero.
         *  \param[out]     result      Returns a boolean value (true = success, false = failure).
         *  \note           This value is set by the SetValue command.
         */
        eStageValueTypeCmsLashWarning                               = 191,

        /*!
         *  \brief          The CMS base heater limit command, use this to set the limit of the base heater.
         *  \param[in]      param2      A 32-bit floating value providing the temperature limit (°C).
         *  \param[out]     result      Returns a boolean value (true = success, false = failure).
         *  \note           This value is set by the SetValue command.
         */
        eStageValueTypeCmsBaseHeaterLimit                           = 192,

        /*!
         *  \brief          The CMS alarm volume command, use this to set the alarm volume.
         *  \param[in]      param2      A 16-bit unsigned integer value providing the volume (0 - 100).
         *  \param[out]     result      Returns a boolean value (true = success, false = failure).
         *  \note           This value is set by the SetValue command.
         */
        eStageValueTypeCmsAlarmVolume                               = 193,

        /*!
         *  \brief          The manual humidity % set point command. Overrides the managed eStageValueTypeHumiditySetpoint
         *                  command.
         *  \param[in]      param2      Is a 32bit floating point value (%) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (true = set, false = not set).
         *  \note           This value may be set using the SetValue.
         *  \note           Only applicible if a connected humidity unit is present.
         */
        eStageValueTypeManualHumiditySetpoint                       = 194,

        /*!
         *  \brief          The Freeze Drying Vial cold trap pump speed command.
         *  \param[in]      param2      Is a 32bit floating point value for the velocity if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (true = set, false = not set).
         *  \note           This value may be set using the SetValue.
         */
        eStageValueTypeFDVSColdTrapPumpSpeed                        = 195,

        /*!
         *  \brief          The Freeze Drying Vial scan motor position.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (true = known, false = unknown).
         *  \note           This value may be get using the GetValue.
         */
        eStageValueTypeFDVSScanMotorPosition                        = 196,

        /*!
         *  \brief          The imaging station brightness.
         *  \param[in]      param2      Is a 32bit floating point value for the brightness (0-100) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (true = set, false = not set).
         *  \note           This value may be set using the SetValue.
         */
        eStageValueTypeImagingStationBrightness                     = 197,

        /*!
         *  \brief          Enable joystick on the stage.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (true = known, false = unknown).
         *  \note           This value may be set using the SetValue.
         */
        eStageValueTypeEnableJoyStick                               = 198,

        /*!
         *  \brief          Disable joystick on the stage.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (true = known, false = unknown).
         *  \note           This value may be set using the SetValue.
         */
        eStageValueTypeDisableJoyStick                              = 199,

        /*!
         *  \brief          Invert joystick axis X on the stage.
         *  \param[in]      param2      A boolean value (true = invert, false = uninvert) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (true = known, false = unknown).
         *  \note           This value may be set using the SetValue.
         */
        eStageValueTypeInvertJoyStickAxisX                          = 200,

        /*!
         *  \brief          Invert joystick axis Y on the stage.
         *  \param[in]      param2      A boolean value (true = invert, false = uninvert) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (true = known, false = unknown).
         *  \note           This value may be set using the SetValue.
         */
        eStageValueTypeInvertJoyStickAxisY                          = 201,

        /*!
         *  \brief          The freeze drying vial system motor velocity.
         *  \param[in]      param2      Is a 32bit floating point value (μm/s) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm/s) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeFDVSMotorVel                                 = 202,

        /*!
         *  \brief          The tensile motor distance set point.
         *  \param[in]      param2      Is a 32bit floating point value (μm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (μm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeFDVSMotorDistanceSetpoint                    = 203,

        /*!
         *  \brief          The CSS default Gap motor change velocity.
         *  \param[in]      param2      Is a 32bit floating point value (µm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (µm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           Default: 300µm/s
         */
        eStageValueTypeCssDefaultGapChangeVel                       = 204,

        /*!
         *  \brief          The tensile gauge compliancy value is a value that describes the amount of distance adjustment in the
         *                  gauge beam due to elasticity.
         *  \param[in]      param2      Is a 32bit floating point value (mm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (mm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by the GetValue command. This value is 
         *                  not saved to the stage and so is volatile. Ensure your application manages this value. The driver 
         *                  manages the default factory set value.
         */
        eStageValueTypeTstGaugeCompliancy                           = 205,

        /*!
         *  \brief          Allows the caller to enable the use of internal tensile gauge compliancy adjustment.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be set using the SetValue command.
         */
        eStageValueTypeTstEnableGaugeCompliancy                     = 206,

        /*!
         *  \brief          Allows the caller to disable the use of internal tensile gauge compliancy adjustment.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be set using the SetValue command.
         */
        eStageValueTypeTstDisableGaugeCompliancy                     = 207,

        /*!
         *  \brief          Allows the caller to get the enabled/disable status of the internal tensile gauge compliancy mode.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (On = true, Off = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTstIsGaugeCompliancyEnabled                   = 208,

        /*!
         *  \brief          Allows the caller to access the tensile maximum extent jaw position.
         *  \param[in]      param2      Is a 32bit floating point value (µm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (µm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by the GetValue command. This value is 
         *                  not saved to the stage and so is volatile. Ensure your application manages this value. The driver 
         *                  manages the default factory set value.
         */
        eStageValueTypeTstMaxExtentPosition                         = 209,

        /*!
         *  \brief          Allows the caller to access the tensile minimum extent jaw position.
         *  \param[in]      param2      Is a 32bit floating point value (µm) if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (µm) if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by the GetValue command. This value is 
         *                  not saved to the stage and so is volatile. Ensure your application manages this value. The driver 
         *                  manages the default factory set value.
         */
        eStageValueTypeTstMinExtentPosition                         = 210,

        /*!
         *  \brief          Allows the caller to access the tensile raw motor position. This is not the same as the eStageValueTypeTstMotorPos
         *                  as eStageValueTypeTstMotorPos may have an offset 'zero calibrated' position applied. This value is the physical motor
         *                  position.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit floating point value (µm).
         *  \note           This value may be acquired by the GetValue command. This command is only supported on T96 controllers supporting
         *                  firmware version 1.28 or higher.
         */
        eStageValueTypeTstRawMotorPos                               = 211,

        /*!
         *  \brief          Allows the caller to enable the use of internal tensile jaw montioring for auto-stop within extent range.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be set using the SetValue command.
         */
        eStageValueTypeTstEnableJawMonitor                          = 212,

        /*!
         *  \brief          Allows the caller to disnable the use of internal tensile jaw montioring for auto-stop within extent range.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Ignored, set to 0.
         *  \note           This value may be set using the SetValue command.
         */
        eStageValueTypeTstDisableJawMonitor                         = 213,

        /*!
         *  \brief          Allows the caller to get the enabled/disable status of the internal tensile jaw montioring for auto-stop within extent range.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a boolean value (On = true, Off = false).
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTstIsJawMonitorEnabled                       = 214,
        
        /*!
         *  \brief          The TST cycle count limit.
         *  \param[in]      param2      Is a 32bit integer value if calling (\b Set), else ignored, set to 0.
         *  \param[out]     result      Returns a 32bit integer value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be set using the SetValue command or acquired by 
         *                  the GetValue command.
         *  \note           This is only required if you are setting up a limited cycle count, otherwise this is ignored.
         */
        eStageValueTypeTstCycleCountLimit                           = 215,

        /*!
         *  \brief          The TST current cycles remaining.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[out]     result      Returns a 32bit integer value if calling (\b Get), else ignored, set to 0.
         *  \note           This value may be acquired by the GetValue command.
         */
        eStageValueTypeTstCyclesRemaining                           = 216,

        /*!
         *  \brief          This is the maximum value a stage value can be.
         *                  Any value greater than this is an error and must
         *                  be ignored.
         */
        eStageValueTypeMaxValue                                     = 65535
    };

    /*!
     *  \enum       StageGroup
     *  \brief      Defines a set of return codes for the type of stage connected to the
     *              the controller.
     *
     *  \note       Enums for the StageGroup support the range 0x0001 - 0x7FFF.
     *  @ingroup    Stage_Config_API
     */
    enum StageGroup
    {
        eStageGroup_START                               = 0x0000,

        /*!
         *  Includes THMS,HFS,LTS,HT,CAT,CAP e.g. single temp normally but does include provision for two temps
         */
        eStageGroup_Standard                            = 0x0000,

        /*!
         *  All peltiers with Control and Water T
         */
        eStageGroup_Peltier                             = 0x0001,

        /*!
         *  2 Control T,motor posn,motor vel,stop switch status
         */
        eStageGroup_Gradient                            = 0x0002,

        /*!
         *  Differential Scanning Calorimetry version 1 stage group. DSC is a technique used to
         *  measure temperature and heat flow associated with thermal transitions in materials.
         *  This version supports a single heater.
         */
        eStageGroup_DifferentialScanningCalorimetry     = 0x0003,

        /*!
         *  1 Control T,vac,motor posn,stop switch status
         */
        eStageGroup_Vacuum                              = 0x0004,

        /*!
         *  1 Control T,P
         */
        eStageGroup_Pressure                            = 0x0005,

        /*!
         *  1 Control T,3 motor posn,3 stop switch status
         */
        eStageGroup_MotorDriven                         = 0x0006,

        /*!
         *  The Tensile Test stage group. Tests the tensile properties of your sample relative to 
         *  temperature and capture high resolution images of the structural changes.
         */
        eStageGroup_TensileTest                         = 0x0007,

        /*!
         *  The Cambridge Shearing System group. An optical shearing system that allows structural 
         *  dynamics of complex fluids to be directly observed via standard optical microscope while 
         *  they are under precisely controlled temperature and various shear modes.
         */
        eStageGroup_CambridgeShearingSystem             = 0x0008,

        /*!
         *  The Temperature Controlled stage group. This difines a wide range of stage systems; -196-600, -196-420, -196-350.
         */
        eStageGroup_TemperatureControlled               = 0x0009,

        /*!
         *  The standard warm stage group. For living cell studies.
         */
        eStageGroup_Warm                                = 0x000A,

        /*!
         *  The Cryo-Correlative Microscopy stage group. A tool that uses fluorescence microscopy
         *  to help localise structures of interest in samples for high resolution cryo electron
         *  microscopy imaging. 
         */
        eStageGroup_CorrelativeMicroscopy               = 0x000B,

        /*!
         *  The Indium Tin Oxide (ITO) warm stage group. For living cell studies.
         */
        eStageGroup_IndiumTinOxideWarm                  = 0x000C,

        /*!
         *  The Temperature Controlled Vacuum stage group. These are the same as the eTemperatureControlled
         *  but with support for vacuum motors for infra-red experiments.
         */
        eStageGroup_TemperatureControlledVacuum         = 0x000D,

        /*!
         *  The Tensile Test version 2 stage group. Tests the tensile properties of your sample 
         *  relative to temperature and capture high resolution images of the structural changes.
         */
        eStageGroup_TensileTestV2                       = 0x000E,

        /*!
         *  Differential Scanning Calorimetry version 2 stage group. DSC is a technique used to 
         *  measure temperature and heat flow associated with thermal transitions in materials.
         *  This version supports dual heaters.
         */
        eStageGroup_DifferentialScanningCalorimetryV2   = 0x000F,

        /*!
         *  Freeze drying vial system (FDVA) stage group. For simulating the industrial freeze 
         *  drying process in a compact and efficient form.
         */
        eStageGroup_FreezeDryingVialSystem              = 0x0010,

        /*!
         *  This ID represents the value for 'no valid stage group'.
         */
        eStageGroup_None                                = 0x7FFF,

        /*!
         *  This ID represents the maximum value for a stage group;
         *  also the same as the eStageGroup_None.
         */
        eStageGroup_MAX                                 = 0x7FFF
    };

    /*!
     *  \union      StageConfig
     *  \brief      This structure defines a set of flags which detail the stage configuration.
     *
     *  @ingroup    Stage_Config_API
     */
    union StageConfig
    {
        struct
        {
            /*!
             *  \brief      Flag defining stages based on a metal block heater with PT100 temperature se sensor.
             *  \note       Bit 0
             *
             *  The full temperature range normally includes negative temperatures, achieved with the addition 
             *  of an LNP cooling pump. Without the LNP cooling pump the minimum temperature will be ambient.
             */
            unsigned    standardStage                   : 1;

            /*!
             *  \brief      Flag defining Stages based on a ceramic heater with a type “S” thermocouple temperature sensor.
             *  \note       Bit 1
             *
             *  These stages are not compatible with the LNP95 cooling pump.
             */
            unsigned    highTempStage                   : 1;

            /*!
             *  \brief      Flag defining stages based on a Peltier element to provide heating and cooling.
             *  \note       Bit 2
             *
             *  These stages do not require an LNP cooling pump for negative temperatures, but the cooling 
             *  water must be cold enough to achieve the full temperature range.
             */
            unsigned    peltierStage                    : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 3
             */
            unsigned    gradedStage                     : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 4
             */
            unsigned    tensileStage                    : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 5
             */
            unsigned    dscStage                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 6
             */
            unsigned    warmStage                       : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 7
             */
            unsigned    itoStage                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 8
             */
            unsigned    css450Stage                     : 1;

            /*!
             *  \brief      CMS196 units with a minimum of V2.0 hardware
             *  \note       Bit 9
             */
            unsigned    correlativeStage                : 1;
    
            /*!
             *  \brief      Reserved.
             *  \note       Bit 10
             */    
            unsigned    unused10                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 11
             */    
            unsigned    unused11                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 12
             */    
            unsigned    unused12                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 13
             */    
            unsigned    unused13                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 14
             */    
            unsigned    unused14                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 15
             */    
            unsigned    unused15                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 16
             */    
            unsigned    unused16                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 17
             */    
            unsigned    unused17                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 18
             */    
            unsigned    unused18                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 19
             */    
            unsigned    unused19                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 20
             */    
            unsigned    unused20                        : 1;
    
            /*!
             *  \brief      Supports manual mode cooling with an LNP cooling pump.
             *  \note       Bit 21
             */
            unsigned    coolingManual                   : 1;

            /*!
             *  \brief      Supports automatic mode cooling with an LNP cooling pump
             *  \note       Bit 22
             *
             *  Some stages that support the use of an LNP cooling pump, to achieve negative temperatures,
             *  have a specific performance criterion that does not allow the use of the automatic cooling
             *  mode.
             */
            unsigned    coolingAutomatic                : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 23
             *  \note       Requires Dual LNP cooling pump.
             */
            unsigned    coolingDual                     : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 24
             *  \note       Dual LNP pump speeds can be independent .
             */
            unsigned    coolingDualSpeedIndependent     : 1;
    
            /*!
             *  \brief      The stage has been designed so that the sample chamber can be pressurized above atmospheric level.
             *  \note       Bit 25
             */
            unsigned    supportsPressure                : 1;
    
            /*!
             *  \brief      Heater 1 fitted.
             *  \note       Bit 26
             */
            unsigned    heater1                         : 1;

            /*!
             *  \brief      Heater 1 temperature can be controlled.
             *  \note       Bit 27
             */
            unsigned    heater1TempCtrl                 : 1;
    
            /*!
             *  \brief      Reserved.
             *  \note       Bit 28
             *  \note       Heater 1 temperature can be controlled by roving temperature probe
             */
            unsigned    heater1TempCtrlProbe            : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 29
             */
            unsigned    unused29                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 30
             */
            unsigned    unused30                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 31
             */
            unsigned    unused31                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 32
             */
            unsigned    unused32                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 33
             */
            unsigned    unused33                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 34
             */
            unsigned    unused34                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 35
             */
            unsigned    unused35                        : 1;

            /*!
             *  \brief      Heater 2 fitted.
             *  \note       Bit 36
             */
            unsigned    heater2                         : 1;

            /*!
             *  \brief      Heater 1 & 2 can have an independent temperature limits.
             *  \note       Bit 37
             */
            unsigned    heater12IndependentLimits       : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 38
             */
            unsigned    unused38                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 39
             */
            unsigned    unused39                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 40
             */
            unsigned    unused40                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 41
             */
            unsigned    unused41                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 42
             */
            unsigned    unused42                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 43
             */
            unsigned    unused43                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 44
             */
            unsigned    unused44                        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 45
             */
            unsigned    unused45                        : 1;

            /*!
             *  \brief      Cooling water sensor fitted.
             *  \note       Bit 46
             *  \note       Normally only fitted on Peltier stages.
             */
            unsigned    waterCoolingSensorFitted        : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 47
             *  \note       Home position post fitted.
             */
            unsigned    home                            : 1;

            /*!
             *  \brief      The stage has been designed so that the sample chamber can be evacuated.
             *  \note       Bit 48
             */
            unsigned    supportsVacuum                  : 1;

            /*!
             *  \brief      Has motorised X axis.
             *  \note       Bit 49
             */
            unsigned    motorX                          : 1;

            /*!
             *  \brief      Has motorised Y axis.
             *  \note       Bit 50
             */
            unsigned    motorY                          : 1;

            /*!
             *  \brief      Has motorised Z axis.
             *  \note       Bit 51
             */
            unsigned    motorZ                          : 1;

            /*!
             *  \brief      The stage has been designed to be compatible with the RH95 humidity generator.
             *  \note       Bit 52
             *  \note       Home position post fitted.
             */
            unsigned    supportsHumidity                : 1;

            /*!
             *  \brief      Reserved.
             *  \note       Bit 53
             */
            unsigned    unused53                        : 1;    

            /*!
             *  \brief      Reserved.
             *  \note       Bit 54
             */
            unsigned    unused54                        : 1;    

            /*!
             *  \brief      Reserved.
             *  \note       Bit 55
             */
            unsigned    unused55                        : 1;    

            /*!
             *  \brief      Reserved.
             *  \note       Bit 56
             */
            unsigned    unused56                        : 1;    

            /*!
             *  \brief      Reserved.
             *  \note       Bit 57
             */
            unsigned    unused57                        : 1;    

            /*!
             *  \brief      Reserved.
             *  \note       Bit 58
             */
            unsigned    unused58                        : 1;    

            /*!
             *  \brief      Reserved.
             *  \note       Bit 59
             */
            unsigned    unused59                        : 1;   

            /*!
             *  \brief      Reserved.
             *  \note       Bit 60
             */
            unsigned    unused60                        : 1;   

            /*!
             *  \brief      Reserved.
             *  \note       Bit 61
             */
            unsigned    unused61                        : 1;   

            /*!
             *  \brief      Reserved.
             *  \note       Bit 62
             */
            unsigned    unused62                        : 1; 

            /*!
             *  \brief      Reserved.
             *  \note       Bit 63
             */
            unsigned    unused63                        : 1;    
        }               flags;          ///< Accessor to the bit flags for this configuration status type.
        uint64_t        value;          ///< The combined value of the bit flags as a 64bit unsigned integer.
    };

    /*!
     *  \union      CSSStatus
     *  \brief      The Cambridge Shearing System status value is a bit feild of
     *              status flags used to feed back information about the
     *              status of Cambridge Shearing System.
     *
     *  @ingroup    Stage_Config_API
     */
    union CSSStatus
    {
        struct
        {
            unsigned    moveDone       : 1;     ///< Bit  0: Flag used to indicate that the current move has completed.
            unsigned    segComp        : 1;     ///< Bit  1: Flag used to indicate that the stepper motor segment has compeleted (deprecated).
            unsigned    motorDirn      : 1;     ///< Bit  2: Flag used to indicate the rotational motor direction (set = anti-clockwise, unset = clockwise).
            unsigned    gapMoving      : 1;     ///< Bit  3: Flag used to indicate that the gap motor is moving.
            unsigned    lidOn          : 1;     ///< Bit  4: Flag used to indicate that the lid is on.
            unsigned    refLimit       : 1;     ///< Bit  5: Flag used to indicate that the CSS has reached the reference limit.
            unsigned    zeroLimit      : 1;     ///< Bit  6: Flag used to indicate that the CSS has reached the zero limit.
            unsigned    gapMotDirn     : 1;     ///< Bit  7: Flag used to indicate that gap motor direction (set = opening, unset = closing).
            unsigned    unused8        : 1;     ///< bit  8: Reserved for future use.
            unsigned    unused9        : 1;     ///< bit  9: Reserved for future use.
            unsigned    unused10       : 1;     ///< bit 10: Reserved for future use.
            unsigned    unused11       : 1;     ///< bit 11: Reserved for future use.
            unsigned    unused12       : 1;     ///< bit 12: Reserved for future use.
            unsigned    unused13       : 1;     ///< bit 13: Reserved for future use.
            unsigned    unused14       : 1;     ///< bit 14: Reserved for future use.
            unsigned    unused15       : 1;     ///< bit 15: Reserved for future use.
            unsigned    unused16       : 1;     ///< bit 16: Reserved for future use.
            unsigned    unused17       : 1;     ///< bit 17: Reserved for future use.
            unsigned    unused18       : 1;     ///< bit 18: Reserved for future use.
            unsigned    unused19       : 1;     ///< bit 19: Reserved for future use.
            unsigned    unused20       : 1;     ///< bit 20: Reserved for future use.
            unsigned    unused21       : 1;     ///< bit 21: Reserved for future use.
            unsigned    unused22       : 1;     ///< bit 22: Reserved for future use.
            unsigned    unused23       : 1;     ///< bit 23: Reserved for future use.
            unsigned    unused24       : 1;     ///< bit 24: Reserved for future use.
            unsigned    unused25       : 1;     ///< bit 25: Reserved for future use.
            unsigned    unused26       : 1;     ///< bit 26: Reserved for future use.
            unsigned    unused27       : 1;     ///< bit 27: Reserved for future use.
            unsigned    unused28       : 1;     ///< bit 28: Reserved for future use.
            unsigned    unused29       : 1;     ///< bit 29: Reserved for future use.
            unsigned    unused30       : 1;     ///< bit 30: Reserved for future use.
            unsigned    unused31       : 1;     ///< bit 31: Reserved for future use.
        }            flags;                     ///< The flag feild accessor.
        uint32_t     value;                     ///< The value that represents the state of the flags as a 32-bit value.
    };

    /*!
     *  \union      CSSCheckCodes
     *  \brief      This enumerated data type holds the maskable error codes used
     *              as check indicators for members of the CssVars structure.
     *
     *  @ingroup    Stage_Config_API
     */
	union CSSCheckCodes
    {
        struct Flags
        {
		    unsigned mode           : 1; ///< Bit 0: Invalid mode. 
		    unsigned gap            : 1; ///< Bit 1: Invalid Gap Value set. 
		    unsigned strain         : 1; ///< Bit 2: Invalid Strain Value set. 
		    unsigned rate           : 1; ///< Bit 3: Invalid Rate value. (Stage max angular velocity is 10 rad/s. Current rate value will lead to this being exceeded.).  
		    unsigned freq           : 1; ///< Bit 4: Frequency is invalid. The valid is either invalid or the current Strain + Freq combination will result in the Max Rate being exceeded. 
            unsigned unused5        : 1; ///< Bit 5: Reserved for future use.
            unsigned unused6        : 1; ///< Bit 6: Reserved for future use.
            unsigned unused7        : 1; ///< Bit 7: Reserved for future use.
        }       flags;
        uint8_t value;
    };

    /*!
     *  \enum       CSSState
     *  \brief      A helper data type for use for setting and understanding the
     *              CSS operational state.
     *  @ingroup    Stage_Config_API
     */
    enum CSSState
    {
        eCssStateProfile         = 0x0, ///< Running a profile program currently.
        eCssStateJogModeRot      = 0x1, ///< Running a jog rotation program currently.
        eCssStateJogModeGap      = 0x2  ///< Running a jog gap program currently.
    };

    /*!
     *  \enum       CSSMode
     *  \brief      A helper data type for use for setting and understanding the
     *              CSS operational mode. This enumerator defines the avaiable 
     *              modes of operation the CSS stage can be in.
     *  @ingroup    Stage_Config_API
     */
	enum CSSMode
    {
		eCSSModeSteady       = 0x0, ///< Used to indicate the CSS stage is in the "Steady" mode. This will move the stage to the specified gap and maintain a shear rate. 
		eCSSModeStep         = 0x1, ///< Used to indicate the CSS stage is in the "Step" mode.
		eCSSModeOscillatory  = 0x2, ///< Used to indicate the CSS stage is in the "Oscillator" mode.
		eCSSModeRelax        = 0x3  ///< Used to indicate the CSS stage is in the "Relax" Mode. Relax mode will only move the gap distance. 
	};

    /*!
     *  \struct     CSSVars
     *  \brief      A set of values holding information about the CSS motor system
     *              which must be validated internally before use. This is used in
     *              conjunction with the CSSCheckCodes structure which is used for
     *              error reporting of these values.
     *  @ingroup    Stage_Config_API
     */
    struct CSSVars
    {
        CSSMode     mode;                   ///< The mode of operation the CSS stage isin, must be a value defined in CSSMode.
        float       gapDist;                ///< The gap distance to set on the stage.
        float       strain;                 ///< The strain to apply to the stage.
        float       rate;                   ///< The rate to apply to the stage.
        float       freq;                   ///< The frequence to apply to the stage.
        bool        dirn;                   ///< The dirn to apply to the stage.

        CSSVars()
        {
            mode                = eCSSModeSteady;
            gapDist             = 0.0f;
            strain              = 0.0f;
            rate                = 0.0f;
            freq                = 0.0f;
            dirn                = 0;
        }
    };


    /*!
     *  \struct     CSSSensorData
     *  \brief      The CSSSensorData provides configuration information and status information
     *              about the CSS sensor system. This can be used for determining feature support
     *              and motor positioning.
     *  @ingroup    Stage_Config_API
     */
    struct CSSSensorData
    {
        float           mainMaxDistance;        ///< The rotational motor max distance.
        float           mainCurrent;            ///< The current rotational motor position.
        float           mainMaxVel;             ///< The maximum rotational motor velocity.
        float           mainMinVel;             ///< The minimum rotational motor velocity.
        float           mainMaxAccel;           ///< The maximum rotational motor acceleration.
        float           mainDefaultVel;         ///< The default/current rotational motor velocity.
        uint32_t        mainEncResn;            ///< The rotational encoder resolution.
        bool            mainEncFitted;          ///< Flag for rotational encoder fitted.
        bool            mainEncIndexFitted;     ///< Flag for rotational encoder index fitted.
        float           gapMaxDistance;         ///< The gap motor max distance.
        float           gapCurrent;             ///< The current gap motor position.
        float           gapMaxVel;              ///< The maximum gap motor velocity.
        float           gapMinVel;              ///< The minimum gap motor velocity.
        float           gapMaxAccel;            ///< The maximum gap motor acceleration.
        float           gapDefaultVel;          ///< The default/current gap motor velocity.
        uint32_t        gapEncResn;             ///< The gap encoder resolution.
        bool            gapEncFitted;           ///< Flag for gap encoder fitted.
        bool            gapEncIndexFitted;      ///< Flag for gap encoder index fitted.
        bool            zeroEndStopFitted;      ///< Flag for the zero end-stop fitted.
        bool            refEndStopFitted;       ///< Flag for the reference end-stop fitted.
        bool            lidOnDetectFitted;      ///< Flag for the lid-on detector fitted.
        float           gapDistance;            ///< The current gap distance.
    };

    /*!
     *  \union      CMSError
     *  \brief      The Correlative Microscopy Stage error value is a bit feild of
     *              status flags used to feed back information about the
     *              status of Correlative Microscopy Stage.
     *
     *  @ingroup    Stage_Config_API
     */
    union CMSError
    {
        struct
        {
            unsigned mainSensorOC           : 1;    ///< Bit  0: Flag used to indicate that the main chamber sensor at 0°C.
            unsigned mainSensorOver         : 1;    ///< Bit  1: Flag used to indicate that the main chamber sensor reads over temperature.
            unsigned ln2SwitchSensorOC      : 1;    ///< Bit  2: Flag used to indicate that the LN2 switch sensor  at 0°C.
            unsigned ln2SwitchSensorOver    : 1;    ///< Bit  3: Flag used to indicate that the LN2 switch sensor reads over temperature.
            unsigned dewarSensorOC          : 1;    ///< Bit  4: Flag used to indicate that the dewar sensor  at 0°C.
            unsigned dewarSensorOver        : 1;    ///< Bit  5: Flag used to indicate that the dewar sensor reads over temperature.
            unsigned baseSensorOC           : 1;    ///< Bit  6: Flag used to indicate that the base sensor at 0°C.
            unsigned baseSensorOver         : 1;    ///< Bit  7: Flag used to indicate that the base sensor reads over temperature.
            unsigned dewarEmpty             : 1;    ///< Bit  8: Flag used to indicate that the dewar is empty.
            unsigned motorPosnError         : 1;    ///< Bit  9: Flag used to indicate that the the motor position is in error.
            unsigned unused10               : 1;    ///< Bit 10: Reserved for future use.
            unsigned unused11               : 1;    ///< Bit 11: Reserved for future use.
            unsigned unused12               : 1;    ///< Bit 12: Reserved for future use.
            unsigned unused13               : 1;    ///< Bit 13: Reserved for future use.
            unsigned unused14               : 1;    ///< Bit 14: Reserved for future use.
            unsigned unused15               : 1;    ///< Bit 15: Reserved for future use.
            unsigned unused16               : 1;    ///< Bit 16: Reserved for future use.
            unsigned unused17               : 1;    ///< Bit 17: Reserved for future use.
            unsigned unused18               : 1;    ///< Bit 18: Reserved for future use.
            unsigned unused19               : 1;    ///< Bit 19: Reserved for future use.
            unsigned unused20               : 1;    ///< Bit 20: Reserved for future use.
            unsigned unused21               : 1;    ///< Bit 21: Reserved for future use.
            unsigned unused22               : 1;    ///< Bit 22: Reserved for future use.
            unsigned unused23               : 1;    ///< Bit 23: Reserved for future use.
            unsigned unused24               : 1;    ///< Bit 24: Reserved for future use.
            unsigned unused25               : 1;    ///< Bit 25: Reserved for future use.
            unsigned unused26               : 1;    ///< Bit 26: Reserved for future use.
            unsigned unused27               : 1;    ///< Bit 27: Reserved for future use.
            unsigned unused28               : 1;    ///< Bit 28: Reserved for future use.
            unsigned unused29               : 1;    ///< Bit 29: Reserved for future use.
            unsigned unused30               : 1;    ///< Bit 30: Reserved for future use.
            unsigned unused31               : 1;    ///< Bit 31: Reserved for future use.
        }            flags;                         ///< The flag feild accessor.
        uint32_t     value;                         ///< The value that represents the state of the flags as a 32-bit value.
    };

    /*!
     *  \union      CMSStatus
     *  \brief      The Correlative Microscopy Stage status value is a bit feild of
     *              status flags used to feed back information about the
     *              status of Correlative Microscopy Stage.
     *
     *  @ingroup    Stage_Config_API
     */
    union CMSStatus
    {
        struct
        {
            unsigned on                     : 1;    ///< Bit  0: The stage has been switched on and is connected.
            unsigned onNoLN2                : 1;    ///< Bit  1: The stage has been switched on but needs Liquid Nitrogen.
            unsigned prime                  : 1;    ///< Bit  2: The stage has entered the first filling cycle.
            unsigned autoTopUp              : 1;    ///< Bit  3: Automatic topping up of the sample chamber.
            unsigned warmingUp              : 1;    ///< Bit  4: Warming up from a test.
            unsigned WarmingUpFromCupboard  : 1;    ///< Bit  5: Warming up from storage.
            unsigned unused6                : 1;    ///< Bit  6: Reserved for future use.
            unsigned unused7                : 1;    ///< Bit  7: Reserved for future use.
            unsigned light                  : 1;    ///< Bit  8: The chamber Light (LED) on/off 
            unsigned sampleDewarFillSignal  : 1;    ///< Bit  9: Sample dewar fill signal; the internal solenoid on flag.
            unsigned mainDewarFillSignal    : 1;    ///< Bit 10: Main dewar fill signal; the external solenoid on flag.
            unsigned unused11               : 1;    ///< Bit 11: Reserved for future use.
            unsigned unused12               : 1;    ///< Bit 12: Reserved for future use.
            unsigned unused13               : 1;    ///< Bit 13: Reserved for future use.
            unsigned unused14               : 1;    ///< Bit 14: Reserved for future use.
            unsigned unused15               : 1;    ///< Bit 15: Reserved for future use.
            unsigned unused16               : 1;    ///< Bit 16: Reserved for future use.
            unsigned unused17               : 1;    ///< Bit 17: Reserved for future use.
            unsigned unused18               : 1;    ///< Bit 18: Reserved for future use.
            unsigned unused19               : 1;    ///< Bit 19: Reserved for future use.
            unsigned unused20               : 1;    ///< Bit 20: Reserved for future use.
            unsigned unused21               : 1;    ///< Bit 21: Reserved for future use.
            unsigned unused22               : 1;    ///< Bit 22: Reserved for future use.
            unsigned unused23               : 1;    ///< Bit 23: Reserved for future use.
            unsigned unused24               : 1;    ///< Bit 24: Reserved for future use.
            unsigned unused25               : 1;    ///< Bit 25: Reserved for future use.
            unsigned unused26               : 1;    ///< Bit 26: Reserved for future use.
            unsigned unused27               : 1;    ///< Bit 27: Reserved for future use.
            unsigned unused28               : 1;    ///< Bit 28: Reserved for future use.
            unsigned unused29               : 1;    ///< Bit 29: Reserved for future use.
            unsigned unused30               : 1;    ///< Bit 30: Reserved for future use.
            unsigned unused31               : 1;    ///< Bit 31: Reserved for future use.
        }            flags;                         ///< The flag feild accessor.
        uint32_t     value;                         ///< The value that represents the state of the flags as a 32-bit value.
    };

    /*!
     *  \struct     StageCableLimit
     *  \brief      The StageCableLimit structure is used to report the voltage and current limits
     *              for the type of stage cable connected. Used as part of the heating cycle on stages.
     *
     *  \note       Size of structure is 8 bytes.
     *
     *  @ingroup    Stage_Config_API
     */
    struct StageCableLimit
    {
        float   limitV; ///< Voltage (V) level.
        float   limitI; ///< Current (I) level.
    };

    /*!
     *  \enum       OptionBoardType
     *  \brief      Defines a set of type codes for the type of option board installed in the
     *              the controller.
     *
     *  \note       Enums for the OptionBoardType support the range 0x0000 - 0xFFFF.
     *  @ingroup    Stage_Config_API
     */
    enum OptionBoardType
    {
        eOptionBoardType_None                   = 0x0000,   ///< Option board ID for no option board present.
        eOptionBoardType_CSSBoard               = 0x0001,   ///< Cambridge shearing system option board.
        eOptionBoardType_DSCBoard               = 0x0002,   ///< Differential scanning calorimetry option board.
        eOptionBoardType_DTCBoard               = 0x0003,   ///< Dual thermocoupled control option board.
        eOptionBoardType_XAxisMotorBoard        = 0x0004,   ///< X axis motor option board.
        eOptionBoardType_YAxisMotorBoard        = 0x0005,   ///< Y axis motor option board.
        eOptionBoardType_ZAxisMotorBoard        = 0x0006,   ///< Z axis motor option board.
        eOptionBoardType_VacuumMotorBoard       = 0x0007,   ///< Vacuum motor option board.
        eOptionBoardType_TSTMotorBoard          = 0x0008,   ///< Tensile test motor option board.
        eOptionBoardType_GSMotorBoard           = 0x0009,   ///< Gradiant stage motor option board.
        eOptionBoardType_FDVacuumMotorBoard     = 0x000A,   ///< Freeze drying vial vacuum motor option board.
        eOptionBoardType_RS232Board             = 0x000B,   ///< RS232 (serial data) expansion option board.
        eOptionBoardType_TSTBoard               = 0x000C,   ///< Tensile test control option board.
        eOptionBoardType_TTCBoard               = 0x000D,   ///< Triple thermocoupled control option board.
        eOptionBoardType_SingleVacuumBoard      = 0x000E,   ///< Vacuum control (single pump) option board.
        eOptionBoardType_DualVacuumBoard        = 0x000F,   ///< Vacuum control (dual pump) option board.
        eOptionBoardType_VTOBoard               = 0x0010,   ///< Video Text Overlay option board (Discontinued).
        eOptionBoardType_Max                    = 0xFFFF    ///< The maximum valid ID for an option board type.
    };

    /*!
     *  \union      RHStatus
     *  \brief      The Relative Humidity status value is a bit feild of
     *              status flags used to feed back information about the
     *              status of the relative humidity element of applicable
     *              stages.
     *  \note       Size of structure is 4 bytes.
     *  @ingroup    Stage_Config_API
     */
    union RHStatus
    {
        struct
        {
            unsigned colSel             : 4;    ///< Bits 0-3: Flag used to indicate which tube is selected.
            unsigned present            : 1;    ///< Bit  4: Flag used to indicate that a humidity unit is present (connected).
            unsigned reset              : 1;    ///< Bit  5: Flag used to indicate that the humidity unit has been reset.
            unsigned started            : 1;    ///< Bit  6: Flag used to indicate that a drying cycle has started.
            unsigned unitType           : 3;    ///< Bits 7-9: Defines the humidity unit type code.
            unsigned dessicantDryMode   : 1;    ///< Bit  10: Flag used to indicate that the dessicant dry mode is enabled.
            unsigned rampLimitReached   : 1;    ///< Bit  11: Flag used to indicate that the ramp limit (target humidity) has been reached.
            unsigned unused12           : 1;    ///< Bit  12: Reserved for future use.
            unsigned unused13           : 1;    ///< Bit  13: Reserved for future use.
            unsigned unused14           : 1;    ///< Bit  14: Reserved for future use.
            unsigned unused15           : 1;    ///< Bit  15: Reserved for future use.
            unsigned unused16           : 1;    ///< Bit  16: Reserved for future use.
            unsigned unused17           : 1;    ///< Bit  17: Reserved for future use.
            unsigned unused18           : 1;    ///< Bit  18: Reserved for future use.
            unsigned unused19           : 1;    ///< Bit  19: Reserved for future use.
            unsigned unused20           : 1;    ///< Bit  20: Reserved for future use.
            unsigned unused21           : 1;    ///< Bit  21: Reserved for future use.
            unsigned unused22           : 1;    ///< Bit  22: Reserved for future use.
            unsigned unused23           : 1;    ///< Bit  23: Reserved for future use.
            unsigned unused24           : 1;    ///< Bit  24: Reserved for future use.
            unsigned unused25           : 1;    ///< Bit  25: Reserved for future use.
            unsigned unused26           : 1;    ///< Bit  26: Reserved for future use.
            unsigned unused27           : 1;    ///< Bit  27: Reserved for future use.
            unsigned unused28           : 1;    ///< Bit  28: Reserved for future use.
            unsigned unused29           : 1;    ///< Bit  29: Reserved for future use.
            unsigned unused30           : 1;    ///< Bit  30: Reserved for future use.
            unsigned unused31           : 1;    ///< Bit  31: Reserved for future use.
        }            flags;                     ///< The flag feild accessor.
        uint32_t     value;                     ///< The value that represents the state of the flags as a 32-bit value.
    };

    /*!
     *  \struct     RHUnit
     *  \brief      The relative humidity unit information structure contains generic status information
     *              about the state of the humidity within the stage. This structure is used within 
     *              applicable stage information structures, sent to the host PC on request.
     *  \note       Size of structure is 52 bytes.
     *  @ingroup    Stage_Config_API
     */
    struct RHUnit
    {
        float       rh;                             ///< Current humidity %
        float       rhSetpoint;                     ///< The target humidity %
        float       rhTemp;                         ///< The temperature of the humidity heater
        int32_t     dryTimeSecs;                    ///< The drying time remaining (s)
        int32_t     setDryTimeSecs;                 ///< The programmed drying time (s)
        int32_t     swapTimeSecs;                   ///< The time to swap humidity tubes (s)
        int32_t     setSwapTimeSecs;                ///< The programmed swap time (s)
        float       tubePercent;                    ///< The % of water in the tube
        float       tubeSetpoint;                   ///< The target % of water in the tube.
        float       waterTemp;                      ///< The current temperature of the water.
        float       waterSetpoint;                  ///< The programmed temperature of the water.
        int32_t     columnDryModeCountTimeSecs;     ///< A timer (s) ?
        RHStatus    status;
    };

    /*!
     *  \union      TSTStatus
     *  \brief      The Tensile Testing status value is a bit feild of
     *              status flags used to feed back information about the
     *              status of Tensile Testing Stage.
     *  @ingroup    Stage_Config_API
     */
	union TSTStatus
    {
		struct
        {
			unsigned zeroLimit              : 1;    ///< Bit   0: Flag used to indicate that the jaws are at the zero limit; the relaxed distance.
			unsigned refLimit               : 1;    ///< Bit   1: Flag used to indicate that the jaws are at the reference limit; the max distance to travel.
			unsigned moveDone               : 1;    ///< Bit   2: Flag used to indicate that the current mode has complete, and await new instruction.
			unsigned dirn                   : 1;    ///< Bit   3: Flag used to indicate the direction the table; closing is \b set, opening is \b unset. 
			unsigned showAsForceDistance    : 1;    ///< Bit   4: Flag used to indicate that the stage is displaying distance if \b set, else force if \b unset.
			unsigned showCalbData           : 1;    ///< Bit   5: Flag used to indicate that the stage show display calibration data.
			unsigned cycleMode              : 1;    ///< Bit   6: Flag used to indicate that the motor is performing a cycle mode.
			unsigned cycleDirnOpen          : 1;    ///< Bit   7: Flag used to indicate that the motor cycle direction is opening if \b set, else closing if \b unset.
            unsigned unused8                : 1;    ///< Bit   8: Reserved for future use.
            unsigned unused9                : 1;    ///< Bit   9: Reserved for future use.
            unsigned unused10               : 1;    ///< Bit  10: Reserved for future use.
            unsigned unused11               : 1;    ///< Bit  11: Reserved for future use.
            unsigned unused12               : 1;    ///< Bit  12: Reserved for future use.
            unsigned unused13               : 1;    ///< Bit  13: Reserved for future use.
            unsigned unused14               : 1;    ///< Bit  14: Reserved for future use.
            unsigned unused15               : 1;    ///< Bit  15: Reserved for future use.
            unsigned unused16               : 1;    ///< Bit  16: Reserved for future use.
            unsigned unused17               : 1;    ///< Bit  17: Reserved for future use.
            unsigned unused18               : 1;    ///< Bit  18: Reserved for future use.
            unsigned unused19               : 1;    ///< Bit  19: Reserved for future use.
            unsigned unused20               : 1;    ///< Bit  20: Reserved for future use.
            unsigned unused21               : 1;    ///< Bit  21: Reserved for future use.
            unsigned unused22               : 1;    ///< Bit  22: Reserved for future use.
            unsigned unused23               : 1;    ///< Bit  23: Reserved for future use.
            unsigned unused24               : 1;    ///< Bit  24: Reserved for future use.
            unsigned unused25               : 1;    ///< Bit  25: Reserved for future use.
            unsigned unused26               : 1;    ///< Bit  26: Reserved for future use.
            unsigned unused27               : 1;    ///< Bit  27: Reserved for future use.
            unsigned unused28               : 1;    ///< Bit  28: Reserved for future use.
            unsigned unused29               : 1;    ///< Bit  29: Reserved for future use.
            unsigned unused30               : 1;    ///< Bit  30: Reserved for future use.
            unsigned unused31               : 1;    ///< Bit  31: Reserved for future use.
        }            flags;                         ///< The flag feild accessor.
        uint32_t     value;                         ///< The value that represents the state of the flags as a 32-bit value.
	};

    /*!
     *  \enum       TSTMode
     *  \brief      This enumerator defines the possible modes of operation the TST stage
     *              can operate in. This affects specifically the type of start/stop command
     *              sent from the motor board.
     *  @ingroup    Stage_Config_API
     */
    enum TSTMode
    {
        eTSTMode_Velocity   = 0x0,      ///< The tensile stage is operating in the velocity only mode (maintain a constant stress/strain).
        eTSTMode_Step       = 0x1,      ///< The tensile stage is operating in the step only mode (distance control).
        eTSTMode_Cycle      = 0x2,      ///< The tensile stage is operating in the cycle only mode (oscillating stress/strain).
        eTSTMode_Force      = 0x3,      ///< The tensile stage is operating in the force only mode (apply a specific force).
        eTSTMode_MotorRelax = 0x4,      ///< The tensile stage is operating in the relax only mode (Not motor control).
        eTSTMode_Stop       = 0x5       ///< The tensile stage is operating in the stop mode.
    };

    /*!
     *  \struct     TSTSampleSize
     *  \brief      This structure defines a sample size.
     *  @ingroup    Stage_Config_API
     */
    struct TSTSampleSize
    {
        float   width;      ///< The width of the sample (μm).
        float   thickness;  ///< The width of the sample (μm).
    };

    /*!
     *  \union      MVStatus
     *  \brief      The motor valve status value is a bit feild of
     *              status flags used to feed back information about the
     *              status of Motor valve element of applicable stages.
     *  \note       Size of structure is 4 bytes.
     *  @ingroup    Stage_Config_API
     */
    union MVStatus
    {
        struct
        {
            unsigned closed             : 1;    ///< Bit  0: The valve is fully closed.
            unsigned open               : 1;    ///< Bit  1: The valve is fully open.
            unsigned moveDone           : 1;    ///< Bit  2: The valve motor move is complete.
            unsigned autoMode           : 1;    ///< Bit  3: The valve motor will operate automatically.
            unsigned unused4            : 1;    ///< Bit  4: Reserved for future use.
            unsigned unused5            : 1;    ///< Bit  5: Reserved for future use.
            unsigned unused6            : 1;    ///< Bit  6: Reserved for future use.
            unsigned unused7            : 1;    ///< Bit  7: Reserved for future use.
            unsigned unused8            : 1;    ///< Bit  8: Reserved for future use.
            unsigned unused9            : 1;    ///< Bit  9: Reserved for future use.
            unsigned unused10           : 1;    ///< Bit 10: Reserved for future use.
            unsigned unused11           : 1;    ///< Bit 11: Reserved for future use.
            unsigned unused12           : 1;    ///< Bit 12: Reserved for future use.
            unsigned unused13           : 1;    ///< Bit 13: Reserved for future use.
            unsigned unused14           : 1;    ///< Bit 14: Reserved for future use.
            unsigned unused15           : 1;    ///< Bit 15: Reserved for future use.
            unsigned unused16           : 1;    ///< Bit 16: Reserved for future use.
            unsigned unused17           : 1;    ///< Bit 17: Reserved for future use.
            unsigned unused18           : 1;    ///< Bit 18: Reserved for future use.
            unsigned unused19           : 1;    ///< Bit 19: Reserved for future use.
            unsigned unused20           : 1;    ///< Bit 20: Reserved for future use.
            unsigned unused21           : 1;    ///< Bit 21: Reserved for future use.
            unsigned unused22           : 1;    ///< Bit 22: Reserved for future use.
            unsigned unused23           : 1;    ///< Bit 23: Reserved for future use.
            unsigned unused24           : 1;    ///< Bit 24: Reserved for future use.
            unsigned unused25           : 1;    ///< Bit 25: Reserved for future use.
            unsigned unused26           : 1;    ///< Bit 26: Reserved for future use.
            unsigned unused27           : 1;    ///< Bit 27: Reserved for future use.
            unsigned unused28           : 1;    ///< Bit 28: Reserved for future use.
            unsigned unused29           : 1;    ///< Bit 29: Reserved for future use.
            unsigned unused30           : 1;    ///< Bit 30: Reserved for future use.
            unsigned unused31           : 1;    ///< Bit 31: Reserved for future use.
        }            flags;                     ///< The flag feild accessor.
        uint32_t     value;                     ///< The value that represents the state of the flags as a 32-bit value.
    };

    /*!
     *  \union      MDSStatus
     *  \brief      The Motor Driven Stage Status value is a bit feild of
     *              status flags used to feed back information about the
     *              status of movement operations on the motor system.
     *  \note       Size of structure is 4 bytes.
     *  @ingroup    Stage_Config_API
     */
    union MDSStatus
    {
        struct
        {
            unsigned xMinLimit          : 1;    ///< Bit   0: The minimum limit on the X axis has been reached.
            unsigned xMaxLimit          : 1;    ///< Bit   1: The maximum limit on the X axis has been reached.
            unsigned xMoveDone          : 1;    ///< Bit   2: The movement operation on the X axis has completed.
            unsigned yMinLimit          : 1;    ///< Bit   3: The minimum limit on the Y axis has been reached.
            unsigned yMaxLimit          : 1;    ///< Bit   4: The maximum limit on the Y axis has been reached.
            unsigned yMoveDone          : 1;    ///< Bit   5: The movement operation on the Y axis has completed.
            unsigned unused6            : 1;    ///< Bit   6: Reserved for future use.
            unsigned unused7            : 1;    ///< Bit   7: Reserved for future use.
            unsigned unused8            : 1;    ///< Bit   8: Reserved for future use.
            unsigned unused9            : 1;    ///< Bit   9: Reserved for future use.
            unsigned unused10           : 1;    ///< Bit  10: Reserved for future use.
            unsigned unused11           : 1;    ///< Bit  11: Reserved for future use.
            unsigned unused12           : 1;    ///< Bit  12: Reserved for future use.
            unsigned unused13           : 1;    ///< Bit  13: Reserved for future use.
            unsigned unused14           : 1;    ///< Bit  14: Reserved for future use.
            unsigned unused15           : 1;    ///< Bit  15: Reserved for future use.
            unsigned unused16           : 1;    ///< Bit  16: Reserved for future use.
            unsigned unused17           : 1;    ///< Bit  17: Reserved for future use.
            unsigned unused18           : 1;    ///< Bit  18: Reserved for future use.
            unsigned unused19           : 1;    ///< Bit  19: Reserved for future use.
            unsigned unused20           : 1;    ///< Bit  20: Reserved for future use.
            unsigned unused21           : 1;    ///< Bit  21: Reserved for future use.
            unsigned unused22           : 1;    ///< Bit  22: Reserved for future use.
            unsigned unused23           : 1;    ///< Bit  23: Reserved for future use.
            unsigned unused24           : 1;    ///< Bit  24: Reserved for future use.
            unsigned unused25           : 1;    ///< Bit  25: Reserved for future use.
            unsigned unused26           : 1;    ///< Bit  26: Reserved for future use.
            unsigned unused27           : 1;    ///< Bit  27: Reserved for future use.
            unsigned unused28           : 1;    ///< Bit  28: Reserved for future use.
            unsigned unused29           : 1;    ///< Bit  29: Reserved for future use.
            unsigned unused30           : 1;    ///< Bit  30: Reserved for future use.
            unsigned unused31           : 1;    ///< Bit  31: Reserved for future use.
        }            flags;                     ///< The flag feild accessor.
        uint32_t     value;                     ///< The value that represents the state of the flags as a 32-bit value.
    };

    /*!
     *  \struct     MotorSensorData
     *  \brief      The MotorSensorData structure holds configuration information about
     *              a motor option board. This can be used to determine limits and
     *              supported features.
     *  @ingroup    Stage_Config_API
     */
    struct MotorSensorData
    {
        float       maxDistance;        ///< The maximum distance the motor can travel (μm).
        float       jawClosedGap;       ///< The jaw closed gap (μm).
        float       current;            ///< The current position (μm).
        float       maxVel;             ///< The maximum velocity supported.
        float       minVel;             ///< The minimum velocity supported.
        float       maxAccel;           ///< The maximum acceleration supported.
        float       defSpeed;           ///< the default motor speed.
        float       postOffset;         ///< The post offest.
        float       centreOffset;       ///< The centre offset.
        float       reserved;           ///< Reserved for future use.
        bool        endStop1Fitted;     ///< Flag to indicate if the 1st end stop is fitted.
        bool        endStop2Fitted;     ///< Flag to indicate if the 1st end stop is fitted.
        bool        sensorInv;          ///< Flag to indicate if the sensor is inverted.
        float       encoderResn;        ///< The encoder resolution (μm).
        bool        encoderFitted;      ///< Flag to indicate if the encoder is fitted.
        bool        encoderIndexFitted; ///< Flag to indicate if the encoder index is fitted.
    };

    /*!
     *  \struct     VacuumSensorData
     *  \brief      The VacuumSensorData structure holds configuration information about
     *              a sensor connected to a vacuum option board. This can be used to determine
     *              supported features.
     *  @ingroup    Stage_Config_API
     */
	struct VacuumSensorData
    {
		uint32_t        vacPressure;            ///< Mode of operational; Apply Pressure = 1, Apply Vacuum == 0.
		uint32_t        range;                  ///< The type of gauge used; 0 = Vpir (pirani), else Vcap (capacitance).
		uint32_t        pressZero;              ///< Pressure level at zero. 
	};


    /*!
     *  \struct     DSCModulationData
     *  \brief      The DSCModulationData structure is used by the DSC stage as wave-form modulation
     *              data to apply.
     *  @ingroup    Stage_Config_API
     */
    struct DSCModulationData 
    {
        float   amplitude;      ///< The amplitude of the wave form.
        float   period;         ///< The period of the wave form.
        uint8_t enabled;        ///< Used as a flag to enable of disable the modulation; 1 = enabled, 0 = disabled.
    };
}

#ifdef __cplusplus
}
#endif


#endif // LINKAM_SDK__COMMON_STAGE_API_H


