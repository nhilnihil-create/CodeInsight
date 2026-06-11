#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const int INF = 1 << 28;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

int main() {
    int n, W;
    cin >> n >> W;
    vl w(n), v(n);
    ll totW = 0;
    ll totV = 0;
    vector<deque<ll>> pq(4);
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
        totW += w[i];
        totV += v[i];
        pq[w[i] - w[0]].emplace_back(v[i]);
    }
    for (int i = 0; i < 4; ++i) {
        sort(pq[i].begin(), pq[i].end(), greater<ll>());
    }
    for (int i = 0; i < 4; ++i) {
        pq[i].push_front(0); // centinel
    }
    vvl vv(4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < pq[i].size(); ++j) {
            if (j == 0) {
                vv[i].push_back(pq[i][0]);
            } else {
                vv[i].push_back(pq[i][j] + vv[i][j - 1]);
            }
        }
    }
    ll ret = 0;
    for (int i = 0; i < pq[0].size(); ++i) {
        for (int j = 0; j < pq[1].size(); ++j) {
            for (int k = 0; k < pq[2].size(); ++k) {
                for (int l = 0; l < pq[3].size(); ++l) {
                    ll weight =
                        i * w[0] + j * (w[0] + 1) + k * (w[0] + 2) + l * (w[0] + 3);
                    if (weight <= W)
                        chmax(ret, vv[0][i] + vv[1][j] + vv[2][k] + vv[3][l]);
                }
            }
        }
    }
    cout << ret << "\n";
    return 0;
}