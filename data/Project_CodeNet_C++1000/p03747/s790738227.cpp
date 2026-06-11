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

ll N,L,T;
ll x[100010],d[100010];
vector<ll> res;

int main(){
  cin>>N>>L>>T;
  ll R=T%L;
  rep(i,N)cin>>x[i]>>d[i];
  ll cnt=0;
  rep(i,N){
    if(d[i]==1){
      res.push_back((x[i]+R)%L);
      cnt+=T/L;
      if(L-x[i]<R)cnt++;
    }else{
      res.push_back((x[i]-R+L)%L);
      cnt-=T/L;
      if(x[i]<R)cnt--;
    }
  }
  cnt%=N;
  if(cnt<0)cnt+=N;
  sort(all(res));
  rep(i,N){
    cout<<res[(i+cnt)%N]<<endl;
  }
  return 0;
}
