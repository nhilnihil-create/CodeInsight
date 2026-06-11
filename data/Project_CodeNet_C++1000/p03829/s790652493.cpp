#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<pii>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, A, B;
    cin >> N >> A >> B;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
        if (i > 0)
            X[i - 1] = X[i] - X[i - 1];
    }

    ll ans = 0;
    for (int i = 0; i < N - 1; ++i)
        ans += min(X[i] * A, B);
    cout << ans << endl;

    return 0;
}
