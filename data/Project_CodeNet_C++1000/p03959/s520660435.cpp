#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
constexpr ll mod = 1e9+7;

int main(){
    ll n;
    cin >> n;
    vector<ll> t(n), a(n);
    rep(i, 0, n) cin >> t[i];
    rep(i, 0, n) cin >> a[i];
    vector<bool> bt(n, false), ba(n, false);
    ll pre = t[0];
    bt[0] = true;
    rep(i, 1, n){
        if(pre != t[i]) bt[i] = true;
        pre = t[i];
    }
    pre = a[n-1];
    ba[n-1] = true;
    for(ll i = n-2; i >= 0; i--){
        if(pre != a[i]) ba[i] = true;
        pre = a[i];
    }
    vector<ll> mx(n);
    rep(i, 0, n){
        mx[i] = min(t[i], a[i]);
        if(bt[i] && mx[i] != t[i]){
            cout << 0 << endl;
            return 0;
        }
        if(ba[i] && mx[i] != a[i]){
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    rep(i, 0, n) {
        if(!bt[i] && !ba[i]) ans *= mx[i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}