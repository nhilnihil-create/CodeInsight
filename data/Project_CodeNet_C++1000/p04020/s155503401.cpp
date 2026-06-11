#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for(int i = (int)n - 1; j <= i; --i)



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    int* a = new int[n];
    rep(i, 0, n) cin >> a[i];

    ll ans = 0;
    rep(i, 0, n - 1) {
        if (a[i] & 1 && a[i + 1] > 0) {
            ++ans;
            --a[i];
            --a[i + 1];
        }
    }
    rep(i, 0, n) ans += a[i] / 2;
    cout << ans << endl;
    delete[] a;
    return 0;
}