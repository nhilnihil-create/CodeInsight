#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int inf = 1 << 30;
const ll INF = 1LL << 60;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<P>> g(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].emplace_back(1, b);
        g[b].emplace_back(1, a);
    }

    priority_queue<P, VP, greater<P>> pq;
    VI dist(n, inf), visited(n, -1);
    pq.push(P(0, 0));
    dist[0] = 0;
    while(!pq.empty()){
        P p = pq.top(); pq.pop();
        int u = p.second;

        if (dist[u] < p.first) continue;
        visited[u] = 1;

        for(P pp: g[u]){
            int v = pp.second, dis = pp.first;
            if (visited[v] == 1) continue;

            if (chmin(dist[v], dist[u] + dis)){
                pq.push(P(dist[v], v));
            }
        }
    }

    if (dist[n-1] == 2) {
        view("POSSIBLE");
    }else{
        view("IMPOSSIBLE");
    }
    return 0;
}