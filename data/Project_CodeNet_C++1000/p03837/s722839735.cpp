#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int G[105][105];
ll dis[105][105];
int n,m;
void floyd(){
    fore(k,0,n)
        fore(i,0,n)
            fore(j,0,n)
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);

}
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    fast;
    cin >> n >> m;
    int u,v,w;
    fore(i,0,105)
        fore(j,0,105)
            dis[i][j] = INF;
    fore(i,0,m){
        cin >> u >> v >> w;
        u--;
        v--;
        G[u][v] = G[v][u] = w;
        dis[u][v] = dis[v][u] = w;
    }
    
    floyd();
    ll par = 0;
    fore(i,0,n)
        fore(j,0,n)
            par = max(par,dis[i][j]);
    int ans = 0;
    fore(i,0,n)
        fore(j,0,n)
            if(G[i][j] && G[i][j] > dis[i][j])
                ans++;
        
        
    cout << ans / 2 << '\n';
    return 0;   
}