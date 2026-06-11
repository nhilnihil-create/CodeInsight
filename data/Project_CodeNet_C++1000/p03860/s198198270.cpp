#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    string ans="";
    for ( int i=0; i<3; i++ ) {
        cin >> s;
        ans+=s[0];
    }
    cout << ans << '\n';
    return 0;
}
