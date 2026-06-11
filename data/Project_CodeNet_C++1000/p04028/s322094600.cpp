#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3

#define mod 1000000007LL

ll mod_pow(ll a,ll n){
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll n;
string s;
ll dp[5005][5005];

int main(){
  cin>>n>>s;
  ll l=s.size();
  dp[0][0]=1;
  rep(i,n)rep(j,n+1){
    if(j>0){
      (dp[i+1][j-1]+=dp[i][j])%=mod;
    }else{
      (dp[i+1][j]+=dp[i][j])%=mod;
    }
    (dp[i+1][j+1]+=dp[i][j]*2)%=mod;
  }
  cout<<dp[n][l]*mod_pow(mod_pow(2LL,l),mod-2)%mod<<endl;
	return 0;
}
