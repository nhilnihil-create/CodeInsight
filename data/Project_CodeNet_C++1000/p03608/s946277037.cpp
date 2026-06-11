#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int N, M, R; cin >> N >> M >> R;
    vector<int> r(R); rep(i, R) cin >> r[i];
    vector<vector<int>> dist(N+1, vector<int>(N+1,0));
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        if(i==j) dist[i][j] = 0;
        else dist[i][j] = 1001001001;
    }
    rep(i, M) {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = c;
    }
    for(int k=1;k<=N;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    sort(r.begin(), r.end());
    ll ans = 1e18;
    do {
        ll d = 0;
        for(int i=0;i<r.size()-1;i++) {
            d += dist[r[i]][r[i+1]];
        }
        ans = min(ans, d);
    }while(next_permutation(r.begin(), r.end()));
    cout << ans;
}