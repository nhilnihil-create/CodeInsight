#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL MOD = 1e9+7;

int main() {
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    REP(i, N) {
        cin >> a[i];
    }

    LL res = max(0, a[0] - x);
    a[0] -= res;
    FOR(i, 1, N) {
        LL y = max(0, (a[i] + a[i - 1]) - x);
        a[i] -= y;
        res += y;
    }
    cout << res << endl;
    return 0;
}
