# -*- coding: utf-8 -*-

from pydoc import cli
import sys

sys.path.append("./gen-py")

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

from nopig.admin import MultiplicationService
from nopig.admin.ttypes import *


def main():
    transport = TSocket.TSocket("localhost", 9090)
    transport = TTransport.TBufferedTransport(transport)
    protocal = TBinaryProtocol.TBinaryProtocol(transport)

    client = MultiplicationService.Client(protocal)

    transport.open()

    x, y = 5, 7
    result = client.multiply(x, y)
    print("x * y = {}".format(result))

    transport.close()


if __name__ == "__main__":
    main()
