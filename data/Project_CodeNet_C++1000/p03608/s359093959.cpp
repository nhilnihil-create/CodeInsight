#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<P> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

//Warshall-floyd
ll dp[310][310];//dpテーブルには辺がないところにはINF、i==jには０を入れておく
void warshallfloyd(ll n){
    rep(k,n){
        rep(i,n){
            rep(j,n){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}

//入力
ll n,m,r;
vector<ll>machi;



int main(){
    cin >> n >> m >> r;
    machi.resize(r);
    rep(i,r){
        cin>>machi[i];
        machi[i]--;
    }
    rep(i,n)rep(j,n)dp[i][j]=INF;
    rep(i,n)dp[i][i]=0;
    rep(i,m){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        dp[a][b]=c;
        dp[b][a]=c;
    }
    warshallfloyd(n);//ここまで全点間最短距離を求める
    ll ans = INF;
    vector<ll>one_case;
    rep(i,r){
        one_case.emplace_back(i);
    }
    do{
        ll res = 0;
        rep(i,r-1){
            ll now = one_case[i];
            ll nx = one_case[i+1];
            ll from = machi[now];
            ll to = machi[nx];
            res += dp[from][to];
        }
        chmin(ans,res);
    } while (next_permutation(one_case.begin(),one_case.end()));
    cout << ans << endl;
    return 0;
}
