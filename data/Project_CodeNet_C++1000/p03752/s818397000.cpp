#include<bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long int ll;
int main() {
    ll n, m,ans = 1e18; cin >> n >> m;
    vector<ll> a(n); rep(i, n) cin >> a[i];
    rep(i, 1 << n) {
        ll mx = 0, sum = 0, cnt = 0;
        rep(j, n) {
            if (i & (1 << j)) {
                cnt++;
                if (mx >= a[j]) sum += mx - a[j] + 1,mx++;
            }mx = max(mx, a[j]);
        }
        if (cnt >= m) ans = min(ans, sum);
    }cout << ans << endl;
}