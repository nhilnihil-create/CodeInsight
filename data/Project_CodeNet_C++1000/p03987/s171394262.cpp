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
    ll n;
    cin>>n;
    V<P> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].fi;
        a[i].se=i;
    }
    sort(all(a));
    set<ll> s;
    s.insert(-1);
    s.insert(n);
    ll ans=0;
    for(int i=0;i<n;i++){
        s.insert(a[i].se);
        auto ite=s.find(a[i].se);
        ll l,r;
        ite--;
        l=a[i].se-(*ite);
        ite++;
        ite++;
        r=(*ite)-a[i].se;
        ans+=a[i].fi*l*r;
    }
    cout<<ans<<"\n";
}
