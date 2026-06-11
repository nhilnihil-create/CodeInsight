#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (int i=0; i<N; ++i) cin >> a[i];

    ll sum = 0;
    for (int i=0; i<N; ++i) sum += a[i];
    vector<ll> dif(N);
    for (int i=0; i<N; ++i) dif[i] = a[(i+1)%N] - a[i];
    if (sum % (N * (N + 1) / 2) != 0) {
        cout << "NO" << '\n';
        return;
    }
    ll ope = sum / (N * (N + 1) / 2);
    for (int i=0; i<N; ++i) {
        if (dif[i] - ope > 0 || (dif[i] - ope) % N != 0) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
