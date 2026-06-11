#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<pint>>;

int N,M,R;
vector<int> r;

int main(){
    cin>>N>>M>>R;
    r.resize(R);
    rep(i,R)cin>>r[i];
    rep(i,R)r[i]--;
    ll dp[210][210];
    rep(i,210)rep(j,210)dp[i][j] = INF;
    rep(i,M){
        int a,b,c; cin>>a>>b>>c;
        a--; b--;
        dp[a][b] = c;
        dp[b][a] = c;
    }
    rep(k,N){
        rep(i,N){
            rep(j,N){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    sort(r.begin(),r.end());
    ll res = INF;
    do{
        ll time = 0;
        rep(i,R-1){
            time += dp[r[i]][r[i+1]];
        }
        res = min(res,time);
    }while(next_permutation(r.begin(),r.end()));
    cout<<res<<endl;
}
