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

bool need(int n, int N, int K, const vector<int> &a) {
    bitset<5000> bits(1);
    for (int i=0; i<N; ++i) {
        if (i != n && a[i] < 5000) bits |= (bits << a[i]);
    }
    for (int i=max(0, K-a[n]); i<K; ++i) {
        if (bits.test(i)) return true;
    }
    return false;
}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i=0; i<N; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    int ok = -1, ng = N;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (!need(mid, N, K, a)) ok = mid;
        else ng = mid;
    }
    cout << ok + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
