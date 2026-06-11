#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const int INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}



int main() {
    int N; cin >> N;
    vector<vector<P>>G(N);
    rep(i, N - 1) {
        int a, b, c;
        cin >> a >> b >> c; --a, --b;
        G[a].pb(mp(b, c));
        G[b].pb(mp(a, c));
    }
    int Q, K; cin >> Q >> K;
    --K;
    vector<ll>dist(N, INF); //K -> i への最短経路
    dist[K] = 0;
    queue<int>que;
    que.push(K);
    while(!que.empty()) {
        int q = que.front(); que.pop();
        for(auto next : G[q]) {
            if(dist[next.first] == INF) {
                que.push(next.first);
                dist[next.first] = dist[q] + next.second;
            }
        }
    }
    int x[Q], y[Q];
    rep(i, Q) {
        cin >> x[i] >> y[i];
        --x[i], --y[i];
    }

    rep(i, Q) {
        cout << dist[x[i]] + dist[y[i]] << endl;
    }
}
