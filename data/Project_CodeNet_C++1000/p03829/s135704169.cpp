#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    int N;
    ll A, B;
    cin >> N >> A >> B;
    vector<ll> X(N);
    rep(i, N) cin >> X[i];

    vector<ll> D(N - 1);
    rep(i, N - 1) D[i] = min((X[i + 1] - X[i]) * A, B);
    ll ans = 0;
    rep(i, N - 1) ans += D[i];
    cout << ans << endl;
}