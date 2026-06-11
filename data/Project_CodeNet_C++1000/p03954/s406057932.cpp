#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;


struct e{
    ll l, r, type;
    e(){}
    e(ll l, ll r, ll type): l(l), r(r), type(type) {}
};



ll n;
ll h;
vector < ll > a;





bool ok(ll x){
    vector < ll > b(n);
    for(ll i = 0; i < n; ++i){
        b[i] = (a[i] >= x);
    }
    ll pos = n / 2;
    if(b[pos - 1] == b[pos] || b[pos] == b[pos + 1]){
        return b[pos];
    }
    ll l = pos - 1;
    ll r = pos + 1;
    while(l - 1 >= 0 && b[l - 1] != b[l]){
        l--;
    }
    while(r + 1 < n && b[r + 1] != b[r]){
        r++;
    }
    if(l != 0){
        l++;
    }
    if(r != n - 1){
        r--;
    }
    if(l == 0 && r == n - 1){
        return b[0];
    }
    if(b[l] == b[r]){
        return 1 - b[l];
    }
    if(pos - l <= r - pos){
        return 1 - b[l];
    } else {
        return 1 - b[r];
    }
}





void solve(){
    cin >> h;
    n = 2 * h - 1;
    a.resize(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        a[i]--;
    }
    ll l = -1;
    ll r = n;
    while(r - l > 1){
        ll m = (l + r) / 2;
        if(ok(m)){
            l = m;
        } else {
            r = m;
        }
    }
    cout << l + 1 << "\n";
}

signed main(){
    srand(time(0));
    ll t = 1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else

    #endif// DEBUG
    while(t--){
        solve();
    }
}
