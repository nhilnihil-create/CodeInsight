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
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i=0; i<n; ++i) {
        cin >> x.at(i);
    }

    sort(x.begin(), x.end());
    vector<vector<int>> modM(m);
    vector<int> cnt(m);
    int tmp = 0;
    for (int i=0; i<n; ++i) {
        if (i > 0 && x.at(i) != x.at(i-1)) {
            modM.at(x.at(i-1)%m).push_back(tmp);
            cnt.at(x.at(i-1)%m) += tmp;
            tmp = 1;
        } else {
            ++tmp;
        }
    }
    modM.at(x.back()%m).push_back(tmp);
    cnt.at(x.back()%m) += tmp;
    int res = 0;
    res += cnt.at(0) / 2;
    if (m%2 == 0) res += cnt.at(m/2) / 2;
    for (int i=1; i<=m/2; ++i) {
        int i0 = i, i1= m-i;
        if (i0 == i1) continue;
        if (cnt.at(i0) < cnt.at(i1)) swap(i0, i1);
        priority_queue<int> p;
        for (int x : modM.at(i0)) p.push(x);
        while (!p.empty() && cnt.at(i0) - 2 >= cnt.at(i1)) {
            int cur = p.top(); p.pop();
            if (cur > 1) {
                ++res;
                cnt.at(i0) -= 2;
                if (cur-2 > 0) p.push(cur-2);
            }
        }
        res += cnt.at(i1);
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
