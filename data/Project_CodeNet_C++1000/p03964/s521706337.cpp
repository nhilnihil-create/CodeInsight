#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> T(N), A(N);
    rep(i, N) cin >> T[i] >> A[i];

    ll x = 1;
    ll y = 1;
    rep(i, N) {
        ll m = max((x + T[i] - 1) / T[i], (y + A[i] - 1) / A[i]);
        x = m * T[i];
        y = m * A[i];
    }
    cout << x + y << endl;
}