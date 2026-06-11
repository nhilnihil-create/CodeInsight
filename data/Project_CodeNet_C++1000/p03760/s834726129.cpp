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

string o, e, ans;
int main() {
    cin >> o >> e;
    int n = o.length();
    int m = e.length();
    for (int i = 0; i < m; ++i) {
        ans += o[i];
        ans += e[i];
    }
    if (n > m)
        ans += o[n - 1];
    cout << ans << endl;
    return 0;
}
