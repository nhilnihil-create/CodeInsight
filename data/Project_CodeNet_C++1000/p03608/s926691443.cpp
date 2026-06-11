#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

struct edge {
    int to;
    ll dist;
};

int main() {
    int N, M, R;
    cin >> N >> M >>R;
    vector<int> r(R);
    REP(i, R) {
        cin >> r[i];
        r[i]--;
    }

    vector< vector<edge> > edges(N, vector<edge>());
    REP(i, M) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        edge e1 = {b, c}, e2 = {a, c};
        edges[a].push_back(e1);
        edges[b].push_back(e2);
    }

    vector<vector<ll> > dist(N, vector<ll>(N, -1));
    REP(i, N) {
        queue<int> que;

        dist[i][i] = 0ll;
        que.push(i);
        while(!que.empty()) {
            int v = que.front();
            que.pop();

            for(edge e: edges[v]) {
                int n = e.to;
                if(dist[i][n] != -1ll) {
                    if(dist[i][n] > dist[i][v] + e.dist) {
                        dist[i][n] = dist[i][v] + e.dist;
                        que.push(n);
                    }
                    // dist[i][n] = min(dist[i][v] + e.dist, dist[i][n]);
                    continue;
                }

                dist[i][n] = dist[i][v] + e.dist;
                que.push(n);
            }
        }
    }

    // cerr << "dist" << endl;
    // REP(i, N) {
    //     REP(j, N) cerr << dist[i][j] << " ";
    //     cerr << endl;
    // }

    vector< vector<ll> > dp(R+1, vector<ll>((1<<R)+ 5, INF)); // dp[i][s]: iにいる状態ですでにsを訪れた

    FOR(i, 1, R) {
        for(int s=0; s < (1<<R); s++) {
            if(__builtin_popcount(s) != i) continue;
            if(i == 1) {
                REP(i, R)
                    if(s&(1<<i))
                    dp[i][s] = 0ll;
            }
            else {
                REP(k, R) {
                    REP(j, R) {
                        if( (s&(1<<(j))) && (s&(1<<(k))) && r[j] != r[k]) {
                            dp[k][s] = min(dp[k][s], dp[j][s&~(1<<(k))] + dist[r[j]][r[k]]);
                        }
                    }
                }
            }
        }
    }
    
    // cerr << "ans" << endl;
    ll ans = INF;
    int idx = -1;
    REP(i, R) {
        // cerr << "final position = " << i << " total-dist = " << dp[i][(1<<R)-1] << endl;
        if(ans > dp[i][(1<<R)-1]) {
            ans = dp[i][(1<<R) - 1];
            idx = i;
        }
    }
    // cerr << "arg idx = " << idx << endl;
    cout << ans << endl;
    return 0;
}