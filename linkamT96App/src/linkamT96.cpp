#include <epicsExport.h>
#include <epicsTime.h>
#include <iocsh.h>
#include <stdio.h>
#include <string.h>
#include "include/LinkamSDK.h"
#include "linkamT96.h"

CommsHandle handle = 0;

static const char *driverName = "linkamT96Driver";

/*
 *
 */
linkamPortDriver::linkamPortDriver(const char *portName)
	: asynPortDriver(portName,
			 1, /* maxAddr */
			 NUM_LINKAM_PARAMS,
			 asynFloat64Mask | asynInt32Mask | asynOctetMask | asynDrvUserMask, /* Interface mask */
			 asynFloat64Mask | asynInt32Mask | asynOctetMask, /* Interrupt mask */
			 0, /* asynFlags */
			 1, /* Autoconnect */
			 0, /* Default priority */
			 0) /* Default stack size */
{
	(void) LinkamSDK::ControllerErrorStrings;

	createParam(P_TempString,        asynParamFloat64, &P_Temp);
	createParam(P_RampRateSetString, asynParamFloat64, &P_RampRateSet);
	createParam(P_RampRateString,    asynParamFloat64, &P_RampRate);
	createParam(P_LimitSetString,    asynParamFloat64, &P_LimitSet);
	createParam(P_LimitString,       asynParamFloat64, &P_Limit);
	createParam(P_PowerString,       asynParamFloat64, &P_Power);
	createParam(P_StartHeatingString,asynParamInt32,   &P_StartHeating);
	createParam(P_LNPSpeedString,    asynParamFloat64, &P_LNPSpeed);
	createParam(P_DSCString,         asynParamFloat64, &P_DSC);
	createParam(P_HoldTimeSetString, asynParamInt32,   &P_HoldTimeSet);
	createParam(P_HoldTimeLeftString,asynParamInt32,   &P_HoldTimeLeft);
	createParam(P_LNPSetSpeedString, asynParamInt32,   &P_LNPSetSpeed);
	createParam(P_LNPSetModeString,  asynParamInt32,   &P_LNPSetMode);
	createParam(P_NameString,        asynParamOctet,   &P_Name);
	createParam(P_SerialString,      asynParamOctet,   &P_Serial);
	createParam(P_StageNameString,   asynParamOctet,   &P_StageName);
	createParam(P_StageSerialString, asynParamOctet,   &P_StageSerial);
	createParam(P_FirmVerString,     asynParamOctet,   &P_FirmVer);
	createParam(P_HardVerString,     asynParamOctet,   &P_HardVer);
	createParam(P_CtrlConfigString,  asynParamInt32,   &P_CtrlConfig);
	createParam(P_CtrlStatusString,  asynParamInt32,   &P_CtrlStatus);
	createParam(P_StageConfigString, asynParamInt32,   &P_StageConfig);
}

asynStatus linkamPortDriver::readFloat64(asynUser *pasynUser, epicsFloat64 *value)
{
	LinkamSDK::Variant param1;
	LinkamSDK::Variant param2;
	LinkamSDK::Variant result;
	int function = pasynUser->reason;
	epicsTimeStamp timeStamp;
	const char *functionName = "readFloat64";
	asynStatus status = asynSuccess;

	getTimeStamp(&timeStamp);
	pasynUser->timestamp = timeStamp;

	if (function == P_Temp) {
		param1.vStageValueType = LinkamSDK::eStageValueTypeHeater1Temp;
	} else if (function == P_RampRate) {
		param1.vStageValueType = LinkamSDK::eStageValueTypeHeater1Rate;
	} else if (function == P_Limit) {
		param1.vStageValueType = LinkamSDK::eStageValueTypeHeater1Limit;
	} else if (function == P_Power) {
		param1.vStageValueType = LinkamSDK::eStageValueTypeHeater1Power;
	} else if (function == P_LNPSpeed) {
		param1.vStageValueType = LinkamSDK::eStageValueTypeHeater1LNPSpeed;
	} else if (function == P_DSC) {
		param1.vStageValueType = LinkamSDK::eStageValueTypeDsc;
	} else if (function == P_HoldTimeLeft) {
        	param1.vStageValueType = LinkamSDK::eStageValueTypeRamp1HoldRemaining;
	}

	if (linkamProcessMessage(LinkamSDK::eLinkamFunctionMsgCode_GetValue, handle, &result, param1, param2))
		*value = result.vFloat32;
	else
		status = asynError;

	if (status)
		epicsSnprintf(pasynUser->errorMessage, pasynUser->errorMessageSize,
			"%s:%s: status=%d, function=%d",
			driverName, functionName, status, function);
	else
		asynPrint(pasynUser, ASYN_TRACEIO_DRIVER,
			"%s:%s: function=%d\n",
			driverName, functionName, function);

	return status;
}

asynStatus linkamPortDriver::readOctet(asynUser *pasynUser, char *value, size_t maxChars, size_t *nActual, int *eomReason)
{
	LinkamSDK::Variant param1;
	LinkamSDK::Variant param2;
	LinkamSDK::Variant result;
	enum LinkamSDK::LinkamFunctionMsgCode linkamMsgCode = LinkamSDK::eLinkamFunctionMsgCode_GetControllerName;
	char string[256];
	int function = pasynUser->reason;
	epicsTimeStamp timeStamp;
	const char *functionName = "readOctet";
	(void)functionName;
	asynStatus status = asynSuccess;

	getTimeStamp(&timeStamp);
	pasynUser->timestamp = timeStamp;

	if (function == P_Serial) {
		linkamMsgCode = LinkamSDK::eLinkamFunctionMsgCode_GetControllerSerial;
	} else if (function == P_Name) {
		linkamMsgCode = LinkamSDK::eLinkamFunctionMsgCode_GetControllerName;
	} else if (function == P_StageSerial) {
		linkamMsgCode = LinkamSDK::eLinkamFunctionMsgCode_GetStageSerial;
	} else if (function == P_StageName) {
		linkamMsgCode = LinkamSDK::eLinkamFunctionMsgCode_GetStageName;
	} else if (function == P_FirmVer) {
		linkamMsgCode = LinkamSDK::eLinkamFunctionMsgCode_GetControllerFirmwareVersion;
	} else if (function == P_HardVer) {
		linkamMsgCode = LinkamSDK::eLinkamFunctionMsgCode_GetControllerHardwareVersion;
	}

	result.vUint64 = 0;
	param1.vPtr = string;
	param2.vUint32 = 256;
	if (linkamProcessMessage(linkamMsgCode, handle, &result, param1, param2)) {
		rtrim(string);
		setStringParam(function, string);

		*nActual = strlen(string) + 1;
		*eomReason = 0;
	} else {
		status = asynError;
	}

	if (status)
		epicsSnprintf(pasynUser->errorMessage, pasynUser->errorMessageSize,
			"%s:%s: status=%d, function=%d",
			driverName, functionName, status, function);
	else
		asynPrint(pasynUser, ASYN_TRACEIO_DRIVER,
			"%s:%s: function=%d\n",
			driverName, functionName, function);

	return status; 
}

void linkamPortDriver::rtrim(char *s) {
	int i;
	for (i = strlen(s); s[i-1] == ' ' || s[i-1] == '\t'; --i)
		;
	s[i] = '\0';
}

asynStatus linkamPortDriver::writeFloat64(asynUser *pasynUser, epicsFloat64 value)
{
	LinkamSDK::Variant param1;
	LinkamSDK::Variant param2;
	LinkamSDK::Variant result;
	int function = pasynUser->reason;
	const char *functionName = "writeFloat64";
	asynStatus status = asynSuccess;

	if (function == P_RampRateSet) {
		param1.vStageValueType = LinkamSDK::eStageValueTypeHeater1Rate;
	} else if (function == P_LimitSet) {
        	param1.vStageValueType = LinkamSDK::eStageValueTypeHeater1Limit;
	} else if (function == P_HoldTimeSet) {
        	param1.vStageValueType = LinkamSDK::eStageValueTypeRamp1HoldTime;
	}

	param2.vFloat32 = value;
	linkamProcessMessage(LinkamSDK::eLinkamFunctionMsgCode_SetValue, handle, &result, param1, param2);

	if (!result.vBoolean) {
		status = asynError;
	}

	if (status)
		epicsSnprintf(pasynUser->errorMessage, pasynUser->errorMessageSize,
			"%s:%s: status=%d, function=%d",
			driverName, functionName, status, function);
	else
		asynPrint(pasynUser, ASYN_TRACEIO_DRIVER,
			"%s:%s: function=%d\n",
			driverName, functionName, function);

	return status;
}

asynStatus linkamPortDriver::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
	LinkamSDK::Variant param1;
	LinkamSDK::Variant param2;
	LinkamSDK::Variant result;
	int function = pasynUser->reason;
	const char *functionName = "writeInt32";
	asynStatus status = asynSuccess;

	if (function == P_StartHeating) {
		param2.vUint64 = 0; /* unused */

		if (value > 0)
			param1.vBoolean = true;
		else
			param1.vBoolean = false;

		linkamProcessMessage(LinkamSDK::eLinkamFunctionMsgCode_StartHeating,
		                     handle, &result, param1, param2);
		
		if (!result.vBoolean) {
			status = asynError;
		}
	} else if (function == P_LNPSetMode) {
		param2.vUint64 = 0; /* unused */

		if (value > 0)
			LNP_AutoMode = param1.vBoolean = true;
		else
			LNP_AutoMode = param1.vBoolean = false;

		linkamProcessMessage(LinkamSDK::eLinkamFunctionMsgCode_LnpSetMode, handle, &result, param1, param2);

		if (result.vBoolean) {
			if (!LNP_AutoMode) { /* Manual Mode, set LNP speed to LNP_ManualSpeed */
				param1.vUint32 = LNP_ManualSpeed;

				linkamProcessMessage(LinkamSDK::eLinkamFunctionMsgCode_LnpSetSpeed,
				                     handle, &result, param1, param2);
			}
		} else {
			status = asynError;
		}
	} else if (function == P_LNPSetSpeed) {
		param2.vUint64 = 0; /* unused */

		if (value < 0)
			value = 0;
		else if (value > 100)
			value = 100;

		LNP_ManualSpeed = value;

		if (!LNP_AutoMode) {

			param1.vUint32 = value;

			linkamProcessMessage(LinkamSDK::eLinkamFunctionMsgCode_LnpSetSpeed, handle, &result, param1, param2);

			if (!result.vBoolean) {
				status = asynError;
			}
		}
	}

	if (status)
		epicsSnprintf(pasynUser->errorMessage, pasynUser->errorMessageSize,
			"%s:%s: status=%d, function=%d",
			driverName, functionName, status, function);
	else
		asynPrint(pasynUser, ASYN_TRACEIO_DRIVER,
			"%s:%s: function=%d\n",
			driverName, functionName, function);

	return status;
}

asynStatus linkamPortDriver::readInt32(asynUser *pasynUser, epicsInt32 *value)
{
	LinkamSDK::Variant param1;
	LinkamSDK::Variant param2;
	LinkamSDK::Variant result;
	int function = pasynUser->reason;
	const char *functionName = "readInt32";
	asynStatus status = asynSuccess;

	if (function == P_CtrlConfig) {
		if (linkamProcessMessage(LinkamSDK::eLinkamFunctionMsgCode_GetControllerConfig, handle, &result)) {
			*value =
			      /* result.vControllerConfig.flags.supportsHeater                      << 0  |
				 result.vControllerConfig.flags.supportsDualHeater                  << 1  |
				 result.vControllerConfig.flags.supportsDualHeaterIndependentLimits << 2  |
				 result.vControllerConfig.flags.supportsDualHeaterIndependentRates  << 3  |
				 result.vControllerConfig.flags.vacuumOption                        << 4  |
				 result.vControllerConfig.flags.tensileForceCardReady               << 5  |*/
				 result.vControllerConfig.flags.dscCardReady                        << 0  |
			       /*result.vControllerConfig.flags.xMotorCardReady                     << 7  |
				 result.vControllerConfig.flags.yMotorCardReady                     << 8  |
				 result.vControllerConfig.flags.zMotorCardReady                     << 9  |
				 result.vControllerConfig.flags.motorValveCardReady                 << 7  |
				 result.vControllerConfig.flags.tensileMotorCardReady               << 8  |
				 result.vControllerConfig.flags.gradedMotorCardReady                << 9  |
				 result.vControllerConfig.flags.dtcCardReady                        << 7  |
				 result.vControllerConfig.flags.cssMotorCardReady                   << 8  |*/
				 result.vControllerConfig.flags.lnpReady                            << 1/*|
				 result.vControllerConfig.flags.lnpDualReady                        << 2  |
				 result.vControllerConfig.flags.humidityReady                       << 3*/;
		} else {
			status = asynError;
		}
	} else if (function == P_CtrlStatus) {
		if (linkamProcessMessage(LinkamSDK::eLinkamFunctionMsgCode_GetStatus, handle, &result)) { 
			*value = result.vControllerStatus.flags.controllerError               << 0  |
				 result.vControllerStatus.flags.heater1RampSetPoint           << 1  |
				 result.vControllerStatus.flags.heater1Started                << 2  |
			       /*result.vControllerStatus.flags.heater2RampSetPoint           << 3  |
				 result.vControllerStatus.flags.heater2Started                << 4  |
				 result.vControllerStatus.flags.vacuumRampSetPoint            << 5  |
				 result.vControllerStatus.flags.vacuumCtrlStarted             << 6  |
				 result.vControllerStatus.flags.vacuumValveClosed             << 7  |
				 result.vControllerStatus.flags.vacuumValveOpen               << 8  |
				 result.vControllerStatus.flags.humidityRampSetPoint          << 3  |
				 result.vControllerStatus.flags.humidityCtrlStarted           << 4  |*/
				 result.vControllerStatus.flags.lnpCoolingPumpOn              << 3  |
				 result.vControllerStatus.flags.lnpCoolingPumpAuto            << 4  |
				 result.vControllerStatus.flags.ramp1                         << 5  |
			       /*result.vControllerStatus.flags.HumidityDesiccantConditioning << 13 |
				 result.vControllerStatus.flags.motorTravelMinX               << 14 |
				 result.vControllerStatus.flags.motorTravelMaxX               << 15 |
				 result.vControllerStatus.flags.motorStoppedX                 << 16 |
				 result.vControllerStatus.flags.motorTravelMinY               << 17 |
				 result.vControllerStatus.flags.motorTravelMaxY               << 18 |
				 result.vControllerStatus.flags.motorStoppedY                 << 19 |
				 result.vControllerStatus.flags.motorTravelMinZ               << 20 |
				 result.vControllerStatus.flags.motorTravelMaxZ               << 21 |
				 result.vControllerStatus.flags.motorStoppedZ                 << 22 |*/
				 result.vControllerStatus.flags.sampleCal                     << 6;
			       /*result.vControllerStatus.flags.motorDistanceCalTST           << 24 |
				 result.vControllerStatus.flags.cssRotMotorStopped            << 8  |
				 result.vControllerStatus.flags.cssGapMotorStopped            << 9  |
				 result.vControllerStatus.flags.cssLidOn                      << 10 |
				 result.vControllerStatus.flags.cssRefLimit                   << 11 |
				 result.vControllerStatus.flags.cssZeroLimit                  << 12;*/
		} else {
			status = asynError;
		}
	} else if (function == P_StageConfig) {
		if (linkamProcessMessage(LinkamSDK::eLinkamFunctionMsgCode_GetStageConfig, handle, &result)) {
			*value = result.vStageConfig.flags.standardStage               << 0  |
			       /*result.vStageConfig.flags.highTempStage               << 1  |
				 result.vStageConfig.flags.peltierStage                << 2  |
				 result.vStageConfig.flags.gradedStage                 << 3  |
				 result.vStageConfig.flags.tensileStage                << 4  |*/
				 result.vStageConfig.flags.dscStage                    << 1  |
			       /*result.vStageConfig.flags.warmStage                   << 6  |
				 result.vStageConfig.flags.itoStage                    << 7  |
				 result.vStageConfig.flags.css450Stage                 << 8  |
				 result.vStageConfig.flags.correlativeStage            << 9  |*/
				 result.vStageConfig.flags.coolingManual               << 2  |
				 result.vStageConfig.flags.coolingAutomatic            << 3  |
			       /*result.vStageConfig.flags.coolingDual                 << 12 |
				 result.vStageConfig.flags.coolingDualSpeedIndependent << 13 |
				 result.vStageConfig.flags.heater1                     << 14 |
				 result.vStageConfig.flags.heater1TempCtrl             << 15 |
				 result.vStageConfig.flags.heater1TempCtrlProbe        << 16 |
				 result.vStageConfig.flags.heater2                     << 17 |
				 result.vStageConfig.flags.heater12IndependentLimits   << 18 |
				 result.vStageConfig.flags.waterCoolingSensorFitted    << 19 |
				 result.vStageConfig.flags.home                        << 20 |
				 result.vStageConfig.flags.supportsVacuum              << 21 |
				 result.vStageConfig.flags.motorX                      << 22 |
				 result.vStageConfig.flags.motorY                      << 23 |
				 result.vStageConfig.flags.motorZ                      << 24 |*/
				 result.vStageConfig.flags.supportsHumidity            << 4;
		} else {
			status = asynError;
		}
	}

	if (status)
		epicsSnprintf(pasynUser->errorMessage, pasynUser->errorMessageSize,
			"%s:%s: status=%d, function=%d",
			driverName, functionName, status, function);
	else
		asynPrint(pasynUser, ASYN_TRACEIO_DRIVER,
			"%s:%s: function=%d\n",
			driverName, functionName, function);

	return status;
}

/*
 * linkamStatus
 */
static const iocshArg * const linkamStatus_Args[0] = {};
static const iocshFuncDef linkamStatus_FuncDef = { "linkamStatus", 0, linkamStatus_Args };

static void linkamStatus_CallFunc(const iocshArgBuf *args)
{
	(void)args;
	LinkamSDK::Variant result;
	linkamProcessMessage(LinkamSDK::eLinkamFunctionMsgCode_GetStatus, handle, &result);

	printf("controllerError               = %d\n", result.vControllerStatus.flags.controllerError);
	printf("heater1RampSetPoint           = %d\n", result.vControllerStatus.flags.heater1RampSetPoint);
	printf("heater1Started                = %d\n", result.vControllerStatus.flags.heater1Started);
	printf("heater2RampSetPoint           = %d\n", result.vControllerStatus.flags.heater2RampSetPoint);
	printf("heater2Started                = %d\n", result.vControllerStatus.flags.heater2Started);
	printf("vacuumRampSetPoint            = %d\n", result.vControllerStatus.flags.vacuumRampSetPoint);
	printf("vacuumCtrlStarted             = %d\n", result.vControllerStatus.flags.vacuumCtrlStarted);
	printf("vacuumValveClosed             = %d\n", result.vControllerStatus.flags.vacuumValveClosed);
	printf("vacuumValveOpen               = %d\n", result.vControllerStatus.flags.vacuumValveOpen);
	printf("humidityRampSetPoint          = %d\n", result.vControllerStatus.flags.humidityRampSetPoint);
	printf("humidityCtrlStarted           = %d\n", result.vControllerStatus.flags.humidityCtrlStarted);
	printf("lnpCoolingPumpOn              = %d\n", result.vControllerStatus.flags.lnpCoolingPumpOn);
	printf("lnpCoolingPumpAuto            = %d\n", result.vControllerStatus.flags.lnpCoolingPumpAuto);
	printf("HumidityDesiccantConditioning = %d\n", result.vControllerStatus.flags.HumidityDesiccantConditioning);
	printf("motorTravelMinX               = %d\n", result.vControllerStatus.flags.motorTravelMinX);
	printf("motorTravelMaxX               = %d\n", result.vControllerStatus.flags.motorTravelMaxX);
	printf("motorStoppedX                 = %d\n", result.vControllerStatus.flags.motorStoppedX);
	printf("motorTravelMinY               = %d\n", result.vControllerStatus.flags.motorTravelMinY);
	printf("motorTravelMaxY               = %d\n", result.vControllerStatus.flags.motorTravelMaxY);
	printf("motorStoppedY                 = %d\n", result.vControllerStatus.flags.motorStoppedY);
	printf("motorTravelMinTST             = %d\n", result.vControllerStatus.flags.motorTravelMinZ);
	printf("motorTravelMaxTST             = %d\n", result.vControllerStatus.flags.motorTravelMaxZ);
	printf("motorStoppedTST               = %d\n", result.vControllerStatus.flags.motorStoppedZ);
	printf("sampleCal                     = %d\n", result.vControllerStatus.flags.sampleCal);
	printf("motorDistanceCalTST           = %d\n", result.vControllerStatus.flags.motorDistanceCalTST);
	printf("cssRotMotorStopped            = %d\n", result.vControllerStatus.flags.cssRotMotorStopped);
	printf("cssGapMotorStopped            = %d\n", result.vControllerStatus.flags.cssGapMotorStopped);
	printf("cssLidOn                      = %d\n", result.vControllerStatus.flags.cssLidOn);
	printf("cssRefLimit                   = %d\n", result.vControllerStatus.flags.cssRefLimit);
	printf("cssZeroLimit                  = %d\n", result.vControllerStatus.flags.cssZeroLimit);
}


/*
 * linkamConnect
 */
static const iocshArg linkamConnect_Arg0 = { "asynPort", iocshArgString };
static const iocshArg linkamConnect_Arg1 = { "serialPort", iocshArgString };
static const iocshArg * const linkamConnect_Args[] = { &linkamConnect_Arg0, &linkamConnect_Arg1 };
static const iocshFuncDef linkamConnect_FuncDef = { "linkamConnect", 2, linkamConnect_Args };

static void linkamConnect_CallFunc(const iocshArgBuf *args)
{
	LinkamSDK::CommsInfo info;
	LinkamSDK::Variant param1;
	LinkamSDK::Variant param2;
	LinkamSDK::Variant result;

	if (linkamInitialiseSDK())
		printf("LinkamT96: linkamInitialiseSDK successful\n");
	else
		printf("LinkamT96: ERROR @ linkamInitialiseSDK\n");

	char version[256];
	linkamGetVersion(version, 256);
	printf("Linkam SDK version: %s\n", version);

	linkamInitialiseSerialCommsInfo(&info, args[1].sval);

	param1.vPtr = &info;
	param2.vPtr = &handle;

	linkamProcessMessage(LinkamSDK::eLinkamFunctionMsgCode_OpenComms, 0, &result, param1, param2);


        if (result.vConnectionStatus.flags.connected) {
                printf("LinkamT96: We got a connection to the Serial device!\n");
        } else {
                printf( "Error openning connection:\n\nstatus.connected = %d\nstatus.flags.errorAllocationFailed = %d\nstatus.flags.errorAlreadyOpen = %d\nstatus.flags.errorCommsStreams = %d\nstatus.flags.errorHandleRegistrationFailed = %d\nstatus.flags.errorMultipleDevicesFound = %d\nstatus.flags.errorNoDeviceFound = %d\nstatus.flags.errorPortConfig = %d\nstatus.flags.errorPropertiesIncorrect = %d\nstatus.flags.errorSerialNumberRequired = %d\nstatus.flags.errorTimeout = %d\nstatus.flags.errorUnhandled = %d\n\n", result.vConnectionStatus.flags.connected, result.vConnectionStatus.flags.errorAllocationFailed, result.vConnectionStatus.flags.errorAlreadyOpen, result.vConnectionStatus.flags.errorCommsStreams, result.vConnectionStatus.flags.errorHandleRegistrationFailed, result.vConnectionStatus.flags.errorMultipleDevicesFound, result.vConnectionStatus.flags.errorNoDeviceFound, result.vConnectionStatus.flags.errorPortConfig, result.vConnectionStatus.flags.errorPropertiesIncorrect, result.vConnectionStatus.flags.errorSerialNumberRequired, result.vConnectionStatus.flags.errorTimeout, result.vConnectionStatus.flags.errorUnhandled);
		return;
        }

	new linkamPortDriver(args[0].sval);
}

/*
 * iocshRegister
 */

void linkamRegistrar(void)
{
	iocshRegister(&linkamStatus_FuncDef, linkamStatus_CallFunc);
	iocshRegister(&linkamConnect_FuncDef, linkamConnect_CallFunc);
}

extern "C" {
	epicsExportRegistrar(linkamRegistrar);
}
