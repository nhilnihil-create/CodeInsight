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
   int n;
   cin>>n;
   V<int> a(n);
   for(int i=0;i<n;i++)cin>>a[i];
   if(n==2){
       if(a[0]==1&&a[1]==1)cout<<"Possible"<<"\n";
       else cout<<"Impossible"<<"\n";
       return 0;
   }
   sort(all(a));
   bool c=true;
   if(a[0]==1&&a[1]==1)c=false;
   if(a[n-1]>n-1)c=false;
   if(a[n-1]==a[0])c=false;

   V<int> cnt(n+1,0);
   if(c){
       for(int i=0;i<n;i++)cnt[a[i]]++;
       if(cnt[a[0]]>2)c=false;
       if(a[n-1]%2==0&&cnt[a[0]]==2)c=false;
       for(int i=0;i<n;i++)if(a[i]!=a[0])if(cnt[a[i]]<2)c=false;
   }
   for(int i=1;i<n;i++){
       if(a[i]-a[i-1]>1)c=false;
   }
   if((a[n-1]+1)/2!=a[0])c=false;
    if(c)cout<<"Possible"<<"\n";
    else cout<<"Impossible"<<"\n";
}