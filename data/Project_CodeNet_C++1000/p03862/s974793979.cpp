#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n, x; cin >> n >> x;
    vector<ll> data(n); rep(i,n) cin >> data[i];
    ll ans = 0;
    rep(i,n-1){
        if(data[i]+data[i+1] <= x) continue;
        ll k = data[i]+data[i+1]-x;
        ans += k;
        data[i+1] -= k;
    }
    if(data[n-1] > x) ans += data[n-1]-x;
    cout << ans <<  endl;
}

