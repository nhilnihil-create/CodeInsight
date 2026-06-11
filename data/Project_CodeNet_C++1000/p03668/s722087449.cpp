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

vector<int> G[maxn];

int dfs(int u, int fa){
    int ans = 0;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        ans ^= (dfs(v, u) + 1);
    } 
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ret = dfs(1, 0);
    if(ret == 0){
        cout << "Bob" << endl;
    }else{
        cout << "Alice" << endl;
    }
    return 0;
}
