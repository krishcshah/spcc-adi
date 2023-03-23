#include            <bits/stdc++.h>
#define sp          ' '
#define ln          '\n'             
using namespace std;

int euclidean(int r1, int r2) {
    cout << ln << "GCD of " << r1 << " and " << r2 << ":\n";
    cout << "q\tr1\tr2\tr" << ln;
    while(true) {
        int q = r1 / r2;
        int r = r1 % r2;
        cout << q << "\t" << r1 << "\t" << r2 << "\t" << r << ln;
        r1 = r2;
        r2 = r;
        if(r2 == 0) {
            cout << q << "\t" << r1 << "\t" << r2 << "\t" << r << ln;
            break;
        }
    } 
    return r1;
}

int main(void) {
    cout << "Enter value of N: ";
    int n;
    cin >> n;
    int phi = 0;
    for(int i=1; i<n; i++) {
        if(euclidean(n, i) == 1) {
            phi++;
        }
    }
    cout << "\nphi(n) = " << phi << ln;
}
