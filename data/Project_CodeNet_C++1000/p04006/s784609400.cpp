#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

//2e5
const ll max_n = 1<<18;
const ll init_m=1e18;
ll leaf_n;
vector<ll> dat(max_n);

// 要素数決定、(1<<31)-1で初期化
void init(ll n) {
  leaf_n=1;
  while(leaf_n<n) leaf_n*=2;
  for(ll i=0;i<2*leaf_n-1;i++) dat[i]=init_m;
}

// from 0 [k]->a
void update(ll k,ll a) {
  k+=leaf_n-1;
  dat[k]=a;
  while(k>0) {
    k=(k-1)/2;
    dat[k]=min(dat[k*2+1],dat[k*2+2]);
  }
}

// (a,b,0,0,leaf_n),[a,b),[0,leaf_n)
ll find(ll a, ll b, ll k, ll l, ll r) {
  if(r<=a||b<=l) return init_m;
  if(a<=l&&r<=b) return dat[k];
  else {
    ll vl=find(a,b,k*2+1,l,(l+r)/2);
    ll vr=find(a,b,k*2+2,(l+r)/2,r);
    return min(vl,vr);
  }
}

int main() {
  ll n,x;
  cin >> n >> x;
  init(n);
  for(ll i=0;i<n;i++) {
    ll a;
    cin >> a;
    update(i,a);
  }
  ll ans=1e18;
  for(ll i=0;i<n;i++) {
    ll tans=x*i;
    for(ll j=0;j<n;j++) {
      ll f=j-i;
      if(f<0) {
        f+=n;
        tans+=min(find(f,n,0,0,leaf_n),find(0,j+1,0,0,leaf_n));
      }
      else {
        tans+=find(f,j+1,0,0,leaf_n);
      }
    }
    ans=min(ans,tans);
  }
  cout << ans << endl;
}