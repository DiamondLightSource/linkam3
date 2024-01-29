/************************************************************************
*
*   File:           ControllerAPI.h
*
*   Description:    This header defines the controller API for the Linkam
*                   SDK.
*
*   Copyright © 2018-2023 Linkam Scientific Instruments. All rights reserved
************************************************************************/
#ifndef LINKAM_SDK__CONTROLLER_API_H
#define LINKAM_SDK__CONTROLLER_API_H
#include "ExportAPI.h"
#include "CommonTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

namespace LinkamSDK
{
    /*!
     *  \brief      This array of constant strings defines the accompanying error messages to
     *              the error codes provided by the ControllerError enumerator data type.
     *
     *  @ingroup    Controller_API
     */
    static const char* ControllerErrorStrings[] =
    {
        "No Error",
        "Stage cable disconnected from the controller",
        "Stage cable identifier error",
        "Stage temperature sensor open circuit or over-range",
        "Load power supply is incorrect for the stage type",
        "Load power supply output voltage incorrect",
        "The stage requires a relay fitted in the T95",
        "The controller has the wrong combination of option boards",
        "Cable disconnected from one of the option boards",
        "Incorrect cable connected to one of the option boards",
        "Sensor open circuit or overrange on one of the option boards",
        "The controller unit fan is not working correctly",
        "The LNP is reporting an error",
        "There has been a communications error",
        "The cooling water is too warm or is not flowing through the stage",
        "CSS450 motor drive overheating error",
        "CSS450 motor winding error",
        "The RH95 humidity unit is reporting an error",
        "T96 Protection error",
        "T96 power driver overheating error",
        "A standard single output LNP is required for the stage type",
        "A dual output LNP is required for the stage type",
        "Incorrect cable limits for stage type",
        "CMS196 Chamber sensor open circuit",
        "CMS196 Chamber sensor over range",
        "CMS196 LN2 Switch sensor open circuit",
        "CMS196 LN2 Switch sensor over range",
        "CMS196 Dewar sensor open circuit",
        "CMS196 Dewar sensor over range",
        "CMS196 Dewar empty",
        "CMS196 Base sensor open circuit",
        "CMS196 Base sensor over range",
        "CMS196 Motor position error"
    };

    /*!
     *  \enum       ControllerError
     *  \brief      This enumerator defines a set of supported value IDs as error codes from the controller.
     *
     *  @ingroup    Controller_API
     */
    enum ControllerError
    {
        eControllerErrorNone                                =  0,   ///< No errors
        eControllerErrorStageCableDisconnected              =  1,   ///< Stage cable disconnected from the controller
        eControllerErrorStageCableError                     =  2,   ///< Stage cable identifier error
        eControllerErrorStageTempSensorOpenOverrange        =  3,   ///< Stage temperature sensor open circuit or over-range
        eControllerErrorLoadPowerIncorrectForStage          =  4,   ///< Load power supply is incorrect for the stage type
        eControllerErrorLoadPowerOutputVoltageWrong         =  5,   ///< Load power supply output voltage incorrect
        eControllerErrorT95RelayMissing                     =  6,   ///< The stage requires a relay fitted in the T95
        eControllerErrorT95OptionBoardWongConfig            =  7,   ///< The controller has the wrong combination of option boards
        eControllerErrorOptionBoardCableDisconnect          =  8,   ///< Cable disconnected from one of the option boards
        eControllerErrorOptionBoardIncorrectCable           =  9,   ///< Incorrect cable connected to one of the option boards
        eControllerErrorOptionBoardSensorOenOverrange       = 10,   ///< Sensor open circuit or overrange on one of the option boards
        eControllerErrorT95FanNotWorking                    = 11,   ///< The controller fan is not working correctly
        eControllerErrorLNP95Error                          = 12,   ///< The LNP is reporting an error
        eControllerErrorCommsError                          = 13,   ///< There has been a communications error
        eControllerErrorCoolingWaterTooWarmNotFlowing       = 14,   ///< The cooling water is too warm or is not flowing through the stage
        eControllerErrorCSS450MotorDriveOverTemp            = 15,   ///< CSS motor drive overheating error (reserved for future development)
        eControllerErrorCSS450MotorWindingError             = 16,   ///< CSS motor winding error
        eControllerErrorRH95UnitError                       = 17,   ///< The RH95 humidity unit is reporting an error
        eControllerErrorControllerProtectionError           = 18,   ///< T96 Protection error
        eControllerErrorControllerPowerDriverOverheating    = 19,   ///< T96 power driver overheating error
        eControllerErrorRequiresSignleOutputLNP             = 20,   ///< A standard single output LNP is required for the stage type
        eControllerErrorRequiresDualOutputLNP               = 21,   ///< A dual output LNP is required for the stage type
        eControllerErrorIncorrectStageCableLimits           = 22,   ///< Incorrect cable limits for stage type
        eControllerErrorReserved1                           = 23,   ///< Reserved for future use.
        eControllerErrorCMS196ChamberSensorOpen             = 24,   ///< CMS Chamber sensor open circuit
        eControllerErrorCMS196ChamberSensorOverrange        = 25,   ///< CMS Chamber sensor over range
        eControllerErrorCMS196LN2SwitchSensorOpen           = 26,   ///< CMS LN2 Switch sensor open circuit
        eControllerErrorCMS196LN2SwitchSensorOverrange      = 27,   ///< CMS LN2 Switch sensor over range
        eControllerErrorCMS196DewarSensorOpen               = 28,   ///< CMS Dewar sensor open circuit
        eControllerErrorCMS196DewarSensorOverrange          = 29,   ///< CMS Dewar sensor over range
        eControllerErrorCMS196DewarEmpty                    = 30,   ///< CMS Dewar empty
        eControllerErrorCMS196BaseSensorOpen                = 31,   ///< CMS Base sensor open circuit
        eControllerErrorCMS196BaseSensorOverrange           = 32,   ///< CMS Base sensor over range
        eControllerErrorCMS196MotorPosnError                = 33    ///< CMS Motor position error
    };

    /*!
     *  \union      ControllerConfig
     *  \brief      This structure defines a set of flags which detail the controllers' configuration.
     *              The controllers configuration is dependent on the peripherial devices connected to
     *              it. This flags within this structure provide the enabled/disabled states of the
     *              possible configuration options.
     *
     *  @ingroup    Controller_API
     */
    union ControllerConfig
    {
        struct Flags
        {
            unsigned    supportsHeater                          : 1; ///< Bit  0:    Single heater supported.
            unsigned    supportsDualHeater                      : 1; ///< Bit  1:    Dual heater supported.
            unsigned    supportsDualHeaterIndependentLimits     : 1; ///< Bit  2:    Dual heater independent limits supported.
            unsigned    supportsDualHeaterIndependentRates      : 1; ///< Bit  3:    Dual heater independent rates supported.
            unsigned    unused4                                 : 1; ///< Bit  4:    Reserved for future use.
            unsigned    unused5                                 : 1; ///< Bit  5:    Reserved for future use.
            unsigned    unused6                                 : 1; ///< Bit  6:    Reserved for future use.
            unsigned    unused7                                 : 1; ///< Bit  7:    Reserved for future use.
            unsigned    unused8                                 : 1; ///< Bit  8:    Reserved for future use.
            unsigned    unused9                                 : 1; ///< Bit  9:    Reserved for future use.
            unsigned    vacuumOption                            : 1; ///< Bit 10:    Vacuum/Pressure option card fitted, vacuum gauge connected, ready to use.
            unsigned    unused11                                : 1; ///< Bit 11:    Reserved for future use.
            unsigned    tensileForceCardReady                   : 1; ///< Bit 12:    Tensile force card ready.
            unsigned    dscCardReady                            : 1; ///< Bit 13:    DSC card fitted.
            unsigned    xMotorCardReady                         : 1; ///< Bit 14:    X Axis motor card fitted, motor connected, ready to use.
            unsigned    yMotorCardReady                         : 1; ///< Bit 15:    Y Axis motor card fitted, motor connected, ready to use.
            unsigned    zMotorCardReady                         : 1; ///< Bit 16:    Z Axis motor card fitted, motor connected, ready to use.
            unsigned    motorValveCardReady                     : 1; ///< Bit 17:    MV196 motor card fitted, MV196 valve connected, ready to use.
            unsigned    tensileMotorCardReady                   : 1; ///< Bit 18:    Tensile motor card fitted, motor connected, ready to use.
            unsigned    gradedMotorCardReady                    : 1; ///< Bit 19:    Graded stage motor card fitted, motor connected, ready to use.
            unsigned    dtcCardReady                            : 1; ///< Bit 20:    Dual thermalcoupled card ready.
            unsigned    cssMotorCardReady                       : 1; ///< Bit 21:    CSS motor card connected and ready.
            unsigned    unused22                                : 1; ///< Bit 22:    Reserved for future use.
            unsigned    unused23                                : 1; ///< Bit 23:    Reserved for future use.
            unsigned    unused24                                : 1; ///< Bit 24:    Reserved for future use.
            unsigned    unused25                                : 1; ///< Bit 25:    Reserved for future use.
            unsigned    unused26                                : 1; ///< Bit 26:    Reserved for future use.
            unsigned    unused27                                : 1; ///< Bit 27:    Reserved for future use.
            unsigned    unused28                                : 1; ///< Bit 28:    Reserved for future use.
            unsigned    unused29                                : 1; ///< Bit 29:    Reserved for future use.
            unsigned    unused30                                : 1; ///< Bit 30:    Reserved for future use.
            unsigned    unused31                                : 1; ///< Bit 31:    Reserved for future use.
            unsigned    unused32                                : 1; ///< Bit 32:    Reserved for future use.
            unsigned    unused33                                : 1; ///< Bit 33:    Reserved for future use.
            unsigned    unused34                                : 1; ///< Bit 34:    Reserved for future use.
            unsigned    unused35                                : 1; ///< Bit 35:    Reserved for future use.
            unsigned    lnpReady                                : 1; ///< Bit 36:    Standard LNP cooling pump present.
            unsigned    lnpDualReady                            : 1; ///< Bit 37:    Dual speed LNP cooling pump present.
            unsigned    unused38                                : 1; ///< Bit 38:    Reserved for future use.
            unsigned    unused39                                : 1; ///< Bit 39:    Reserved for future use.
            unsigned    unused40                                : 1; ///< Bit 40:    Reserved for future use.
            unsigned    unused41                                : 1; ///< Bit 41:    Reserved for future use.
            unsigned    unused42                                : 1; ///< Bit 42:    Reserved for future use.
            unsigned    unused43                                : 1; ///< Bit 43:    Reserved for future use.
            unsigned    unused44                                : 1; ///< Bit 44:    Reserved for future use.
            unsigned    unused45                                : 1; ///< Bit 45:    Reserved for future use.
            unsigned    humidityReady                           : 1; ///< Bit 46:    RH95 humidity controller present.
            unsigned    unused47                                : 1; ///< Bit 47:    Reserved for future use.
            unsigned    unused48                                : 1; ///< Bit 48:    Reserved for future use.
            unsigned    unused49                                : 1; ///< Bit 49:    Reserved for future use.
            unsigned    unused50                                : 1; ///< Bit 50:    Reserved for future use.
            unsigned    unused51                                : 1; ///< Bit 51:    Reserved for future use.
            unsigned    unused52                                : 1; ///< Bit 52:    Reserved for future use.
            unsigned    unused53                                : 1; ///< Bit 53:    Reserved for future use.
            unsigned    unused54                                : 1; ///< Bit 54:    Reserved for future use.
            unsigned    unused55                                : 1; ///< Bit 55:    Reserved for future use.
            unsigned    unused56                                : 1; ///< Bit 56:    Reserved for future use.
            unsigned    unused57                                : 1; ///< Bit 57:    Reserved for future use.
            unsigned    unused58                                : 1; ///< Bit 58:    Reserved for future use.
            unsigned    unused59                                : 1; ///< Bit 59:    Reserved for future use.
            unsigned    unused60                                : 1; ///< Bit 60:    Reserved for future use.
            unsigned    unused61                                : 1; ///< Bit 61:    Reserved for future use.
            unsigned    unused62                                : 1; ///< Bit 62:    Reserved for future use.
            unsigned    unused63                                : 1; ///< Bit 63:    Reserved for future use.
        }           flags;
        uint64_t    value;
    };

    /*!
     *  \struct     ControllerStatus
     *  \brief      This structure defines a set of flags which detail the states of the properties
     *              of the peripherial devices connected to the controller, the controller's status.
     *              This covers the stage, LNPs, humidity controllers, and extension cards connected 
     *              to the controller device.
     *
     *  @ingroup    Controller_API
     */
    union ControllerStatus
    {
        struct Flags
        {
            unsigned    controllerError                 : 1;    ///< Bit   0:       The controller is reporting an error, use GetControllerError method.
            unsigned    heater1RampSetPoint             : 1;    ///< Bit   1:       The Stages' 1st (primary) heater ramp at set point.
            unsigned    heater1Started                  : 1;    ///< Bit   2:       The Stages' 1st (primary) heater has started.
            unsigned    heater2RampSetPoint             : 1;    ///< Bit   3:       The Stages' 2nd heater ramp at set point.
            unsigned    heater2Started                  : 1;    ///< Bit   4:       The Stages' 2nd heater has started.
            unsigned    vacuumRampSetPoint              : 1;    ///< Bit   5:       The Vacuum ramp is at set point.
            unsigned    vacuumCtrlStarted               : 1;    ///< Bit   6:       The Vacuum control has started.
            unsigned    vacuumValveClosed               : 1;    ///< Bit   7:       The motorised vacuum valve is in the fully closed position (Maximum vacuum).
            unsigned    vacuumValveOpen                 : 1;    ///< Bit   8:       The motorised vacuum valve is in the fully open position (Atmospheric pressure).
            unsigned    humidityRampSetPoint            : 1;    ///< Bit   9:       The Humidity ramp at set point.
            unsigned    humidityCtrlStarted             : 1;    ///< Bit  10:       The Humidity control started.
            unsigned    lnpCoolingPumpOn                : 1;    ///< Bit  11:       The Liquid Nitrogen Pump cooling pump pumping.
            unsigned    lnpCoolingPumpAuto              : 1;    ///< Bit  12:       The Liquid Nitrogen Pump cooling pump in automatic mode.
            unsigned    unused13                        : 1;    ///< Bit  13:       Reserved for future use.
            unsigned    HumidityDesiccantConditioning   : 1;    ///< Bit  14:       The humidity unit is in "desiccant conditioning" mode. For more information please refer to the "Desiccant Conditioning" section of the RH95 manual.
            unsigned    unused15                        : 1;    ///< Bit  15:       Reserved for future use.
            unsigned    unused16                        : 1;    ///< Bits 16:       Reserved for future use.
            unsigned    unused17                        : 1;    ///< Bits 17:       Reserved for future use.
            unsigned    unused18                        : 1;    ///< Bits 18:       Reserved for future use.
            unsigned    unused19                        : 1;    ///< Bits 19:       Reserved for future use.
            unsigned    unused20                        : 1;    ///< Bits 20:       Reserved for future use.
            unsigned    unused21                        : 1;    ///< Bits 21:       Reserved for future use.
            unsigned    unused22                        : 1;    ///< Bits 22:       Reserved for future use.
            unsigned    unused23                        : 1;    ///< Bits 23:       Reserved for future use.
            unsigned    unused24                        : 1;    ///< Bits 24:       Reserved for future use.
            unsigned    unused25                        : 1;    ///< Bits 25:       Reserved for future use.
            unsigned    unused26                        : 1;    ///< Bits 26:       Reserved for future use.
            unsigned    unused27                        : 1;    ///< Bits 27:       Reserved for future use.
            unsigned    unused28                        : 1;    ///< Bits 28:       Reserved for future use.
            unsigned    unused29                        : 1;    ///< Bits 29:       Reserved for future use.
            unsigned    unused30                        : 1;    ///< Bits 30:       Reserved for future use.
            unsigned    unused31                        : 1;    ///< Bits 31:       Reserved for future use.
            unsigned    unused32                        : 1;    ///< Bits 32:       Reserved for future use.
            unsigned    unused33                        : 1;    ///< Bits 33:       Reserved for future use.
            unsigned    unused34                        : 1;    ///< Bits 34:       Reserved for future use.
            unsigned    unused35                        : 1;    ///< Bits 35:       Reserved for future use.
            unsigned    unused36                        : 1;    ///< Bits 36:       Reserved for future use.
            unsigned    unused37                        : 1;    ///< Bits 37:       Reserved for future use.
            unsigned    unused38                        : 1;    ///< Bits 38:       Reserved for future use.
            unsigned    unused39                        : 1;    ///< Bits 39:       Reserved for future use.
            unsigned    unused40                        : 1;    ///< Bit  40:       Reserved for future use.
            unsigned    motorTravelMinX                 : 1;    ///< Bit  41:       The stage X motor at min travel.
            unsigned    motorTravelMaxX                 : 1;    ///< Bit  42:       The stage X motor at max travel.
            unsigned    motorStoppedX                   : 1;    ///< Bit  43:       The stage X motor stopped.
            unsigned    motorTravelMinY                 : 1;    ///< Bit  44:       The stage Y motor at min travel.
            unsigned    motorTravelMaxY                 : 1;    ///< Bit  45:       The stage Y motor at max travel.
            unsigned    motorStoppedY                   : 1;    ///< Bit  46:       The stage Y motor stopped.
            unsigned    motorTravelMinZ                 : 1;    ///< Bit  47:       The stage Z motor at min travel; this can double up as a TST axis motor card value.
            unsigned    motorTravelMaxZ                 : 1;    ///< Bit  48:       The stage Z motor at max travel; this can double up as a TST axis motor card value.
            unsigned    motorStoppedZ                   : 1;    ///< Bit  49:       The stage Z motor started; this can double up as a TST axis motor card value.
            unsigned    sampleCal                       : 1;    ///< Bit  50:       The stage is currently using user defined sample calibration values.
            unsigned    motorDistanceCalTST             : 1;    ///< Bit  51:       The TST stage motor is at the calibration distance.
            unsigned    cssRotMotorStopped              : 1;    ///< Bit  52:       The CSS stage rotation motor has stopped moving.
            unsigned    cssGapMotorStopped              : 1;    ///< Bit  53:       The CSS stage gap (pressure) motor has stopped moving.
            unsigned    cssLidOn                        : 1;    ///< Bit  54:       The CSS stage lid/cover is in place.
            unsigned    cssRefLimit                     : 1;    ///< Bit  55:       The CSS stage is at the referenced limit.
            unsigned    cssZeroLimit                    : 1;    ///< Bit  56:       The CSS stage is at the zero limit.
            unsigned    unused57                        : 1;    ///< Bits 57:       Reserved for future use.
            unsigned    unused58                        : 1;    ///< Bits 58:       Reserved for future use.
            unsigned    unused59                        : 1;    ///< Bits 59:       Reserved for future use.
            unsigned    unused60                        : 1;    ///< Bits 60:       Reserved for future use.
            unsigned    unused61                        : 1;    ///< Bits 61:       Reserved for future use.
            unsigned    unused62                        : 1;    ///< Bits 62:       Reserved for future use.
            unsigned    unused63                        : 1;    ///< Bits 63:       Reserved for future use.
        }               flags;                                  ///< Accessor to the flags.
        uint64_t        value;                                  ///< Flags as a single value;
    };

    /*!
     *  \struct     PowerSupplyUnitDetails
     *  \brief      This structure defines a set of values which provide details
     *              about the controller's power supply unit.
     *
     *  @ingroup    Controller_API
     */
    struct PowerSupplyUnitDetails
    {
        uint32_t    psu;                ///< PUS type code; 0 = PPS125-24 125W (24V 5.2A), 1 = PPS125-15 125W (15V 8.33A), 2 = PPS200-15 200W (15V 13.33A)
        uint32_t    mainsFreq;          ///< The mains frequency of the power supply unit; 0 = 60HZ, 8 = 50HZ.
        uint32_t    relay;              ///< Relay fitted.
    };

    /*!
     *  \struct     HeaterDetails
     *  \brief      This structure defines a set of values which provide
     *              specification details about an installed heater.
     *
     *  @ingroup    Controller_API
     */
    struct HeaterDetails
    {
        float       minLimit;           ///< Heater min temperature limit.
        float       maxLimit;           ///< Heater max temperature limit.
        float       maxRate;            ///< Heater max temperature rate of change.
        float       maxV;               ///< Heater max voltage rating.
        float       maxI;               ///< Heater max current rating.
    };

    /*!
     *  \union      StageCableConfig
     *  \brief      A union structure used to hold status flag information
     *              about the various elements of the stage cable. This
     *              union can provide the configuration data as a set of
     *              known flags or as a single integer value.
     *  \note       Size of structure is 4 bytes.
     *  @ingroup    Controller_API
     */    
    union StageCableConfig
    {
        struct Flags
        {
            unsigned stageOk            :  4; ///< Stage OK status.
            unsigned sensorA            :  1; ///< Sensor A present.
            unsigned sensorB            :  1; ///< Sensor B present.
            unsigned sensorC            :  1; ///< Sensor C present.
            unsigned relay              :  1; ///< T95 Relay fitted.
            unsigned motorised          :  1; ///< Stage is motorised.
            unsigned postFitted         :  1; ///< Motor drive stage post is fitted.
            unsigned lnpCanBeUsed       :  1; ///< Liquid Nitrogen Pump can be used with this stage.
            unsigned lnpManOnly         :  1; ///< Liquid Nitrogen Pump can only be manually used.
            unsigned sampleCal0         :  1; ///< Sample calibration state 0.
            unsigned sampleCal1         :  1; ///< Sample calibration state 1.
            unsigned ws96LensHeater     :  1; ///< WS96 lens heater is fitted.
            unsigned unused             : 17; ///< Reserved for future use. 
        }            flags;                   ///< Access to flag members.
        uint32_t     value;                   ///< Access to the combined flag states as a single value.
    };

    /*!
     *  \enum       InstrumentBusDeviceType
     *  \brief      This enumerator defines the current supported instrument bus device
     *              types.
     *  @ingroup    Controller_API
     */
    enum InstrumentBusDeviceType
    {
        /*!
         *  The type value for an unknown instrument bus device.
         */
        eInstrumentBusDeviceType_Unknown                                = 0x00000000,

        /*!
         *  The type value for an humidity controller.
         */
        eInstrumentBusDeviceType_HumidityController                     = 0x00000001,

        /*!
         *  The type value for a Linkpad device.
         */
        eInstrumentBusDeviceType_LiquidNitrogenPump                     = 0x00000002,

        /*!
         *  The type value for a Linkpad device.
         */
        eInstrumentBusDeviceType_Linkpad                                = 0x00000003,

        /*!
         *  The type value for a Linkpad device.
         */
        eInstrumentBusDeviceType_ImagingStation                         = 0x00000004,

        /*!
         *  The type value for a Water Pump device.
         */
         eInstrumentBusDeviceType_WaterPump                             = 0x00000005,
    };

    /*!
     *  \enum       ControllerType
     *  \brief      This enumerator defines the current supported controller
     *              types.
     *  @ingroup    Controller_API
     */
    enum ControllerType
    {
        /*!
         *  The type value for an unknown instrument bus device.
         *  \note   This can be used to work out if any controller is connected
         *          or if an unknown controller is connected.
         */
        eControllerType_Unknown         = 0x00000000,

        /*!
         *  The type value for a T95 controller.
         */
        eControllerType_T95             = 0x00000001,

        /*!
         *  The type value for a any type of T96 controller.
         */
        eControllerType_T96             = 0x00000002,

        /*!
         *  The type value for a T96 P12 controller.
         */
        eControllerType_T96_P12         = 0x00000003,

        /*!
         *  The type value for a T96 S12 controller.
         */
        eControllerType_T96_S12         = 0x00000004,

        /*!
         *  The type value for a v2 T96 P12 controller.
         */
        eControllerType_T96v2_P12       = 0x00000005,

        /*!
         *  The type value for a v2 T96 S12 controller.
         */
        eControllerType_T96v2_S12       = 0x00000006
    };

    /*!
     *  \union      ControllerProgramStatus
     *  \brief      The Controller program status is a bit feild of status flags
     *              used to feed back information about various internal program
     *              elements of the controller.
     *  \note       Size of structure is 4 bytes.
     *  @ingroup    Controller_API
     */
    union ControllerProgramStatus
    {
        struct Flags
        {
            /*!
             *  Bit  0: Direction of temperature to target setpoint.
             *
             *  \note       If set then the controller is applying heat to reach the setpoint temperature,
             *              else unset then applying cooling to reach the setpoint temperature.
             *  \note       This flag is a unified view of the heat and cool flags.
             */
            unsigned dirn               : 1;

            /*!
             *  Bit  1: Hold mode enabled.
             *
             *  \note       A general flag for indicating the controller is in a hold current state mode.
             *              This will remain set until either a new temperature setpoint is programmed,
             *              or an automatic heating/cooling mode is enabled. Automatic heating/cooling modes
             *              are used to maintain temperature. The state of this flag may change during the
             *              the period of a timed hold.
             *  \see        timeHold
             *  \see        inLimitTime
             */
            unsigned hold               : 1;

            /*!
             *  Bit  2: Heating mode enabled.
             *
             *  \see dirn.
             */
            unsigned heat               : 1;

            /*!
             *  Bit  3: Cooling mode enabled.
             *
             *  \see dirn.
             */
            unsigned cool               : 1;

            /*!
             *  Bit 4: Start the hold time.
             *
             *  \note       Set when the ramp programme detects the temperature is within the threshold of the setpoint.
             *              Used by the firmware to invoke the hold time program. This is only reset when a new setpoint
             *              is programmed.
             *  \note       Can be used inconjunction with the inLimitTime flag to determine when to 
             *              send/programme the new setpoint.
             *  \see        timeHold
             */
            unsigned inLimitTime        : 1;

            /*!
             *  Bit 5: Holding temperature for defined time.
             *
             *  \note       Set when the temperature setpoint has been reached and the ramp hold time count down has started.
             *              This is reset when the hold time period is completed.
             *  \note       Can be used inconjunction with the inLimitTime
             *              flag to determine when to send/programme the new setpoint.
             *  \see        inLimitTime
             */
            unsigned timeHold           : 1;

            /*!
             *  Bit 6: Started ramp programme.
             *
             *  \note       Set when the controller begins a new ramp programme. A ramp programme is invoked when
             *              the host programme sends a new temperature setpoint to the controller. The ramp
             *              programme only manages the change in temperature to the current programmed setpoint.
             */
            unsigned started            : 1;

            /*!
             *  Bit 7: New rate set.
             *
             *  \note       Set when the controller receives instruction to change the rate of heating.
             *              The rate of heating is defined as °C/min.
             */
            unsigned newRate            : 1;

            /*!
             *  Bit 8: Ramp completed.
             *
             *  \note       Set when a temperature ramp has been completed. A controller considers a ramp
             *              as achiving a programmed setpoint.
             *  \note       This flag can be used to inform a host application that the required temperature 
             *              ramp has been completed and a new temperstaure setpoint can be sent to the controller.
             */
            unsigned rampDone           : 1;

            /*!
             *  Bit 9: Sensor over-range warning.
             *
             *  \note       Set when a sensor has been detected reading a value belyond the min/max range.
             *              This is a system error flag.
             */
            unsigned overRange          : 1;

            /*!
             *  Bit 10: Linksys32 mode enabled.
             *
             *  \note       Provided for compatibility with older systems using the Linksys32 communications
             *              module. This has been replaced by the LinkamSDK.
             */
            unsigned linksys32Mode      : 1;

            /*!
             *  Bit 11: Linkam driver mode enabled.
             *
             *  \note       Set when the Linkam SDK driver has successfully established a connection to the controller.
             */
            unsigned netDllMode         : 1;

            /*!
             *  Bit 12: Mode cooling to 300°C.
             *
             *  \note       Used by high temperature stages when they have completed a high temperature command
             *              to indicate they have entered a cool down routine to reach 300°C or below.
             */
            unsigned coolTo300          : 1;

            /*!
             *  Bit 13: Rate slow down warning.
             */
            unsigned rateSlowDown       : 1;

            /*!
             *  Bit 14: The remote link is active.
             *
             *  \note       Set when the remote host has control over the controller unit.
             *              Unset when the local host (linkpad) has control of the the controller unit.
             */
            unsigned linkMode           : 1;

            /*!
             *  Bit 15: Reserved for future use.
             */
            unsigned unused15           : 1;

            /*!
             *  Bit 16: Reserved for future use.
             */
            unsigned unused16           : 1;

            /*!
             *  Bit 17: Reserved for future use.
             */
            unsigned unused17           : 1;

            /*!
             *  Bit 18: Reserved for future use.
             */
            unsigned unused18           : 1;

            /*!
             *  Bit 19: Reserved for future use.
             */
            unsigned unused19           : 1;

            /*!
             *  Bit 20: Reserved for future use.
             */
            unsigned unused20           : 1;

            /*!
             *  Bit 21: Reserved for future use.
             */
            unsigned unused21           : 1;

            /*!
             *  Bit 22: Reserved for future use.
             */
            unsigned unused22           : 1;

            /*!
             *  Bit 23: Reserved for future use.
             */
            unsigned unused23           : 1;

            /*!
             *  Bit 24: An error has occurred.
             */
            unsigned errPtr             : 1;

            /*!
             *  Bit 25: Reserved for future use.
             */
            unsigned unused25           : 1;

            /*!
             *  Bit 26: Reserved for future use.
             */
            unsigned unused26           : 1;

            /*!
             *  Bit 27: Reserved for future use.
             */
            unsigned unused27           : 1;

            /*!
             *  Bit 28: Reserved for future use.
             */
            unsigned unused28           : 1;

            /*!
             *  Bit 29: Reserved for future use.
             */
            unsigned unused29           : 1;

            /*!
             *  Bit 30: Reserved for future use.
             */
            unsigned unused30           : 1;

            /*!
             *  Bit 31: Reserved for future use.
             */
            unsigned unused31           : 1;
        }            flags;                     ///< The flag feild accessor.
        uint32_t     value;                     ///< The value that represents the state of the flags as a 32-bit value.
    };

    /*!
     *  \struct     Running
     *  \brief      The Running information structure contains generic status information
     *              about a ramp program running on the stage. This structure is used within 
     *              applicable stage information structures, sent to the host PC on request.
     *  \note       Size of structure is 36 bytes.
     *  @ingroup    Controller_API
     */
    struct Running
    {
		float                       timeLeft;   ///< Time in seconds left for the current program.
		float                       lnpSpeed;   ///< Current speed of the LNP.
		float                       voltage;    ///< Current value of the voltage being drawn by the heater.
		float                       current;    ///< Current value of the current being drawn by the heater.
		float                       pwm;        ///< Current value of power being drawn (watts).
		ControllerProgramStatus     status;     ///< This is the internal program/action states of the controller.
		uint32_t                    auxStatus;  ///< Reserved for future use.
        uint32_t                    padding;    ///< The host machine and controller align data to an 8-byte boundary, therefore we add 4-byte padding here to align the dllStatus.
		ControllerStatus            dllStatus;  ///< This is the exposed status to the peripherial devices connected to the controller.
	};
}

#ifdef __cplusplus
}
#endif


#endif // LINKAM_SDK__CONTROLLER_API_H


