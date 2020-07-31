cd "$(INSTALL)"

epicsEnvSet "EPICS_TS_MIN_WEST", '0'


# Loading libraries
# -----------------

# Device initialisation
# ---------------------

cd "$(INSTALL)"

dbLoadDatabase "dbd/example.dbd"
example_registerRecordDeviceDriver(pdbbase)

# Linkam 3.0 connect
linkamConnect "EA-LINKAM-01_AP", "/dev/ttyUSB0"

# Final ioc initialisation
# ------------------------
cd "$(INSTALL)"
dbLoadRecords 'db/example_expanded.db'
iocInit
