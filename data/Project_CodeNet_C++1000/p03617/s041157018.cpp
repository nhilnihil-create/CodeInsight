#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main()
{
    int q, h, s, d;
    int n;
    cin >> q >> h >> s >> d;
    cin >> n;
    h = min(2 * q, h);
    s = min(2 * h, s);
    if(2 * s <= d) cout << (ll) n * s << endl;
    else cout << (ll) (n / 2) * d + (n % 2) * s << endl;
    return 0;
}
