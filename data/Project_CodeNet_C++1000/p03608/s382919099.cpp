#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順
#define INF 1<<29

using Graph = vector<vector<int>>;
Graph d;

void warshall_floyd(int V) {
    rep(k,V)
        rep(i,V)
            rep(j,V) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    int N, M, R; cin >> N >> M >> R;
    d.assign(N, vector<int>(N, INF));
    rep(i,N) d[i][i] = 0;
    vector r(R, 0);
    rep(i,R) {
        int n; cin >> n; n--;
        r.at(i) = n;
    }
    sort(r.begin(), r.end());

    rep(i, M) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        if (d[a][b] > c) {
            d[a][b] = d[b][a] = c;
        }
    }
    
    warshall_floyd(N);

    ll mi = INT64_MAX;
    do {
       ll c = 0;
       rep(i, R-1) c += d[r[i]][r[i+1]];
       mi = min(mi, c);
    } while(next_permutation(r.begin(), r.end()));

    cout << mi << endl;

}
