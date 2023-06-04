#include <bits/stdc++.h>
using namespace std;

int powerMod(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result;
}

int main() {
    int prime, primitiveRoot;
    int privateKeyA, privateKeyB;

    cout << "Enter the prime number and its primitive root: ";
    cin >> prime >> primitiveRoot;

    cout << "Enter the private key for User A and User B: ";
    cin >> privateKeyA >> privateKeyB;

    int publicKeyA = powerMod(primitiveRoot, privateKeyA, prime);
    int publicKeyB = powerMod(primitiveRoot, privateKeyB, prime);

    int sharedSecretA = powerMod(publicKeyB, privateKeyA, prime);
    int sharedSecretB = powerMod(publicKeyA, privateKeyB, prime);

    cout << "Shared secret of User A and User B: " << sharedSecretA << " " << sharedSecretB << endl;

    return 0;
}
