#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define inf 1e9
#define INF 1000000000000000000

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> X(N);
    rep(i, N) { cin >> X[i]; }

    ll res = 0;
    rep(i, N - 1) {
        ll diff = X[i + 1] - X[i];
        res += min(diff * A, B);
    }

    cout << res << endl;
}