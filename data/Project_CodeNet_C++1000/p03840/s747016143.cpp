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
bool check(ll a,ll b,ll c){
    if(a==0)return (b%2&&c%2);
    if(b==0)return (a%2&&c%2);
    if(c==0)return (a%2&&b%2);
    return false;
}
int main(){
  V<ll> a(7);
  for(int i=0;i<7;i++)cin>>a[i];
  ll ans=a[1];
  ll d=min({a[0],a[3],a[4]});
      ans+=d*3;
      a[0]-=d;
      a[3]-=d;
      a[4]-=d;
      if(d&&check(a[0],a[3],a[4])){
          ans-=3;
          if(a[0]==0){
              a[3]++;
              a[4]++;
          }
          if(a[3]==0){
              a[0]++;
              a[4]++;
          }
          if(a[4]==0){
              a[0]++;
              a[3]++;
          }
      }
     ans+=a[0]/2*2+a[3]/2*2+a[4]/2*2;
     cout<<ans<<"\n";
}
