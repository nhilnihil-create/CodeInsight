#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll comb(ll n,ll k){
    ll ret = 1;
    for(ll i = n; i > n-k;--i) {
        ret *= i;
        ret /= (n+1-i);
    }
    return ret;
}
int main(){
    ll n,a,b; cin >> n >> a >> b;
    vector<ll> v(n);
    for(ll i = 0; i < n; ++i) cin >> v[i];
    sort(v.rbegin(),v.rend());
    ll sum = 0;
    for(ll i = 0; i < a; ++i) sum += v[i];
    cout << fixed << setprecision(10) << sum*1.0/a  << endl;

    ll left = -1, right = 0;
    for(ll i = 0; i < n;++i){
        if(v[i] == v[a-1] && left == -1) left = i;
        if(v[i] == v[a-1]) right = i;
    }
    if(left != 0) cout << comb(right-left+1,a-left) << endl;
    else {
        ll ans = 0;
        for(ll i = a;i <= min(right+1,b);++i){
            ans += comb(right+1,i);
        }
        cout << ans << endl;
    }
}