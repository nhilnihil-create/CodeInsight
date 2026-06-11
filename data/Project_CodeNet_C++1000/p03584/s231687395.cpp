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
  cout<<'\n';
}

template <class T>
void cout_vec2(const vector<vector<T>> &vec){
  rep(i,vec.size()){
    rep(j,vec[i].size()){
      cout<<vec[i][j]<<' ';
    }
    cout<<endl;
  }
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vector<ll> a(n),b(n);
    rep(i,n) cin>>a[i]>>b[i];
    ll ans=0;
    for(int i=31;i>=0;i--){
      ll mask=0;
      ll cnt=0;
      if(!(k & (1<<i))) continue;
      for(int j=31;j>=i+1;j--){
        if((k & (1<<j))) mask+=(1ll<<j);
      }
      for(int j=i-1;j>=0;j--) mask+=(1ll<<j);
      rep(j,n){
        if((a[j] & mask)==a[j]) cnt+=b[j];
      }
      ans=max(ans,cnt);
    }
    ll mask=k,cnt=0;
    rep(j,n){
      if((a[j] & mask)==a[j]) cnt+=b[j];
    }
    ans=max(ans,cnt);
    cout<<ans<<endl;
}