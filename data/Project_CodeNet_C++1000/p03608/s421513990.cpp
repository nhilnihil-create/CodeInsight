#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N, M, R, A[40000], B[40000], r[10];
ll C[40000], dist[201][201];
ll ans = LONG_LONG_MAX / 2;

void floyd(){
    REP(k, N){
        REP(i, N){
            REP(j, N){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void solve(int depth, int index, int state, ll value){
    if(depth == R){
        ans = min(ans, value);
    }
    REP(i, R){
        if((1 << i) & state) continue;
        solve(depth + 1, r[i], state | (1 << i), value + dist[index][r[i]]);
    }
}

signed main(){
    cin >> N >> M >> R;
    REP(i, R){
        cin >> r[i];
        r[i]--;
    }
    REP(i, N) REP(j, N) dist[i][j] = LONG_LONG_MAX / 2;
    REP(i, M){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
        dist[A[i]][B[i]] = dist[B[i]][A[i]] = C[i];
    }
    floyd();
    REP(i, R) solve(1, r[i], 1 << i, 0);
    PRINT(ans);
    return 0;
}