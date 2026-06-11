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
  int n,x;
  cin>>n>>x;
  vector<ll> a(2*n);
  vector<vector<ll>> b(n,vector<ll>(n,inf));
  rep(i,n){
    cin>>a[i];
    a[i+n]=a[i];
  }
  FOR(i,n,2*n){
    b[i-n][0]=a[i];
    FOR(k,1,n){
      b[i-n][k]=min(b[i-n][k-1],a[i-k]);
    }
  }
  ll ans=inf;
  rep(k,n){//魔法を唱える回数をk回に固定
    ll cnt=k*x;
    rep(i,n){
      cnt+=b[i][k];
    }
    ans=min(ans,cnt);
  }
  cout<<ans<<endl;
}