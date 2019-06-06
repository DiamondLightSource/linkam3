/************************************************************************
*
*   File:           DeprecatedAPI.h
*
*   Description:    This is the deprecated Linkam SDK header for 
*                   interfacing to Linkam devices using the old API.
*                   This may be used on Windows and Linux platforms.
*
*                   This API will not be supported in future versions 
*                   of the SDK, it is strongly recommended that you
*                   start making the move over to the new API as defined
*                   in version 3.0.0.0 and above.
*
*   Copyright © 2018 Linkam Scientific Instruments. All rights reserved
************************************************************************/
#ifndef LINKAM__SDK__DEPRECATED_API_H
#define LINKAM__SDK__DEPRECATED_API_H
#include "ExportAPI.h"
#include "CommonTypes.h"
#include "CommonStageAPI.h"
#include "EventAPI.h"


/*!
 *  \brief      Call to open/close a connection to a comms device/port.
 *  \param[in]  bConnect        A value of 'true' for 'open' or 'false' for 'close' connection.
 *  \param[in]  u32CommsType    The type of device connection required, either 0=USB, 1=SERIAL.
 *  \param[in]  u32CommsPort    Used only if a SERIAL connection is required, the number of the serial port name (remove 'COM' from COM2, or '/dev/ttyS' from /dev/ttyS1).
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with OpenComms under CommsAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL uint32_t OpenComms(bool bConnect, uint32_t u32CommsType, uint32_t u32CommsPort);

/*!
 *  \brief      Call this function to apply or remove the sample calibration values saved to the controller.
 *  \param[in]  bValue      Set to 'true' to apply the sample calibration settings saved to
 *                          the controller, else 'false' to remove.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with ApplySampleCals under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool ApplySampleCals(bool bValue);

/*!
 *  \brief      Send the calibrate distance command to the TST stage.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with CalibrateTstDistance under TSTStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool CalibrateTstDistance(void);

/*!
 *  \brief      Call this method to apply the temporary values to the CSS stage. This will
 *              make them current and live.
 *
 *              The CSS card maintains a set of temporary variables which are used to set/control
 *              features on the CSS stage, the card is responsible for managing them. You can set
 *              the temporary variables using the setValue method.
 *              
 *              You should always check the validity of the temporary variables before applying them,
 *              however this is done automatically by the applyValues method. Be aware that you only
 *              get a true/false result from applyValues method, so you cannot determine what values
 *              did not conform to the expected safe ranges. For this you must call the checkValues
 *              method.
 *
 *  \return     Returns 'true' if the values successfully passed the safety check and were
 *              sent to the CSS stage, else this method will return 'false' if one or more
 *              values failed the safety check.
 *  \remark     Replace this call with CssApplyValues under CSSStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool CssApplyValues(void);

/*!
 *  \brief      Call this method to check the state temporary CSS variables currently set
 *              before applying them to the stage.
 *
 *              The CSS card maintains a set of temporary variables which are used to set/control
 *              features on the CSS stage, the card is responsible for managing them. You can set
 *              the temporary variables using the setValue method.
 *
 *              You should always check the validity of the temporary variables before applying them,
 *              however this is done automatically by the applyValues method. Be aware that you only
 *              get a true/false result from applyValues method, so you cannot determine what values
 *              did not conform to the expected safe ranges. For this you must call the checkValues
 *              method.
 *
 *  \return     Returns an 8bit value holding error flags, each bit is a flag for a specific
 *              variable. If set then the variable was found to have a problem. See CSSCheckCodes
 *              for more details.
 *  \remark     Replace this call with CssCheckValues under CSSStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL unsigned char CssCheckValues(void);

/*!
 *  \brief      Call this to perform a goto reference point operation.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with CssGotoReference under CSSStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool CssGotoReference(void);

/*!
 *  \brief      Call this to perform a calibration step on the sensor.
 *  \param[in]  bValue      The calibration step to perform.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with CssSensorCal under CSSStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool CssSensorCal(unsigned int u32value);

/*!
 *  \brief      Call this to perform a jog gap operation.
 *  \param[in]  bValue      A value of 'true' for 'start' or 'false' for 'stop'.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with CssStartJogGap under CSSStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool CssStartJogGap(bool bValue);

/*!
 *  \brief      Call this to perform a jog rotation operation.
 *  \param[in]  bValue      A value of 'true' for 'start' or 'false' for 'stop'.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with CssStartJogRot under CSSStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool CssStartJogRot(bool bValue);

/*!
 *  \brief      Call this function to obtain the controller settings and options available.
 *  \return     Returns a ControllerConfig structure populated with available information.
 *  \remark     Replace this call with GetControllerConfig under ControllerAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL uint64_t GetControllerConfig(void);

/*!
 *  \brief      Call this function to obtain the current controller error code.
 *  \return     Returns a \link LinkamSDK::ControllerError ControllerError \endlink value.
 *  \remark     Replace this call with GetControllerError under ControllerAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL unsigned int GetControllerError(void);

/*!
 *  \brief      Call this function to obtain the maximum range value for the \link LinkamSDK::StageValueType StageValueType \endlink passed.
 *  \param[in]  u32eValueType       A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
 *  \return     Returns the maximum value, as a 32 bit float, for this stage value field.
 *  \remark     Replace this call with GetMaxValue under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL float GetMaxValue(unsigned int u32eValueType);

/*!
 *  \brief      Call this function to obtain the minimum range value for the \link LinkamSDK::StageValueType StageValueType \endlink passed.
 *  \param[in]  u32eValueType       A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
 *  \return     Returns the minimum value, as a 32 bit float, for this stage value field.
 *  \remark     Replace this call with GetMinValue under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL float GetMinValue(unsigned int u32eValueType);

/*!
 *  \brief      Call this function to obtain the resolution for \link LinkamSDK::StageValueType StageValueType \endlink passed.
 *  \param[in]  u32eValueType       A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
 *  \return     Returns the resolution, as a 32 bit float, for this stage value field.
 *  \remark     Replace this call with GetResolution under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL float GetResolution(unsigned int u32eValueType);

/*!
 *  \brief      Call this function to obtain the stage configuration details of the connected stage.
 *  \return     Returns a \link LinkamSDK::StageConfig StageConfig \endlink structure which details to properties of the connected stage.
 *  \remark     Replace this call with GetStageConfig under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL uint64_t GetStageConfig(void);

/*!
 *  \brief      Call this function to obtain the serial number of the stage.
 *  \return     Returns a pointer to a NULL terminated char array holding the serial number.
 *  \remark     Replace this call with GetStageSerial under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL char* GetStageSerial();

/*!
 *  \brief      Call this function to obtain the current status of the controller.
 *  \return     Returns a ControllerStatus structure detailing the current status.
 *  \remark     Replace this call with GetStatus under ControllerAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL uint64_t GetStatus(void);

/*!
 *  \brief      Call this function to obtain the name of the stage.
 *  \return     Returns a pointer to a NULL terminated char array holding the name.
 *  \remark     Replace this call with GetStageName under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL char* GetStageName();

/*!
 *  \brief      Call this function to obtain the current value of the \link LinkamSDK::StageValueType StageValueType \endlink passed.
 *  \param[in]  u32eValueType       A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
 *  \return     Returns the value of the \link LinkamSDK::StageValueType StageValueType \endlink, as a 32 bit float.
 *  \remark     Replace this call with GetValue under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL float GetValue(unsigned int u32eValueType);

/*!
 *  \brief      Call this function save the current sample values on the stage to the controller.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with SetValue under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool SaveSampleCals();

/*!
 *  \brief      Call to turn on/off the cooling mode.
 *  \param[in]  bValue      A value of 'true' to turn ON, else 'false' to turn OFF.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with SetLnpMode under LNPStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool SetLnpMode(bool bValue);

/*!
 *  \brief      Call to set the speed as a percentage from off (0) to full speed (100).
 *  \param[in]  u32Speed    A value of 0-100.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with SetLnpSpeed under LNPStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool SetLnpSpeed(unsigned int u32Speed);

/*!
 *  \brief      Call this function to set the current value of the \link LinkamSDK::StageValueType StageValueType \endlink passed.
 *  \param[in]  u32eValueType       A value from the \link LinkamSDK::StageValueType StageValueType \endlink enumerator.
 *  \param[in]  fValue              The new value for the \link LinkamSDK::StageValueType StageValueType \endlink passed, as a 32 bit float.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with SetValue under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool SetValue(unsigned int u32eValueType, float fValue);

/*!
 *  \brief      Call this to start a heading cycle.
 *  \param[in]  bValue      A value of 'true' to turn ON, else 'false' to turn OFF.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with StartHeating under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool StartHeating(bool bValue);

/*!
 *  \brief      Call to start/stop a motor connected to this card.
 *  \param[in]  bValue      A value of 'true' to turn ON, else 'false' to turn OFF.
 *  \param[in]  u32Axis     Either 0=X, 1=Y, 2=Z for Motor Driven Stage, or ignored if stage is of Vacuum, Graded, TST or CSS type.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with StartMotors under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool StartMotors(bool bValue, unsigned int u32Axis);

/*!
 *  \brief      Call this to start/stop a vacuum reading cycle.
 *  \param[in]  bValue      A value of 'true' to turn ON, else 'false' to turn OFF.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with StartVacuum under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool StartVacuum(bool bValue);

/*!
 *  \brief      Call to start the humidity controller.
 *  \param[in]  bValue      A value of 'true' to turn ON, else 'false' to turn OFF.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with StartHumidity under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool StartHumidity(bool bValue);

/*!
 *  \brief      Call to start the conditioning process of the atmosphere.
 *  \param[in]  bValue      A value of 'true' to turn ON, else 'false' to turn OFF.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with StartHumidityDesiccantConditioning under CommonStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool StartHumidityDesiccantConditioning(bool bValue);

/*!
 *  \brief      Call this function to set the motor mode the TST will operate in (force or distance mode).
 *  \param[in]  bValue      Set to 'true' for 'Force mode' else 'false' for 'Distance mode'.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with SetTstMode under TSTStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool SetTstMode(bool bValue);

/*!
 *  \brief      Send the zero force command to the TST stage.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with TstZeroForce under TSTStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool TstZeroForce(void);

/*!
 *  \brief      Send the zero position command to the TST stage.
 *  \return     Returns 'true' if successful, else 'false'.
 *  \remark     Replace this call with TstZeroPosition under TSTStageAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL bool TstZeroPosition(void);

/*!
 *  \brief      Call this function to obtain the controllers' name.
 *  \return     Returns a pointer to a NULL terminated char array holding the name.
 *  \remark     Replace this call with GetControllerName under ControllerAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL char* GetControllerName();

/*!
 *  \brief      Call this function to obtain the controllers' serial number.
 *  \return     Returns a pointer to a NULL terminated char array holding the serial number.
 *  \remark     Replace this call with GetControllerSerial under ControllerAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL char* GetControllerSerial();

/*!
 *  \brief      Call this function to obtain the version number for the SDK.
 *  \return     Returns a pointer to a NULL terminated char array holding the version number.
 *  \remark     Replace this call with GetVersion in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL char* GetDllVersion();

/*!
 *  \brief      This function is no longer supported by the LinkamSDK. This version has no wrapper
 *              library as the Mono service has been replaced by dedicated platforms for Mircosoft
 *              Windows and Linux operating systems.
 *
 *              This function use to handle obtaining the C wrapper version around the Mono - SDK Dll
 *              service.
 *
 *  \return     Returns a NULL pointer.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL char* GetWrapperVersion(void);

/*!
 *  \brief      This function is no longer supported by the LinkamSDK. This version has no wrapper
 *              library as the Mono service has been replaced by dedicated platforms for Mircosoft
 *              Windows and Linux operating systems.
 *
 *              This function use to handle activating the event handling service on Mono.
 *
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL void StartEvents();

/*!
 *  \brief      This function is no longer supported by the LinkamSDK. This version has no wrapper
 *              library as the Mono service has been replaced by dedicated platforms for Mircosoft
 *              Windows and Linux operating systems.
 *
 *              This function use to handle deactivating the event handling service on Mono.
 *
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL void StopEvents();

/*!
 *  \brief      This function is no longer supported by the LinkamSDK. This version does the same job
 *              as SetNewValueCallback under EventAPI.h in the latest API.
 *
 *              Call this function to add a callback function to receive new value event signals.
 *
 *  \remark     Replace this call with SetCallbackNewValue under EventAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL void SetNewValueCallback(eventNewValueCallback callback);

/*!
 *  \brief      This function is no longer supported by the LinkamSDK. This version does the same job
 *              as SetControllerConnectedCallback under EventAPI.h in the latest API.
 *
 *              Call this function to add a callback function to receive connected event signals.
 *
 *  \remark     Replace this call with SetCallbackControllerConnected under EventAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL void SetControllerConnectedCallback(eventCallback callback);

/*!
 *  \brief      This function is no longer supported by the LinkamSDK. This version does the same job
 *              as SetControllerDisconnectedCallback under EventAPI.h in the latest API.
 *
 *              Call this function to add a callback function to receive disconnected event signals.
 *
 *  \remark     Replace this call with SetCallbackControllerDisconnected under EventAPI.h in the latest API.
 *  \warning    This type will be removed in future versions.
 *
 *  @ingroup    Deprecated_Functions
 */
LINKAM_API_CALL void SetControllerDisconnectedCallback(eventCallback callback);

#endif // LINKAM__SDK__DEPRECATED_API_H


