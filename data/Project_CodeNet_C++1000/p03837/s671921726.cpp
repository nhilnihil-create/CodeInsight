#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1e9;
int const MAX_N = 105;

using P = pair<int,int>;
vector<P> G[MAX_N];

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> dist(n,vector<int>(n,INF));
    rep(i,n) dist[i][i] = 0;
    rep(i,m) {
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
        G[a].emplace_back(b,c);
        G[b].emplace_back(a,c);
    }

    rep(k,n) {
        rep(i,n) {
            rep(j,n) {
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int res = 0;
    rep(i,n) {
        for(auto e : G[i]) {
            int j = e.first;
            int d = e.second;
            bool ok = false;
            for(int x = 0; x < n; ++x) {
                for(int y = x+1; y < n; ++y) {
                    if(dist[x][y] == dist[x][i] + d + dist[j][y] 
                    || dist[x][y] == dist[x][j] + d + dist[i][y]) {
                        ok = true;
                    }
                }
            }
            if(!ok) res++;
        }
    }
    cout << res/2 << endl;
    return 0;
}
