//2020-04-11 23:20:32
//#pragma GCC optimize("-Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2")  //Enable AVX
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//order_of_key(x) : number of items less than x
//find_by_order(x) : iterator to x

#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(ll i=a;i<b;i++)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define fastio              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F                   first
#define S                   second
#define all(v)              (v).begin(),(v).end()

const ld pi=3.14159265359;
ll INF=1e18+10;
ll MOD=998244353;
ll mod=1e9+7;

inline ll add(ll a,ll b,ll m){
    if((a+b)>=m)return (a+b)%m;
    return a+b;
}

inline ll mul(ll a,ll b,ll m){
    if((a*b)<m)return a*b;
    return (a*b)%m;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll n,k;cin>>n>>k;
    ll a[n];
    rep(i,0,n){
        cin>>a[i];
        if(i!=0)
            a[i]+=a[i-1];
    }

    rep(i,0,n)a[i]-=((i+1)*k);
    set<pair<ll,ll>> ss;
    rep(i,0,n)ss.insert(mp(a[i],i));
    ss.insert(mp(-1,INF));
    map<pair<ll,ll>,int> m;
    int cnt=0;
    for(auto x: ss)m[x]=cnt++;
    rep(i,0,n)a[i]=m[mp(a[i],i)];
    ll ans=0;
    indexed_set s;s.insert(m[mp(-1,INF)]);
    rep(i,0,n){
        s.insert(a[i]);
        ll rank=s.order_of_key(a[i]);
        ans+=rank;
    }
    cout<<ans;
}