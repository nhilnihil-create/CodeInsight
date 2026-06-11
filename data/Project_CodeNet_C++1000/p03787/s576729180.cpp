//                                ** ALLAH **
//                        who is Hussain? -> whoishussain.org

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1000000007;
inline int in(){ int x; scanf("%d",&x); return x; }
const int N = 1e5 + 100;
vector<int> adj[N];
int n, m, pa, qa, ia, mark[N], ret;
void dfs(int v){
        for(int u : adj[v] ){
                if( !mark[u] ) 
                        mark[u] = 3-mark[v],dfs(u);
                else if( mark[u] == mark[v] ) ret = 1;
        }
}
int32_t main(){
        n = in(), m = in();
        for(int i = 0;i < m; i++){
                int u = in()-1, v = in()-1;
                adj[u].pb(v), adj[v].pb(u);
        }

        for(int i = 0;i < n;i ++){
                if( adj[i].empty() ) { ia++; continue; } 
                if( mark[i] ) continue;
                mark[i] = 1, ret = 0;
                dfs(i);
                if( ret ) pa++;
                else qa++;
        }

        cout << 1ll * ia * ia + 1ll * ia * (n-ia) * 2 + 1ll *pa * pa + 1ll*qa * pa * 2 + 2ll * qa * qa << endl; 
}
