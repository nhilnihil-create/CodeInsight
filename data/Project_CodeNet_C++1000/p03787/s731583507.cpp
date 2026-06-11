#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;

int n, m;
int color[100010];
vector<int> G[100010];
int d = 0;
bool f = true;

void dfs(int v, int c){
    color[v] = c;
    d++;
    rep(i, 0, G[v].size()){
        if(color[G[v][i]] == c) f = false;//
        if(color[G[v][i]] == 0) dfs(G[v][i], -c);
    }
}

signed main(){
    cin >> n >> m;
    rep(i, 0, m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u]. push_back(v);
        G[v]. push_back(u);
    }
    int ca = 0, cb = 0, cc = 0;
    rep(i, 0, n){
        d = 0; f = true;
        if(color[i] == 0){
            dfs(i, 1);
            if(d == 1) ca++;
            else if(f == true) cb++;
            else cc++;
        }
    }
    cout << cb * cb + (cb + cc) * (cb + cc) + ca * ca + 2 * ca * (n - ca) << endl;
}
