#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ld long double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

#define INF 1e9

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vector<vi> dp(n,vi(n,INF));
    rep(i,n) dp[i][i] = 0;
    using edge = tuple<int,int,int>;
    vector<edge> es(m);
    rep(i,m){
        int a,b,c; cin>>a>>b>>c; a--; b--;
        dp[a][b] = c;
        dp[b][a] = c;
        es[i] = tie(a,b,c);
    }
    rep(k,n)rep(i,n)rep(j,n)
        chmin(dp[i][j],dp[i][k]+dp[k][j]);
    int ans=0;
    rep(i,m){
        int a,b,c;
        tie(a,b,c) = es[i];
        if (c>dp[a][b]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
