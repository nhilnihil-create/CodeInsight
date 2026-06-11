#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;
 
const int N = 505;
typedef long long ll;
ll n, m, h, w, d;
ll a[N][N], ans;
 
int main() {
    cin >> n >> m >> h >> w;
    d = 1000;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if (i % h == 0 && j % w == 0) a[i][j] = -((h * w - 1) * d) - 1;
            else a[i][j] = d;
            ans += a[i][j];
        }
    }
    if (ans < 0) return puts("No"), 0;
    puts("Yes");
    rep(i, 1, n) {
        rep(j, 1, m) printf("%lld ", a[i][j]);
        puts("");
    }
    return 0;
}