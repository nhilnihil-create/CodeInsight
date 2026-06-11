#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll mod = 1000000007;
    ll N, M;
    cin >> N >> M;
    ll ans;
    ll Nkai = 1;
    ll Mkai = 1;
    rep(i,N) Nkai = Nkai * (i + 1) % mod;
    rep(i,M) Mkai = Mkai * (i + 1) % mod;
    if (N - M == 0) {
        ans = 2 * Nkai * Mkai % mod ;
    } else if (abs(N - M) == 1) {
        ans = Nkai * Mkai % mod ;
    } else {
        ans = 0;
    }
    cout << ans << endl;
}
