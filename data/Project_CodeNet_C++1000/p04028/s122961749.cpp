#include <bits/stdc++.h>
using namespace std;
 
#define int long long
//#define uint __int128_t
 
#define pb emplace_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define low(a,b) lower_bound(all(a),(b))-(a).begin()
#define upp(a,b) upper_bound(all(a),(b))-(a).begin()
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<vint> vvint;
typedef vector<pint>vpint;
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
typedef pair<pint,pint> PP;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007;
const ll INF=1e18;

int N;
string s;
int dp[5050][5050];

ll mod_pow(ll x, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}

int mod_inv(int x)
{
	return mod_pow(x, MOD - 2);
}
 
signed main() {
    IOS();
    //(1ll<<N)シフト演算のオーバーフローに気をつける
    //MOD同士の引き算に注意
    cin>>N>>s;
    dp[0][0]=1;
    rep(i,0,N){
        rep(j,0,N){
            if(dp[i][j]==0)continue;
            (dp[i+1][j+1]+=2*dp[i][j])%=MOD;
            (dp[i+1][max(0ll,j-1)]+=dp[i][j])%=MOD;
        }
    }
    cout<<dp[N][(int)s.size()]*mod_inv(mod_pow(2,(int)s.size()))%MOD<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}