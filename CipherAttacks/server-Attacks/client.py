#client.py
import socket


def Brute_Force(cipherText):
    
    for key in range(0,25):
        dec=""
        for char in cipherText:
            base=65 if char.isupper() else 97
            if char.isalpha():    
                dec+=chr(((ord(char)-base-key+26)%26)+base)
            else:
                dec+=char
        print(f"decrypted for key{key}: ",dec)


def client():
    client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    
    host='127.0.0.1'
    port=7956 
    
    client_socket.connect((host,port))
    
    print("server is connected!!!")
    
    encrypted_msg=client_socket.recv(1024).decode()
    
    print("Received Encrypted Text: ",encrypted_msg)
    
    print("Applying Brute Force!!!: ")
    
    Brute_Force(encrypted_msg)
    
    
    
    


if __name__=="__main__":      
    client()
            
            
            
        
        
        
        

