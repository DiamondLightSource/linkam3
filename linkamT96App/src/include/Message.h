/************************************************************************
*
*   File:           Message.h
*
*   Description:    This header provides the public interface to the
*                   command message API for interfacing with the LinkamSDK.
*
*   Copyright © 2018-2023 Linkam Scientific Instruments. All rights reserved
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
     *  \brief      The ID for the motor axis for a vacuum supporting stage.
     */
    #define MotorAxisVac                (3)

    /*!
     *  \brief      The ID for the motor axis gradient stage.
     */
    #define MotorAxisGS                 (4)

    /*!
     *  \brief      The ID for the motor axis tensile test stage.
     */
    #define MotorAxisTST                (5)

    /*!
     *  \brief      The ID for the motor axis cambridge shearing system stage.
     */
    #define MotorAxisCSS                (6)

    /*!
     *  \union      Variant
     *  \brief      A data type which may be seen as many different types.
     *              The size of this data type is 64 bits.
     *
     *  @ingroup    Library_Functions
     */
    union Variant
    {
        char                            vChar;                          ///< Use to pass a char value.
        uint8_t                         vUint8;                         ///< Use to pass an unsigned 8 bit value.
        uint16_t                        vUint16;                        ///< Use to pass an unsigned 16 bit value.
        uint32_t                        vUint32;                        ///< Use to pass an unsigned 32 bit value.
        uint64_t                        vUint64;                        ///< Use to pass an unsigned 64 bit value.
        int8_t                          vInt8;                          ///< Use to pass a signed 8 bit value.
        int16_t                         vInt16;                         ///< Use to pass a signed 16 bit value.
        int32_t                         vInt32;                         ///< Use to pass a signed 32 bit value.
        int64_t                         vInt64;                         ///< Use to pass a signed 64 bit value.
        float                           vFloat32;                       ///< Use to pass a 32 bit floating point value.
        double                          vFloat64;                       ///< Use to pass a 64 bit floating point value.
        void*                           vPtr;                           ///< A generic pointer which may be used to pass an address of any data structure.
        bool                            vBoolean;                       ///< Use to pass a boolean value.
        ControllerConfig                vControllerConfig;              ///< Use to pass a controller configuration structure.
        ControllerError                 vControllerError;               ///< Use to pass a controller error code.
        ControllerStatus                vControllerStatus;              ///< Use to pass a controller status code.
        ConnectionStatus                vConnectionStatus;              ///< Use to pass a connection status code.
        StageValueType                  vStageValueType;                ///< Use to pass a data value type ID.
        StageCableConfig                vStageCableConfig;              ///< Use to pass a stage cable configuration structure.
        StageConfig                     vStageConfig;                   ///< Use to pass a stage configuration structure.
        StageGroup                      vStageGroup;                    ///< Use to pass a stage firmware group ID.
        StageType                       vStageType;                     ///< Use to pass a stage configuration type ID.
        StageCableLimit                 vStageCableLimit;               ///< Use to pass a stage cable limit structure.
        CSSStatus                       vCSSStatus;                     ///< Use to pass a CSS status code.
        CSSCheckCodes                   vCSSCheckCodes;                 ///< Use to pass a CSS check code.
        CSSMode                         vCSSMode;                       ///< Use to pass a CSS mode code.
        CSSState                        vCSSState;                      ///< Use to pass a CSS state code.
        CMSStatus                       vCMSStatus;                     ///< Use to pass a CMS status code.
        CMSError                        vCMSError;                      ///< Use to pass a CMS error code.
        OptionBoardType                 vOptionBoardType;               ///< Use to pass an OptionBoardType code.
        InstrumentBusDeviceType         vInstrumentBusDeviceType;       ///< Use to pass an InstrumentBusDeviceType code.
        ControllerType                  vControllerType;                ///< Use to pass an ControllerType code.
        TSTStatus                       vTSTStatus;                     ///< Use to pass a TSTStatus code.
        TSTMode                         vTSTMode;                       ///< Use to pass a TST mode code.
        TSTSampleSize                   vTSTSampleSize;                 ///< Use to pass a TST sample size.
        MVStatus                        vMVStatus;                      ///< Use to pass a MVStatus code.
        MDSStatus                       vMDSStatus;                     ///< Use to pass a MDSStatus code.
        CommsType                       vCommsType;                     ///< Use to pass a CommsType code.

        /*!
         *  \brief      Default constructor which initialises the Varient instance to the value zero.
         */
        Variant()                                       {vUint64 = 0;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed 8 bit ANSI character.
         *  \param[in]  value       A character (8 bit character ANSI) value to assign to the Varient instance.
         */
        Variant(char value)                             {vChar = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed 8 bit unsigned integer value.
         *  \param[in]  value       An 8 bit unsigned integer value to assign to the Varient instance.
         */
        Variant(uint8_t value)                          {vUint8 = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed 16 bit unsigned integer value.
         *  \param[in]  value       An 16 bit unsigned integer value to assign to the Varient instance.
         */
        Variant(uint16_t value)                         {vUint16 = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed 32 bit unsigned integer value.
         *  \param[in]  value       An 32 bit unsigned integer value to assign to the Varient instance.
         */
        Variant(uint32_t value)                         {vUint32 = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed 64 bit unsigned integer value.
         *  \param[in]  value       An 64 bit unsigned integer value to assign to the Varient instance.
         */
        Variant(uint64_t value)                         {vUint64 = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed 8 bit signed integer value.
         *  \param[in]  value       An 8 bit signed integer value to assign to the Varient instance.
         */
        Variant(int8_t value)                           {vInt8 = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed 16 bit signed integer value.
         *  \param[in]  value       An 16 bit signed integer value to assign to the Varient instance.
         */
        Variant(int16_t value)                          {vInt16 = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed 32 bit signed integer value.
         *  \param[in]  value       An 32 bit signed integer value to assign to the Varient instance.
         */
        Variant(int32_t value)                          {vInt32 = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed 64 bit signed integer value.
         *  \param[in]  value       An 64 bit signed integer value to assign to the Varient instance.
         */
        Variant(int64_t value)                          {vInt64 = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed 32 bit floating point value.
         *  \param[in]  value       A 32 bit floating point value to assign to the Varient instance.
         */
        Variant(float value)                            {vFloat32 = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed 64 bit floating point value.
         *  \param[in]  value       A 64 bit floating point value to assign to the Varient instance.
         */
        Variant(double value)                           {vFloat64 = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed void pointer to some memory.
         *  \param[in]  value       A void pointer to some memory to assign to the Varient instance.
         */
        Variant(void* value)                            {vPtr = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed boolean value.
         *  \param[in]  value       A boolean value to assign to the Varient instance.
         */
        Variant(bool value)                             {vBoolean = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed ControllerConfig structure.
         *  \param[in]  value       A ControllerConfig structure to assign to the Varient instance.
         */
        Variant(ControllerConfig value)                 {vControllerConfig = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed ControllerError value.
         *  \param[in]  value       A ControllerError value to assign to the Varient instance.
         */
        Variant(ControllerError value)                  {vControllerError = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed ControllerStatus structure.
         *  \param[in]  value       A ControllerStatus structure to assign to the Varient instance.
         */
        Variant(ControllerStatus value)                 {vControllerStatus = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed ConnectionStatus structure.
         *  \param[in]  value       A ConnectionStatus structure to assign to the Varient instance.
         */
        Variant(ConnectionStatus value)                 {vConnectionStatus = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed StageValueType value.
         *  \param[in]  value       A StageValueType value to assign to the Varient instance.
         */
        Variant(StageValueType value)                   {vStageValueType = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed StageCableConfig structure.
         *  \param[in]  value       A StageCableConfig structure to assign to the Varient instance.
         */
        Variant(StageCableConfig value)                 {vStageCableConfig = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed StageConfig structure.
         *  \param[in]  value       A StageConfig structure to assign to the Varient instance.
         */
        Variant(StageConfig value)                      {vStageConfig = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed StageGroup enumerator.
         *  \param[in]  value       A StageGroup enumerator to assign to the Varient instance.
         */
        Variant(StageGroup value)                       {vStageGroup = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed StageCableLimit structure.
         *  \param[in]  value       A StageCableLimit structure to assign to the Varient instance.
         */
        Variant(StageCableLimit value)                  {vStageCableLimit = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed CSSStatus structure.
         *  \param[in]  value       A CSSStatus structure to assign to the Varient instance.
         */
        Variant(CSSStatus value)                        {vCSSStatus = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed CSSCheckCodes structure.
         *  \param[in]  value       A CSSCheckCodes structure to assign to the Varient instance.
         */
        Variant(CSSCheckCodes value)                    {vCSSCheckCodes = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed CSSMode structure.
         *  \param[in]  value       A CSSMode structure to assign to the Varient instance.
         */
        Variant(CSSMode value)                          {vCSSMode = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed CSSState enumerator.
         *  \param[in]  value       A CSSState enumerator to assign to the Varient instance.
         */
        Variant(CSSState value)                         {vCSSState = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed CMSStatus enumerator.
         *  \param[in]  value       A CMSStatus enumerator to assign to the Varient instance.
         */
        Variant(CMSStatus value)                        {vCMSStatus = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed CMSError structure.
         *  \param[in]  value       A CMSError structure to assign to the Varient instance.
         */
        Variant(CMSError value)                         {vCMSError = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed OptionBoardType enumerator.
         *  \param[in]  value       An OptionBoardType enumerator to assign to the Varient instance.
         */
        Variant(OptionBoardType value)                  {vOptionBoardType = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed OptionBoardType enumerator.
         *  \param[in]  value       An OptionBoardType enumerator to assign to the Varient instance.
         */
        Variant(InstrumentBusDeviceType value)          {vInstrumentBusDeviceType = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed ControllerType enumerator.
         *  \param[in]  value       A ControllerType enumerator to assign to the Varient instance.
         */
        Variant(ControllerType value)                   {vControllerType = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed TSTStatus bit field.
         *  \param[in]  value       A TSTStatus bit field to assign to the Varient instance.
         */
        Variant(TSTStatus value)                        {vTSTStatus = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed TSTMode enumerator.
         *  \param[in]  value       A TSTMode enumerator to assign to the Varient instance.
         */
        Variant(TSTMode value)                          {vTSTMode = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed TSTSampleSize structure.
         *  \param[in]  value       A TSTSampleSize structure to assign to the Varient instance.
         */
        Variant(TSTSampleSize value)                    {vTSTSampleSize = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed MVStatus bit field.
         *  \param[in]  value       A MVStatus bit field to assign to the Varient instance.
         */
        Variant(MVStatus value)                         {vMVStatus = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed MDSStatus bit field.
         *  \param[in]  value       A MDSStatus bit field to assign to the Varient instance.
         */
        Variant(MDSStatus value)                        {vMDSStatus = value;}

        /*!
         *  \brief      Initialises the Varient instance with a user passed CommsType enumerator.
         *  \param[in]  value       A CommsType enumerator value to assign to the Varient instance.
         */
        Variant(CommsType value)                        {vCommsType = value;}
    };

    /*!
     *  \enum       LinkamFunctionMsgCode
     *  \brief      This enumerated data type contains the valid message codes that
     *              represent operations that can be called from the Linkam SDK. These
     *              message codes are used in conjuction with the linkamProcessMessage
     *              function.
     *  \note       Reserved ID range 0x00000000 - 0x0FFFFFFF, that's 268,435,455 possible
     *              message codes for function calls in the public API for this enumerator
     *              type.
     *  @ingroup    Library_Functions
     */
    enum LinkamFunctionMsgCode
    {
        /*!
         *  \brief          Send this message to open a connection to a comms device/port.
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns a ConnectionStatus structure for the connection request.
         *  \param[in]      param1      A valid pointer to a \link LinkamSDK::CommsInfo CommsInfo \endlink structure instance defining the connection properties.
         *  \param[out]     param2      A pointer to a CommsHandle instance which will recieve the handle to the comms device/port.
         *  \param[in]      param3      Ignored, set to 0.
         *
         *  Send this message to open a connection to a comms device/port. This is sent via the linkamProcessMessage function.
         *  Populate the CommsInfo structure with the correct connection information; this may be for a Serial or USB connection.
         *  Cast the info member to an appropriate SerialCommsInfo or USBCommsInfo structure and populate.
         *
         *  This signal will open a valid connection to a Linkam device such as a controller, if one is connected and visible to
         *  the host machine. A connection event will be raised which will return the device handle. A device handle is required 
         *  to make subsequent calls to the device. Ensure an EventCallback function pointer is registered with the driver, using 
         *  the linkamSetCallbackControllerConnected function, to receive the device handle.
         */
        eLinkamFunctionMsgCode_OpenComms                                        = 0x00000001,

        /*!
         *  \brief          Call to close a valid open connection to a comms device/port.
         *  \param[in]      hDevice     A valid handle to a comms device/port returned by eLinkamFunctionMsgCode_OpenComms.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *
         *  Send this message to close a valid open connection to a comms device/port. This is sent via the linkamProcessMessage function.
         *  
         *  This signal will close a valid connection to a Linkam device such as a controller, if one is connected to the host machine.
         *  A disconnection event will be raised which will return the device handle of the now closed device. Ensure an EventCallback 
         *  function pointer is registered with the driver, using the linkamSetCallbackControllerDisconnected function, to receive 
         *  disconnection events. These events ensure you know when the device handle has been safely deleted by the driver.
         */
        eLinkamFunctionMsgCode_CloseComms                                       = 0x00000002,

        /*!
         *  \brief          Send this message to obtain the controller settings and options available.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a ControllerConfig structure populated with available information.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetControllerConfig                              = 0x00000003,

        /*!
         *  \brief          Send this message to obtain the current controller error code.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a \link LinkamSDK::ControllerError ControllerError \endlink value.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetControllerError                               = 0x00000004,

        /*!
         *  \brief          Send this message to obtain the name of the controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the controller name to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t (should be 26 bytes).
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetControllerName                                = 0x00000005,

        /*!
         *  \brief          Send this message to obtain the serial number of the controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the controller serial number to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t (should be 18 bytes).
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetControllerSerial                              = 0x00000006,

        /*!
         *  \brief          Send this message to obtain the current status of the controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a ControllerStatus structure detailing the current status.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetStatus                                        = 0x00000007,

        /*!
         *  \brief          Send this message to obtain the stage configuration details of the connected stage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a \link LinkamSDK::StageConfig StageConfig \endlink structure which details to properties of the connected stage.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetStageConfig                                   = 0x00000008,

        /*!
         *  \brief          Send this message to obtain the connected stages' serial number.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage serial number to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t (should be 18 bytes).
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetStageSerial                                   = 0x00000009,

        /*!
         *  \brief          Send this message to obtain the name of the stage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage name to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t (should be 26 bytes).
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetStageName                                     = 0x0000000A,

        /*!
         *  \brief          Send this message to obtain the maximum range value for the \link LinkamSDK::StageValueType StageValueType \endlink passed.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns the maximum value, as a 32 bit float, for this stage value field.
         *  \param[in]      param1      A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetMaxValue                                      = 0x0000000B,

        /*!
         *  \brief          Send this message to obtain the minimum range value for the \link LinkamSDK::StageValueType StageValueType \endlink passed.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns the minimum value, as a 32 bit float, for this stage value field.
         *  \param[in]      param1      A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetMinValue                                      = 0x0000000C,

        /*!
         *  \brief          Send this message to obtain the resolution for \link LinkamSDK::StageValueType StageValueType \endlink passed.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns the resolution in decimal places, as a 32 bit float, for this stage value field.
         *  \param[in]      param1      A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
         *  \param[in]      param2      An unsigned 32 bit integer; 0 = return in decimal format, 1 = return in fractional format.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetResolution                                    = 0x0000000D,

        /*!
         *  \brief          Send this message to apply or remove the sample calibration values saved to the controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Set to 'true' to apply the sample calibration settings saved to the controller, else 'false' to remove.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_ApplySampleCals                                  = 0x0000000E,

        /*!
         *  \brief          Send this message to save the current sample values on the stage to the controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_SaveSampleCals                                   = 0x0000000F,

        /*!
         *  \brief          Send this message to start/stop a heading cycle.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' to turn ON, else 'false' to turn OFF.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_StartHeating                                     = 0x00000010,

        /*!
         *  \brief          Send this message to start/stop a vacuum reading cycle.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' to turn ON, else 'false' to turn OFF.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_StartVacuum                                      = 0x00000011,

        /*!
         *  \brief          Send this message to start/stop the humidity controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' to turn ON, else 'false' to turn OFF.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_StartHumidity                                    = 0x00000012,

        /*!
         *  \brief          Send this message to start/stop the conditioning process of the atmosphere.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' to turn ON, else 'false' to turn OFF.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_StartHumidityDesiccantConditioning               = 0x00000013,

        /*!
         *  \brief          Send this message to start/stop a motor connected to this card.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' to turn ON, else 'false' to turn OFF.
         *  \param[in]      param2      Either 0=X, 1=Y, 2=Z, 3=Vacuum, 4=Graded, 5=TST, 6=CSS.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_StartMotors                                      = 0x00000014,

        /*!
         *  \brief          Send this message to obtain the current value of the \link LinkamSDK::StageValueType StageValueType \endlink passed.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns the value of the stage value.
         *  \param[in]      param1      A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
         *  \param[in]      param2      Optional argument, see specific StageValueType value for usage.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetValue                                         = 0x00000015,

        /*!
         *  \brief          Send this message to set the current value of the \link LinkamSDK::StageValueType StageValueType \endlink passed.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
         *  \param[in]      param2      The new value for the \link LinkamSDK::StageValueType StageValueType \endlink passed.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_SetValue                                         = 0x00000016,

        /*!
         *  \brief          Send this message to calibrate distance on the TST stage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_TstCalibrateDistance                             = 0x00000017,

        /*!
         *  \brief          Send this message to set the motor mode the TST will operate in.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A TSTMode value.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_TstSetMode                                       = 0x00000018,

        /*!
         *  \brief          Send this message to set the zero force on the TST stage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_TstZeroForce                                     = 0x00000019,

        /*!
         *  \brief          Send this message to set the zero position on the TST stage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_TstZeroPosition                                  = 0x0000001A,

        /*!
         *  \brief          Send this message to turn on/off the cooling mode on the LNP.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' to turn ON, else 'false' to turn OFF.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_LnpSetMode                                       = 0x0000001B,

        /*!
         *  \brief          Send this message to set the speed of the LNP as a percentage from off (0) to full speed (100).
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 0-100 as a uint32_t.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_LnpSetSpeed                                      = 0x0000001C,

        /*!
         *  \brief          Send this message to apply the temporary values to the CSS stage. This will
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
        eLinkamFunctionMsgCode_CssApplyValues                                   = 0x0000001D,

        /*!
         *  \brief          Send this message to check the state of the temporary CSS variables currently set
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
         *  \param[in]      param1      A valid pointer to a CSSVars structure to check, or 0 if checking the temporary 
         *                              stored values set using setValue.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssCheckValues                                   = 0x0000001E,

        /*!
         *  \brief          Send this message to perform a goto reference point operation.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssGotoReference                                 = 0x0000001F,

        /*!
         *  \brief          Send this message to perform a calibration step on the sensor.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      The calibration step to perform as a uint32_t.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssSensorCal                                     = 0x00000020,

        /*!
         *  \brief          Send this message to perform a jog gap operation.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' for 'start' or 'false' for 'stop'.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssStartJogGap                                   = 0x00000021,

        /*!
         *  \brief          Send this message to perform a jog rotation operation.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A value of 'true' for 'start' or 'false' for 'stop'.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssStartJogRot                                   = 0x00000022,

        /*!
         *  \brief          Send this message to enable logging for the library.
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      32-bit Unsigned integer which may be either \link ::LOGGING_LEVEL_MINIMAL LOGGING_LEVEL_MINIMAL\endlink, \link ::LOGGING_LEVEL_INFORMATIVE LOGGING_LEVEL_INFORMATIVE\endlink, \link ::LOGGING_LEVEL_VERBOSE LOGGING_LEVEL_VERBOSE\endlink, or \link ::LOGGING_LEVEL_INVESTIGATION LOGGING_LEVEL_INVESTIGATION\endlink.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \note           This will allow log events to be recorded to either a file or to a parent application by callback event.
         */
        eLinkamFunctionMsgCode_EnableLogging                                    = 0x00000023,

        /*!
         *  \brief          Send this message to disable logging for the library.
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \note           This will disable log events to be recorded to either a file or to a parent application by callback event.
         */
        eLinkamFunctionMsgCode_DisableLogging                                   = 0x00000024,

        /*!
         *  \brief          Send this message to get the controller's firmware version number as a ANSI string.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage serial number to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t.
         *  \param[in]      param3      Ignored, set to 0.
         *  \return         Returns 'true' if successful, else 'false'.
         *  \note           The firmware string size is 6 characters plus a null terminator character.
         */
        eLinkamFunctionMsgCode_GetControllerFirmwareVersion                     = 0x00000025,

        /*!
         *  \brief          Send this message to get the controller's hardware version number as a ANSI string.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage serial number to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t.
         *  \param[in]      param3      Ignored, set to 0.
         *  \return         Returns 'true' if successful, else 'false'.
         *  \note           The hardware string size is 6 characters plus a null terminator character.
         */
        eLinkamFunctionMsgCode_GetControllerHardwareVersion                     = 0x00000026,

        /*!
         *  \brief          Send this message to get the stage's firmware version number as a ANSI string.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage serial number to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t.
         *  \param[in]      param3      Ignored, set to 0.
         *  \return         Returns 'true' if successful, else 'false'.
         *  \note           The firmware string size is 6 characters plus a null terminator character.
         */
        eLinkamFunctionMsgCode_GetStageFirmwareVersion                          = 0x00000027,

        /*!
         *  \brief          Send this message to get the stage's hardware version number as a ANSI string.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage serial number to.
         *  \param[in]      param2      The size of the buffer in bytes as a uint32_t.
         *  \param[in]      param3      Ignored, set to 0.
         *  \return         Returns 'true' if successful, else 'false'.
         *  \note           The hardware string size is 6 characters plus a null terminator character.
         */
        eLinkamFunctionMsgCode_GetStageHardwareVersion                          = 0x00000028,

        /*!
         *  \brief          Send this message to get the driver rate (in ms) data requests are made.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \return         Returns a 32-bit unsigned integer which is the rate in (ms).
         */
        eLinkamFunctionMsgCode_GetDataRate                                      = 0x00000029,

        /*!
         *  \brief          Send this message to set the driver rate (in ms) data requests are made.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      param1      A 32-bit unsigned integer which is the rate in (ms), limited to between 5-1000.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \return         Returns 'true' if successful, else 'false'.
         *  \warning        Linkam Scientific Instruments recommends leaving the default data set. This only alters
         *                  the rate of the internal data request polling thread, this does not affect how fast you
         *                  can send commands.
         *  \remark         The LinkamSDK driver internally manages how often requests for the latest status information
         *                  from the connected devices can be made. For serial RS232 connections it is recommended that 
         *                  you do not exceed 20Hz (50ms), this is the optimal data transfer rate. For USB connections 
         *                  the default is set to 200Hz (5ms). If you are using numerous devices connected to the same
         *                  USB hub then it is recommended to reduce this to 20Hz (50ms). 20Hz is an optimal rate for
         *                  most applications.
         *  \remark         Note that the internal data request thread is a managed thread and regulates the amount
         *                  of requests for maximum efficient data rate. You cannot override this feature. If your system
         *                  cannot manage the data rate set then the LinkamSDK driver will automatically override the set
         *                  rate to regulate for optimal performance.
         */
        eLinkamFunctionMsgCode_SetDataRate                                      = 0x0000002A,

        /*!
         *  \brief          Send this message to obtain the stage cable limits.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a StageCableLimit structure.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetStageCableLimits                              = 0x0000002B,

        /*!
         *  \brief          Send this message to upload the current gain values to the
         *                  controller for a DSC stage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_SendDscGainValues                                = 0x0000002C,

        /*!
         *  \brief          Send this message to upload the current power values to the
         *                  controller for a DSC stage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_SendDscPowerValue                                = 0x0000002D,

        /*!
         *  \brief          Send this message to upload the current baseline power values to the
         *                  controller for a DSC stage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_SendDscBaselinePowerValues                       = 0x0000002E,

        /*!
         *  \brief          Send this message to upload the current set Kendall's tau coefficients
         *                  to the controller for a DSC stage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_SendDscTuaConstants                              = 0x0000002F,

        /*!
         *  \brief          Send this message to set the DSC stage modulation data.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a DSCModulationData structure.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \remark         The DSC stage allows customisation of the modulation data which affects
         *                  the wave applied to the differential scanning routine. The modulation
         *                  data consists of the amplitude and period, there is also a flag to
         *                  enable or disable the feature.
         */
        eLinkamFunctionMsgCode_SetDSCModulationData                             = 0x00000030,

        /*!
         *  \brief          Send this message to obtain the type of option card fitted in the specified slot.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns an OptionBoardType.
         *  \param[in]      param1      The slot ID of the option board, as a 32bit unsigned value.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetOptionCardType                                = 0x00000031,

        /*!
         *  \brief          Send this message to obtain the slot ID for a card matching the specified OptionBoardType.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns the slot ID of the option board matching the type.
         *  \param[in]      param1      The OptionBoardType to find.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetOptionCardSlot                                = 0x00000032,

        /*!
         *  \brief          Send this message to obtain the name of the option card.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage name to, must be 26 bytes long.
         *  \param[in]      param2      The slot ID of the option board, as a 32bit unsigned value.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetOptionCardName                                = 0x00000033,

        /*!
         *  \brief          Send this message to obtain the option card serial number.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the serial number to, must be 18 bytes long.
         *  \param[in]      param2      The slot ID of the option board, as a 32bit unsigned value.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetOptionCardSerial                              = 0x00000034,

        /*!
         *  \brief          Send this message to obtain the option card hardware version.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the hardware version to, must be 7 bytes long.
         *  \param[in]      param2      The slot ID of the option board, as a 32bit unsigned value.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetOptionCardHardwareVersion                     = 0x00000035,

        /*!
         *  \brief          Send this message to obtain the name of the option board sensor.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns an unsigned 32bit integer for the number of supported sensors.
         *  \param[in]      param1      The slot ID of the option board, as a 32bit unsigned value.
         *  \param[in]      param2      The sensor ID of the option board, as a 32bit unsigned value; sensor 1 = 1, sensor 2 = 2, etc.
         *  \param[in]      param3      Ignored, set to 0.
         *  \note           A sensor is a peripheral device that can be plugged into the option card, typically connecting
         *                  part of the stage directly to the option card. For example, specific onboard sensors which are
         *                  monitored and controlled by the option board. You must check if your specific option board and 
         *                  stage combination support this feature. Not all option boards support additional sensors. Some
         *                  option boards just connect to 3rd party peripheral devices, for example video devices.
         */
        eLinkamFunctionMsgCode_DoesOptionCardSupportSensors                     = 0x00000036,

        /*!
         *  \brief          Send this message to obtain the name of the option board sensor.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to an ANSI char buffer to pass the stage name to, must be 26 bytes long.
         *  \param[in]      param2      The slot ID of the option board, as a 32bit unsigned value.
         *  \param[in]      param3      The sensor ID of the option board, as a 32bit unsigned value; sensor 1 = 1, sensor 2 = 2, etc.
         *  \see            eLinkamFunctionMsgCode_DoesOptionCardSupportSensors
         */
        eLinkamFunctionMsgCode_GetOptionCardSensorName                          = 0x00000037,

        /*!
         *  \brief          Send this message to obtain the serial number of the option board sensor.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to an ANSI char buffer to pass the stage serial number to, must be 18 bytes long.
         *  \param[in]      param2      The slot ID of the option board, as a 32bit unsigned value.
         *  \param[in]      param3      The sensor ID of the option board, as a 32bit unsigned value; sensor 1 = 1, sensor 2 = 2, etc.
         *  \see            eLinkamFunctionMsgCode_DoesOptionCardSupportSensors
         */
        eLinkamFunctionMsgCode_GetOptionCardSensorSerial                        = 0x00000038,

        /*!
         *  \brief          Send this message to obtain the hardware version of the option board sensor.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the hardware version to, must be 7 bytes long.
         *  \param[in]      param2      The slot ID of the option board, as a 32bit unsigned value.
         *  \param[in]      param3      The sensor ID of the option board, as a 32bit unsigned value; sensor 1 = 1, sensor 2 = 2, etc.
         *  \see            eLinkamFunctionMsgCode_DoesOptionCardSupportSensors
         */
        eLinkamFunctionMsgCode_GetOptionCardSensorHardwareVersion               = 0x00000039,

        /*!
         *  \brief          Send this message to obtain the connected stage firmware group.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a StageGroup value.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetStageGroup                                    = 0x0000003A,

        /*!
         *  \brief          Send this message to obtain the identity code of the instument bus device.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a boolean value, true if present, else false.
         *  \param[in]      param1      An InstrumentBusDeviceType code for the device to look up.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_HaveInstrumentBusDeviceType                      = 0x0000003B,

        /*!
         *  \brief          Send this message to obtain the name of the instument bus device.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage name to, must be 26 bytes long.
         *  \param[in]      param2      An InstrumentBusDeviceType code for the device to look up.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetInstrumentBusDeviceName                       = 0x0000003C,

        /*!
         *  \brief          Send this message to obtain the serial number of the instument bus device.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage serial number to, must be 18 bytes long.
         *  \param[in]      param2      An InstrumentBusDeviceType code for the device to look up.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetInstrumentBusDeviceSerial                     = 0x0000003D,

        /*!
         *  \brief          Send this message to obtain the firmware version of the instument bus device.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the hardware version to, must be 7 bytes long.
         *  \param[in]      param2      An InstrumentBusDeviceType code for the device to look up.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetInstrumentBusDeviceFirmwareVersion            = 0x0000003E,

        /*!
         *  \brief          Send this message to obtain the hardware version of the instument bus device.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the hardware version to, must be 7 bytes long.
         *  \param[in]      param2      An InstrumentBusDeviceType code for the device to look up.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetInstrumentBusDeviceHardwareVersion            = 0x0000003F,

        /*!
         *  \brief          Send this message to obtain the sensor name for the humidity controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage name to, must be 26 bytes long.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetHumidityControllerSensorName                  = 0x00000040,

        /*!
         *  \brief          Send this message to obtain the sensor serial number for the humidity controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the stage serial number to, must be 18 bytes long.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetHumidityControllerSensorSerial                = 0x00000041,

        /*!
         *  \brief          Send this message to obtain the sensor hardware version for the humidity controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer to pass the hardware version to, must be 7 bytes long.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetHumidityControllerSensorHardwareVersion       = 0x00000042,

        /*!
         *  \brief          Send this message to obtain whether the controller is of a certain type.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a boolean value, true if present, else false.
         *  \param[in]      param1      An ControllerType code for the device to look up.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \note           If the eControllerType_Unknown is used this will return \b true if any
         *                  controller is present regardless of type, else it will return false if
         *                  no controller is present.
         */
        eLinkamFunctionMsgCode_IsControllerType                                 = 0x00000043,

        /*!
         *  \brief          Send this message to obtain the controller's PSU details.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a PowerSupplyUnitDetails structure to populate.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetControllerPSUDetails                          = 0x00000044,

        /*!
         *  \brief          Send this message to enable trigger signal usage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_SetControllerTriggerSignalEnable                 = 0x00000045,

        /*!
         *  \brief          Send this message to disable trigger signal usage.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_SetControllerTriggerSignalDisable                = 0x00000046,

        /*!
         *  \brief          Send this message to set the controller's mains frequency.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      An unsigned 32bit integer providing the mains frequency to set; 0 = AD60HZ, 8 = AD50HZ.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_SetControllerMainsFrequency                      = 0x00000047,

        /*!
         *  \brief          Send this message to set the controller to initialise the
         *                  the trigger signal system for a new pulse configuration.
         *                  This command resets the current pluse configuration emitted
         *                  from the green and pink channels.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_InitialiseTriggerSignalPulse                     = 0x00000048,

        /*!
         *  \brief          Send this message to set the controller to set the type of
         *                  pulse generated on the green and pink trigger signal channels.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      An unsigned 32bit integer providing the pluse format ID for the green channel; 0 = none, 1 = positive pulse signal, 2 = negative pulse signal, 3 = positive edge signal, 4 = negative edge signal.
         *  \param[in]      param2      An unsigned 32bit integer providing the pluse format ID for the pink channel; 0 = none, 1 = positive pulse signal, 2 = negative pulse signal, 3 = positive edge signal, 4 = negative edge signal.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_SetTriggerSignalPulse                            = 0x00000049,

        /*!
         *  \brief          Send this message to set the controller to adjust the pluse with
         *                  of the emitted signals from the green and pink trigger channels.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A 32bit floating point value defining the duration of the pluse.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_SetTriggerSignalPluseWidth                       = 0x0000004A,

        /*!
         *  \brief          Send this message to obtain the details for a specific program ramp running on the controller.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      An unsigned 32bit integer providing the program state ID to get; 1 = primary heater program, 2 = secondary heater program.
         *  \param[in]      param2      A valid pointer to a Running structure to popluate.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetProgramState                                  = 0x0000004B,

        /*!
         *  \brief          Send this message to obtain the details for the stage configuration.
         *                  This allows the developer to look at mode flags for what is supported
         *                  by the current stage configuration.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a StageCableConfig value.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetStageConfiguration                            = 0x0000004C,

        /*!
         *  \brief          Send this message to obtain the details for the supported heaters
         *                  for this controller. Controllers may support 1 or more heater outputs
         *                  to a stage, this does not define how many heaters can be supported on
         *                  a stage though. These are just power characteristics for the heater
         *                  output. 
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a HeaterDetails structure to popluate.
         *  \param[in]      param2      An unsigned 32bit integer providing the heater output ID to get; 1 = primary heater program, 2 = secondary heater program.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetControllerHeaterDetails                       = 0x0000004D,

        /*!
         *  \brief          Send this message to directly set gap motor velocity on the CSS stage. 
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A 32bit float describing the velocity to set.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssSendGapVelocity                               = 0x0000004E,

            /*!
         *  \brief          Send this message to directly set gap override distance on the CSS stage. 
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A 32bit float describing the gap distance.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssSendGapOverride                               = 0x0000004F,

        /*!
         *  \brief          Send this message to directly set gap motor position to obtain on the CSS stage. 
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A 32bit float describing the final gap motor position.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssSendGap                                       = 0x00000050,

        /*!
         *  \brief          Send this message to directly set rotary velocity on the CSS stage. 
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A 32bit float describing the velocity to set.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssSendVelocity                                  = 0x00000051,

        /*!
         *  \brief          Send this message to directly set rate to apply on the CSS stage. 
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A 32bit float describing a value based on the strain (S-1).
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssSendRate                                      = 0x00000052,

        /*!
         *  \brief          Send this message to directly set frequency to apply on the CSS stage. 
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A 32bit float describing the frequency in Hz.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssSendFrequency                                 = 0x00000053,

        /*!
         *  \brief          Send this message to directly set strain to apply on the CSS stage. 
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A 32bit float describing the strain force.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssSendStrain                                    = 0x00000054,

        /*!
         *  \brief          Send this message to send the rotational motor direction to apply on the CSS stage. 
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A boolean describing the direction the motor should travel (cw = false, acw = true).
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssSendDirection                                 = 0x00000055,

        /*!
         *  \brief          Send this message to directly stop the CSS stage motors. 
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_CssSendForceStop                                 = 0x00000056,

        /*!
         *  \brief          Send this message to directly set the main motor troque value. 
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A scalar between the value of 0 - 9 (low - high).
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \remark         This is a legacy command provided for support with older models of the CSS.
         */
        eLinkamFunctionMsgCode_CssSendTorque                                    = 0x00000057,

        /*!
         *  \brief          Send this message to force the TST to perform a specific force calibration operation.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A 16bit unsigned integer use to provide the id of the program to run; 0 = Move Jaws 5mm, 1 = Do Gauge Zero, 2 = Do Gauge Gain.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \note           This command can be used to perform custom calibration tasks. It
         *                  currently provides 3 operations:
         *                  - move jaws out by 5mm
         *                  - calibrate zero force
         *                  - calibrate gain
         */
        eLinkamFunctionMsgCode_TstSetCalibrateForceProgramMode                  = 0x00000058,
        eLinkamFunctionMsgCode_TstSetCalibrationForce                           = eLinkamFunctionMsgCode_TstSetCalibrateForceProgramMode, // Deprecated.

        /*!
         *  \brief          Send this message to force heating at the currently programmed
         *                  rate. This is used when a manual hold has been invoked.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \remark         If a limit has been previously is set and the current temperature is below the limit
         *                  then heating will stop once the limit has been reached. If the current temperature is at
         *                  the programmed limit or above then heating will continued at the programmed rate indefinitely
         *                  or until damage occurs to the stage unit.
         *  \warning        It is possible to cause damage to the stage unit with this cammand. Ensure you have protection
         *                  code monitoring the temperature so it does not exceed the maximum recommanded temperature of 
         *                  the stage unit.
         */
        eLinkamFunctionMsgCode_ForceHeating                                     = 0x00000059,

        /*!
         *  \brief          Send this message to force cooling at the currently programmed
         *                  rate. This is used when a manual hold has been invoked.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \remark         If a limit has been previously is set and the current temperature is at the programmed limit or
         *                  below the limit then cooling will continued at the programmed rate indefinitely or until the 
         *                  physical limits of the stage and LNP units have been reached. If the current temperature above 
         *                  the programmed limit then cooling will continue till reaching the programmed limit. 
         *  \warning        It is possible to cause damage to the stage unit with this cammand. Ensure you have protection
         *                  code monitoring the temperature so it does not exceed the minimum recommanded temperature of 
         *                  the stage unit.
         */
        eLinkamFunctionMsgCode_ForceCooling                                     = 0x0000005A,

        /*!
         *  \brief          Send this message to impose a manual hold on the temperature.
         *  \remark         This command will force an indefinit hold of the current temperature.
         *                  Sending this command a second time will toggle the hold mode off.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_ForceHold                                        = 0x0000005B,

        /*!
         *  \brief          Send this message to obtain the instument bus device identity code (\b linkam \b only).
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a 32-bit unsigned integer which is the identity code for the device.
         *  \param[in]      param1      An InstrumentBusDeviceType code for the device to look up.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \remark         This is used by Linkam Scientific Instruments to obtain the device identity code.
         *                  This has no applicable application for 3rd party developers, outside of diagnostics
         *                  purposes.
         */
        eLinkamFunctionMsgCode_GetInstrumentBusDeviceIdent                      = 0x0000005C,
    
        /*!
         *  \brief          Send this message to obtain the stage identity code (\b linkam \b only).
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a 32-bit unsigned integer which is the identity code for the device.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \remark         This is used by Linkam Scientific Instruments to obtain the device identity code.
         *                  This has no applicable application for 3rd party developers, outside of diagnostics
         *                  purposes.
         */
        eLinkamFunctionMsgCode_GetStageIdent                                    = 0x0000005D,

        /*!
         *  \brief          Send this message to obtain the controller identity code (\b linkam \b only).
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a 32-bit unsigned integer which is the identity code for the device.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \remark         This is used by Linkam Scientific Instruments to obtain the device identity code.
         *                  This has no applicable application for 3rd party developers, outside of diagnostics
         *                  purposes.
         */
        eLinkamFunctionMsgCode_GetControllerIdent                               = 0x0000005F,

        /*!
         *  \brief          Send this message to obtain the device connection information.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a boolean value (true = successful, false = failed).
         *  \param[in]      param1      A valid pointer to a CommsInfo.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \remark         This is used by Linkam Scientific Instruments to obtain the device identity code.
         *                  This has no applicable application for 3rd party developers, outside of diagnostics
         *                  purposes.
         */
        eLinkamFunctionMsgCode_GetConnectionInformation                         = 0x00000060,

        /*!
         *  \brief          Send this message to obtain the stage heater identity code (\b linkam \b only).
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a 32-bit unsigned integer which is the identity code for the device.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \remark         This is used by Linkam Scientific Instruments to obtain the device hetater identity code.
         *                  This has no applicable application for 3rd party developers, outside of diagnostics
         *                  purposes.
         */
        eLinkamFunctionMsgCode_GetStageHeaterIdent                              = 0x00000061,

        /*!
         *  \brief          Send this message to enable serial RS232 loopback testing (\b linkam \b only).
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a 32-bit unsigned integer which is the identity code for the device.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \remark         This is used by Linkam Scientific Instruments and has no applicable application for 3rd
         *                  party developers, outside of diagnostics purposes.
         */
        eLinkamFunctionMsgCode_EnableSerialLoopbackTest                         = 0x00000062,

        /*!
         *  \brief          Send this message to disable serial RS232 loopback testing (\b linkam \b only).
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a 32-bit unsigned integer which is the identity code for the device.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \remark         This is used by Linkam Scientific Instruments and has no applicable application for 3rd
         *                  party developers, outside of diagnostics purposes.
         */
        eLinkamFunctionMsgCode_DisableSerialLoopbackTest                        = 0x00000063,

        /*!
         *  \brief          Send this message to the driver before initialisation to prevent creation of a driver log file.
         *
         * By default logging is enabled within the driver. Logging allows developers to record error events
         * within a text file that can be sent to Linkam for diagnostics. This message allows developers
         * to prevent the creation of the log file before the driver is initialised. Once the driver is
         * initialised the log usage option cannot be changed.
         *
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *
         *  \note           If log file creation is disabled then the user can still obtain driver log messages by way
         *                  of registering a callback function to receive logging events.
         */
        eLinkamFunctionMsgCode_PreventLogging                                   = 0x00000064,

        /*!
         *  \brief          Send this message to the driver before initialisation to allow creation of a driver log file.
         *
         * By default logging is enabled within the driver. Logging allows developers to record error events
         * within a text file that can be sent to Linkam for diagnostics. This message allows developers
         * to enable the creation of the log file before the driver is initialised. Once the driver is
         * initialised the log usage option cannot be changed.
         *
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_AllowLogging                                     = 0x00000065,

        /*!
         *  \brief          Send this message to the device to set the maximum time the Rx communications channel will
         * wait for a complete message reply to the last command message sent before dropping the command message.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A 64-bit unsigned integer representing the time in microseconds (us) to wait up to.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \note           A valid device must be opened (connected) for this message to work. To set the Rx timeout before
         *                  a valid connection to a device is established, set the 'timeout' paramater of the specific CommsInfo
         *                  structure for the device. This will ensure the timeout setting is correct for your system before
         *                  device connection starts. Device connection relies on the ability to pass connection message to the
         *                  device and for the replies to these messages to be recieved. If you experience problems establishing 
         *                  a connection to your device, the problem is most likely due to delays in the network service. Simply
         *                  increase the timeout to ensure complete replies are obtained.
         */
        eLinkamFunctionMsgCode_SetCommsRxTimeout                                = 0x00000066,

        /*!
         *  \brief          Send this message to a plunger device to execute a command custom script.
         *
         * Plunger is the latest new device added to the Linkam communications driver. This device accepts complex command scripts
         * as a way to control the device. Developer's can provide their own scripts to control the device from an application level.
         *
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A 32-bit unsigned integer representing the number of PlungerScriptCommand structure in the command array.
         *  \param[in]      param2      A pointer to a valid array of PlungerScriptCommand structures, the command array to execute.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_PlungerExecuteScript                             = 0x00000067,

        /*!
         *  \brief          Send this message to get the type of plunger board connected.
         *
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a 32bit unsigned interger for the type of ancillary board this device handle represents.
         *  \param[in]      param1      Reserved by Linkam, set to 0.
         *  \param[in]      param2      Reserved by Linkam, set to 0.
         *  \param[in]      param3      Reserved by Linkam, set to 0.
         */
        eLinkamFunctionMsgCode_GetPlungerBoardType                              = 0x00000068,

        /*!
         *  \brief          Send this message to a plunger device to find out if a script is executing.
         *
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if  executing a script, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \note           The ethane bath control can be commanded from scripts. This command has been supplied for convenience.
         */
        eLinkamFunctionMsgCode_PlungerIsScriptExecuting                         = 0x00000069,

        /*!
         *  \brief          Send this message to obtain the connected stage configuration type.
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns a StageType value.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_GetStageType                                    = 0x0000006A,

        /*!
         *  \brief          Send this message to get the number of enumeratable USB devices.
         *
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns a 32 bit unsigned integer for the the number of discovered supported devices.
         *  \param[in]      param1      Reserved by Linkam, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_DiscoverUSBDeviceCount                           = 0x0000006B,

        /*!
         *  \brief          Send this message to get the details of all available USB devices.
         *
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns a 32 bit unsigned integer for the the number of discovered supported devices.
         *  \param[in]      param1      A valid pointer to an array of USBDeviceInfo structures.
         *  \param[in]      param2      A 32 bit unsigned integer providing the number of entries in the array.
         *  \param[in]      param3      Reserved by Linkam, set to 0.
         */
        eLinkamFunctionMsgCode_GetUSBDeviceDetailsList                          = 0x0000006C,

        /*!
         *  \brief          Send this message to the driver to create a data log file and start recording.
         *
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to a char buffer of 1024 bytes long to pass the full path of the data log file (set to 0 to ignore and use defaults).
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *
         *  \note           Data logs are different to standard logs. Data logs record live data from the stage
         *                  to a CSV file. These logs can be loaded into any application supporting CSV files;
         *                  for example you can load these into Microsoft Excel and create charts from them.
         *
         *  \note           Data logs will be written to the current application directory.
         *
         *  \note           This requires an additional licensed option. Please speak to our sales team at Linkam Scientific Instruments.
         */
        eLinkamFunctionMsgCode_StartDataLogging                                 = 0x0000006D,

        /*!
         *  \brief          Send this message to the driver to stop a recording data and close the CSV file.
         *
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *
         *  \note           This requires an additional licensed option. Please speak to our sales team at Linkam Scientific Instruments.
         */
        eLinkamFunctionMsgCode_StopDataLogging                                  = 0x0000006E,

        /*!
         *  \brief          Send this message to the driver to enable data recording feature.
         *
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *
         *  \note           Data logs are different to standard logs. Data logs record live data from the stage
         *                  to a CSV file. These logs can be loaded into any application supporting CSV files;
         *                  for example you can load these into Microsoft Excel and create charts from them.
         *
         *  \note           Data logs will be written to the current application directory.
         *
         *  \note           This requires an additional licensed option. Please speak to our sales team at Linkam Scientific Instruments.
         */
        eLinkamFunctionMsgCode_EnableDataLogging                                = 0x0000006F,

        /*!
         *  \brief          Send this message to the driver to disable data recording feature.
         *
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *
         *  \note           This requires an additional licensed option. Please speak to our sales team at Linkam Scientific Instruments.
         */
        eLinkamFunctionMsgCode_DisableDataLogging                               = 0x00000070,

        /*!
         *  \brief          Send this message to the driver to set the data recording rate.
         *
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A 32 bit unsigned integer for the sample time (ms).
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *
         *  \note           This requires an additional licensed option. Please speak to our sales team at Linkam Scientific Instruments.
         */
        eLinkamFunctionMsgCode_SetDataLoggingRate                               = 0x00000071,

        /*!
         *  \brief          Send this message to the driver to set the data recording rate.
         *
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns a 32 bit unsigned integer for the sample time (ms).
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *
         *  \note           This requires an additional licensed option. Please speak to our sales team at Linkam Scientific Instruments.
         */
        eLinkamFunctionMsgCode_GetDataLoggingRate                               = 0x00000072,

        /*!
         *  \brief          Send this message to the driver before initialising the SDK.
         *                  This will set the optimised COMS mode for improved CPU consumption.
         *                  By default optimised mode is set.
         *
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Ignored.
         *  \param[in]      param1      A boolean value, true = enabled, false = disabled.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_SetCPUOptimisation                               = 0x00000073,

        /*!
         *  \brief          Reserved by Linkam for future use.
         *
         *  \param[in]      hDevice     Unknown.
         *  \param[in]      result      Unknown.
         *  \param[in]      param1      Unknown.
         *  \param[in]      param2      Unknown.
         *  \param[in]      param3      Unknown.
         */
        eLinkamFunctionMsgCode_Reserved8                                        = 0x00000074,

        /*!
         *  \brief          Reserved by Linkam for future use.
         *
         *  \param[in]      hDevice     Unknown.
         *  \param[in]      result      Unknown.
         *  \param[in]      param1      Unknown.
         *  \param[in]      param2      Unknown.
         *  \param[in]      param3      Unknown.
         */
        eLinkamFunctionMsgCode_Reserved9                                        = 0x00000075,

        /*!
         *  \brief          Reserved by Linkam for future use.
         *
         *  \param[in]      hDevice     Unknown.
         *  \param[in]      result      Unknown.
         *  \param[in]      param1      Unknown.
         *  \param[in]      param2      Unknown.
         *  \param[in]      param3      Unknown.
         */
        eLinkamFunctionMsgCode_Reserved10                                       = 0x00000076,

        /*!
         *  \brief          Send this message to set the logging level. This controls the amount of information produced.
         *
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      32-bit Unsigned integer which may be either \link ::LOGGING_LEVEL_MINIMAL LOGGING_LEVEL_MINIMAL\endlink, \link ::LOGGING_LEVEL_INFORMATIVE LOGGING_LEVEL_INFORMATIVE\endlink, \link ::LOGGING_LEVEL_VERBOSE LOGGING_LEVEL_VERBOSE\endlink, or \link ::LOGGING_LEVEL_INVESTIGATION LOGGING_LEVEL_INVESTIGATION\endlink.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         *  \note           This command only sets the current logging level required. To create a driver log you must allow loggin prior
         *                  to initialising the driver. The default is that the driver will create a log file. You can turn logging on/off
         *                  anytime using the enable and disable logging commands.
         */
        eLinkamFunctionMsgCode_SetLoggingLevel                                  = 0x00000077,

        /*!
         *  \brief          Reserved by Linkam - Do not use!
         *
         *  \param[in]      hDevice     Known.
         *  \param[in]      result      Known.
         *  \param[in]      param1      Known.
         *  \param[in]      param2      Known.
         *  \param[in]      param3      Known.
         */
        eLinkamFunctionMsgCode_Reserved1                                        = 0x00000078,

        /*!
         *  \brief          Reserved by Linkam - Do not use!
         *
         *  \param[in]      hDevice     Known.
         *  \param[in]      result      Known.
         *  \param[in]      param1      Known.
         *  \param[in]      param2      Known.
         *  \param[in]      param3      Known.
         */
        eLinkamFunctionMsgCode_Reserved2                                        = 0x00000079,

       /*!
        *  \brief          Reserved by Linkam - Do not use!
        *
        *  \param[in]      hDevice     Known.
        *  \param[in]      result      Known.
        *  \param[in]      param1      Known.
        *  \param[in]      param2      Known.
        *  \param[in]      param3      Known.
        */
        eLinkamFunctionMsgCode_Reserved3                                        = 0x00000080,

       /*!
        *  \brief          Send this message to force the TST to perform a move to home position.
        *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
        *  \param[in]      result      Returns 'true' if successful, else 'false'.
        *  \param[in]      param1      Ignored, set to 0.
        *  \param[in]      param2      Ignored, set to 0.
        *  \param[in]      param3      Ignored, set to 0.
        *  \warning        This command removes all software limits and safegards to allows the jaws to close fully.
        *                  Ensure anything in its way is removed first.
        */
        eLinkamFunctionMsgCode_TstHome                                          = 0x00000081,

        /*!
         *  \brief          Send this message to get the details of a USB device.
         *
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      A valid pointer to an array of USBDeviceInfo structures.
         *  \param[in]      param2      Reserved by Linkam, set to 0.
         *  \param[in]      param3      Reserved by Linkam, set to 0.
         */
        eLinkamFunctionMsgCode_GetUSBDeviceDetails                              = 0x00000082,

        /*!
         *  \brief          Send this message to start the water pump.
         *
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Reserved by Linkam, set to 0.
         *  \param[in]      param2      Reserved by Linkam, set to 0.
         *  \param[in]      param3      Reserved by Linkam, set to 0.
         */
        eLinkamFunctionMsgCode_StartWaterPump                                   = 0x00000083,

        /*!
         *  \brief          Send this message to stop the water pump.
         *
         *  \param[in]      hDevice     The CommsHandle for the device this command call is for.
         *  \param[in]      result      Returns 'true' if successful, else 'false'.
         *  \param[in]      param1      Reserved by Linkam, set to 0.
         *  \param[in]      param2      Reserved by Linkam, set to 0.
         *  \param[in]      param3      Reserved by Linkam, set to 0.
         */
        eLinkamFunctionMsgCode_StopWaterPump                                    = 0x00000084,

        /*!
         *  \brief          Send this message to open a connection to a comms device/port, this version does not
         *                  wait till the connection occurs before returning. This version assumes you are using 
         *                  the event system to detect controller connection events
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Returns a ConnectionStatus structure for the connection request.
         *  \param[in]      param1      A valid pointer to a \link LinkamSDK::CommsInfo CommsInfo \endlink structure instance defining the connection properties.
         *  \param[out]     param2      A pointer to a CommsHandle instance which will recieve the handle to the comms device/port.
         *  \param[in]      param3      Ignored, set to 0.
         *
         *  Send this message to open a connection to a comms device/port. This is sent via the linkamProcessMessage function.
         *  Populate the CommsInfo structure with the correct connection information; this may be for a Serial or USB connection.
         *  Cast the info member to an appropriate SerialCommsInfo or USBCommsInfo structure and populate.
         *
         *  This signal will open a valid connection to a Linkam device such as a controller, if one is connected and visible to
         *  the host machine. A connection event will be raised which will return the device handle. A device handle is required
         *  to make subsequent calls to the device. Ensure an EventCallback function pointer is registered with the driver, using
         *  the linkamSetCallbackControllerConnected function, to receive the device handle.
         */
        eLinkamFunctionMsgCode_OpenCommsNonBlocking                             = 0x00000085,

        /*!
         *  \brief          The maximum command ID in this set.
         *  \param[in]      hDevice     Ignored, set to 0.
         *  \param[in]      result      Ignored.
         *  \param[in]      param1      Ignored, set to 0.
         *  \param[in]      param2      Ignored, set to 0.
         *  \param[in]      param3      Ignored, set to 0.
         */
        eLinkamFunctionMsgCode_Max                                              = 0x0FFFFFFF
    };
}

#ifdef __cplusplus
}
#endif

#endif /// LINKAM_SDK__MESSAGE_API_H


