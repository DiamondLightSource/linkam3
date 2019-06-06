#!../../bin/linux-x86_64/linkamT96

cd ../..

dbLoadDatabase "dbd/linkamT96.dbd"
linkamT96_registerRecordDeviceDriver pdbbase

linkamConnect "linkamT96Port" "/dev/ttyUSB0"

dbLoadRecords "db/linkam.db" "PORT=linkamT96Port,P=linkamT96,ADDR=0,TIMEOUT=1"

cd startup

iocInit

