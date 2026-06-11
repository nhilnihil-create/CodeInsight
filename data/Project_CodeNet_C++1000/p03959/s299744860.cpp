#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

// x^n in mod
ll modpow(ll x, ll n, ll mod){
  if(n==0) return 1;

  if(n%2==0){
    return modpow(x*x%mod, n/2, mod) % mod;
  }else{
    return x * modpow(x, (n-1), mod) % mod;
  }
}

int main(){
  int n;cin>>n;
  vector<ll> t(n), a(n);
  rep(i, n)cin>>t[i];
  rep(i, n)cin>>a[i];

  if(a[0]==t[0] && a.back()==t.back()){
    cout<<modpow(a[0], max<ll>(0, n-2), MOD)<<endl;
    return 0;
  }

  int max_t_i=0, max_a_i=n-1;
  rep(i, n)if(t[max_t_i]<t[i])max_t_i=i;
  rrep(i, n)if(a[max_a_i]<a[i])max_a_i=i;
//cout<<max_t_i<<' '<<max_a_i<<endl;

  if(a[max_a_i] != t[max_t_i] || max_a_i < max_t_i) { cout<<0<<endl; return 0;}

  vector<pll> h_l;
  ll ch=0, cl=0;
  rep(i, n){
    if(ch<t[i]){
      if(ch>0 && cl>0)h_l.push_back({ch, cl});
      ch=t[i]; cl=0;
    }else{
      cl++;
    }
  }

  ch=0, cl=0;
  rrep(i, n){
    if(ch<a[i]){
      if(ch>0 && cl>0)h_l.push_back({ch, cl});
      ch=a[i]; cl=0;
    }else{
      cl++;
    }
  }

  ll result=1;
  for(auto p: h_l){
//cout<<p.first<<','<<p.second<<endl;
    result = ( result * modpow(p.first, p.second, MOD) ) % MOD;
  }

  if(max_a_i != max_t_i)result=( result*modpow(a[max_a_i], max_a_i - max_t_i + 1-2, MOD) ) % MOD;

  cout<<result<<endl;

  return 0;
}