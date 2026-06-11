#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

const ll MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    ll ans = 1;
    repl(i, 1, n + 1) {
        ans %= MOD;
        ans *= i;
    }
    ans %= MOD;
    cout << ans << endl;
    return 0;
}
