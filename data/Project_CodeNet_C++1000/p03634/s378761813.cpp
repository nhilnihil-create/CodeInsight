#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
#define w(t) while(t--)
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1 * 1e5 + 5;
const ll mod = 1000000;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
vector< pair<int, ll> >  G[N];
vi pro(N);
vector<ll> dis(N);
int P[N][20];
void dfs(int u, int parent, int prof){
    P[u][0] = parent;
    pro[u] = prof;
    fore(i, 1, 20)
        P[u][i] = P[P[u][i - 1]][i - 1];
    for(auto v : G[u]){
        if(v.F != parent){
            dis[v.F] = dis[u] + v.S;
            dfs(v.F, u, prof + 1);
        }
    }
}
int main(){
    fin;
    int n;
    cin >> n;
    fore(i, 1, n){
        int u, v; 
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }
    int q, k;
    cin >> q >> k;
    k--;
    dfs(k, k, 0);
    w(q){
        int u, v;
        cin >> u >> v;
        u--;v--;
        cout << dis[u] + dis[v] << '\n';
    }
    return 0;
}   