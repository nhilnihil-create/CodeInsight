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

const int N = 1e5 + 5;
ll n, x, ans;
ll a[N];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0 && a[i] > x) {
            ans += a[i] - x;
            a[i] = x;
        }
        if (i > 0) {
            if (a[i] + a[i - 1] > x) {
                ll d = a[i] + a[i - 1] - x;
                a[i] -= d;
                ans += d;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
