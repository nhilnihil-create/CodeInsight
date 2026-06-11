#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<P> cnt(n+2,P(0,0));
  bool flag=true;
  FOR(i,1,n+1){
    ll a;
    cin>>a;
    cnt[i].fi=a;
    if(cnt[i-1].fi<a) cnt[i].se=1;
  }
  vector<ll> b(n+1);
  rep(i,n) cin>>b[i+1];
  for(int i=n;i>=1;i--){
    ll a=b[i];
    if(cnt[i].se && cnt[i].fi>a) flag=false;
    cnt[i].fi=min(cnt[i].fi,a);
    if(cnt[i+1].fi<cnt[i].fi) cnt[i].se=1;
  }
  if(!flag) cout<<0<<endl;
  else{
    ll ans=1;
    FOR(i,1,n+1){
      if(cnt[i].se) continue;
      (ans*=(cnt[i].fi)%mod)%=mod;
    }
    cout<<ans<<endl;
  }
}