#include <bits/stdc++.h>

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
// #define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77, mod = 1e9 + 7;
int vis[N];
vector<int> g[N];

void dfs(int x, int d){
    if(vis[x]!=1e9) return;
    vis[x] = d;
    if(x==2){
        cout << d << endl;
        exit(0);
    }
    for(auto i : g[x]) dfs(i,d+1);
}

int32_t main()
{
    fast;
    fill(vis,vis+N,1e9);
    int n ; cin >> n ;
    for(int i = 1 ; i <= n ; ++i){
        int a ; cin >> a;
        g[i].push_back(a);
    }
    dfs(1,0);
    cout << -1 << endl;
    return 0;
}