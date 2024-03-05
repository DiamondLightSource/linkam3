#include "asynPortDriver.h"
#include <epicsEvent.h>

#define P_TempString          "LINKAM_TEMP"
#define P_RampRateSetString   "LINKAM_RAMPRATE_SET"
#define P_RampRateString      "LINKAM_RAMPRATE"
#define P_SetpointSetString   "LINKAM_SETPOINT_SET"
#define P_SetpointString      "LINKAM_SETPOINT"
#define P_PowerString         "LINKAM_POWER"
#define P_StartHeatingString  "LINKAM_START_HEATING"
#define P_LNPSpeedString      "LINKAM_LNP_SPEED"
#define P_DSCString           "LINKAM_DSC"
#define P_LNPSetModeString    "LINKAM_LNP_MODE_SET"
#define P_LNPSetSpeedString   "LINKAM_LNP_SPEED_SET"
#define P_HoldTimeSetString   "LINKAM_HOLD_TIME_SET"
#define P_HoldTimeLeftString  "LINKAM_HOLD_TIME_LEFT"
#define P_StageNameString     "LINKAM_STAGE_NAME"
#define P_StageSerialString   "LINKAM_STAGE_SERIAL"
#define P_FirmVerString       "LINKAM_FIRM_VERSION"
#define P_HardVerString       "LINKAM_HARD_VERSION"
#define P_CtrllrErrorString   "LINKAM_CTRLLR_ERROR"
#define P_CtrlConfigString    "LINKAM_CONFIG"
#define P_CtrlStatusString    "LINKAM_STATUS"
#define P_StageConfigString   "LINKAM_STAGE_CONFIG"
#define P_VacuumChamberString "LINKAM_VAC_CHAMBER"
#define P_VacuumData1String   "LINKAM_VAC_DATA1"
#define P_NameString          "LINKAM_NAME"
#define P_SerialString        "LINKAM_SERIAL"

// Tensile stage parameters
#define P_TstMotorPosString     "LINKAM_TSTP_RBV"
#define P_ForceString           "LINKAM_FORCE"
#define P_MaxForceString        "LINKAM_MAX_FORCE"
#define P_TstMtrVelSetString    "LINKAM_TST_MTR_VEL_SET"
#define P_TstMtrVelString       "LINKAM_TST_MTR_VEL"
#define P_TstMtrDistSPSetString    "LINKAM_TST_MTR_DIST_SP_SET"
#define P_TstMtrDistSPString       "LINKAM_TST_MTR_DIST_SP"
#define P_ForceSetpointSetString "LINKAM_FORCE_SETPOINT_SET"
#define P_ForceSetpointString   "LINKAM_FORCE_SETPOINT"
#define P_ForceGaugeString      "LINKAM_FORCE_GAUGE"
#define P_JawToJawSizeSetString "LINKAM_JAW_TO_JAW_SIZE_SET"
#define P_JawToJawSizeString    "LINKAM_JAW_TO_JAW_SIZE"
#define P_TstTableDirSetString  "LINKAM_TST_TABLE_DIR_SET"
#define P_TstTableDirString     "LINKAM_TST_TABLE_DIR"
#define P_SampleWidthSetString  "LINKAM_SAMPLE_WIDTH_SET"
#define P_SampleWidthString     "LINKAM_SAMPLE_WIDTH"
#define P_SampleThicknessSetString "LINKAM_SAMPLE_THICKNESS_SET"
#define P_SampleThicknessString "LINKAM_SAMPLE_THICKNESS"
#define P_SampleSizeSetString   "LINKAM_SAMPLE_SIZE_SET"
#define P_SampleSizeString      "LINKAM_SAMPLE_SIZE"
#define P_StrainEguSetString    "LINKAM_STRAIN_EGU_SET"
#define P_StrainEguString       "LINKAM_STRAIN_EGU"
#define P_StrainPercentageSetString "LINKAM_STRAIN_PERCENTAGE_SET"
#define P_StrainPercentageString "LINKAM_STRAIN_PERCENTAGE"
#define P_ShowForceAsDistSetString "LINKAM_SHOW_FORCE_AS_DIST_SET"
#define P_ShowForceAsDistString "LINKAM_SHOW_FORCE_AS_DIST"
#define P_CalForceValSetString  "LINKAM_CAL_FORCE_VAL_SET"
#define P_JawPositionString     "LINKAM_JAW_POSITION"
#define P_StrainString          "LINKAM_STRAIN"
#define P_StressString          "LINKAM_STRESS"
#define P_TstTableModeSetString "LINKAM_TST_TABLE_MODE_SET"
#define P_TstTableModeString    "LINKAM_TST_TABLE_MODE"
#define P_TstDefaultMtrSpeedSetString "LINKAM_TST_DEFAULT_MTR_SPEED_SET"
#define P_TstDefaultMtrSpeedString "LINKAM_TST_DEFAULT_MTR_SPEED"
#define P_TstGaugeCompliancySetString "LINKAM_TST_GAUGE_COMPLIANCY_SET"
#define P_TstMaxJawPosSetString "LINKAM_TST_MAX_JAW_POS_SET"
#define P_TstMaxJawPosString    "LINKAM_TST_MAX_JAW_POS"
#define P_TstMinJawPosSetString "LINKAM_TST_MIN_JAW_POS_SET"
#define P_TstMinJawPosString    "LINKAM_TST_MIN_JAW_POS"
#define P_TstRawMotorPosString  "LINKAM_TST_RAW_MOTOR_POS"
#define P_TstJawMonitorSetString "LINKAM_TST_JAW_MONITOR_SET"
#define P_TstJawMonitorString   "LINKAM_TST_JAW_MONITOR"
#define P_TstCycleCountLimSetString "LINKAM_TST_CYCLE_COUNT_LIM_SET"
#define P_TstCycleCountLimString "LINKAM_TST_CYCLE_COUNT_LIM"
#define P_TstCyclesRemainingString "LINKAM_TST_CYCLES_REMAINING"
#define P_TstStatusString           "LINKAM_TST_STATUS"
#define P_TstCalibDistanceString "LINKAM_TST_CALIB_DIST"
#define P_TstZeroDistanceString "LINKAM_TST_ZERO_DISTANCE"
#define P_TstZeroForceString "LINKAM_TST_ZERO_FORCE"
#define P_TstStartMotorString "LINKAM_TST_START_MOTOR"
#define P_TstForceKpString "LINKAM_TST_FORCE_KP"
#define P_TstForceKiString "LINKAM_TST_FORCE_KI"
#define P_TstForceKdString "LINKAM_TST_FORCE_KD"

// Position motor variables
#define P_TstpVeloString "LINKAM_TSTP_VELO"
#define P_TstpValString "LINKAM_TSTP_VAL"

// Force motor variables 
#define P_TstfValString "LINKAM_TSTF_VAL"

// Vacuum stage parameters
#define P_StartVacuumString   "LINKAM_START_VACUUM"
#define P_VacuumSetString     "LINKAM_VACUUM_SET"
#define P_VacuumString        "LINKAM_VACUUM"
#define P_VacuumUnitSetString "LINKAM_VACUUM_UNIT_SET"
#define P_VacuumUnitString    "LINKAM_VACUUM_UNIT"
#define P_PressureString      "LINKAM_PRESSURE"

struct PositionMotorParams
{
	float demandPosition;
	float demandVelocity;
    float stepSize;
	float jawToJawZero;
};

struct ForceMotorParams
{
	float demandForce;
    float stepSize;
};

class linkamPortDriver : public asynPortDriver {
public:
	linkamPortDriver(const char *);
    asynStatus SetTstGotoMode(float position, float vel);
    asynStatus SetTstForceMode(float force);
	virtual asynStatus readFloat64(asynUser *, epicsFloat64 *);
	virtual asynStatus readOctet(asynUser *, char *, size_t, size_t *, int *);
	virtual asynStatus writeFloat64(asynUser *, epicsFloat64);
	virtual asynStatus writeInt32(asynUser *, epicsInt32);
	virtual asynStatus readInt32(asynUser *, epicsInt32 *);
protected:
	//epicsEventId eventId_;
	int P_Temp;
	#define FIRST_LINKAM_COMMAND P_Temp
	int P_RampRateSet;
	int P_RampRate;
	int P_SetpointSet;
	int P_Setpoint;
	int P_Power;
	int P_StartHeating;
	int P_LNPSpeed;
	int P_DSC;
	int P_LNPSetMode;
	int P_LNPSetSpeed;
	int P_HoldTimeSet;
	int P_HoldTimeLeft;
	int P_StageName;
	int P_StageSerial;
	int P_FirmVer;
	int P_HardVer;
	int P_CtrllrError;
	int P_CtrlConfig;
	int P_CtrlStatus;
	int P_StageConfig;
	int P_VacuumChamber;
	int P_VacuumData1;
	int P_Name;
	int P_Serial;
    // Tensile stage parameters
    int P_TstMotorPos;
    int P_Force;
    int P_MaxForce;
    int P_TstMtrVelSet;
    int P_TstMtrVel;
    int P_TstMtrDistSPSet;
    int P_TstMtrDistSP;
    int P_ForceSetpointSet;
    int P_ForceSetpoint;
    int P_ForceGauge;
    int P_JawToJawSizeSet;
    int P_JawToJawSize;
    int P_TstTableDirSet;
    int P_TstTableDir;
    int P_SampleWidthSet;
    int P_SampleWidth;
    int P_SampleThicknessSet;
    int P_SampleThickness;
    int P_SampleSizeSet;
    int P_SampleSize;
    int P_StrainEguSet;
    int P_StrainEgu;
    int P_StrainPercentageSet;
    int P_StrainPercentage;
    int P_ShowForceAsDistSet;
    int P_ShowForceAsDist;
    int P_CalForceValSet;
    int P_JawPosition;
    int P_Strain;
    int P_Stress;
    int P_TstTableModeSet;
    int P_TstTableMode;
    int P_TstDefaultMtrSpeedSet;
    int P_TstDefaultMtrSpeed;
    int P_TstGaugeCompliancySet;
    int P_TstMaxJawPosSet;
    int P_TstMaxJawPos;
    int P_TstMinJawPosSet;
    int P_TstMinJawPos;
    int P_TstRawMotorPos;
    int P_TstJawMonitorSet;
    int P_TstJawMonitor;
    int P_TstCycleCountLimSet;
    int P_TstCycleCountLim;
    int P_TstCyclesRemaining;
    int P_TstStatus;
    int P_TstCalibDistance;
    int P_TstZeroDistance;
    int P_TstZeroForce;
    int P_TstStartMotor;

    int P_TstForceKp;
    int P_TstForceKi;
    int P_TstForceKd;

    int P_TstpVelo;
    int P_TstpVal;

    int P_TstfVal;

    // Vacuum stage parameters
    int P_StartVacuum;
    int P_VacuumSet;
    int P_Vacuum;
    int P_VacuumUnitSet;
    int P_VacuumUnit;
    int P_Pressure;

    #define LAST_LINKAM_COMMAND P_Pressure

    // Connection functions
    bool initUSBConnection(unsigned int vendorID, unsigned int productID);
    bool initSerialConnection(const char* serialPort, 
                                unsigned int baudrate, 
                                unsigned int bytesize, 
                                unsigned int flowcontrol, 
                                unsigned int parity, 
                                unsigned int stopbits);

    // Status printing functions
    void printErrorConnectionStatus(LinkamSDK::Variant connectionResult);
    void printLinkam3Status();


private:
	void rtrim(char *);
	bool LNP_AutoMode;
	int LNP_ManualSpeed;
    PositionMotorParams pMotorParams;
    ForceMotorParams fMotorParams;
};

#define NUM_LINKAM_PARAMS (&LAST_LINKAM_COMMAND - &FIRST_LINKAM_COMMAND + 1)

