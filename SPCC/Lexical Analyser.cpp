#include            <bits/stdc++.h>
#define sp          ' '
#define ln          '\n'             
using namespace std;

int main(void) {

    // Declaration of default values
    vector<string> keywords = {"int", "bool", "string", "float", "double", "const"};
    vector<string> operators = {"+", "-", "=", "+=", "-=", "*", "/", "^", "*=", "/=", "%", "%=", "!="};
    vector<string> seperators = {",", ";"};

    // Input the strings and seperate all words
    cout << "Enter lexemes:\n\n";
    vector<string> words;
    while(true) {
        string s;
        getline(cin, s);
        if(s.empty()) {
            break;
        }
        string word = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') {
                words.push_back(word);
                word.clear();
            }
            else {
                word.push_back(s[i]);
            }
        }
        words.push_back(word);
    }

    // Store words according to their type
    unordered_set<string> key, op, num, sep, id;
    for(int i=0; i<words.size(); i++) {
        string s = words[i];
        int n = s.size();
        if(s[n-1] == ';' || s[i] == ',') {
            if(find(sep.begin(), sep.end(), s) != sep.end()) {
                sep.insert(s[n-1] + "");
            }
            s.erase(n-1);
        }
        if(find(keywords.begin(), keywords.end(), s) != keywords.end()) {
            key.insert(s);
        }
        else if(s[0] >= '0' && s[0] <= '9') {
            num.insert(s);
        }
        else if(find(operators.begin(), operators.end(), s) != operators.end()) {
            op.insert(s);
        }
        else {
            id.insert(s);
        }
    }

    // Printing each category 
    cout << "----------------------------------------------";
    if(!key.empty()) {
        cout << ln << "Keywords: \t";
        for(unordered_set<string> :: iterator it = key.begin(); it != key.end(); it++) {
            cout << *it << sp << sp;
        }   
        cout << ln << "----------------------------------------------";
    }
    if(!op.empty()) {
        cout << ln << "Operators: \t";
        for(unordered_set<string> :: iterator it = op.begin(); it != op.end(); it++) {
            cout << *it << sp << sp;
        }
        cout << ln << "----------------------------------------------";
    }
    if(!num.empty()) {
        cout << ln << "Numbers: \t";
        for(unordered_set<string> :: iterator it = num.begin(); it != num.end(); it++) {
            cout << *it << sp << sp;
        }
        cout << ln << "----------------------------------------------";
    }
    if(!id.empty()) {
        cout << ln << "Identifiers: \t";
        for(unordered_set<string> :: iterator it = id.begin(); it != id.end(); it++) {
            cout << *it << sp << sp;
        }
    }
    if(!sep.empty()) {
        cout << ln << ln << "Seperators: \t";
        for(unordered_set<string> :: iterator it = sep.begin(); it != sep.end(); it++) {
            cout << *it << sp << sp;
        }
    }
    cout << ln << "----------------------------------------------" << ln;;
}
