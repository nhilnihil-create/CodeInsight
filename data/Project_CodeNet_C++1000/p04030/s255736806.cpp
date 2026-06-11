#include<cstdio>
#include<iostream>
using namespace std;
int main() {
    string s, t;
    cin >> s;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == '0') t += '0';
        else if(s[i] == '1') t += '1';
        else if(s[i] == 'B') {
            if(t.length()) t.erase(t.end()-1);
        }
    }
    cout << t << '\n';
return 0;
}