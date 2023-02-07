#include            <bits/stdc++.h>
#define sp          ' '
#define ln          '\n'             
using namespace std;

int main(void) {
    cout << "Enter a message: ";
    string s;
    getline(cin, s);
    cout << "Enter key: ";
    int key;
    cin >> key;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == ' ') {
            continue;
        }

        int pos = s[i] - 'a';
        pos = (pos + key) % 26;
        s[i] = char(pos + 'a');
    }
    cout << "\nEncrypted string is: " << s << ln;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == ' ') {
            continue;
        }
        bool special = true;
        if(s[i] >= 'a' && s[i] <= 'z') {
            special = false;
        }
        int pos;
        if(special) {
            pos = s[i] - '!';
        }
        else {
            pos = s[i] - 'a';
        }
        pos = (pos - key);
        if(pos < 0) {
            pos += 26;
        }
        if(special) {
            s[i] = char(pos + '!');
        }
        else {
            s[i] = char(pos + 'a');
        }
    }
    cout << "\nDecrypted string is: " << s;
}
