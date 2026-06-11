#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <cctype>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr int INF = 1 << 28;
constexpr ll LINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};


int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    int dist[n][n], edges[n][n];
    fill_n(dist[0], n*n, INF);
    fill_n(edges[0], n*n, INF);
    for(int i=1;i<=m;++i) {
        cin >> a >> b >> c;
        --a; --b;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
        edges[a][b] = c;
    }

    for(int k=0;k<n;++k) {
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            if(edges[i][j] == INF) continue;
            if(edges[i][j] > dist[i][j]) ++ans;
        }
    }

    cout << ans << endl;

}