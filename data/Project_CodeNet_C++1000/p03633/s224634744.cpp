#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<ll> T(N);
    rep(i,N) cin >> T.at(i);
    ll ans = 1;
    rep(i,N) ans = lcm(ans, T.at(i));
    cout << ans << endl;
}
