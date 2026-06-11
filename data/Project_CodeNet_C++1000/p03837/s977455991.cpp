#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1e9;


int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> dist(n,vector<int>(n,INF));
    vector<tuple<int,int,int>> G;
    rep(i,n) dist[i][i] = 0;
    rep(i,m) {
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
        G.emplace_back(a,b,c);
    }

    rep(k,n) {
        rep(i,n) {
            rep(j,n) {
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int res = 0;
    rep(iter,m) {
        int i = get<0>(G[iter]);
        int j = get<1>(G[iter]);
        int d = get<2>(G[iter]);
        bool ok = true;
        for(int x = 0; x < n; ++x) {
            for(int y = x+1; y < n; ++y) {
                if(dist[x][y] == dist[x][i] + d + dist[j][y] 
                || dist[x][y] == dist[x][j] + d + dist[i][y]) {
                    ok = false;
                }
            }
        }
        if(ok) res++;
    }
    cout << res << endl;
    return 0;
}
