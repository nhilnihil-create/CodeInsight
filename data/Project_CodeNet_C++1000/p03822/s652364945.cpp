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
V<ll> g[100005];
ll cnt[100005];
ll solve(int cur){
    V<ll> tmp;
    for(int v:g[cur]){
        tmp.push_back(solve(v));
    }
    if(tmp.size()==0)return 0ll;
    ll res=0;
    sort(all(tmp),greater<ll>());
    for(int i=0;i<tmp.size();i++){
        chmax(res,tmp[i]+i+1);
    }
    return res;
}
int main(){
  ll n;
  cin>>n;
  V<ll> a(n);
  for(int i=0;i<n-1;i++){
      cin>>a[i];
      g[a[i]-1].push_back(i+1);
  }
  cout<<solve(0)<<"\n";
}
