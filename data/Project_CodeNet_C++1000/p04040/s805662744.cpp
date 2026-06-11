#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) std::memset(arg,n,sizeof(arg))
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::set<int> si;
typedef std::string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
const ll MAX_P=200010;
ll fact[MAX_P];
ll H,W,A,B;
void make_fact(){
  fact[0]=fact[1]=1;
  for(ll i=2;i<MAX_P;i++){
    fact[i]=(fact[i-1]*i)%MOD;
  }
}
ll Extgcd(ll a,ll b,ll &x,ll &y){
  ll d=a;
  if(b!=0){
    Extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }
  else{
    x=1;y=0;
  }
  return d;
}

ll mod_inv(ll a,ll p){//mod pでのaの逆元を求める
  ll x,y;
  Extgcd(a,p,x,y);
  return (x%p+p)%p;
}
//n!=a*p^e (a,p互いに素,p素数) とした時のeとa mod p を求める
ll mod_fact(ll n,ll p,ll& e){
  e=0;
  if(n==0) return 1;
  
  ll res=mod_fact(n/p,p,e);
  e+=n/p;

  if(n/p%2!=0) return res*(p-fact[n%p])%p;
  return res*fact[n%p]%p;
}

//nCk mod pを求める
ll mod_comb(ll n,ll k,ll p){
  if(n<0||k<0||n-k<0) return 0;
  ll e1,e2,e3;
  ll a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);
  if(e1>e2+e3) return 0;
  return a1*mod_inv(a2*a3%p,p)%p;
}


int main(){
  make_fact();
  cin>>H>>W>>A>>B;
  ll res=0;
  rep(i,H-A){
    ll temp=(mod_comb(B-1+i,i,MOD)*mod_comb(W-B+H-2-i,H-1-i,MOD))%MOD;
    res=(res+temp)%MOD;
  }
  prin(res);
  return 0;
}
