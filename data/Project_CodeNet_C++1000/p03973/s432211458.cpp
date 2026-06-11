#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

int main() {
    int n; cin >> n;
    int m = 0;//現在の最大値
    ll ans = 0;
    REP(i, n) {
        int a; cin >> a;
        if (m + 1 == a) {
            m = a;
            continue;
        }
        else if (m >= a) {
            continue;
        }
        else {
            ans += (a-1) / (m + 1);
            if (m == 0) m = 1;
        }
    }
    cout << ans << endl;
    return 0;
}