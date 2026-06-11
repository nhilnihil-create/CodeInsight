#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
  ll n,x;
  cin>>n>>x;
  if(x==1||x==2*n-1){
      cout<<"No"<<"\n";
      return 0;
  }
  cout<<"Yes"<<"\n";
  V<bool> used(2*n,false);
  V<ll> ans(2*n-1,-1);
  used[x-1]=used[x]=used[x+1]=true;
  ans[(2*n-1)/2]=x;
  ans[(2*n-1)/2-1]=x-1;
  ans[(2*n-1)/2+1]=x+1;
  ll id=1;
  for(int i=0;i<2*n-1;i++){
      if(ans[i]==-1){
      while(id<=2*n-1&&used[id])id++;
      ans[i]=id;
      id++;
      }
      cout<<ans[i]<<"\n";
  }
}