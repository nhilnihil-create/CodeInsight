#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> flgs(n, 0);
    rep(i, n){
        cin >> a[i];
    }

    ll ans=0;
    ll i = 1;
    while(true){
        if(flgs[i-1] == 1){
            cout << -1 << endl;
            return 0;
        }
        flgs[i-1] = 1;
        i = a[i-1];
        ans++;
        if(i == 2){
            break;
        }
    }

    cout << ans << endl;


    return 0;
}
