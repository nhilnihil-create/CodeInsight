#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main() {
    ll Ma, Mb;
    cin>>N>>Ma>>Mb;
    vec a(N), b(N), c(N);
    rep(i,N) cin>>a[i]>>b[i]>>c[i];
    vector<mat> dp(N+1, mat(401, vec(401, INF)));
    dp[0][0][0] = 0;
    rep(i,N){
        rep(j,401) rep(k,401) dp[i + 1][j][k] = dp[i][j][k];
        reps(j, a[i], 401){
            reps(k, b[i], 401){
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j - a[i]][k - b[i]] + c[i]);
            }
        }
    }
    ll ans = INF;
    for(ll i = 1; (i*Ma < 401) && (i * Mb < 401); ++i){
        ans = min(ans, dp[N][i*Ma][i*Mb]);
    }
    cout<<(ans == INF ? -1 : ans)<<endl;
}