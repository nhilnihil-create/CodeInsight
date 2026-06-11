#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxx = 1e6 ;
const ll mod = 1e9 + 7;
ll t, T, n, m, k, ans[maxx], tong, r, o[12], h;
struct icon
{
    ll pos  , val , mn;
};
icon b[maxx];
bool ss(const icon&x, const icon&y)
{
    return (x.val < y.val) || (x.val == y.val && x.pos < y.pos);
}
ll c[maxx], f[2002][2002], ma[12][12];
map<ll, ll> mp;
char ch;
vector<ll> adj[maxx];
string s;
ll a[maxx], dd[maxx], vit[maxx];

set<ll> st[maxx];
vector<ll> bo[maxx], sat[maxx];
void bfs(ll u, ll x)
{
    a[u] = x;
    for(auto v: bo[u])
    {
        if(a[v] == 0)
        {
            bfs(v, x);
        }
    }
}
void dfs(ll u, ll x)
{
    dd[u] = x;
    for(auto v: sat[u])
    {
        if(dd[v] == 0)
        {
            dfs(v, x);
        }
    }
}
vector<pair<pair<ll, ll>, ll>> tp;
void sol()
{
    cin >> n >>  k >> m;
    ll x, y;
    for(int i = 1; i <= k; i ++)
    {
        cin >> x >> y;
        bo[x].push_back(y);
        bo[y].push_back(x);
    }
    for(int i = 1; i <= m; i ++)
    {
        cin >> x >> y;
        sat[x].push_back(y);
        sat[y].push_back(x);
    }
    fill_n(dd, n+1, 0);
    fill_n(a, n+1, 0);
    for(int i = 1; i <= n; i ++)
    {
        if(a[i] == 0)
            bfs(i, i);
    }
    for(int i = 1; i <= n; i ++)
        {
            if(dd[i] == 0)dfs(i, i);
        }
    for(int i = 1; i <= n; i ++)
    {
        tp.push_back({{a[i], dd[i]}, i});
    }
    sort(tp.begin(), tp.end(), [](const pair<pair<ll, ll>, ll> &x, const pair<pair<ll, ll>,ll> &y)
         {
            return ((x.first.first < y.first.first) || (x.first.first == y.first.first && x.first.second < y.first.second));
         });
    h = 0;
    for(int i = 0; i < n; i ++)
        {
            t = 1;
            ++h;
            while(i + 1 < n && (tp[i].first.first == tp[i+1].first.first) && (tp[i+1].first.second == tp[i].first.second))
            {
                ans[tp[i].second] = h;
                ++t;
                ++i;
            }
            ans[tp[i].second] = h;
            c[h] = t;
        }
    for(int i = 1; i <= n; i ++)
        cout << c[ans[i]] <<" ";
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    sol();
}


