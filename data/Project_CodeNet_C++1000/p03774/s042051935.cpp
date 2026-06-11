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

const int N = 51;
int n, m;
ii s[N], c[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i].first >> s[i].second;
    }
    for (int i = 0; i < m; ++i) {
        cin >> c[i].first >> c[i].second;
    }
    for (int i = 0; i < n; ++i) {
        ll ans = LLONG_MAX;
        ll ri = 0;
        for (int j = 0; j < m; ++j) {
            ll x = abs(s[i].first - c[j].first);
            ll y = abs(s[i].second - c[j].second);
            if (x + y < ans) {
                ans = x + y;
                ri = j;
            }
        }
        cout << ri + 1 << endl;
    }
    return 0;
}
