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

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    int ans = 0;

    int bound = n/2 - (n%2 == 0);
    for (int i=0; i<n; i++) {
        if (i <= bound) {
            if (s.at(i) == 'p') ans--;
        } else {
            if (s.at(i) == 'g') ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
