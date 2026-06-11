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

const int N = 1e5;
int ans, k, s;
int cnt[N];

int main() {
    cin >> k >> s;
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            ++cnt[i + j];
        }
    }
    for (int i = 0; i <= k; ++i) {
        int d = s - i;
        if (d >= 0) {
            ans += cnt[d];
        }
    }
    cout << ans << endl;
    return 0;
}
