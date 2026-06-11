#include<bits/stdc++.h>
#define nguyendz the_best

#define all(n) n.begin(),n.end()
#define ll int
#define ld long double
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define pll pair<ll,ll>
#define YES cout <<"YES"<<endl;
#define NO cout <<"NO"<<endl;
#define ff first
#define ss second
//#define ((x|y)-y) (x&(~y))
//#define gcd(fibo(x),fibo(y)) = fibo(gcd(x,y))
using namespace std;
const ll maxn=6e5+5;
const ll maxx=1e13;
const ll mod=1e9+7;
const ll mod1=998244353;

//vector<ll> ans;
//bool kt[maxn];

map<ll,map<ll,ll>> mp;
ll ans[maxn];
ll par1[maxn];
ll par[maxn];
vector<ll> st[maxn];
vector<ll> st1[maxn];
ll find_par(ll u)
{
    if (u==par[u]) return u ;
    return par[u]=find_par(par[u]);
}
void  dsu(ll a,ll b)
{
    ll u=find_par(a);
    ll v=find_par(b);
    if (u!=v)
    {
        if (st[u].size()<st[v].size()) swap(u,v);
        par[v]=u;
        for (auto p:st[v])
        {
            st[u].pb(p);
        }
        st[v].clear();
    }
}
ll find_par1(ll u)
{
    if (u==par1[u]) return u ;
    return par1[u]=find_par1(par1[u]);
}
void  dsu1(ll a,ll b)
{
    ll u=find_par1(a);
    ll v=find_par1(b);
    if (u!=v)
    {

        if (st1[u].size()<st1[v].size()) swap(u,v);
        par1[v]=u;
        for (auto p:st1[v])
        {
            st1[u].pb(p);
        }
        st1[v].clear();
    }
}

int main()
{
    // freopen("test.txt","r",stdin);
    // freopen("CHEMIST.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k,l;
    cin>>n>>k>>l;
    for (int i=1;i<=n;i++)
    {
        par[i]=i;
        st[i].pb(i);
        par1[i]=i;
        st1[i].pb(i);
    }
    for (int i=1;i<=k;i++)
    {
        ll x,y;
        cin>>x>>y;
        dsu(x,y);
    }
    for (int i=1;i<=l;i++)
    {
           ll x,y;
           cin>>x>>y;
           dsu1(x,y);
    }
    for (int i=1;i<=n;i++)
    {
      auto u=find_par(i);
      auto v=find_par1(i);
    //  cout <<u<<" "<<v<<endl;
      mp[u][v]++;
    }
    for (int i=1;i<=n;i++)
    {
        auto u=find_par(i);
      auto v=find_par1(i);
        cout <<mp[u][v]<<" ";
    }
 //   for (int i=1;i<=n;i++) cout <<ans[i]<<" ";


}
