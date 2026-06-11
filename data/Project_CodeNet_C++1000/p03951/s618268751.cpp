#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    rep(i, n){
        bool flg = true;
        rep(j, n-i){
            if (s[i+j] != t[j]){
                flg = false;
            }
        }
        if (flg){
            ll ans = n + i;
            cout << ans << endl;
            return 0;
        }
    }
    ll ans = n + n;
    cout << ans << endl;


    return 0;
}
