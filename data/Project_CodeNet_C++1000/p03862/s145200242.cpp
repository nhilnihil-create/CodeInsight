#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll N,x;
  cin >> N >> x;
  vl a(N);
  vl b(N-1);
  ll ans=0;
  rep(i,N){
    cin >> a[i];
    if(i>=1){
      b[i-1]=a[i]+a[i-1];
    }
  }
  rep(i,N-1){
    if(b[i]>x){
      ll k=min(a[i+1],b[i]-x);
      ans+=b[i]-x;
      b[i]-=k;
      b[i+1]-=k;
    }
  }
  cout << ans << endl;
}
