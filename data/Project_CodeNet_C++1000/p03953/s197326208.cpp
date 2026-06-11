#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define M 1000000007
#define sz(a) (ll)a.size()
#define pll pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define sep(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define mll map<ll,ll>
#define vl vector<ll>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define F first
#define S second
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll p[100005],x[100005],n,m,k,diff[100005];
vl expo(ll k)
{
    vl v;
    if(k==1)
    {
        v.pb(0);
        rep(i,1,n)
            v.pb(p[i]);
            return v;
    }
    vl g=expo(k/2);
    vl temp=g;
    rep(i,1,n)
    temp[i]=g[g[i]];
    g=temp;
    if(k&1)
    {
        rep(i,1,n)
            temp[i]=g[p[i]];
    }
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    rep(i,1,n+1)
    cin>>x[i];
    rep(i,1,n)
        diff[i]=x[i+1]-x[i];
    cin>>m>>k;
    rep(i,1,n)
        p[i]=i;
    ll a;
    rep(i,0,m)
    {
        cin>>a;
        swap(p[a-1],p[a]);
    }
    vl g=expo(k);
    vl temp;
    temp.pb(0);
    rep(i,1,n)
        temp.pb(diff[i]);
    rep(i,1,n)
        diff[i]=temp[g[i]];
    vl f;
    f.pb(x[1]);
    rep(i,1,n)
        f.pb(f.back()+diff[i]);
    rep(i,0,n)
    cout<<f[i]<<"\n";
}
