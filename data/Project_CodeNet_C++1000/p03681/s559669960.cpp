#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int N, M;

const ll MOD = 1e9 + 7;


void input() {
    cin >> N >> M;
}


ll perm(int x) {
    ll ret = 1;
    rep(i, x) ret = ret * (i + 1) % MOD;
    return ret;
}


int main() {
    input();
    if (abs(N - M) >= 2) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = perm(N) * perm(M) % MOD;
    if (N == M) ans = 2 * ans % MOD;
    cout << ans << endl;
}
