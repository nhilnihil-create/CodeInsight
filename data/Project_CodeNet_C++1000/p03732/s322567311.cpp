#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, W, w[101], v[101];
vector<ll> V[4];
ll acc[4][101];

signed main(){
    cin >> N >> W;
    REP(i, N){
        cin >> w[i] >> v[i];
        V[w[i] - w[0]].push_back(v[i]);
    }
    REP(i, 4) sort(ALL(V[i]), greater<ll>());
    REP(i, 4){
        REP(j, V[i].size()) acc[i][j + 1] += acc[i][j] + V[i][j];
    }
    ll ans = 0;
    REP(i, V[0].size() + 1){
        REP(j, V[1].size() + 1){
            REP(k, V[2].size() + 1){
                REP(l, V[3].size() + 1){
                    if(i * w[0] + j * (w[0] + 1) + k * (w[0] + 2) + l * (w[0] + 3) > W) continue;
                    ans = max(ans, acc[0][i] + acc[1][j] + acc[2][k] + acc[3][l]);
                }
            }
        }
    }
    PRINT(ans);
    return 0;
}