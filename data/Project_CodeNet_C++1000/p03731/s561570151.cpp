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

const int N = 2e5 + 5;
int n;
ll t, c, p, ans;

int main() {
    cin >> n >> t;
    cin >> p;
    for (int i = 1; i < n; ++i) {
        cin >> c;
        ans += min(c - p, t);
        p = c;
    }
    cout << ans + t << endl;
    return 0;
}
