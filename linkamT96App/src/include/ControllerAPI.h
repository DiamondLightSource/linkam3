/************************************************************************
*
*   File:           ControllerAPI.h
*
*   Description:    This header defines the controller API for the Linkam
*                   SDK.
*
*   Copyright © 2018 Linkam Scientific Instruments. All rights reserved
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
        "The stage requires a relay fitted in the T95",
        "The controller has the wrong combination of option boards",
        "Cable disconnected from one of the option boards",
        "Load power supply is incorrect for the stage type",
        "Incorrect cable connected to one of the option boards",
        "Sensor open circuit or overrange on one of the option boards",
        "The controller unit fan is not working correctly",
        "The LNP is reporting an error",
        "There has been a communications error",
        "The cooling water is too warm or is not flowing through the stage",
        "CSS450 motor drive overheating error",
        "CSS450 motor winding error (type 1)",
        "CSS450 motor winding error (type 2)",
        "(reserved for future development)",
        "(reserved for future development)",
        "(reserved for future development)",
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
        eControllerErrorNone                            =  0,    ///< No errors
        eControllerErrorStageCableDisconnected          =  1,    ///< Stage cable disconnected from the controller
        eControllerErrorStageCableError                 =  2,    ///< Stage cable identifier error
        eControllerErrorStageTempSensorOpenOverrange    =  3,    ///< Stage temperature sensor open circuit or over-range
        eControllerErrorLoadPowerOutputVoltageWrong     =  4,    ///< Load power supply output voltage incorrect
        eControllerErrorT95RelayMissing                 =  5,    ///< The stage requires a relay fitted in the T95
        eControllerErrorT95OptionBoardWongConfig        =  6,    ///< The T95 has the wrong combination of option boards
        eControllerErrorOptionBoardCableDisconnect      =  7,    ///< Cable disconnected from one of the option boards
        eControllerErrorLoadPowerIncorrectForStage      =  8,    ///< Load power supply is incorrect for the stage type
        eControllerErrorOptionBoardIncorrectCable       =  9,    ///< Incorrect cable connected to one of the option boards
        eControllerErrorOptionBoardSensorOenOverrange   = 10,    ///< Sensor open circuit or overrange on one of the option boards
        eControllerErrorT95FanNotWorking                = 11,    ///< The T95 unit fan is not working correctly
        eControllerErrorLNP95Error                      = 12,    ///< The LNP95 is reporting an error
        eControllerErrorCommsError                      = 13,    ///< There has been a communications error
        eControllerErrorCoolingWaterTooWarmNotFlowing   = 14,    ///< The cooling water is too warm or is not flowing through the stage
        eControllerErrorCSS450MotorDriveOverTemp        = 15,    ///< CSS450 motor drive overheating error (reserved for future development)
        eControllerErrorCSS450MotorWindingError1        = 16,    ///< CSS450 motor winding error (reserved for future development)
        eControllerErrorCSS450MotorWindingError2        = 17,    ///< CSS450 motor winding error (reserved for future development)
        eControllerErrorReserved1                       = 18,    ///< Reserved.
        eControllerErrorReserved2                       = 19,    ///< Reserved.
        eControllerErrorReserved3                       = 20,    ///< Reserved.
        eControllerErrorCMS196ChamberSensorOpen         = 21,    ///< CMS196 Chamber sensor open circuit
        eControllerErrorCMS196ChamberSensorOverrange    = 22,    ///< CMS196 Chamber sensor over range
        eControllerErrorCMS196LN2SwitchSensorOpen       = 23,    ///< CMS196 LN2 Switch sensor open circuit
        eControllerErrorCMS196LN2SwitchSensorOverrange  = 24,    ///< CMS196 LN2 Switch sensor over range
        eControllerErrorCMS196DewarSensorOpen           = 25,    ///< CMS196 Dewar sensor open circuit
        eControllerErrorCMS196DewarSensorOverrange      = 26,    ///< CMS196 Dewar sensor over range
        eControllerErrorCMS196DewarEmpty                = 27,    ///< CMS196 Dewar empty
        eControllerErrorCMS196BaseSensorOpen            = 28,    ///< CMS196 Base sensor open circuit
        eControllerErrorCMS196BaseSensorOverrange       = 29,    ///< CMS196 Base sensor over range
        eControllerErrorCMS196MotorPosnError            = 30     ///< CMS196 Motor position error
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
        struct
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
        struct
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
            unsigned    ramp1                           : 1;    ///< Bit  13:       Ramp 1
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
            unsigned    motorTravelMaxZ                 : 1;    ///< Bit  48:       The stage Z motor at max travel; this can double up as a TST axis motor card value
            unsigned    motorStoppedZ                   : 1;    ///< Bit  49:       The stage Z motor started; this can double up as a TST axis motor card value
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
}

#ifdef __cplusplus
}
#endif


#endif // LINKAM_SDK__CONTROLLER_API_H


