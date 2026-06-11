#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){

    // input
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll ans = 0;
    rep(i, 1, n){
        ll tmp = a[i-1] + a[i];
        if(tmp <= x) continue;
        ans += tmp - x;
        a[i] -= min(a[i], tmp-x);
    }

    cout << ans << endl;
    return 0;
}