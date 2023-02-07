#include <bits/stdc++.h>
#define ln '\n'
#define sp ' '
using namespace std;

string encrypt(string pr, vector<vector<char>> &a) {
    int i1, i2, j1, j2;

    // Find positions of both characters in the grid
    for(int i=0; i<5; i++) {
        bool ok = false;
        for(int j=0; j<5; j++) {
            if(a[i][j] == pr[0] || pr[0] == 'j' && a[i][j] == 'i') {
                i1 = i, j1 = j;
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    for(int i=0; i<5; i++) {
        bool ok = false;
        for(int j=0; j<5; j++) {
            if(a[i][j] == pr[1] || pr[1] == 'j' && a[i][j] == 'i') {
                i2 = i, j2 = j;
                ok = true;
                break;
            }
        }
        if(ok) break;
    }

    // Form the encrypted string of length 2
    string ans = "";
    if(i1 == i2) {
        ans.push_back(a[i1][(j1 + 1) % 5]);
        ans.push_back(a[i2][(j2 + 1) % 5]);
    }
    else if(j1 == j2) {
        ans.push_back(a[(i1 + 1) % 5][j1]);
        ans.push_back(a[(i2 + 1) % 5][j2]);
    }
    else if(i1 != i2 && j1 != j2) {
        ans.push_back(a[i1][j2]);
        ans.push_back(a[i2][j1]);
    }
    return ans;
}

string decrypt(string pr, vector<vector<char>> &a) {
    int i1, i2, j1, j2;

    // Find the positions of the encrypted letters in the grid
    for(int i=0; i<5; i++) {
        bool ok = false;
        for(int j=0; j<5; j++) {
            if(a[i][j] == pr[0] || pr[0] == 'j' && a[i][j] == 'i') {
                i1 = i, j1 = j;
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    for(int i=0; i<5; i++) {
        bool ok = false;
        for(int j=0; j<5; j++) {
            if(a[i][j] == pr[1] || pr[1] == 'j' && a[i][j] == 'i') {
                i2 = i, j2 = j;
                ok = true;
                break;
            }
        }
        if(ok) break;
    }

    // Form the decrypted string of length 2
    string ans = "";
    if(i1 == i2) {
        j1--;
        j2--;
        if(j1 < 0) {
            j1 += 5;
        }
        if(j2 < 0) {
            j2 += 5;
        }
        ans.push_back(a[i1][j1]);
        ans.push_back(a[i2][j2]);
    }
    else if(j1 == j2) {
        i1--;
        i2--;
        if(i1 < 0) {
            i1 += 5;
        }
        if(i2 < 0) {
            i2 += 5;
        }
        ans.push_back(a[i1][j1]);
        ans.push_back(a[i2][j2]);
    }
    else if(i1 != i2 && j1 != j2) {
        ans.push_back(a[i1][j2]);
        ans.push_back(a[i2][j1]);
    }
    return ans;
}

int main(void) {
    string pt;
    cout << "Enter plain text: ";
    cin >> pt;
    cout << ln << "Enter keyword: ";
    string key;
    cin >> key;

    // Removing duplicates from plain text
    for(int i=0; i<key.size(); i++) {
        for(int j=i+1; j<key.size(); j++) {
            if(key[i] == key[j]) {
                key[i] = '0';
            }
        }
    }
    string keyword = "";
    for(char c : key) {
        if(c != '0') {
            keyword.push_back(c);
        }
    }

    // Marking letters that are not present in the string
    vector<int> alpha(26);
    for(int i=0; i<keyword.size(); i++) {
        alpha[keyword[i] - 'a']++;
    }

    // Forming and printing the matrix
    vector<vector<char>> a(5, vector<char>(5));
    int pos = 0;
    int wordPos = 0;
    cout << ln << "5 x 5 matrix is:\n" << ln;
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(wordPos < keyword.size()) {
                a[i][j] = keyword[wordPos++];
            }
            else {
                while(alpha[pos] != 0) {
                    pos++;
                }
                char let = char(pos + int('a'));
                a[i][j] = let;
                if(let == 'i') {
                    pos++;
                }
                pos++;
            }
            cout << a[i][j] << sp;
        }
        cout << ln;
    }

    // Encrypt and decrypt
    string str = "";
    int i=0;
    while(i < pt.size()-1) {
        if(pt[i+1] == pt[i]) {
            str.push_back(pt[i]);
            str.push_back('x');
            i += 1;
        }
        else {
            str.push_back(pt[i]);
            str.push_back(pt[i+1]);
            i += 2;
        }
    }
    if(str.size() % 2 == 1) {
        str.push_back('z');
    }
    cout << ln << "Encoded plain text: " << str << ln;
    string enc = "";
    for(int i=0; i<str.size(); i+=2) {
        string pr = str.substr(i, 2);
        enc += encrypt(pr, a);
    }
    cout << ln << "Encrypted string is: " << enc << ln;
    string dec = "";
    for(int i=0; i<enc.size(); i+=2) {
        string pr = enc.substr(i, 2);
        dec += decrypt(pr, a);
    }
    i = 0;
    string ans = "";
    while(i < dec.size()) {
        if(i+2 < dec.size() && dec[i] == dec[i+2] && dec[i+1] == 'x') {
            ans.push_back(dec[i]);
            ans.push_back(dec[i+2]);
            i += 3;
        }
        else {
            ans.push_back(dec[i]);
            ans.push_back(dec[i+1]);
            i += 2;
        }
    }
    cout << ln << "Decrypted string is:  " << ans;
}
