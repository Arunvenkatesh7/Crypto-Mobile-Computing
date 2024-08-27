import socket

# Function to encrypt the message using Caesar cipher
def caesar_cipher_encrypt(plaintext, shift):
    encrypted_text = ""
    for char in plaintext:
        if char.isalpha():
            shift_base = ord('A') if char.isupper() else ord('a')
            encrypted_text += chr((ord(char) - shift_base + shift) % 26 + shift_base)
        else:
            encrypted_text += char  # Non-alphabet characters remain unchanged
    return encrypted_text

def server_program():
    # Server setup
    host = '127.0.0.1'
    port = 65432

    # Create and bind the socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))

    # Listen for incoming connections
    server_socket.listen(1)
    print("Server is listening...")

    while True:
        # Accept a connection
        conn, address = server_socket.accept()
        print(f"Connection from: {address}")

        # Message to encrypt
        plaintext = "HELLO CLIENT"
        shift_key = 3  # Caesar cipher shift key
        encrypted_message = caesar_cipher_encrypt(plaintext, shift_key)

        # Send the encrypted message and key to the client
        conn.send(encrypted_message.encode())
        conn.send(f"KEY:{shift_key}".encode())

        # Close the connection
        conn.close()

if __name__ == "__main__":
    server_program()
