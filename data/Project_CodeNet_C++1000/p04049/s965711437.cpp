#include<bits/stdc++.h>

#define len(x) (int)(x).size()
#define fi first
#define se second
#define fast_io ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define pb push_back
#define all(x) (x).begin() , (x).end()
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 2e3 + 10;
int n , k;
vector < int > g[N];
int dfs(int v , int p , int len){
    if(len > k / 2)return 0;
    int curr = 1;
    for(auto u : g[v])if(u != p){
        curr += dfs(u , v , len + 1);
    }
    return curr;
}
signed main(){
    cin >> n >> k;
    vector<pair<int,int>>edges;
    for(int i = 0; i < n - 1;++i){
        int u , v;
        cin >> u >> v;
        --u , --v;
        edges.pb({u,v});
        g[u].pb(v) , g[v].pb(u);
    }
    int ans = n;
    if(!(k&1)){
        for(int i = 0; i < n; ++i){
            ans = min(ans , n - dfs(i , -1 , 0));
        }
    }else{
        for(int i = 0 ; i < n - 1; ++i){
            ans = min(ans , n - (dfs(edges[i].fi,edges[i].se,0)+dfs(edges[i].se,edges[i].fi,0)));
        }
    }
    cout << ans;
    return 0;
}
/*
4 3
1 2 1 2 7
1 3 2 1 8
2 3 3 2 6
6
4 3
1 2 1 2 7
1 3 2 1 8
2 3 3 2 6
6
4 3
1 2 1 2 7
1 3 2 1 8
2 3 3 2 6
6
4 3
1 2 1 2 7
1 3 2 1 8
2 3 3 2 6
6
4 3
1 2 1 2 7
1 3 2 1 8
2 3 3 2 6
6

4 3
1 2 1 2 7
1 3 2 1 8
2 3 3 2 6
6
*/
