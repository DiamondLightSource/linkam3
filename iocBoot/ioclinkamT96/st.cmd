## Example vxWorks startup file

## The following is needed if your board support package doesn't at boot time
## automatically cd to the directory containing its startup script
#cd "/home/oli99962/t96/iocBoot/ioclinkamT96"

< cdCommands
#< ../nfsCommands

cd topbin

## You may have to change linkamT96 to something else
## everywhere it appears in this file
ld 0,0, "linkamT96.munch"

## Register all support components
cd top
dbLoadDatabase "dbd/linkamT96.dbd"
linkamT96_registerRecordDeviceDriver pdbbase

## Load record instances
#dbLoadTemplate "db/linkamT96.substitutions"
#dbLoadRecords "db/linkamT96.db", "user=oli99962"

cd startup
iocInit

## Start any sequence programs
#seq &sncxxx, "user=oli99962"
