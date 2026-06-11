#pragma region Macros
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;
#pragma endregion

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a.at(i).first;
        a.at(i).second = i;
    }

    sort(a.begin(), a.end());
    vector<int> pla(n);
    for (int i=0; i<n; i++) {
        pla.at(a.at(i).second) = i;
    }
    int res = 0;
    for (int i=0; i<n; i+=2) {
        if (i%2 != pla.at(i)%2) res++;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
