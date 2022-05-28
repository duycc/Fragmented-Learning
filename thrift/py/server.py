# -*- coding: utf-8 -*-
import sys

sys.path.append("./gen-py")

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

from nopig.admin import MultiplicationService
from nopig.admin.ttypes import *


class IntHandler:
    def multiply(self, x, y):
        return x * y


def main():
    handler = IntHandler()
    processor = MultiplicationService.Processor(handler)
    transport = TSocket.TServerSocket(port=9090)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()

    server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)
    print("server start...")
    server.serve()


if __name__ == "__main__":
    main()
