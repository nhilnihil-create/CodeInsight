#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char f(char c) {
    if(c == 'b') {
        return 'd';
    }
    if(c == 'd') {
        return 'b';
    }
    if(c == 'p') {
        return 'q';
    }
    if(c == 'q') {
        return 'p';
    }
    return c;
}

string deal(string s) {
    reverse(s.begin(), s.end());

    for(int i = 0; i < s.size(); i++) {
        s[i] = f(s[i]);
    }
    return s;
}

int main() {
    string s;

    cin >> s;
    
    if(s == deal(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}