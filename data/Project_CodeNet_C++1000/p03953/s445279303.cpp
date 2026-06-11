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

#define INF 1e16
#define mod 1000000007

ll N,M,K;
ll x[100010],d[100010];
ll ch[61][100010];
ll res[100010];

int main(){
  cin>>N;
  rep(i,N){
    cin>>x[i];
  }
  rep(i,N-1){
    d[i]=x[i+1]-x[i];
    ch[0][i]=i;
    res[i]=i;
  }
  cin>>M>>K;
  rep(i,M){
    ll a;
    cin>>a;
    a--;
    swap(ch[0][a-1],ch[0][a]);
  }

  rep(i,60){
    rep(j,N-1){
      ch[i+1][j]=ch[i][ch[i][j]];
    }
  }

  rep(i,60){
    if((K>>i)&1LL){
      rep(j,N-1){
        res[j]=ch[i][res[j]];
      }
    }
  }

  ll ans=x[0];
  rep(i,N){
    cout<<ans<<endl;
    ans+=d[res[i]];
  }

  return 0;
}
