#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll H, W;
    cin >> H >> W;
    map<char,int> m;
    string s;
    for ( int i = 0; i < H; i++ ) {
        cin >> s;
        for ( char c : s ) {
            m[c]++;
        }
    }
    int n1 = 0, n2 = 0, n4 = 0;
    if ( H%2==1 && W%2==1 ) n1 = 1;
    if ( H%2==1 ) n2 += W/2;
    if ( W%2==1 ) n2 += H/2;
    n4 = (H*W - n2*2 - n1) / 4;

    for ( auto& p : m ) {
        while ( n4 > 0 &&  p.second >= 4 ) {
            p.second -= 4;
            n4--;
        }
        if ( n4 == 0 ) break;
    }
    if ( n4 > 0 ) return false;
    for ( auto& p : m ) {
        while ( n2 > 0 &&  p.second >= 2 ) {
            p.second -= 2;
            n2--;
        }
        if ( n2 == 0 ) break;
    }
    if ( n2 > 0 ) return false;
    for ( auto& p : m ) {
        while ( n1 > 0 &&  p.second >= 1 ) {
            p.second -= 1;
            n1--;
        }
    }
    if ( n1 > 0 ) return false;
    return true;
}

int main() {
    string ans = solve() ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}