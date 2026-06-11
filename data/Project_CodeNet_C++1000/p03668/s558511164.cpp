#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define taskname "A"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int maxn = 1e5 + 5;

vector<int> adj[maxn];
int DFS(int u , int par){
    int cnt = 0 , res = 0;
    for(int c : adj[u]){
        if(c == par)continue;
        res ^= (DFS(c , u) + 1);
    }
    return res;
}
int n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    cin >> n;
    for(int i = 1; i < n ; ++i){
        int u,v;cin >> u >> v;
        adj[u].pb(v);adj[v].pb(u);
    }
    puts(DFS(1,0) ? "Alice" : "Bob");
}
