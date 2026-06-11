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
  if((a+=b)>=mod)a%=mod;
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

  ll h,w,a,b;
  cin >> h >> w >> a >> b;

  ll fact[h+w+1];
  ll inv[h+w+1];
  fact[0]=1;
  rep1(i,h+w) fact[i] = mu(fact[i-1],i);
  rep(i,h+w+1) inv[i] = dv(1,fact[i]);

  ll ans = 0;
  rep(i,h-a){    
    ans = ad(ans,mu(mu(mu(fact[b+i-1],inv[i]),inv[b-1]) , mu(mu(fact[h+w-b-i-2],inv[h-i-1]),inv[w-b-1])));
    //    cout << mu(mu(fact[b+i-1],inv[i]),inv[b-1])<< " " << mu(mu(fact[h+w-b-i-2],inv[h-i-1]),inv[w-b-1]) << endl;
  }
  
  cout << ans  << endl;
  


  
  return 0;
    

}
