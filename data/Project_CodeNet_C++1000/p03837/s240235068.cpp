#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

int N;
const int N_MAX = 201;
long long dist[N_MAX][N_MAX];

void floyd(){
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

ll M, edge[101][101];

signed main(){
    cin >> N >> M;
    ll a, b, c;
    REP(i, N) REP(j, N) edge[i][j] = dist[i][j] = LONG_LONG_MAX / 2;
    REP(i, N) edge[i][i] = dist[i][i] = 0;
    REP(i, M){
        cin >> a >> b >> c;
        a--; b--;
        edge[a][b] = edge[b][a] = dist[a][b] = dist[b][a] = c;
    }
    floyd();
    ll ans = 0;
    REP(i, N - 1){
        FOR(j, i + 1, N){
            if(edge[i][j] < LONG_LONG_MAX / 2 && edge[i][j] > dist[i][j]) ans++;
        }
    }
    PRINT(ans);
    return 0;
}