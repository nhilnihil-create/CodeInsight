#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans=0, cnt=0;
    for ( char c:s ) {
        if ( c=='T' ) {
            if ( cnt>0 ) cnt--;
            else ans++;
        } else {
            cnt++;
        }
    }
    cout << ans+cnt << '\n';
    return 0;
}