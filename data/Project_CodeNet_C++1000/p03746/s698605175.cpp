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

int n, m;
bool is[maxn];
deque<int> deq = {1}; 
vector<int> g[maxn];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n >> m;
    for(int i = 1, u, v; i <= m; i++)
    {
        cin>> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    is[1] = 1;
    while(1)
    {
        bool can = 0;
        for(auto u : g[deq.back()])
            if(!is[u])
            {
                can = 1;
                deq.push_back(u);
                is[u] = 1;
                break;
            }
        if(!can) break;
    }
    while(1)
    {
        bool can = 0;   
        for(auto u : g[deq.front()])
            if(!is[u])
            {
                can = 1;
                deq.push_front(u);
                is[u] = 1;
                break;
            }
        if(!can) break;
    }     
    cout<< deq.size() <<"\n";
    for(auto x : deq) cout<< x <<" ";
}



