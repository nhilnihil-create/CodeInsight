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
int n, k, t;
ll ans;

unordered_map<int, int> mp;
int res[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        ++mp[t];
        if (mp[t] == 2) {
            res[k++] = t;
        } if (mp[t] == 4) {
            ans = max(ans, 1LL * t * t);
        }
    }
    if (k <= 1) {
        cout << ans << endl;
        exit(0);
    }
    sort(res, res + k, greater<int>());
    ans = max(ans, 1LL * res[0] * res[1]);
    cout << ans << endl;
    return 0;
}
