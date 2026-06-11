#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1e18 + 10;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using edge = pll;
const int max_v = 100100;

int n;
vector<edge> G[max_v];
ll d[max_v]; 

void dijkstra(int s){ 
    priority_queue<pll, vector<pll>, greater<pll>> que;
    fill(d, d+n, LINF); 
    d[s] = 0;
    que.push(pll(0, s));

    while(!que.empty()){
        pll p = que.top(); que.pop();
        int v = p.second; 
        if(d[v] < p.first) continue; 

        for(edge e: G[v]){
            int to = e.first; ll cost = e.second;
            if(d[to] > d[v] + cost){
                d[to] = d[v] + cost;
                que.push(pll(d[to], to));
            }
        }
    }
}

int main(){
    cin >> n;
    rep(i, n-1){
        ll a, b, c; cin >> a >> b >> c; a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    int q, k; cin >> q >> k; k--;
    dijkstra(k);
    rep(i, q){
        int x, y; cin >> x >> y; x--, y--;
        cout << d[x] + d[y] << ln;
    }
}
