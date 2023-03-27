#include            <bits/stdc++.h>
#define sp          ' '
#define ln          '\n'             
using namespace std;

bool uniqueMods(int n, int p) {
    unordered_set<int> st;
    for(int i=1; i<p; i++) {
        int number = pow(n, i);
        number %= p;

        if(st.find(number) != st.end()) {
            return false;
        }
        st.insert(number);
    }
    return true;
}

int main(void) {
    cout << "Enter prime number p: ";
    int p;
    cin >> p;
    int gen = -1;

    for(int i=2; i<p; i++) {
        if(uniqueMods(i, p)) {
            gen = i;
            break;
        }
    }
    if(gen == -1) {
        cout << "Generator does not exist!";
        return 0;
    }
    cout << "Generator obtained is: " << gen << ln;
    cout << ln << "Enter private key for Alice: ";
    int x;
    cin >> x;
    cout << ln << "Enter private key for Bob: ";
    int y;
    cin >> y;
    int key1 = pow(gen, x);
    key1 %= p;
    int key2 = pow(gen, y); 
    key2 %= p;
    cout << ln << "Public key for Alice is " << "(" << gen << "^" << x << ")" << "mod" << p << " = " << key1 << ln;
    cout << ln << "Public key for Bob is " << "(" << gen << "^" << x << ")" <<  "mod" << p << " = " << key2 << ln;
    cout << ln << ln << "Exchanging keys..." << ln << ln;
    int k1 = key1, k2 = key2;
    key1 = pow(k2, x);
    key1 %= p;
    key2 = pow(k1, y);
    key2 %= p;
    cout << ln << "Final key with Alice: " << key1;
    cout << ln << "Final key with Bob: " << key2 << ln << ln;   
}
