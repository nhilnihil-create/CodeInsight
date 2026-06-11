#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll n, c, k;
    cin >> n >> c >> k;
    vector<ll> t(n);
    rep(i, n) cin >> t[i];
    sort(t.begin(), t.end());
    ll cnt = 1, p = 0, lim = 0;
    rep(i, n){
        if(i == 0){
            lim = t[i] + k;
            p++;
        }
        else if(p == c || lim < t[i]){
            p = 1;
            cnt++;
            lim = t[i] + k;
        }
        else {
            p++;
        }
        //printf("%lld %lld %lld\n", cnt, p, lim);
    }
    cout  << cnt << endl;
    return 0;
}