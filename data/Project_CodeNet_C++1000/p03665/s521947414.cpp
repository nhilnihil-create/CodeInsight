#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int INF = 1e9;
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;

void solve()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ki = 0, gu = 0;
    for (auto i : a)
    {
        if (i % 2 == 0)
            gu++;
        else
            ki++;
    }
    if (ki == 0)
    {
        if (p == 0)
            cout << ((ll)1 << n) << endl;
        else
            cout << 0 << endl;
    }
    else
        cout << ((ll)1 << (n - 1)) << endl;
}
int main(void)
{
    solve();
}