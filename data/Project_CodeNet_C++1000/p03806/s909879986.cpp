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

int dp[401][401];

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,ma,mb; cin>>n>>ma>>mb;
    vi a(n),b(n),c(n);
    rep(i,n) cin>>a[i]>>b[i]>>c[i];
    rep(j,401)rep(k,401) dp[j][k] = INF;
    dp[0][0] = 0;
    rep(i,n)RFOR(j,400,a[i])RFOR(k,400,b[i]){
        chmin(dp[j][k], dp[j-a[i]][k-b[i]]+c[i]);
    }
    int ans=INF;
    for(int i=1; ma*i<=400 && mb*i<=400; i++){
        chmin(ans,dp[ma*i][mb*i]);
    }
    ans = (ans==INF)?-1:ans;
    cout<<ans<<endl;
    return 0;
}
