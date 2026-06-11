#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<int,int>;
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
  int n,m;
  cin>>n>>m;
  V<int> same(m,0),d(m,0);
  map<int,int> mp;
  for(int i=0;i<n;i++){
    int a;cin>>a;
    mp[a]++;
    d[a%m]++;
  }
  for(auto p:mp){
     same[p.fi%m]+=p.se/2;
  }
  int ans=0;
  for(int i=0;i<=m/2;i++){
    if(i==(m-i)%m)ans+=d[i]/2;
    else{
    ans+=min(d[i],d[(m-i)%m]);
    if(d[i]>d[(m-i)%m]){
      d[i]-=d[(m-i)%m];
      ans+=min(d[i]/2,same[i]);
    }else{
      d[(m-i)%m]-=d[i];
      ans+=min(d[(m-i)%m]/2,same[(m-i)%m]);
    }
   }
  }
  cout<<ans<<"\n";
}
