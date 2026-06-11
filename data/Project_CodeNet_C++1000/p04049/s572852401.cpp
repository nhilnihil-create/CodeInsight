#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MAXN = 2000+10,
        INF = MAXN;

vi adj[MAXN];

int dfs(int u,int k, int p = -1){
    int res =(k==0);
    int nxtk = max(k-1,0);
    for(int v: adj[u]){
        if(v!=p)res+= dfs(v,nxtk,u);
    }
    return res;
}

int main() {
	fastio;
	
    int n,k;

    cin >> n >> k;

    forn(_,n-1){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int res = INF;
    forn(u,n){
        int nodecut = dfs(u,k/2+1);
        res = min(res,nodecut);
        //D(u);D(nodecut);
        for(int v:adj[u]){
            if(v>u){
                int bounds = (k-1)/2+1;
                nodecut = min(
                        dfs(u,bounds,v)+dfs(v,bounds,u),
                        dfs(u,bounds,v)+dfs(v,bounds,u)); 
                //cerr << "u-v = " << u << " " << v << endl;
                //D(nodecut);
                res = min(res,nodecut);
            }
        }
    }

    cout << res << endl;
	
	return 0;
}

