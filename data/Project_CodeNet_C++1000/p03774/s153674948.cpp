#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n), c(m), d(m);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,m) cin >> c[i] >> d[i];
    rep(i,n) {
        ll mn = 1e18;
        int ans;
        rep(j,m) {
            ll dist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if(mn > dist) {
                mn = dist;
                ans = j+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}