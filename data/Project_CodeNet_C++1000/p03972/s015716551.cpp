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
    V<ll> p(w),q(h+1);
    ll ans=0;
    for(int i=0;i<w;i++){
        cin>>p[i];
        ans+=p[i];
    }
        V<ll> sum(h+1,0);
    for(int i=0;i<h;i++){
        cin>>q[i+1];
        ans+=q[i+1];
    }
    q[0]=-1;
    sort(all(q));
    for(int i=0;i<h;i++){
        sum[i+1]+=q[i+1]+sum[i];
    }
    for(int i=0;i<w;i++){
        int t=upper_bound(all(q),p[i])-q.begin();
        t--;//cout<<t<<" "<<sum[t]<<"\n";
        ans+=sum[t]+(h-t)*p[i];
    }
    cout<<ans<<"\n";
}
