#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

vector<vector<int>> dist;
int N;
ll prim() {
    vector<int>mincost(N, INF);
    vector<int> used(N, false);
    mincost[0] = 0;
    priority_queue<P, vector<P>, greater<>> pque;
    pque.emplace(0, 0);
    ll res = 0;
    while(!pque.empty()) {
        P p = pque.top();
        pque.pop();
        if(used[p.second]) continue;
        used[p.second] = true;
        res += p.first;
        for(int i = 0; i < N; ++i) {
            if(dist[p.second][i] == 0) continue;
            if(!used[i]) {
                pque.push(mp(dist[p.second][i], i));
            }
        }
    }
    return res;
}



int main() {
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N)
        rep(j, N)
            cin >> A[i][j];

    dist = A;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    bool ok = true;
    rep(i, N) {
        rep(j, N) {
            if(dist[i][j] != A[i][j]) ok = false;
        }
    }
    ll ans = 0;
    if(!ok) {
        cout << -1 << endl;
    }else {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                for(int k = 0; k < N; ++k) {
                    if(i == k || j == i) continue;
                    if(dist[j][i] + dist[i][k] == dist[j][k])
                        dist[j][k] = INF;
                }
            }
        }
        rep(i, N) {
            for(int j = i + 1; j < N; ++j) {
                if(dist[i][j] != INF) ans += dist[i][j];
            }
        }

        cout << ans << endl;
    }
}
