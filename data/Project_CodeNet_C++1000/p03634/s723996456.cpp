#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

const ll INI = -1;
int n;
vector<vector<P>> tree(101010, vector<P>(0));
vector<ll> dist(101010, INI);

void dfs(int pos)
{
    for(auto x : tree[pos])
    {
        if(dist[x.first] != INI) continue;
        dist[x.first] = dist[pos] + x.second;
        dfs(x.first);
    }
    return;
}

int main()
{
    cin >> n;
    rep(i, n - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].emplace_back(P(b, c));
        tree[b].emplace_back(P(a, c));
    }

    int q, k;
    cin >> q >> k;
    dist[k] = 0;
    dfs(k);

    rep(i, q)
    {
        int x, y;
        cin >> x >> y;
        cout << dist[x] + dist[y] << "\n";
    }
    
    return 0;
}