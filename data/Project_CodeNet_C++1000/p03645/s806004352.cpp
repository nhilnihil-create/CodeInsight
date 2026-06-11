#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> g1, g2;

    rep(i, m) {
        int t1, t2;
        cin >> t1 >> t2;
        if (t1 == 1) {
            g1.emplace_back(t2);
        }
        if (t2 == n) {
            g2.emplace_back(t1);
        }
    }

    if(g1.empty()||g2.empty()){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    sort(g2.begin(), g2.end());

    bool b = false;
    rep(i, g1.size()) {
        int t1 = g1[i];
        auto itr = lower_bound(g2.begin(), g2.end(), t1);

        if (*itr == t1) {
            b = true;
            break;
        }
    }

    if (b) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}