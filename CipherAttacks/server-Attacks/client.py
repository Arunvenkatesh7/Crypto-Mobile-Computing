import socket

# Function to decrypt the message using Caesar cipher
def caesar_cipher_decrypt(encrypted_text, shift):
    decrypted_text = ""
    for char in encrypted_text:
        if char.isalpha():
            shift_base = ord('A') if char.isupper() else ord('a')
            decrypted_text += chr((ord(char) - shift_base - shift) % 26 + shift_base)
        else:
            decrypted_text += char  # Non-alphabet characters remain unchanged
    return decrypted_text

def client_program():
    # Client setup
    host = '127.0.0.1'
    port = 65432

    # Create and connect the socket
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((host, port))

    # Receive the encrypted message from the server
    encrypted_message = client_socket.recv(1024).decode()
    print(f"Encrypted message received from server: {encrypted_message}")

    # Receive the key from the server
    key_message = client_socket.recv(1024).decode()
    if key_message.startswith("KEY:"):
        shift_key = int(key_message.split(":")[1])
        print(f"Key received from server: {shift_key}")

        # Decrypt the message using the received key
        decrypted_message = caesar_cipher_decrypt(encrypted_message, shift_key)
        print(f"Decrypted message: {decrypted_message}")
    else:
        print("Key not received or intercepted!")

    # Close the connection
    client_socket.close()

if __name__ == "__main__":
    client_program()
