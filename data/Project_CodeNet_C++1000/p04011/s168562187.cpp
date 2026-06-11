#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n, k, x, y;

int main() {
    cin >> n >> k >> x >> y;
    int ans = min(n, k) * x + max(0, n - k) * y;
    cout << ans << endl;
    return 0;
}
