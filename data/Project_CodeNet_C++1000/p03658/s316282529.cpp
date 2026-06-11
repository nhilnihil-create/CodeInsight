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
int n, k, ans;
int a[N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    for (int i = 0; i < k; ++i) {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}
