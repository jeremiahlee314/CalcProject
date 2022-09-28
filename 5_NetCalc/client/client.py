import socket
import time
import os
import sys
import getopt
from  struct import *

PORT = 5555
FORMAT = 'utf-8'
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)
SIZE = 1024


def ConnectToServer():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(ADDR)
    data = client.recv(SIZE).decode(FORMAT)
    print(f"[SERVER] {data}")
    return client

def ParseDir():
    for root, dirs, files in os.walk(dir):
        for filename in files:
            f = filename
            path = root + filename
            SendFileContents(f, path)



def SendFileContents(f, path):
    client = ConnectToServer()
    flen = str(len(f)) + '\n'
    print(len(f))
    client.send(flen.encode())
    client.send(str(f).encode())
    with open(path, 'rb') as file:
        print("[CLIENT]: Sending ", f)
        print("\n\n\n\n")

        headerForm = "4s8s8s1s4s2s"
        magicNum = file.read(4)
        print(''.join(format(x, '02x') for x in magicNum))
        fileID = file.read(8)
        print(''.join(format(x, '02x') for x in fileID))
        numOfEq = file.read(8)
        print(''.join(format(x, '02x') for x in numOfEq))
        flags = file.read(1)
        print(''.join(format(x, '02x') for x in flags))
        equOffset = file.read(4)
        print(''.join(format(x, '02x') for x in equOffset))
        numOptHeaders = file.read(2)
        print(''.join(format(x, '02x') for x in numOptHeaders))

        header = pack(headerForm, magicNum, fileID, numOfEq, flags, equOffset, numOptHeaders)
        print("Header: ")
        print(''.join(format(x, '02x') for x in header))
        print("\n\n\n" + str(len(header)))
        client.send(header)

    client.close()


def main():
    ParseDir()


if __name__ == "__main__":
    dir = sys.argv[1]
    main()