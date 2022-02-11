import sys
sys.path.append('./gen-py')

from thrift.transport import TSocket, TTransport
from thrift.server import TServer
from thrift.protocol import TBinaryProtocol
from multiplication.ttypes import *
from multiplication import MultiplicationService
from thrift import Thrift


def main():
    try:
        transport = TSocket.TSocket('localhost', 9090)
        transport = TTransport.TBufferedTransport(transport)
        protocol = TBinaryProtocol.TBinaryProtocol(transport)
        client = MultiplicationService.Client(protocol)
        transport.open()

        n1 = 5
        n2 = 7
        res = client.multiply(n1, n2)
        print('{} * {} = {}'.format(n1, n2, res))

        transport.close()
    except Thrift.TException as tx:
        print(tx)


if __name__ == '__main__':
    main()
