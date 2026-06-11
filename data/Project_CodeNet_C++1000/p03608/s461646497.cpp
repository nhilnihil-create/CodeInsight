#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m, R;
    cin >> n >> m >> R;
    vector<int> r(R);
    rep(i, R) {
        cin >> r[i];
        r[i]--;
    }
    const int INF = 1001001001;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    rep(i, n) dist[i][i] = 0;

    rep(k, n)rep(i, n)rep(j, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    sort(r.begin(), r.end());

    int ans = 1001001001;
    do{
        int d = 0;
        rep(i, R - 1) d += dist[r[i]][r[i + 1]];
        ans = min(ans, d);
    }while(next_permutation(r.begin(), r.end()));
    
    cout << ans << endl;
}