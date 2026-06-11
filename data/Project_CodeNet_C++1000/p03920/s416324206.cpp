#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007
#define INF (1 << 30)
#define REP(i, m, n) for(int i = (int)m; i < (int)n; ++i)
#define rep(i, n) REP(i, 0, n)


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    ll sum = 0, lim = 0, rmv = 0;
    REP(i, 1, n+1) {
        sum += i;
        if(sum >= n) {
            lim = i;
            rmv = sum-n;
            break;
        }
    }
    for(int i = 1; i <= lim; i++) {
        if(i == rmv) continue;
        cout << i << '\n';
    }
    return 0;
}