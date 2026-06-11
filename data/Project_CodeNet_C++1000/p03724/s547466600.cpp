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
constexpr long long MOD = 1e9 + 7;
constexpr double EPS = 1e-10;
#pragma endregion

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i=0; i<m; i++) {
        int aa, bb;
        cin >> aa >> bb;
        a.at(aa)++;
        a.at(bb)--;
    }
    for (int i=1; i<n+1; i++) {
        a.at(i) += a.at(i-1);
    }
    for (int i=1; i<n; i++) {
        if (a.at(i)%2 != 0) {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
