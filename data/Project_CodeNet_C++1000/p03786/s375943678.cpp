#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n);
    int cnt = 0;
    int now = a[0];
    rep(i, 1, n) {
        if (now * 2 >= a[i]) {
            cnt++;
        } else {
            cnt = 0;
        }
        now += a[i];
    }
    cout << ++cnt << "\n";
}