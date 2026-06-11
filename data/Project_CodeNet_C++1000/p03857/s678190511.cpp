#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int e = 2*1e5 + 69;
vector<ll>adj1[e];
vector<ll>adj2[e];
bool visited[e];
vector<ll>ans[e];
map<ll,ll>kt;
map<ll,ll>kt1;
ll dem = 0;
ll dem1 = 0;
void dfs(ll n)
{
    visited[n] = false;
    kt[n] = dem;
    for(auto i:adj1[n])
    {
        if(visited[i] == true)
        dfs(i);
    }
}
void dfs1(ll n)
{
    kt1[n] = dem1;
    //ans[dem].pb(n);
    visited[n] = false;
    for(auto i:adj2[n])
    {
        if(visited[i] == true)
        {
            dfs1(i);
        }
    }
}
int main()
{
    ll n, k , l;
    cin >> n >> k >> l;
    for(ll i=1; i<=k; i++)
    {
         ll a, b;
         cin >> a >> b;
         adj1[a].pb(b);
         adj1[b].pb(a);
    }
    for(ll i=1; i<=l; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj2[a].pb(b);
        adj2[b].pb(a);
    }
    memset(visited, true, sizeof(visited));
    for(ll i=1; i<=n; i++)
    {
        if(visited[i] == true)
        {
            dem ++;
            dfs(i);
        }
    }
    memset(visited, true, sizeof(visited));
    for(ll i=1; i<=n; i++)
    {
        if(visited[i] == true)
        {
            dem1++;
            dfs1(i);
        }
    }
    map<ll,map<ll,ll>>ans;
    for(ll i=1; i<=n; i++)
    {
        ans[kt[i]][kt1[i]]++;
    }
    for(ll i=1; i<=n; i++)
    {
        cout << ans[kt[i]][kt1[i]]<<" ";
    }

}
