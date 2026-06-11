#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
 
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
    return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

struct edge {
    int s, t, w;
};

template<typename T = ll>
pair<bool, vector<T>> bellman_ford(int n, int s, const vector<edge>& edges) {
    constexpr T inf = numeric_limits<T>::max();
    vector<T> d(n, inf);
    bool n_cycle = false;

    d[s] = 0;
    REP(i, n) {
        bool update = false;
        for (const edge & e : edges) {
            if (d[e.s] != inf && d[e.s] + e.w < d[e.t]) {
                d[e.t] = d[e.s] + e.w;
                update = true;
            }
        }

        if (i == n-1 && update) {
            vector<bool> neg(n, false);

            REP(i, n) {
                for (const edge& e : edges) {
                    if (d[e.s] != inf && d[e.s] + e.w < d[e.t] || neg[e.s]) {
                        neg[e.t] = true;
                    }
                }
            }

            n_cycle = neg[n - 1];
        }
    }

    return {n_cycle, d};
}

int main() {
    int n, m; cin >> n >> m;
    vector<edge> edges(m);

    REP(i, m) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        edges[i] = {a, b, -c};
    }

    auto ret = bellman_ford(n, 0, edges);

    if (!ret.first) {
        cout << -ret.second[n-1] << endl;
    } else {
        cout << "inf" << endl;
    }

    return 0;
}
