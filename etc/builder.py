from iocbuilder import AutoSubstitution, Device
from iocbuilder.arginfo import *
from iocbuilder.modules.asyn import Asyn, AsynPort, AsynIP


class _LinkamT96Pars(AutoSubstitution):
    TemplateFile = "Linkam.template"


class LinkamT96(Device):

    Dependencies = (Asyn,)
    LibFileList = ['linkamT96']
    DbdFileList = ['linkamT96Support']

    def __init__(
            self,
            name,
            P,
            serial_port='/dev/ttyUSB0',
            virtual_port=False,
            ip_address=None,
            ip_port=None,
            log_path="/dev/null"
        ):
        # Call super class
        self.__super.__init__()

        # Invoke template
        self.template = _LinkamT96Pars(
            PORT='{}_AP'.format(P),
            P=P,
            ADDR=0,
            TIMEOUT=1,
            name=name
        )

        # Store args for boot script
        self.P = P
        self.log_path = log_path
        self.serial_port = serial_port
        self.virtual_port = virtual_port
        self.ip_address = ip_address
        self.ip_port = ip_port

        # If we are instantiating a virtual port, then include the dbd support
        # for invoking system commands so we can use socat
        if self.virtual_port and 'systemCommandSupport' not in LinkamT96.DbdFileList:
            LinkamT96.DbdFileList += ['systemCommandSupport']

    ArgInfo = makeArgInfo(
        __init__,
        name=Simple("GUI name", str),
        P=Simple("Device Prefix", str),
        serial_port=Simple(
            "Path to real or virtual serial port (virtual is created at runtime)", str
        ),
        virtual_port=Simple(
            "Whether to create virtual port at runtime using socat (requires IP address and port)", bool
        ),
        ip_address=Simple(
            "IP address for virtual port to connect to using socat", str
        ),
        ip_port=Simple("IP port for virtual port to connect to using socat", int),
        log_path=Simple("Log file path for the Linkam SDK", str),
    )

    def Initialise(self):
        if self.virtual_port:
            # Check we have provided required args
            assert self.ip_address is not None, "IP address required for virtual port"
            assert self.ip_port is not None, "IP port required for virtual port"

            # Create our socat command to create virtual port to specified address
            virtual_port_string = (
                'system "socat pty,link={serial_port},waitslave '
                'tcp:{ip_address}:{ip_port}&"'
            )
            print('# Create virtual port using socat to connect to device')
            print(virtual_port_string.format(
                serial_port=self.serial_port,
                ip_address=self.ip_address,
                ip_port=self.ip_port
                )
            )

            # In practice a delay is needed as the command is run in the background.
            # 5 seconds should give enough time to clean up an old port from killing
            # an old IOC process and set it up ready for the new connection.
            print('# Sleep for 5 seconds to give socat time to prepare')
            print('epicsThreadSleep 5')
        print('# Linkam 3.0 connect')
        print(
            'linkamConnect "{P}_AP", "{serial_port}", "{log_path}"'.format(
                P=self.P,
                serial_port=self.serial_port,
                log_path=self.log_path
            )
        )
