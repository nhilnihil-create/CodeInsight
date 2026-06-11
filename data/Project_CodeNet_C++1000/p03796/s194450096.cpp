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

const int mod = 1e9 + 7;
int n;
ll ans;

int main() {
    cin >> n;
    ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans = (ans * i) % mod;
    }
    cout << ans << endl;
    return 0;
}
