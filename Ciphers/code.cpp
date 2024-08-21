#include <iostream>
using namespace std;
// Function to perform the Extended Euclidean Algorithm using quotient and remainder
int extendedGCD(int a, int b, int &quotient, int &remainder) {
    int q0 = 1, q1 = 0, r0 = 0, r1 = 1;
    while (b != 0) {
        int q = a / b;  // quotient
        int r = a % b;  // remainder
        cout<<"a: "<<a<<"b: "<<b<<"q: "<<q<<"r: "<<r<<endl;
        // Update a and b
        a = b;
        b = r;
        
        // Update quotient and remainder
        int tempQ = q0 - q * q1;
        int tempR = r0 - q * r1;

        q0 = q1;
        q1 = tempQ;

        r0 = r1;
        r1 = tempR;
    }

    quotient = q0;
    remainder = r0;

    return a;
}

// Function to find the modular inverse of 'a' under modulo 'm'
int modInverse(int a, int m) {
    int quotient, remainder;
    int gcd = extendedGCD(a, m, quotient, remainder);
    if (gcd != 1) {
        std::cerr << "Inverse doesn't exist";  // a and m must be coprime
        return -1;
    } else {
        // Make sure the result is positive
        return (quotient % m + m) % m;
    }
}

int main() {
    int a = 3;
    int m = 26;

    int inverse = modInverse(a, m);
    if (inverse != -1) {
        std::cout << "Modular inverse of " << a << " under modulo " << m << " is: " << inverse << std::endl;
    }

    return 0;
}
