#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;


int main(){
    int N, M, R; cin >> N >> M >> R;
    vector<int> r(R);
    rep(i,R) cin >> r[i];
    rep(i,R) r[i]--;

    vector<vector<ll>> cost(N+1, vector<ll>(N+1, INF));
    rep(i,N+1) cost[i][i] = 0;
    rep(i,M){
        int a, b, c; cin >> a >> b >> c;
        a--;
        b--;
        cost[a][b] = c;
        cost[b][a] = c;
    }

    rep(k,N+1){
        rep(i,N+1){
            rep(j,N+1){
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
            }
        }
    }
    ll ans = INF;
    sort(r.begin(), r.end());
    do{
        ll tmp = 0;
        rep(i,R-1){
            tmp += cost[r[i]][r[i+1]];
        }    
        ans = min(ans, tmp);

    }while(next_permutation(r.begin(), r.end()));
   
    cout << ans << endl;
} 