//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2")  //Enable AVX
#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define mp make_pair
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
const int mod=1e9+7;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int mul(int a,int b){
  return ((a)*1ll*(b))%mod;
}
 
void add(int &a,int b){
  a+=b;
  if(a>=mod)a-=mod;
}
 
int sub(int a,int b){
  a-=b;
  if(a<0){
    a+=mod;
  }
  return a;
}
 
int powz(int a,int b){
  int res=1;
  while(b){
    if(b&1){
      res=mul(res,a);
    }
    b/=2;
    a=mul(a,a);
  }
  return res;
}
 
template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x) {
  input>>x.F>>x.S;
  return input;
}
 
template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
  for(auto& i:x)
    input>>i;
  return input;
}
 
template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
  for(auto& i:x)
    output<<i<<' ';
  return output;
}
 
const int N=2000002;

struct ST{
  vector<ll>t;
  ST(int n){
    t.resize(4*n);
  }
  void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      t[v] += add;
    } else {
      int tm = (tl + tr) / 2;
      update(v*2, tl, tm, l, min(r, tm), add);
      update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
  }

  ll get(int v, int tl, int tr, int pos) {
    if (tl == tr)
      return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      return t[v] + get(v*2, tl, tm, pos);
    else
      return t[v] + get(v*2+1, tm+1, tr, pos);
  }

};


void solve(){
  int n,m;
  cin>>n>>m;
  vi a(n);
  cin>>a;
  ST st1(m+1),st2(m+1);
  for(int i=1;i<n;i++){
    if(a[i]==a[i-1]){
      continue;
    }
    int j=i;
    if(a[j-1]<a[j]){
      st1.update(1,1,m,a[j-1]+1,a[j],a[j-1]);
      st2.update(1,1,m,a[j-1]+1,a[j],1);
    }
    if(a[j]<a[j-1]){
      st1.update(1,1,m,a[j-1]+1,m,a[j-1]);
      st2.update(1,1,m,a[j-1]+1,m,1);
      st1.update(1,1,m,1,a[j],a[j-1]-m);
      st2.update(1,1,m,1,a[j],1);
    }
  }
  ll ans=0;
  for(int i=1;i<=m;i++){
    ans=max(ans,st2.get(1,1,m,i)*1ll*(i-1)-st1.get(1,1,m,i));
    debug(i,st2.get(1,1,m,i),st1.get(1,1,m,i),ans);
  }
  debug(ans);
  ans*=-1;
  for(int i=1;i<n;i++){
    int j=i;
    ans+=(a[j]>=a[j-1]?a[j]-a[j-1]:m-a[j-1]+a[j]);
  }
  cout<<ans;
 
  
}  
 
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc=1;
  //~cin>>tc;
  for(int _=0;_<tc;_++){
    // cout<<"Case #"<<_+1<<": ";
    solve();
    if(_!=tc-1){
      cout<<'\n';
    }
  }
}
