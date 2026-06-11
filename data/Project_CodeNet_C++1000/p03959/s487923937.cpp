#pragma region Macros
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
#pragma endregion

constexpr ll mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> t(n);
    for (int i=0; i<n; i++) {
        cin >> t.at(i);
    }
    vector<ll> a(n);
    for (int i=0; i<n; i++) {
        cin >> a.at(i);
    }
    if (a.at(0) != t.at(n-1)) {
        cout << 0 << "\n";
        return;
    }
    vector<ll> mnt(n);
    mnt.at(0) = (t.at(0) > a.at(0)) ? 0 : 1;
    mnt.at(n-1) = (a.at(n-1) > t.at(n-1)) ? 0 : 1;
    for (int i=1; i<n-1; i++) {
        bool isSameT = (t.at(i) == t.at(i-1));
        bool isSameA = (a.at(i) == a.at(i+1));
        if (isSameT && isSameA) {
            mnt.at(i) = min(t.at(i), a.at(i));
        } else if (isSameT) {
            if (a.at(i) > t.at(i)) mnt.at(i) = 0;
            else mnt.at(i) = 1;
        } else if (isSameA) {
            if (t.at(i) > a.at(i)) mnt.at(i) = 0;
            else mnt.at(i) = 1;
        } else {
            if (t.at(i) != a.at(i)) mnt.at(i) = 0;
            else mnt.at(i) = 1;
        }
    }
    ll ans = 1;
    for (int i=0; i<n; i++) {
        ans *= mnt.at(i);
        ans %= mod;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
