/// In the name of God
#include <bits/stdc++.h>
//#define int long long
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

#define y1 def1
#define X first
#define Y second
#define endl '\n'
#define all(o) o.begin(), o.end()
#define IOS ios::sync_with_stdio(0), cin.tie(0)
const int maxn = 1e5 + 10;
vi adj[maxn];
int dfs(int v,int p){
    int res = 0;
    for(auto u : adj[v])
        if(u != p) res ^= (dfs(u, v) + 1);
    return res;
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(dfs(0, 0))
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
}
