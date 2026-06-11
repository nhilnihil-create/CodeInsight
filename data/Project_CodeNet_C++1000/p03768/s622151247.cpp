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

ll N,M,H,W,K,Q,A,B;
string S;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main(){
    cin>>N>>M;
    vec a(M+N), b(M+N);
    rep(i,M) cin>>a[i]>>b[i], --a[i], --b[i];
    rep(i,N) a[i+M] = b[i+M] = i;
    cin>>Q;
    mat dp(11,vec(N,-1));
    vec color(Q);
    rep(i,Q){
        cin>>A>>B>>K;
        --A;
        dp[B][A] = i;
        color[i] = K;
    }
    Rrep(i,10){
        rep(j,M + N){
            dp[i][b[j]] = max(dp[i][b[j]], dp[i+1][a[j]]);
            dp[i][a[j]] = max(dp[i][a[j]], dp[i+1][b[j]]);
        }
        //rep(j,N) cout<<dp[i][j]<<' ';
        //cout<<endl;
    }
    rep(i,N) cout<<(dp[0][i] == -1 ? 0 : color[dp[0][i]])<<endl;
}