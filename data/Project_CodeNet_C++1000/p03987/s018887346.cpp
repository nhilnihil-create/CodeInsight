//2020-04-11 17:15:45
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
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
const int N=2e5+10;
ll a[N];
ll ans[N];
stack<ll> s;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll n;cin>>n;
    rep(i,0,n)cin>>a[i];
    a[n]=-1;
    s.push(n-1);
    ans[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        if(a[i]>a[i+1])
            ans[i]+=(a[i]+ans[i+1]);
        else{
            while(!s.empty() && a[s.top()]>a[i])s.pop();
            int in = (!s.empty()) ? s.top() : n;
            ans[i]+=((a[i]*(in-i))+ans[in]);
        }
        s.push(i);
    }
    ll sum=0;
    rep(i,0,n)sum+=ans[i];
    cout<<sum;
}