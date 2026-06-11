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
const ll mod=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
  V<ll> a(7);
  for(int i=0;i<7;i++)cin>>a[i];
  ll ans=a[1];
  if(a[0]&&a[3]&&a[4]){
    ll d=min({a[0],a[3],a[4]});
    if((a[3]-d)%2==0&&(a[4]-d)%2==0){
      a[0]-=d;
      a[3]-=d;
      a[4]-=d;
      ans+=3*d;
    }else if((a[3]-d)%2==1&&(a[4]-d)%2==1){
      a[0]-=d-1;
      a[3]-=d-1;
      a[4]-=d-1;
      ans+=(d-1)*3;
    }else if((a[0]-d)%2==1){
      a[0]-=d-1;
      a[3]-=d-1;
      a[4]-=d-1;
      ans+=(d-1)*3;
    }else{
      a[0]-=d;
      a[3]-=d;
      a[4]-=d;
      ans+=3*d;
    }
  }
   ans+=a[0]/2*2;
  ans+=a[3]/2*2+a[4]/2*2;
  cout<<ans<<"\n";
}
