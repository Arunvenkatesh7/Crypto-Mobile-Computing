#server code

import socket

def encrypt(plainText,key):
    enc=""
    for char in plainText:
        base=65 if char.isupper() else 97
        if char.isalpha():
            enc+=chr((ord(char)-base+key+26)%26+base)
        else:
            enc+=char
    return enc


def server():
    host="127.0.0.1"
    port=7956
    
    server_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    
    #server_socket bind to host and port
    
    server_socket.bind((host,port))
    
    #server_socket listen
    
    server_socket.listen(1)
    print(f"Server Socket is listening at port{port}")
    
    conn,address=server_socket.accept()
    print(f"connection is created with address: {address}")
    
    plainText="Hello World"
    cipherText=encrypt(plainText,3)

    conn.send(cipherText.encode())
    
    print("cipherText is Sent from the Server")
    
    conn.close()
    
if __name__=="__main__":
    server()