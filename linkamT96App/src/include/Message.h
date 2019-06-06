/************************************************************************
*
*   File:           Message.h
*
*   Description:    This header provides the public interface to the
*                   command message API for interfacing with the LinkamSDK.
*
*   Copyright © 2018 Linkam Scientific Instruments. All rights reserved
************************************************************************/
#ifndef LINKAM_SDK__MESSAGE_API_H
#define LINKAM_SDK__MESSAGE_API_H
#include "CommonTypes.h"
#include "ControllerAPI.h"
#include "CommonStageAPI.h"
#include "CommsAPI.h"


#ifdef __cplusplus
extern "C" {
#endif

namespace LinkamSDK
{
    /*!
     *  \brief      The ID for the motor on state.
     */
    #define HumidityConditioningOn        (true)

    /*!
     *  \brief      The ID for the motor off state.
     */
    #define HumidityConditioningOff       (false)

    /*!
     *  \brief      The ID for the vacuum on state.
     */
    #define VacuumOn                    (true)

    /*!
     *  \brief      The ID for the vacuum off state.
     */
    #define VacuumOff                   (false)

    /*!
     *  \brief      The ID for the humidity on state.
     */
    #define HumidityOn                  (true)

    /*!
     *  \brief      The ID for the humidity off state.
     */
    #define HumidityOff                 (false)

    /*!
     *  \brief      The ID for the motor on state.
     */
    #define MotorOn                     (true)

    /*!
     *  \brief      The ID for the motor off state.
     */
    #define MotorOff                    (false)

    /*!
     *  \brief      The ID for the motor axis X.
     */
    #define MotorAxisX                  (0)

    /*!
     *  \brief      The ID for the motor axis Y.
     */
    #define MotorAxisY                  (1)

    /*!
     *  \brief      The ID for the motor axis Z.
     */
    #define MotorAxisZ                  (2)

    /*!
     *  \brief      The ID for the motor axis TST.
     */
    #define MotorAxisTST                (2)

    /*!
     *  \union      Variant
     *  \brief      A data type which may be seen as many different types.
     *              The size of this data type is 64 bits.
     *
     *  @ingroup    Library_Functions
     */
    union Variant
    {
        char                vChar;              ///< Use to pass a char value.
        uint8_t             vUint8;             ///< Use to pass an unsigned 8 bit value.
        uint16_t            vUint16;            ///< Use to pass an unsigned 16 bit value.
        uint32_t            vUint32;            ///< Use to pass an unsigned 32 bit value.
        uint64_t            vUint64;            ///< Use to pass an unsigned 64 bit value.
        int8_t              vInt8;              ///< Use to pass an signed 8 bit value.
        int16_t             vInt16;             ///< Use to pass an signed 16 bit value.
        int32_t             vInt32;             ///< Use to pass an signed 32 bit value.
        int64_t             vInt64;             ///< Use to pass an signed 64 bit value.
        float               vFloat32;           ///< Use to pass a 32 bit floating point value.
        double              vFloat64;           ///< Use to pass a 64 bit floating point value.
        void*               vPtr;               ///< A generic pointer which may be used to pass an address of any data structure.
        bool                vBoolean;           ///< Use to pass a boolean value.
        ControllerConfig    vControllerConfig;  ///< Use to pass a controller configuration structure.
        ControllerError     vControllerError;   ///< Use to pass a controller error code.
        ControllerStatus    vControllerStatus;  ///< Use to pass a controller status code.
        ConnectionStatus    vConnectionStatus;  ///< Use to pass a connection status code.
        StageValueType      vStageValueType;    ///< Use to pass a data value type ID.
        StageConfig         vStageConfig;       ///< Use to pass a stage configuration structure.
        CSSStatus           vCSSStatus;         ///< Use to pass a CSS status code.
        CSSCheckCodes       vCSSCheckCodes;     ///< Use to pass a CSS check code.
        CMSStatus           vCMSStatus;         ///< Use to pass a CMS status code.
        CMSError            vCMSError;          ///< Use to pass a CMS error code.

        /*!
         *  \biref      Default constructor which initialises the Varient instance to the value zero.
         */
        Variant()                           {vUint64 = 0;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed 8 bit ANSI character.
         *  \param[in]  value       A character (8 bit character ANSI) value to assign to the Varient instance.
         */
        Variant(char value)                 {vChar = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed 8 bit unsigned integer value.
         *  \param[in]  value       An 8 bit unsigned integer value to assign to the Varient instance.
         */
        Variant(uint8_t value)              {vUint8 = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed 16 bit unsigned integer value.
         *  \param[in]  value       An 16 bit unsigned integer value to assign to the Varient instance.
         */
        Variant(uint16_t value)             {vUint16 = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed 32 bit unsigned integer value.
         *  \param[in]  value       An 32 bit unsigned integer value to assign to the Varient instance.
         */
        Variant(uint32_t value)             {vUint32 = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed 64 bit unsigned integer value.
         *  \param[in]  value       An 64 bit unsigned integer value to assign to the Varient instance.
         */
        Variant(uint64_t value)             {vUint64 = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed 8 bit signed integer value.
         *  \param[in]  value       An 8 bit signed integer value to assign to the Varient instance.
         */
        Variant(int8_t value)               {vInt8 = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed 16 bit signed integer value.
         *  \param[in]  value       An 16 bit signed integer value to assign to the Varient instance.
         */
        Variant(int16_t value)              {vInt16 = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed 32 bit signed integer value.
         *  \param[in]  value       An 32 bit signed integer value to assign to the Varient instance.
         */
        Variant(int32_t value)              {vInt32 = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed 64 bit signed integer value.
         *  \param[in]  value       An 64 bit signed integer value to assign to the Varient instance.
         */
        Variant(int64_t value)              {vInt64 = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed 32 bit floating point value.
         *  \param[in]  value       A 32 bit floating point value to assign to the Varient instance.
         */
        Variant(float value)                {vFloat32 = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed 64 bit floating point value.
         *  \param[in]  value       A 64 bit floating point value to assign to the Varient instance.
         */
        Variant(double value)               {vFloat64 = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed void pointer to some memory.
         *  \param[in]  value       A void pointer to some memory to assign to the Varient instance.
         */
        Variant(void* value)                {vPtr = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed boolean value.
         *  \param[in]  value       A boolean value to assign to the Varient instance.
         */
        Variant(bool value)                 {vBoolean = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed ControllerConfig structure.
         *  \param[in]  value       A ControllerConfig structure to assign to the Varient instance.
         */
        Variant(ControllerConfig value)     {vControllerConfig = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed ControllerError value.
         *  \param[in]  value       A ControllerError value to assign to the Varient instance.
         */
        Variant(ControllerError value)      {vControllerError = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed ControllerStatus structure.
         *  \param[in]  value       A ControllerStatus structure to assign to the Varient instance.
         */
        Variant(ControllerStatus value)     {vControllerStatus = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed ConnectionStatus structure.
         *  \param[in]  value       A ConnectionStatus structure to assign to the Varient instance.
         */
        Variant(ConnectionStatus value)     {vConnectionStatus = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed StageValueType value.
         *  \param[in]  value       A StageValueType value to assign to the Varient instance.
         */
        Variant(StageValueType value)       {vStageValueType = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed StageConfig structure.
         *  \param[in]  value       A StageConfig structure to assign to the Varient instance.
         */
        Variant(StageConfig value)          {vStageConfig = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed CSSStatus structure.
         *  \param[in]  value       A CSSStatus structure to assign to the Varient instance.
         */
        Variant(CSSStatus value)            {vCSSStatus = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed CSSCheckCodes structure.
         *  \param[in]  value       A CSSCheckCodes structure to assign to the Varient instance.
         */
        Variant(CSSCheckCodes value)        {vCSSCheckCodes = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed CMSStatus structure.
         *  \param[in]  value       A CMSStatus structure to assign to the Varient instance.
         */
        Variant(CMSStatus value)            {vCMSStatus = value;}

        /*!
         *  \biref      Initialises the Varient instance with a user passed CMSError structure.
         *  \param[in]  value       A CMSError structure to assign to the Varient instance.
         */
        Variant(CMSError value)             {vCMSError = value;}
    };

    /*!
     *  \enum       LinkamFunctionMsgCode
     *  \brief      This enumerated data type contains the valid message codes that
     *              represent operations that can be called from the Linkam SDK. These
     *              message codes are used in conjuction with the linkamProcessMessage
     *              function.
     *  \note       Reserved ID range 0x00000000 - 0x0FFFFFFF, that's 268,435,455 possible
     *              message coses for function calls in the public API for this enumerator
     *              type.
     *  @ingroup    Library_Functions
     */
    enum LinkamFunctionMsgCode
    {
        /*!
         *  \breif          Send this message to open a connection to a comms device/port.
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns a ConnectionStatus structure for the connection request.
         *  \param[in]      param1      A valid pointer to a \link LinkamSDK::CommsInfo CommsInfo \endlink structure instance defining the connection properties.
         *  \param[out]     param2      A pointer to a CommsHandle instance which will recieve the handle to the comms device/port.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_OpenComms                                = 0x00000001,

        /*!
         *  \breif          Call to close a valid open connection to a comms device/port.
         *  \param[in]      hDevice     A valid handle to a comms device/port returned by eLinkamFunctionMsgCode_OpenComms.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CloseComms                               = 0x00000002,

        /*!
         *  \breif          Send this message to obtain the controller settings and options available.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a ControllerConfig structure populated with available information.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetControllerConfig                      = 0x00000003,

        /*!
         *  \breif          Send this message to obtain the current controller error code.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a \link LinkamSDK::ControllerError ControllerError \endlink value.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetControllerError                       = 0x00000004,

        /*!
         *  \breif          Send this message to obtain the name of the controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a \link LinkamSDK::ControllerError ControllerError \endlink value.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the controller name to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetControllerName                        = 0x00000005,

        /*!
         *  \breif          Send this message to obtain the serial number of the controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the controller serial number to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetControllerSerial                      = 0x00000006,

        /*!
         *  \breif          Send this message to obtain the current status of the controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a ControllerStatus structure detailing the current status.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetStatus                                = 0x00000007,

        /*!
         *  \breif          Send this message to obtain the stage configuration details of the connected stage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a \link LinkamSDK::StageConfig StageConfig \endlink structure which details to properties of the connected stage.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetStageConfig                           = 0x00000008,

        /*!
         *  \breif          Send this message to obtain the connected stages' serial number.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage serial number to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetStageSerial                           = 0x00000009,

        /*!
         *  \breif          Send this message to obtain the name of the stage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage name to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetStageName                             = 0x0000000A,

        /*!
         *  \breif          Send this message to obtain the maximum range value for the \link LinkamSDK::StageValueType StageValueType \endlink passed.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns the maximum value, as a 32 bit float, for this stage value field.
         *  \param[in]      param1      A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetMaxValue                              = 0x0000000B,

        /*!
         *  \breif          Send this message to obtain the minimum range value for the \link LinkamSDK::StageValueType StageValueType \endlink passed.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns the minimum value, as a 32 bit float, for this stage value field.
         *  \param[in]      param1      A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetMinValue                              = 0x0000000C,

        /*!
         *  \breif          Send this message to obtain the resolution for \link LinkamSDK::StageValueType StageValueType \endlink passed.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns the resolution, as a 32 bit float, for this stage value field.
         *  \param[in]      param1      A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetResolution                            = 0x0000000D,

        /*!
         *  \breif          Send this message to apply or remove the sample calibration values saved to the controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Set to 'true' to apply the sample calibration settings saved to the controller, else 'false' to remove.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_ApplySampleCals                          = 0x0000000E,

        /*!
         *  \breif          Send this message to save the current sample values on the stage to the controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_SaveSampleCals                           = 0x0000000F,

        /*!
         *  \breif          Send this message to start/stop a heading cycle.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' to turn ON, else 'false' to turn OFF.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_StartHeating                             = 0x00000010,

        /*!
         *  \breif          Send this message to start/stop a vacuum reading cycle.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' to turn ON, else 'false' to turn OFF.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_StartVacuum                              = 0x00000011,

        /*!
         *  \breif          Send this message to start/stop the humidity controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' to turn ON, else 'false' to turn OFF.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_StartHumidity                            = 0x00000012,

        /*!
         *  \breif          Send this message to start/stop the conditioning process of the atmosphere.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' to turn ON, else 'false' to turn OFF.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_StartHumidityDesiccantConditioning       = 0x00000013,

        /*!
         *  \breif          Send this message to start/stop a motor connected to this card.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' to turn ON, else 'false' to turn OFF.
         *  \param[in]      param2      Either 0=X, 1=Y, 2=Z for Motor Driven Stage, or ignored if stage is of Vacuum, Graded, TST or CSS type.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_StartMotors                              = 0x00000014,

        /*!
         *  \breif          Send this message to obtain the current value of the \link LinkamSDK::StageValueType StageValueType \endlink passed.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns the value of the stage value, as a 32 bit float.
         *  \param[in]      param1      A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetValue                                 = 0x00000015,

        /*!
         *  \breif          Send this message to set the current value of the \link LinkamSDK::StageValueType StageValueType \endlink passed.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
         *  \param[in]      param2      The new value for the \link LinkamSDK::StageValueType StageValueType \endlink passed, as a 32 bit float.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_SetValue                                 = 0x00000016,

        /*!
         *  \breif          Send this message to calibrate distance on the TST stage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_TstCalibrateDistance                     = 0x00000017,

        /*!
         *  \breif          Send this message to set the motor mode the TST will operate in (force or distance mode).
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Set to 'true' for 'Force mode' else 'false' for 'Distance mode'.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_TstSetMode                               = 0x00000018,

        /*!
         *  \breif          Send this message to set the zero force on the TST stage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_TstZeroForce                             = 0x00000019,

        /*!
         *  \breif          Send this message to set the zero position on the TST stage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_TstZeroPosition                          = 0x0000001A,

        /*!
         *  \breif          Send this message to turn on/off the cooling mode on the LNP.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' to turn ON, else 'false' to turn OFF.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_LnpSetMode                               = 0x0000001B,

        /*!
         *  \breif          Send this message to set the speed of the LNP as a percentage from off (0) to full speed (100).
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 0-100 as a uint32_t.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_LnpSetSpeed                              = 0x0000001C,

        /*!
         *  \breif          Send this message to apply the temporary values to the CSS stage. This will
         *                  make them current and live.
         *
         *                  The CSS card maintains a set of temporary variables which are used to set/control
         *                  features on the CSS stage, the card is responsible for managing them. You can set
         *                  the temporary variables using the setValue method.
         *                  
         *                  You should always check the validity of the temporary variables before applying them,
         *                  however this is done automatically by the applyValues method. Be aware that you only
         *                  get a true/false result from applyValues method, so you cannot determine what values
         *                  did not conform to the expected safe ranges. For this you must call the checkValues
         *                  method.
         *
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if the values successfully passed the safety check and were
         *                              sent to the CSS stage, else this method will return 'false' if one or more
         *                              values failed the safety check.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssApplyValues                            = 0x0000001D,

        /*!
         *  \breif          Send this message to check the state temporary CSS variables currently set
         *                  before applying them to the stage.
         *
         *                  The CSS card maintains a set of temporary variables which are used to set/control
         *                  features on the CSS stage, the card is responsible for managing them. You can set
         *                  the temporary variables using the setValue method.
         *                  
         *                  You should always check the validity of the temporary variables before applying them,
         *                  however this is done automatically by the applyValues method. Be aware that you only
         *                  get a true/false result from applyValues method, so you cannot determine what values
         *                  did not conform to the expected safe ranges. For this you must call the checkValues
         *                  method.
         *
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns an unsigned 8bit value holding error flags, each bit is a flag for a specific
         *                              variable. If set then the variable was found to have a problem. See CSSCheckCodes
         *                              for more details.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssCheckValues                           = 0x0000001E,

        /*!
         *  \breif          Send this message to perform a goto reference point operation.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssGotoReference                         = 0x0000001F,

        /*!
         *  \breif          Send this message to perform a calibration step on the sensor.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      The calibration step to perform as a uint32_t.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssSensorCal                             = 0x00000020,

        /*!
         *  \breif          Send this message to perform a jog gap operation.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' for 'start' or 'false' for 'stop'.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssStartJogGap                           = 0x00000021,

        /*!
         *  \breif          Send this message to perform a jog rotation operation.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' for 'start' or 'false' for 'stop'.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssStartJogRot                           = 0x00000022,

        /*!
         *  \breif          Send this message to enable logging for the library.
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      May be either \link ::LOGGING_LEVEL_MINIMAL LOGGING_LEVEL_MINIMAL\endlink, \link ::LOGGING_LEVEL_INFORMATIVE LOGGING_LEVEL_INFORMATIVE\endlink, \link ::LOGGING_LEVEL_VOBOSE LOGGING_LEVEL_VOBOSE\endlink, or \link ::LOGGING_LEVEL_INVESTIGATION LOGGING_LEVEL_INVESTIGATION\endlink.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_EnableLogging                            = 0x00000023,

        /*!
         *  \breif          Send this message to disable logging for the library.
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_DisableLogging                           = 0x00000024,

        /*!
         *  \breif          Send this message to get the controller's firmware version number as a ANSI string.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage serial number to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t.
         *  \param[in]      param3      Ignored, set to 0.
         *  \return         Returns 'true' if successful, else 'false'.
         */
        eLinkamFunctionMsgCode_GetControllerFirmwareVersion             = 0x00000025,

        /*!
         *  \breif          Send this message to get the controller's hardware version number as a ANSI string.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage serial number to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t.
         *  \param[in]      param3      Ignored, set to 0.
         *  \return         Returns 'true' if successful, else 'false'.
         */
        eLinkamFunctionMsgCode_GetControllerHardwareVersion             = 0x00000026,

        /*!
         *  \breif          Send this message to get the stage's firmware version number as a ANSI string.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage serial number to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t.
         *  \param[in]      param3      Ignored, set to 0.
         *  \return         Returns 'true' if successful, else 'false'.
         */
        eLinkamFunctionMsgCode_GetStageFirmwareVersion                  = 0x00000027,

        /*!
         *  \breif          Send this message to get the stage's hardware version number as a ANSI string.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage serial number to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t.
         *  \param[in]      param3      Ignored, set to 0.
         *  \return         Returns 'true' if successful, else 'false'.
         */
        eLinkamFunctionMsgCode_GetStageHardwareVersion                  = 0x00000028,

        /*!
         *  \breif          Send this message to get the driver rate (in ms) data requests are made.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \return         Returns a 32-bit unsigned integer which is the rate in (ms).
         */
        eLinkamFunctionMsgCode_GetDataRate                              = 0x00000029,

        /*!
         *  \breif          Send this message to set the driver rate (in ms) data requests are made.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      param1      A 32-bit unsigned integer which is the rate in (ms), limited to between 5-1000.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \return         Returns 'true' if successful, else 'false'.
         */
        eLinkamFunctionMsgCode_SetDataRate                              = 0x0000002A,

        /*!
         *  \breif          Send this message to test stuff.
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Ignored, set to 0.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_Test                                    = 0x0FFFFFFF
    };
}

#ifdef __cplusplus
}
#endif

#endif /// LINKAM_SDK__MESSAGE_API_H


