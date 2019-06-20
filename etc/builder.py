from iocbuilder import AutoSubstitution, Device
from iocbuilder.arginfo import *
from iocbuilder.modules.asyn import Asyn, AsynPort, AsynIP

class _LinkamT96Pars(AutoSubstitution):
    TemplateFile = "Linkam.template"

class LinkamT96(Device):

    Dependencies = (Asyn,)
    LibFileList = ['linkamT96']
    DbdFileList = ['linkamT96'] 

    def __init__(self, name, P, serial='/dev/ttyUSB0'):
        self.__dict__.update(locals())
	self.template = _LinkamT96Pars(PORT='{}_AP'.format(P), P=P, ADDR=0, TIMEOUT=1)
        self.__super.__init__()

    ArgInfo = makeArgInfo(__init__,
                          name=Simple("GUI name", str),
                          P=Simple("Device Prefix", str),
                          serial=Simple("Serial Device", str)
                          )

    def Initialise(self):
	print('# Linkam 3.0 connect')
        print('linkamConnect "{P}_AP", "{serial}"'.format(**self.__dict__))

