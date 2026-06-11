#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    int sum = 0;
    rep(i, n) sum += t[i];
    int m;
    cin >> m;
    rep(i, m) {
        int p, x;
        cin >> p >> x;
        p--;
        cout << sum - (t[p] - x) << endl;
    }
    return 0;
}