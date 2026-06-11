#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
typedef pair<ll,ll> P;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
queue<ll> q;
int n,k;
cin>>n>>k;
ll sum1=0,sum2=0;
V<ll> a(n);
for(int i=0;i<n;i++){
cin>>a[i];
if(i<k){q.emplace(a[i]);sum2+=a[i];}
else if(a[i]>0){sum1+=a[i];sum2+=a[i];}
}
ll ans=0;
ans=max({ans,sum1,sum2});
for(int i=k;i<n;i++){
    if(a[i]>0)sum1-=a[i];
    if(a[i]<0)sum2+=a[i];
    q.emplace(a[i]);
    ll tmp=q.front();
    q.pop();
    if(tmp<0)sum2-=tmp;
    if(tmp>0)sum1+=tmp;
    ans=max({ans,sum1,sum2});
}
cout<<ans<<"\n";
}