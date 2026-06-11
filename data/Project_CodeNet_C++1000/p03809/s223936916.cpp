#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int n;
const int maxn = 1e5 + 5;
ll a[maxn];
vector<int> G[maxn];
int deg[maxn];

bool dfs(int u, int fa){
    ll up = 0;
    if(deg[u] == 1){
        return true;
    }
    ll mx = 0;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        if(!dfs(v, u))
            return false;
        up += a[v];
        mx = max(mx, a[v]);
    } 
    if(up < a[u])
        return false;
    ll ub = 0;
    if(mx > up - mx){
        ub = up - mx; 
    }else{
        ub = up / 2;
    }
    ll delta = up - a[u];
    if(delta  > ub)
        return false;
    a[u] -= delta;
    return true;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i < n;i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if(n == 2){
        if(a[1] != a[2]){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }else{
        int root = 0;
        for(int i = 1;i <= n;i++){
            if(deg[i] != 1){
                root = i;
            }
        } 
        if(dfs(root, root)){
            if(a[root] == 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
