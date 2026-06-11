#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <map>
#include <cassert>
#include <iterator>
using namespace std;
using VI = vector<int>;
VI adj[101010];
int dp[101010][11];

int main() {
    int n, m, q;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> q;
    VI vs, ds, cs;
    for (int i = 0; i < q; i++) {
        int v, d, c;
        cin >> v >> d >> c;
        v--;
        vs.push_back(v);
        ds.push_back(d);
        cs.push_back(c);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 11; j++) {
            dp[i][j] = -1;
        }
    }
    
    for (int i = 0; i < q; i++) {
        dp[vs[i]][ds[i]] = i;
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 1) {
                
            }
            for (int k = 10; k > 0; k--) {
                if (dp[j][k] != -1) {
                    dp[j][k - 1] = max(dp[j][k - 1], dp[j][k]);
                    for (auto v: adj[j]) {
                        dp[v][k - 1] = max(dp[v][k - 1], dp[j][k]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dp[i][0] == -1) {
            cout << 0 << endl;
        } else {
            cout << cs[dp[i][0]] << endl;
        }
    }
}
