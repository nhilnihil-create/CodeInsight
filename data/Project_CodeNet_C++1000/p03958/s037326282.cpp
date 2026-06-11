#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int K, T;
    cin >> K >> T;
    vector<int> a(T);
    ll sum = 0;
    REP(i, T) {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = 0;
    REP(i, T) ans = max(ans, a[i] - (sum - a[i]) - 1);
    cout << ans << endl;
}