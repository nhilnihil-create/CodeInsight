#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n;i++)
ll d[300][300],v, n, c, e, u, k, sum = 0,ans;
const  long long int INF = (1LL << 32);
void warshall_floyd(int n) { // nは頂点数
    rep(k, n) {  // 経由する頂点
        rep(i, n) {
            if (d[i][k] == INF) continue;// 開始頂点
            rep(j, n) {// 終端
                if (d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
int main(void) {
    cin >> n >> e >> k;
    vector<int>r(k);
    rep(i, k) { 
        cin >> r[i];r[i]--;
    }
    sort(r.begin(), r.end());
    rep(i, n) {
        rep(j, n) {
            d[i][j] = ((i == j) ? 0 : INF);
        }
    }
    rep(i, e) {
        cin >> u >> v >> c;u--;v--;
        d[u][v] = c;
        d[v][u] = c;
    }
    warshall_floyd(n);ans = 9223372036854775800;
        do {
            sum = 0;
            rep(i, k - 1) {
                sum += d[r[i]][r[i + 1]];
            }
            ans = min(ans, sum);
        } while (next_permutation(r.begin(), r.end()));
    cout << ans << endl;
}