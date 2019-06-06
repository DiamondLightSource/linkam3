/************************************************************************
*
*   File:           CommonStageAPI.h
*
*   Description:    This header defines the common stage API used by the
*                   Linkam SDK.
*
*   Copyright © 2018 Linkam Scientific Instruments. All rights reserved
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
     */
    #define AtmosphericLimit (2e3f)

    /*!
     *  \brief      The limit on the vacuum sensor which determines we have vacuum perssure.
     *              This is messaured in millbars (mBar). Used in conjunction with eStageValueTypeVacuumLimit.
     */
    #define MaxVacuumLimit (5e-4f)

    /*!
     *  \enum       StageValueType
     *  \brief      This enumerator defines a set of supported value IDs for accessing data fields from the stage.
     *
     *  @ingroup    Stage_IO_API
     */
    enum StageValueType
    {
        eStageValueTypeHeater1Temp                          =  0,   ///< Heater 1 temperature in °C (Read). Main stage temperature or CMS196 Correlative Bridge temperature).
        eStageValueTypeHeater1Rate                          =  1,   ///< Heater 1 rate in °C/min (Read / Write)
        eStageValueTypeHeater1Limit                         =  2,   ///< Heater 1 limit °C (Read / Write)
        eStageValueTypeHeater1Power                         =  3,   ///< Heater 1 power 0 - 100% (Read)
        eStageValueTypeHeater1LNPSpeed                      =  4,   ///< Heater 1 LNP speed 0 - 100% (Read)
        eStageValueTypeHeater2Temp                          =  5,   ///< Heater 2 temperature in °C (Read). (CMS196 Correlative Chamber temperature)
        eStageValueTypeHeater2Rate                          =  6,   ///< Heater 2 rate °C/min (Read / Write) (reserved for future development)
        eStageValueTypeHeater2Limit                         =  7,   ///< Heater 2 limit °C (Read / Write) (reserved for future development)
        eStageValueTypeHeater2Power                         =  8,   ///< Heater 2 power 0 - 100% (Read) (reserved for future development)
        eStageValueTypeHeater2LNPSpeed                      =  9,   ///< Heater 2 LNP speed 0 - 100% (Read) (reserved for future development)
        eStageValueTypeWaterCoolingTemp                     = 10,   ///< Cooling water temperature (Read)
        eStageValueTypeHumidityTemp                         = 11,   ///< Humidity chamber temperature from sensor
        eStageValueTypeVacuum                               = 12,   ///< Vacuum in mBar (Read)
        eStageValueTypeVacuumLimit                          = 13,   ///< Vacuum limit in mBar (Read / Write)
        eStageValueTypeHumidity                             = 14,   ///< Humidity in %rh (Read)
        eStageValueTypeHumidityLimit                        = 15,   ///< Humidity limit in %rh (Read / Write)
        eStageValueTypeMotorPosX                            = 16,   ///< X motor position in um (Read)
        eStageValueTypeMotorVelX                            = 17,   ///< X motor velocity in um/sec (Read / Write)
        eStageValueTypeMotorLimitX                          = 18,   ///< X motor limit in um (Read / Write)
        eStageValueTypeMotorPosY                            = 19,   ///< Y motor position in um (Read)
        eStageValueTypeMotorVelY                            = 20,   ///< Y motor velocity in um/sec (Read / Write)
        eStageValueTypeMotorLimitY                          = 21,   ///< Y motor limit in um (Read / Write)
        eStageValueTypeMotorPosZ                            = 22,   ///< Z motor position in um (Read) \note Reserved for future development.
        eStageValueTypeMotorVelZ                            = 23,   ///< Z motor velocity in um/sec (Read / Write) \note Reserved for future development.
        eStageValueTypeMotorLimitZ                          = 24,   ///< Z motor limit in um (Read / Write) \note Reserved for future development.
        eStageValueTypeReserved1                            = 25,   ///< Reserved.
        eStageValueTypeReserved2                            = 26,   ///< Reserved.
        eStageValueTypeReserved3                            = 27,   ///< Reserved.    
        eStageValueTypeVacMotorValvePos                     = 28,   ///< Vacuum motorised valve position in um (Read) (MV196)
        eStageValueTypeVacMotorValveVel                     = 29,   ///< Vacuum motorised valve velocity in um/sec (Read / Write) (MV196)
        eStageValueTypeVacMotorValveLimit                   = 30,   ///< Vacuum motorised valve limit in um (Read / Write) \note Reserved for future development. (MV196)
        eStageValueTypeGradedMotorPos                       = 31,   ///< Graded stage valve position in um (Read)
        eStageValueTypeGradedMotorVel                       = 32,   ///< Graded stage motor velocity in um/sec (Read / Write)
        eStageValueTypeGradedMotorLimit                     = 33,   ///< Graded stage motor limit in um (Read)    
        eStageValueTypeSampleRef1                           = 34,   ///< Reference ( True) value for first calibration point in °C (Read / Write)
        eStageValueTypeSampleAct1                           = 35,   ///< Actual (stage measured) value for first calibration point in  °C (Read / Write)
        eStageValueTypeSampleRef2                           = 36,   ///< Reference ( True) value for second calibration point in °C (Read / Write)
        eStageValueTypeSampleAct2                           = 37,   ///< Actual (stage measured) value for second calibration point in  °C (Read / Write)
        eStageValueTypeSampleRef3                           = 38,   ///< Reference ( True) value for third calibration point in °C (Read / Write)
        eStageValueTypeSampleAct3                           = 39,   ///< Actual (stage measured) value for third calibration point in  °C (Read / Write)
        eStageValueTypeSampleRef4                           = 40,   ///< Reference (True) value for fourth calibration point in °C (Read / Write)
        eStageValueTypeSampleAct4                           = 41,   ///< Actual (stage measured) value for fourth calibration point in  °C (Read / Write)
        eStageValueTypeSampleRef5                           = 42,   ///< Reference ( True)  value for fifth calibration point in °C (Read / Write)
        eStageValueTypeSampleAct5                           = 43,   ///< Actual (stage measured) value for fifth calibration point in  °C (Read / Write)
        eStageValueTypeHeater3Temp                          = 44,   ///< Heater 3 temperature in °C (Read). (CMS196 Correlative Dewar temperature) <b>(reserved for future development)
        eStageValueTypeDsc                                  = 45,   ///< Read the current DSC (Differential Scanning Calorimetry) value.
        eStageValueTypeReserved4                            = 46,   ///< Reserved.
        eStageValueTypeReserved5                            = 47,   ///< Reserved.
        eStageValueTypeReserved6                            = 48,   ///< Reserved.
        eStageValueTypeReserved7                            = 49,   ///< Reserved.
        eStageValueTypeReserved8                            = 50,   ///< Reserved.
        eStageValueTypeHeater4Temp                          = 51,   ///< Heater 4 temperature in °C (Read)
        eStageValueTypeCMS196Light                          = 52,   ///< CMS196 (Correlative stage) light
        eStageValueTypeCMS196WarmingHeater                  = 53,   ///< CMS196 (Correlative stage) (Write) warming heater
        eStageValueTypeCMS196SolenoidRefill                 = 54,   ///< CMS196 (Correlative stage) (Write) solenoid refill
        eStageValueTypeCMS196SampleDewarFillSig             = 55,   ///< CMS196 (Correlative stage) (Read) sample dewar filling signal (1=filling)
        eStageValueTypeCMS196Status                         = 56,   ///< CMS196 (Correlative stage) (Read) Status
        eStageValueTypeCMS196Error                          = 57,   ///< CMS196 (Correlative stage) (Read) Errors
        eStageValueTypeRamp1HoldTime                        = 58,   ///< Ramp 1 Hold time in secs (Read / Write)
        eStageValueTypeRamp1HoldRemaining                   = 59,   ///< Ramp 1 hold time left in secs (Read)
        eStageValueTypeCMS196MainDewarFillSig               = 60,   ///< CMS196 (Correlative stage) (Read) main dewar filling signal (1=filling)
        eStageValueTypeCMS196CondenserLEDLevel              = 61,   ///< CMS196 (Correlative stage) (Read/Write) condenser led level (0-100). Only 0 and 100 can be used.0=off.100=on
        eStageValueTypeTestMotion                           = 62,   ///< test motion (linkam only)
        eStageValueTypeMotorFeedbackYX                      = 63,   ///< X & Y Motor feedback mode (linkam only)
        eStageValueTypeTstMotorPos                          = 64,   ///< Tensile motor position in mm (Read)
        eStageValueTypeTstMotorVel                          = 65,   ///< Tensile motor velocity in um/sec (Read / Write)
        eStageValueTypeTstMotorLimit                        = 66,   ///< Tensile motor limit in um (Read / Write). Set this parameter to be the distance you would like the jaws to open when "StartMotors" is called. Set as positive to close jaws.
        eStageValueTypeTstForce                             = 67,   ///< Tensile force value in Newtons (Read)
        eStageValueTypeTstForceLimit                        = 68,   ///< Tensile Force set-point value in Newtons (Read / Write)
        eStageValueTypeTstPidKp                             = 69,   ///< Tensile PID Proportional Gain (Read /Write)
        eStageValueTypeTstPidKi                             = 70,   ///< Tensile PID Integral Gain (Read /Write)
        eStageValueTypeTstPidKd                             = 71,   ///< Tensile PID Derivative Gain (Read /Write)
        eStageValueTypeTstForceGauge                        = 72,   ///< Tensile stage force transducer size (Read) 
        eStageValueTypeCssMode                              = 73,   ///< Set the CssMode. 0:Steady, 1: Step, 2: Osc, 3: Relax
        eStageValueTypeCssGapLimit                          = 74,   ///< Set gap distance [µm]
        eStageValueTypeCssGapPos                            = 75,   ///< The current gap distance in [µm]
        eStageValueTypeCssStrainLimit                       = 76,   ///< Set the shear strain (Step and Osc Modes only)
        eStageValueTypeCssRateLimit                         = 77,   ///< Set the S-1 Shear rate.
        eStageValueTypeCssOcsFreq                           = 78,   ///< Set oscillation frequency (Osc/oscillatory mode )
        eStageValueTypeCssDirn                              = 79,   ///< Set to 1 for Anti-Clockwise or 0 for Clockwise. (Default=0 Clockwise.)
        eStageValueTypeCssJogRotVel                         = 80,   ///< Set the rotational velocity for CSS jog mode. (Set a Negative velocity to reverse direction).
        eStageValueTypeCssJogGapDis                         = 81,   ///< Set the gap distance for CSS jog mode.
        eStageValueTypeCssDefaultGapRefVel                  = 82,   ///< Set the Default Gap motor velocity (Default: 300µm/s)
        eStageValueTypeCssDefaultRotRefVel                  = 83,   ///< Set the Default Rot motor velocity

    // These values are currently not supported.
    // These are for future use with the LinkamSDK.
    #if 0    
        eStageValueTypeHumiditySetDesiccantDryTimeRW        = 84,   ///< Returns desiccant drying time in seconds
        eStageValueTypeHumidityDesiccantDryTimeR            = 85,   ///< Returns desiccant drying time left in seconds
        eStageValueTypeHumidityManualPIDR                   = 86,   ///< returns whether the Rh stage cable is for use in OEM enclosures with manual PID enabled
        eStageValueTypeHumidityPGainRW                      = 87,   ///< Sets proportional gain for OEM enclosures. Default is 40.0
        eStageValueTypeHumidityIGainRW                      = 88,   ///< Sets integral gain for OEM enclosures. Default is 2.0
        eStageValueTypeHumidityDGainRW                      = 89,   ///< Sets differential gain for OEM enclosures. Default is 0.0
        eStageValueTypeHumidityLNGainRW                     = 90,   ///< Sets PID lag new gain for OEM enclosures. Lag new must be 1 greater than lag old. Default is 11.0
        eStageValueTypeHumidityLOGainRW                     = 91,   ///< Sets PID lag old gain for OEM enclosures. Lag old must be 1 less than lag new. Default is 10.0
        eStageValueTypeHumidityTubePwrRW                    = 92,   ///< Sets delivery tube heater power in %. Default is 40%
        eStageValueTypeHumidityWaterSetTempRW               = 93,   ///< Gets the water bottle temperature Set Point in °C. Default is 45°C
        eStageValueTypeHumidityWaterTempR                   = 94,   ///< Gets the water bottle temperature in °C
        eStageValueTypeHumiditySetSwapTimeRW                = 95,   ///< Sets column swap time in seconds. Default is 6000 (100 mins)
        eStageValueTypeHumiditySetDryTimeRW                 = 96,   ///< Sets column drying time in seconds. Default is 2400 (40 mins)</summary
        eStageValueTypeHumiditySwapTimeR                    = 97,   ///< Returns current column swap time left seconds
        eStageValueTypeHumidityDryTimeR                     = 98,   ///< Returns current column drying time left seconds
    #endif

        eStageValueTypeCMS196AutoDewarFill                  = 99,   ///< CMS196 (Correlative stage) (Write) Use to start or stop auto filling feature of the dewar; 0.0f = stop, 1.0f = start.
        eStageValueTypeTstShowCalbData                      = 65535 ///< Tensile show calibration data.
    };

    /*!
     *  \struct     StageConfig
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
             *  \brief      Reserved.
             *  \note       Bit 25
             */
            unsigned    unused25                        : 1;
    
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
             *  \brief      Reserved.
             *  \note       Bit 51
             *  \note       Motorised Z axis.
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
            unsigned    moveDone       : 1;     ///< Bit  0: ...
            unsigned    segComp        : 1;     ///< Bit  1: ...
            unsigned    motorDirn      : 1;     ///< Bit  2: ...
            unsigned    gapMoving      : 1;     ///< Bit  3: ...
            unsigned    lidOn          : 1;     ///< Bit  4: ...
            unsigned    refLimit       : 1;     ///< Bit  5: ...
            unsigned    zeroLimit      : 1;     ///< Bit  6: ...
            unsigned    gapMotDirn     : 1;     ///< Bit  7: ...
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
     *  \enum       CSSCheckCodes
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
        char    value;
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
            unsigned mainSensorOC           : 1;    ///< Bit  0: 
            unsigned mainSensorOver         : 1;    ///< Bit  1: 
            unsigned ln2SwitchSensorOC      : 1;    ///< Bit  2: 
            unsigned ln2SwitchSensorOver    : 1;    ///< Bit  3: 
            unsigned dewarSensorOC          : 1;    ///< Bit  4: 
            unsigned dewarSensorOver        : 1;    ///< Bit  5: 
            unsigned baseSensorOC           : 1;    ///< Bit  6: 
            unsigned baseSensorOver         : 1;    ///< Bit  7: 
            unsigned dewarEmpty             : 1;    ///< Bit  8: 
            unsigned motorPosnError         : 1;    ///< Bit  9: 
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
            unsigned unused4                : 1;    ///< Bit  4: Reserved for future use.
            unsigned unused5                : 1;    ///< Bit  5: Reserved for future use.
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
}

#ifdef __cplusplus
}
#endif


#endif // LINKAM_SDK__COMMON_STAGE_API_H


