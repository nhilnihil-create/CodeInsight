#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

ll ans = 0;
int n;
string s;
void dfs (int now, ll sum) {
    if (now == n) {
        ans += sum;
        // cout << sum << "\n";
        return;
    }
    rep (i, now + 1, n + 1) {
        ll m = stoll (s.substr (now, i - now));
        // cout << m << "\n";
        dfs (i, sum + m);
    }
}

int main() {
    cin >> s;
    n = s.size();
    dfs (0, 0);
    cout << ans << "\n";
}
