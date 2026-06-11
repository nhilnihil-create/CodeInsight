#include <bits/stdc++.h>
using namespace std;
#define rep(i,e) for(int i= 0; i< (int)(e); i++)
#define reps(i,s,e) for(int i = s; i < (int)(e); i++)
#define repr(i,s,e) for(int i = s; i > (int)(e); i--)
#define pb push_back
typedef long long ll;
const ll INF = 1LL << 60;

vector<vector<ll>> g;
vector<int> visited;
vector<ll> path;

bool dfs(ll v, ll goal){
    visited[v] = 1;
    if(v == goal){return true;}
    for(auto nv : g[v]){
        if(!visited[nv]){
            if(dfs(nv, goal)){
                path.pb(nv);
                return true;
            };
        }
    }
    return false;
}

void dfs_n(ll v){
    visited[v] = 1;
    for(auto nv : g[v]){
        if(!visited[nv]){
            dfs_n(nv);
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    g.resize(n);
    visited.resize(n);
    rep(i,n-1){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    //path 0 - (n-1)
    dfs(0,n-1);
    reverse(path.begin(),path.end());
    vector<ll> path_;
    path_.pb(0);
    rep(i,path.size()){
        path_.pb(path[i]);
    }
    path = path_;
    //remove critical edge
    ll tmp_e = ceil(((double)path.size())/2);
    g[path[tmp_e]].erase(remove(g[path[tmp_e]].begin(), g[path[tmp_e]].end(), path[tmp_e-1]), g[path[tmp_e]].end());
    g[path[tmp_e-1]].erase(remove(g[path[tmp_e-1]].begin(), g[path[tmp_e-1]].end(), path[tmp_e]), g[path[tmp_e-1]].end());

    //num fennec
    visited.assign(n,0);
    dfs_n(0);
    ll visited_num = 0;
    rep(i,n){
        visited_num += visited[i];
    }
    if(visited_num > n-visited_num){
        cout << "Fennec";
    }else{
        cout << "Snuke";
    }
}