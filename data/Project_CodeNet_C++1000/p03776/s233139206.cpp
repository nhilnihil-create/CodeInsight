#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

const ll mod=1e14+7;
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

void comb(ll *c, ll n){
  c[0] = 1;
  rep1(i,n){
    c[i] = c[i - 1]*(n + 1 - i)/i;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,a,b;
  cin >> n >> a>>b;
  ll v[n];
  rep(i,n) cin >> v[i];
  sort(v,v+n);
  reverse(v,v+n);
  ll res=0;
  ll pre=v[0];
  ll c=0;
  ll k=0;
  ll ina=0;
  rep(i,n){
    if(i<a) pre = v[i];
  }
  rep(i,n){
    if(pre==v[i]) c++;
    if(i<a && pre==v[i]) ina++;
  }
  ll C[c+1];
  comb(C,c);
  //  cout << ina << endl;
  if(v[0]==pre){
    for(int i=a; i<=min(b,c);i++){
      res+=C[i];
    }
  }
  else{
    res+=C[ina];
  }
  ll sum=0;
  rep(i,a) sum+=v[i];
  cout << fixed;
  cout << setprecision(12) << (((long double)(sum))/((long double)(a))) << endl;

  
  cout << res<<endl;

  
  return 0;
    

}
