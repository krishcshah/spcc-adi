#include            <bits/stdc++.h>
#define sp          ' '
#define ln          '\n'             
using namespace std;

int _pow(int b, int e, int mod){
    int ret = 1;
    while(e > 0){
        if(e&1) {
            ret = ret * b % mod;
        }
        b = b * b % mod;
        e /= 2;
    }
    return ret;
}

int gcd(int a, int b) {
    if(a == b) {
        return a;
    }
    if(a > b) {
        return gcd(a-b, b);
    }
    return gcd(a, b-a);
}

int main(){
    int p, q, n;
    cout << "Enter p : ";
    cin >> p;
    cout << "Enter q : ";
    cin >> q;
    n = p * q;
    int phi = (p-1)*(q-1);
    cout << ln << ln << "phi = " << phi << ln;
    int e;
    for(int i = 2; i < phi; i++) {
        if(gcd(phi, i) == 1) {
            cout << ln << "Value of e is: " << i << ln;
            e = i;
            break;
        }
    }
    int d;
    for(int i = 0; i <= 9; i++){
        int x = i*phi+1;
        if(x%e == 0) {
            d = x/e;
            cout << "\nValue of d such that de = 1 mod p(n) is: " << d << ln;
            break;
        }
    }
    cout << "Public Key: {" << e << ", " << n << "}\n";
    cout << "Private Key: {" << d << ", " << n << "}\n";
    cout << "phi(n): " << phi << "\n";
    int msg; 
    cout << ln << ln << "Enter number to encrypt: "; 
    cin >> msg;
    int enc = _pow(msg, e, n);
    cout << ln << ln << "Encrypted Message: " << enc << "\n";
    int dec = _pow(enc, d, n);
    cout << "Decrypted Message: " << dec << "\n";
    return 0;
}
