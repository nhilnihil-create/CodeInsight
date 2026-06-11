// be name khoda
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define int long long
#define mpr make_pair 
typedef long long ll;
#pragma GCC optimize("Ofast")

const int maxn = 1e6+10;
const int N = 1e6+5;
const int mod = 998244353;
const int inf = 1e9+10;

int n, m, c[maxn], q;
int mx[maxn];
vector<int> g[maxn];

void dfs(int v, int C)
{
    if(!c[v]) c[v] = C;
    for(auto u : g[v])
        if(mx[u] < mx[v]-1)
        {
            mx[u] = mx[v]-1;
            dfs(u,C);
        }
}

int v[maxn], d[maxn], C[maxn];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n >> m;
    memset(mx, -1, sizeof mx);
    for(int i = 1, u, v; i <= m; i++)
    {
        cin>> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin>> q;
    for(int i = 1; i <= q; i++) cin>> v[i] >> d[i] >> C[i];
    for(int i = q; i >= 1; i--)
    {
        //cout<< mx[v[i]] <<" "<< d[i] <<" "<< C[i] <<"\n";
        if(mx[v[i]] < d[i])
        {
            mx[v[i]] = d[i];
            dfs(v[i],C[i]);
        }
    }
    for(int i = 1; i <= n; i++) cout<< c[i] <<"\n";
}



