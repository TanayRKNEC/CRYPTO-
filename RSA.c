#include <bits/stdc++.h>
using namespace std;
int modInverse(int A, int M)
{
    for (long int X = 1; X < M; X++)
        if (((A % M) * (X % M)) % M == 1)
            return X;
    return -1;
}
int main()
{
    long int p, q, n, toutn, publickey, message, privatekey, C, M;
    cin.ignore();
    cout << "Enter the value of p and q : ";
    cin >> p >> q;
    n = p * q;
    toutn = (p - 1) * (q - 1);
    cout << "Enter the value of public key: ";
    cin >> publickey;
    privatekey = modInverse(publickey, toutn);
    cout << "Enter the value of message: ";
    cin >> message;
    C = fmod(pow(message, publickey), n);
    M = fmod(pow(C, privatekey), n);
    cout << "Encrypted message is: ";
    cout << C << endl;
    cout << "Decrypted message is: ";
    cout << M << endl;
    return 0;
}
