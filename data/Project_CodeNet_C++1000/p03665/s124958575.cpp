#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P  = pair<int, int>;
int main() {
    ll n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    ll c0 = 0, c1 = 0;
    for (int i : a) ++(i & 1 ? c1 : c0);
    c0 = 1ll << c0;
    c1 = (c1 > 0 ? (1ll << (c1 - 1)) : 0);
    cout << c0 * max(c1, p ? c1 : 1ll) << endl;
    cerr << "c0,c1:" << c0 << "," << c1 << endl;
    return 0;
}
