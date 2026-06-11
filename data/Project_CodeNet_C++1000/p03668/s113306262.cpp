#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long int ll;
typedef vector< pair<int, int> > vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;

const ll INF = 1e18;
const ll inf = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll nax = 100000 + 10;

vi graph[nax];

int dfs(int v, int par)
{
    if(graph[v].size() == 1 && par != -1)
    {
        return 0;
    }
    int xori = 0;
    for(auto x: graph[v])
    {
        if(x == par) continue;
        xori ^= (dfs(x, v) + 1);
    }
    return xori;
}
void clr()
{
    for(int i = 1; i <= 1e5; i++)
        graph[i].clear();
}
int main()
{
    ios::sync_with_stdio(0);
    int t = 1;
    while(t--)
    {
        int n;
        cin >> n;
        clr();
        for(int i = 1; i <= n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        int ans = dfs(1, -1);
        if(ans == 0)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
    return 0;
}
