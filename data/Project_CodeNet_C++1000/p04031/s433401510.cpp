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

const int N = 105;
int n, ans;
int a[N];

int main() {
    ans = 1e9;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = -100; i <= 100; ++i) {
        int cost = 0;
        for (int j = 0; j < n; ++j) {
            cost += (i - a[j]) * (i - a[j]);
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}
