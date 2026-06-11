#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
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
 string s,t;
 cin>>s>>t;
 int n=s.size(),m=t.size();
 V<V<int>> ss(2,V<int>(n+1,0)),tt(2,V<int>(m+1,0));
 for(int i=0;i<n;i++){
     ss[s[i]-'A'][i+1]=ss[s[i]-'A'][i]+1;
     ss[(s[i]-'A')^1][i+1]=ss[(s[i]-'A')^1][i];
 }
  for(int i=0;i<m;i++){
     tt[t[i]-'A'][i+1]=tt[t[i]-'A'][i]+1;
     tt[(t[i]-'A')^1][i+1]=tt[(t[i]-'A')^1][i];
 }
 int q;
 cin>>q;
 while(q--){
     int w,x,y,z;
     cin>>w>>x>>y>>z;
     ll a1=(ss[0][x]-ss[0][w-1])%3,b1=(ss[1][x]-ss[1][w-1])%3;
     ll a2=(tt[0][z]-tt[0][y-1])%3,b2=(tt[1][z]-tt[1][y-1])%3;
     int d1=min(a1,b1),d2=min(a2,b2);
     a1-=d1;b1-=d1;
   //  cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<"\n";
     if(a1&&a1%2==0){b1=1;a1=0;}
     else if(b1&&b1%2==0){a1=1;b1=0;}
     a2-=d2;b2-=d2;
     if(a2&&a2%2==0){b2=1;a2=0;}
     else if(b2&&b2%2==0){a2=1;b2=0;}
     //cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<"\n";
     if(b1){
         if(b1==b2)cout<<"YES"<<"\n";
         else cout<<"NO"<<"\n";
     }else if(a1){
         if(a1==a2)cout<<"YES"<<"\n";
         else cout<<"NO"<<"\n";
     }else{
         if(a1==a2&&b1==b2)cout<<"YES"<<"\n";
         else cout<<"NO"<<"\n";
     }
 }
}