#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 100001;

int n, m, vis[N];
vector <int> v[N];

void dfs(int node, int &sz, int &b){
    sz++;
    for(auto &i : v[node]){
        if(vis[i] == -1){
            vis[i] = vis[node] ^ 1;
            dfs(i, sz, b);
        }
        if(vis[node] != (vis[i] ^ 1)) b = 1;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(vis, -1, sizeof vis);
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ones = 0;
    int g = 0, h = 0;
    for(int i = 1 ; i <= n ; i++){
        if(vis[i] != -1) continue;
        vis[i] = 0;
        int sz = 0, b = 0;
        dfs(i, sz, b);
        if(sz == 1) ones++;
        else{
            if(b == 0) g++;
            else h++;
        }
    }
    ll ans = 2LL * g * g;
    ans += 1LL * (g + h) * (g + h) - 1LL * g * g;
    int cur = n - ones;
    while(ones--){
        ans += 2 * cur + 1;
        cur++;
    }
    cout << ans << endl;
}
