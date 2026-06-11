#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    ll ans = k;
    repl(i, 1, n) ans *= k - 1;
    cout << ans << endl;
    return 0;
}
