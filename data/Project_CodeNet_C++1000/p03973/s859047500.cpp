#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    ans += a[0] - 1;
    ll now = 2;
    for(i = 1;i < n;++i){
        if(a[i] == now) ++now;
        else ans += (a[i] - 1)/now;
    }
    cout << ans << endl;

    return 0;
}