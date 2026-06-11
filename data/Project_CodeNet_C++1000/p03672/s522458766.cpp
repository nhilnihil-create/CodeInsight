#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    while ( 1 ) {
        s.pop_back();
        if ( s.substr(0,s.size()/2)==s.substr(s.size()/2) ) {
            break;
        }
    }
    cout << s.size() << '\n';
    return 0;
}
