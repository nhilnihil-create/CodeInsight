#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
const int INF = 1e9 + 1;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    ll resT = 1, resA = 1;
    for (int i = 0; i < N; ++i) {
        int T, A;
        cin >> T >> A;
        ll tmp = max((resT + T - 1) / T, (resA + A - 1) / A);
        resT = tmp * T;
        resA = tmp * A;
    }
    cout << resT + resA << endl;

    return 0;
}
