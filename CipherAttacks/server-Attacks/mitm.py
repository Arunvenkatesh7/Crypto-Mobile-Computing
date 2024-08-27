import socket

# Function to modify the intercepted encrypted message
def modify_message(encrypted_text):
    # Example modification: shift all letters by 1 more
    modified_text = ""
    for char in encrypted_text:
        if char.isalpha():
            shift_base = ord('A') if char.isupper() else ord('a')
            modified_text += chr((ord(char) - shift_base + 1) % 26 + shift_base)
        else:
            modified_text += char
    return modified_text

def mitm_attack():
    # MitM setup
    host = '127.0.0.1'
    port = 65432
    mitm_port = 65433  # Port for MitM to listen on
    
    # Create a socket to act as the MitM proxy
    mitm_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    mitm_socket.bind((host, mitm_port))
    mitm_socket.listen(1)
    print("MitM is listening...")

    while True:
        # Accept a connection from the client
        client_conn, client_address = mitm_socket.accept()
        print(f"Client connected: {client_address}")

        # Connect to the server
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.connect((host, port))
        print("MitM connected to server.")

        # Relay data between client and server
        try:
            while True:
                # Receive data from the client
                client_data = client_conn.recv(1024)
                if not client_data:
                    break

                # Modify the intercepted message
                modified_data = modify_message(client_data.decode())
                server_socket.send(modified_data.encode())

                # Receive data from the server
                server_data = server_socket.recv(1024)
                if not server_data:
                    break

                # Forward server data to the client
                client_conn.send(server_data)
        finally:
            client_conn.close()
            server_socket.close()

if __name__ == "__main__":
    mitm_attack()
