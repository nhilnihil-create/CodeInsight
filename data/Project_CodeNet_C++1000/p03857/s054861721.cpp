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
    int N, K, L;
    cin >> N >> K >> L;
    Graph T(N), C(N);
    for (int i=0; i<K; ++i) {
        int a, b;
        cin >> a >> b;
        T[a-1].push_back(b-1);
        T[b-1].push_back(a-1);
    }
    for (int i=0; i<L; ++i) {
        int a, b;
        cin >> a >> b;
        C[a-1].push_back(b-1);
        C[b-1].push_back(a-1);
    }

    vector<pair<int, int>> color(N, {-1, -1});
    queue<int> que;
    for (int i=0; i<N; ++i) {
        if (color[i].first == -1) {
            color[i].first = i;
            que.push(i);
            while (!que.empty()) {
                int cur = que.front(); que.pop();
                for (int nx : T[cur]) {
                    if (color[nx].first == -1) {
                        color[nx].first = i;
                        que.push(nx);
                    }
                }
            }
        }
        if (color[i].second == -1) {
            color[i].second = i;
            que.push(i);
            while (!que.empty()) {
                int cur = que.front(); que.pop();
                for (int nx : C[cur]) {
                    if (color[nx].second == -1) {
                        color[nx].second = i;
                        que.push(nx);
                    }
                }
            }
        }
    }

    map<pair<int, int>, int> mp;
    for (auto p : color) ++mp[p];
    for (int i=0; i<N; ++i) {
        cout << mp[color[i]];
        if (i == N-1) cout << '\n';
        else cout << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
