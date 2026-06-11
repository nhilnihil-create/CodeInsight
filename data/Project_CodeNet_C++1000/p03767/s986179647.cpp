#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(3*n);
    rep(i,3*n) cin >> a[i];
    sort(all(a), greater<ll>());
    ll ans = 0;
    for(int i = 1; i < 2*n; ++i) {
        if(i%2) ans+=a[i];
    }
    cout << ans << endl;
    return 0;
}