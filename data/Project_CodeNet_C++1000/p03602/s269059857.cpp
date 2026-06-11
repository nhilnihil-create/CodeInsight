#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
#include <stack>
#include <cmath>

using namespace std;

#define ll long long
const int maxn = 400;
const int mod = 998244353;

ll Map[maxn][maxn];
int n;

int main() {
    //freopen("input.txt", "r", stdin);
    ll ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> Map[i][j];
            ans += Map[i][j];
        }
    }
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (i != j && j != k && i != k) {
                    if (Map[i][j] == Map[i][k] + Map[k][j]) {
                        ans -= Map[i][j];
                        break;
                    }
                    if (Map[i][j] > Map[i][k] + Map[k][j]) flag = 1;
                }
            }
        }
    }
    if (flag) cout << -1 << endl;
    else cout << ans / 2 << endl;
    return 0;
}