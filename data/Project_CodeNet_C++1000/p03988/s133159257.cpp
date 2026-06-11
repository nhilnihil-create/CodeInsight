#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    int mx = 0;
    int a[n];
    rep(i, n) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int mn = (mx + 1) / 2;
    sort(a, a + n);
    if (mx % 2 == 0) {
        if (a[0] != mn || a[1] == mn) {
            cout << "Impossible" << endl;
            return 0;
        }
    } else {
        if (a[0] != mn || a[1] != mn || a[2] == mn) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    int cnt[mx + 1] = {};
    for (int i = (mx % 2 == 0 ? 1 : 2); i < n; i++) {
        cnt[a[i]]++;
    }
    for (int i = mn + 1; i <= mx; i++){
        if(cnt[i] < 2){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}