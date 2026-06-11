#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

const ll mod=1e9+7;
ll mu(ll a,ll b){
  return (ll)a*b%mod;
}
ll ad(ll a,ll b){
  if((a+=b)>=mod)a-=mod;
  return a;
}
ll pw(ll a,ll b,ll c=1LL){
  for(;b;b>>=1,a=mu(a,a))if(b&1)c=mu(c,a);
  return c;
}
ll dv(ll a,ll b){
  return mu(a,pw(b,mod-2));
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int x[n];
  rep(i,n) cin>>x[i];
  int kara=0;
  int iru=0;
  vector<int> k;
  int c=2;
  rep(i,n){
    if(x[i]-i-1+c==i+1){
      k.pb(i+1);
      c+=2;
    }
  }
  ll ans=1;
  rep(i,k.size()){
    ans = mu(ans,k[i]-i);
  }
  rep1(i,n-k.size()){
    ans = mu(ans,i);
  }
  cout << ans << endl;
  return 0;
    

}
