#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 9e18
#define mod 1000000007

ll n;
ll st;
ll dp[3];

int main(){
  cin>>n>>st;
  dp[0]=st;dp[1]=-INF;dp[2]=-INF;
  rep(i,n-1){
    char c;
    ll a;
    cin>>c>>a;
    ll nxt[3];
    nxt[0]=nxt[1]=nxt[2]=-INF;
    if(c=='+'){
      maxch(nxt[0],dp[0]+a);

      maxch(nxt[1],dp[1]-a);
      maxch(nxt[0],dp[1]+a);

      maxch(nxt[2],dp[2]+a);
      maxch(nxt[1],dp[2]+a);
      maxch(nxt[0],dp[2]+a);
    }else{
      maxch(nxt[0],dp[0]-a);
      maxch(nxt[1],dp[0]-a);

      maxch(nxt[1],dp[1]+a);
      maxch(nxt[0],dp[1]-a);
      maxch(nxt[2],dp[1]+a);

      maxch(nxt[2],dp[2]+a);
      maxch(nxt[1],dp[2]+a);
      maxch(nxt[0],dp[2]+a);
    }
    dp[0]=nxt[0]; dp[1]=nxt[1]; dp[2]=nxt[2];
  }
  cout<<*max_element(dp,dp+3)<<endl;
  return 0;
}
