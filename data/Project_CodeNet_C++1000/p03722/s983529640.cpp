
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

const int MAX_V = 1e4;
const int MAX_E = 1e4;

struct Edge {
    ll from, to, w;
};

vector<Edge> w(MAX_E);
ll d[MAX_V];
int V, E;

bool bellman_ford(int s) {
    REP(i, V) d[i] = INF;
    d[s] = 0;

    REP(i, 2 * V) {
        REP(j, E) {
            Edge e = w[j];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.w) {
                d[e.to] = d[e.from] + e.w;

                if (i >= V - 1 && e.to == V - 1) {
                    return true; // detect negative loop.
                }
            }
        }
    }

    return false; // no negative loops.
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> V >> E;

    REP(i, E) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a; --b;

        w[i] = {a, b, -c};
    }

    if (bellman_ford(0)) {
        cout << "inf" << endl;
    } else {
        cout << -d[V-1] << endl;
    }
    
}
