#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int x[100100];

int main()
{
    int n;
    cin >> n;
    rep(i, n) {
        int a;
        cin >> a;
        x[a]++;
    }
    int ans = x[0] + x[1];
    repl(i, 1, 100100) {
        int t;
        t = x[i] + x[i + 1] + x[i - 1];
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}
