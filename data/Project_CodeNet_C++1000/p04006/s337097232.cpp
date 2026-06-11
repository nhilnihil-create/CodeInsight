#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

typedef struct {
    bool L, R;
} p_t;

Int cost[2001][2001];

int main() {
    Int n, x;
    cin >> n >> x;
    vector<Int> a(n);
    for (Int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (Int i = 0; i < n; i++) {
        cost[i][0] = a[i];
        for (Int j = 1; j < n; j++) {
            cost[i][j] = min(cost[i][j - 1], a[(i - j + n) % n]);
        }
    }
    Int res = INF;
    for (Int i = 0; i < n; i++) {
        Int c = i * x;
        for (Int j = 0; j < n; j++) {
            c += cost[j][i];
        }
        res = min(res, c);
    }
    dump(res);
    return 0;
}
