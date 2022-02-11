import sys
sys.path.append('./gen-py')

from multiplication import MultiplicationService
from multiplication.ttypes import *
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer
from thrift.transport import TSocket, TTransport


class MultiplicationHandler():
    def multiply(self, n1, n2):
        print("mul n1 * n2, n1: {}, n2: {}, result: {}".format(n1, n2, n1 * n2))
        return n1 * n2


def main():
    handler = MultiplicationHandler()
    processor = MultiplicationService.Processor(handler)
    transport = TSocket.TServerSocket(port=9090)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()
    server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)
    print('server start...')
    server.serve()
    print('done.')


if __name__ == '__main__':
    main()
