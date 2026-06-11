#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    for(ll i=0; i<=n; i++) {
        bool ok = true;
        for(ll j=0; j<n && i+j<n; j++)
            ok &= s[i+j] == t[j];
        if(ok) {
            cout << i+n << endl;
            return 0;
        }
    }
}
