#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define outmat(v) for(auto i : v){for(auto j : i) cout << j << " ";cout << endl;}
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define infi 1900000000
#define infl 1100000000000000000
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define csp << " " <<
#define outset(n) cout << fixed << setprecision(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> using ve = vector<T>;
template<typename T> using pq2 = priority_queue<T>;
template<typename T> using pq1 = priority_queue<T,vector<T>,greater<T>>;


ve<vi> A;


struct edge { int to, cost; };
struct dijkstra {
    vector<vector<edge>> g;
    vector<int> d;
    vector<int> from_v;
    int V;
    
    dijkstra(int v){
        V = v;
        d.resize(V);
        g.resize(V);
        from_v.assign(V,-1);
    }
    
    void solve_d(int s){
        from_v[s] = s;
        pq1<pii> que;
        rep(i,V) d[i] = infi;
        d[s] = 0;
        que.push({0,s});
        
        while (!que.empty()) {
            pii p = que.top();
            que.pop();
            int v = p.se;
            if(d[v] < p.fi) continue;
            rep(i,int(g[v].size())){
                edge e = g[v][i];
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    from_v[e.to] = v;
                    que.push({d[e.to],e.to});
                }
            }
        }
    }
    
    int dis(int a){
        return d[a];
    }
};

int main()
{
    int N,M;
    cin >> N >> M;
    dijkstra G(N);
    A.assign(N,vi(N,0));
    rep(i,M){
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        G.g[a].pb({b,c});
        G.g[b].pb({a,c});
        A[a][b] = 1;
        A[b][a] = 1;
    }
    rep(i,N){
        G.solve_d(i);
        //outve(G.from_v);
        rep(i,N) A[i][G.from_v[i]] = -1, A[G.from_v[i]][i] = -1;
    }
    int ans = 0;
    rep(i,N) reps(j,i+1,N) if(A[i][j] == 1) ans++;
    

    cout << ans << endl;
    
    
    //outmat(A);
    
    

    return 0;
}
