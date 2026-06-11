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
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(4);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
   ll w,h;
   cin>>w>>h;
   V<P> d;
   for(int i=0;i<h+w;i++){
       ll a;cin>>a;
       d.emplace_back(a,(w<=i));
   }
   sort(all(d));
   h++;w++;
   ll ans=0;
   for(int i=0;i<d.size();i++){
       if(d[i].se){
           ans+=w*d[i].fi;
           h--;
       }else{
           ans+=h*d[i].fi;
           w--;
       }
   }
   cout<<ans<<"\n";
}