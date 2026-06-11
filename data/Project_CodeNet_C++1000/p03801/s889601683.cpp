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
   priority_queue<P,V<P>,greater<P>> q;
   int n;
   cin>>n;
   V<ll> a(n),ans(n,0);
   for(int i=0;i<n;i++){
       cin>>a[i];
       q.emplace(-a[i],i);
   }
   q.emplace(0,-1);
   ll ma2=0,cnt=0;
   queue<ll> tmp;
   while(q.size()){
       auto p=q.top();
       if(p.fi==0)break;
       while(q.size()&&(q.top().fi<=p.fi||p.se<=q.top().se)){
       tmp.push(-q.top().fi);
       q.pop();
       }
       ans[p.se]+=(-p.fi+q.top().fi)*cnt;
       while(tmp.size()){
           ans[p.se]+=tmp.front()+q.top().fi;
           tmp.pop();
           cnt++;
       }
   }
   for(int i=0;i<n;i++)cout<<ans[i]<<"\n";
}