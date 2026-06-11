#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), ab(n);
    rep(i, n){
        cin >> a[i] >> b[i];
        ab[i] = b[i] - a[i]%b[i];
    }
    reverse(ab.begin(), ab.end());
    ll ans = 0;
    rep(i, n){
        if(i > 0) ab[i] = b[n-1-i] - (a[n-1-i]+ans)%b[n-1-i];
        if(ab[i] != b[n-1-i] && b[n-1-i] > 1) ans += ab[i];
    }
    
    //rep(i, n) cout << a[i] << " "; cout << endl;
    //rep(i, n) cout << b[i] << " "; cout << endl;
    //for(ll i = n-1; i >= 0; --i) cout << ab[i] << " "; cout << endl;

    cout << ans << endl;
    return 0;
}