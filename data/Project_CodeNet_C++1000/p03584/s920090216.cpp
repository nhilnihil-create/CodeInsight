#include "bits/stdc++.h"
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i,n,m) for(int i = (int)(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 4e18;

ll maxsum(const vector<int> &a, const vector<int> &b, int n) {
    ll res = 0;
    REP(i, a.size()) {
        if ((a[i] & n) == a[i]) {
            res += b[i];
        }
    }
    return res;
}

int main() {
    int n, k; scanf("%d %d", &n, &k);
    vector<int> a(n), b(n);
    REP(i, n) scanf("%d %d", &a[i], &b[i]);
    ll ans = 0;
    while (k != -1) {
        ans = max(ans, maxsum(a, b, k));
        k = ((k + 1) & k) - 1;
    }
    cout << ans << endl;
    getchar(); getchar();
}