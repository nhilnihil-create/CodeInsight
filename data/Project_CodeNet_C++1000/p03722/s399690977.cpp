#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;

using namespace std;
using Edge = pair<int, long long>;
int N, M;
vector<vector<Edge>> G;

int main() {
    cin >> N >> M;
    G.clear(); G.resize(N);
    for (int i = 0; i < M; ++i) {
        int a, b; ll w;
        cin >> a >> b >> w; --a; --b;
        G[a].push_back(Edge(b, -w));
    }

    vector<ll> dist(N, INF);
    bool negative = false;
    dist[0] = 0;
    for (int iter = 0; iter <= N*2; ++iter) {
        for (int v = 0; v < N; ++v) {
//            if (dist[v] >= INF / 2) continue;
            for (auto e: G[v]) {
                if (chmin(dist[e.first], dist[v] + e.second)) {
                    if (e.first == N - 1 && iter == N * 2) negative = true;
                }
            }
        }
    }

    if(!negative) cout << -dist[N-1] << endl;
    else cout << "inf" << endl;

}