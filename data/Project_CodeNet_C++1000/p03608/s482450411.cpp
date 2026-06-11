#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

class Main {
    int N, M, R;
    vector<int> r;
    using T = pair<ll, int>;
    vector<vector<T>> edge;
    void input() {
        cin >> N >> M >> R;
        r.resize(R);
        edge.resize(N);
        REP(i, R) {
            cin >> r[i];
            r[i]--;
        }
        REP(i, M) {
            int a, b;
            ll c;
            cin >> a >> b >> c;
            --a;
            --b;
            edge[a].emplace_back(c, b);
            edge[b].emplace_back(c, a);
        }
    }
    void output() {
        const ll INF = 1e18;
        map<int, vector<ll>> d;
        REP(k, R) {
            d[r[k]] = vector<ll>(N, INF);
            priority_queue<T, vector<T>, greater<T>> pq;
            pq.emplace(0, r[k]);
            while (!pq.empty()) {
                ll c;
                int i;
                tie(c, i) = pq.top();
                pq.pop();
                if (c >= d[r[k]][i]) continue;
                d[r[k]][i] = c;
                for (auto &p : edge[i]) {
                    ll dc;
                    int j;
                    tie(dc, j) = p;
                    if (c + dc < d[r[k]][j]) { pq.emplace(c + dc, j); }
                }
            }
        }
        SORT(r);
        ll res = INF;
        do {
            ll sum = 0;
            REP(i, R - 1) { sum += d[r[i]][r[i + 1]]; }
            res = min(res, sum);
        } while (next_permutation(r.begin(), r.end()));
        cout << res << endl;
    }

public:
    Main() {
        input();
        output();
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Main();

    return 0;
}
